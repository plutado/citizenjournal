<?php
/**
 * @file
 * Contains all utinities function
 * @author Duynv
 */

/**
 * convert rows_setting from array to string
 */
function tab_setting_to_string($settings, $menu, $tab_id) {
  $output = array();
  $output['mnu_fly_type'] = $settings['general']['is_dropdown_menu'];
  $output['title_enabled'] = $settings['general']['title_enable'];
  $output['mnu_title'] = $settings['general']['title'];
  $output['mnu_path'] = $settings['general']['path'];
  $output['mnu_desc'] = $settings['general']['description'];
  $org_icon = $settings['general']['icon'];
  replace_icon_url($menu->settings['design']['top_dmi_img'], $org_icon);
  $output['icon_url'] = $org_icon;
  $output['mnu_class'] = $settings['general']['css_class'];
  $output['mnu_id'] = $menu->mid;
  $output['tab_id'] = $tab_id;
  $output['mnu_layout']['numCol'] = $settings['layout']['col_grid'];
  $output['mnu_layout']['setting'] = $settings['layout']['rows_setting'];
  $output['mnu_layout']['isFullWidth'] =  $settings['layout']['is_full_width'];
  $output['mnu_layout']['subWidth'] =  $settings['layout']['submenu_width'];

  return json_encode($output);
}

/**
 * Replace icon url of sub-items by image_style url
 */
function prepare_subitem_icon($img_style, &$settings) {
  switch ($settings->type) {
    case 'a':
      if ( $settings->a_icon != '') {
        replace_icon_url($img_style, $settings->a_icon);
      }
      break;

    case 'header':
      if ($settings->h_icon != '') {
        replace_icon_url($img_style, $settings->h_icon);
      }
      break;

    case 'img':
      if ($settings->img_path != '') {
        replace_icon_url($img_style, $settings->img_path);
      }
      break;
  }
}

  /**
   * Replace icon url by image-style url of icon
   */
function replace_icon_url($img_style, &$org_icon) {
  $encoded = FALSE;
  if (strpos($org_icon, 'id=') === FALSE) {
    $org_icon = urldecode($org_icon);
    $encoded = TRUE;
  }

  $icon_attr = explode('&', $org_icon);
  foreach ($icon_attr as $attr) {
    if (strpos($attr, 'id=') !== FALSE) {
      $icon_id = explode('=', $attr);
      $icon_id = $icon_id[1];
      $icon_file = file_load($icon_id);
      if ($img_style != '') {
        $icon_url = image_style_url($img_style, $icon_file->uri);
      }
      else {
        $icon_url = file_create_url($icon_file->uri);
      }
      $org_icon = 'id=' . $icon_id . '&url=' . $icon_url;
    }
  }

  if ($encoded) {
    $org_icon = urlencode($org_icon);
  }
}

/**
 * Get url of icon in icon data
 */
function get_icon_url($icon_data) {
  $icon_url = '';

  if (strpos($icon_data, '&') === FALSE) {
    $icon_data = urldecode($icon_data);
  }
  $icon_attr = explode('&', $icon_data);
  foreach ($icon_attr as $attr) {
    if (strpos($attr, 'url=') !== FALSE) {
      $icon_url = explode('=', $attr);
      $icon_url = $icon_url[1];
    }
  }

  return $icon_url;
}

/**
 * Get icon id in icon data
 */
function get_icon_id($icon_data) {
  $icon_id = '';

  if (strpos($icon_data, '&') === FALSE) {
    $icon_data = urldecode($icon_data);
  }
  $icon_attr = explode('&', $icon_data);
  foreach ($icon_attr as $attr) {
    if (strpos($attr, 'id=') !== FALSE) {
      $icon_id = explode('=', $attr);
      $icon_id = $icon_id[1];
    }
  }

  return $icon_id;
}

function md_megamenu_get_youtube_id_from_url($url) {
  $pattern = '/(?:youtube\.com\/(?:[^\/]+\/.+\/|(?:v|e(?:mbed)?)\/|.*[?&]v=)|youtu\.be\/)([^"&?\/ ]{11})/i';
  preg_match($pattern, $url, $matches);

  return isset($matches[1]) ? $matches[1] : FALSE;
}

function md_megamenu_get_vimeo_id_from_url($url) {
  $parsed = parse_url($url);
  $hostname = $parsed['host'];  // WWW.YOUTUBE.COM
  $vimdeo_id_int = FALSE;
  if ((isset($hostname)) && $hostname=='vimeo.com') {
    $arrv = explode('://vimeo.com/', $url); // from ID to end of the string
    $video_id = substr($arrv[1], 0, 8); // to get video ID
    $vimdeo_id_int = intval($video_id); // ID must be integer
  }
  return $vimdeo_id_int;
}

function generate_menu_css_configure($mid, $menu_settings) {
  $design = $menu_settings['design'];
  $css_content = "";

  # generate css for top level config
  $out = generate_css_by_level('top', $design);
  if ($out != '') {
    $css_content .= "#megamenu-" . $mid . ".md-horizontal,\n";
    $css_content .= "#megamenu-" . $mid . ".md-vertical ul.megamenu {" . "\n";
    $css_content .= $out . "}\n";
  }

  # Generate for sub level config
  $out = generate_css_by_level('sub', $design);

  if ($menu_settings['text_typography']['text_sub_level'] != '') {
    $font_sub = explode('|', $menu_settings['text_typography']['text_sub_level']);
    if (end($font_sub) != '') {
      $out .= end($font_sub) . "\n";
    }
  }

  if ($menu_settings['text_typography']['text_sub_level_color'] != '') {
    $out .= "color: #" . $menu_settings['text_typography']['text_sub_level_color'] . ";\n";
  }

  if ($out != '') {
    $css_content .= "#megamenu-" . $mid . " .mm-container {\n" . $out . "}\n";
  }

  # Generate for hover mega item config
  $out = generate_css_by_level('hoveritem', $design);
  if ($out != '') {
    $css_content .= "#megamenu-" . $mid . " li.mm-hover > a,\n";
    $css_content .= "#megamenu-" . $mid . " li.mm-hover > a:link,\n";
    $css_content .= "#megamenu-" . $mid . " li.mm-hover > a:hover,\n";
    $css_content .= "#megamenu-" . $mid . " .md-vertical li.mm-hover > a,\n";
    $css_content .= "#megamenu-" . $mid . " .md-vertical li.mm-hover > a:link,\n";
    $css_content .= "#megamenu-" . $mid . " .md-vertical li.mm-hover > a:hover  {\n";
    $css_content .= $out . "}\n";
  }

  # Generate css for custom height
  $height = 0;
  if ($menu_settings['general']['dmg_defaultheight'] && $menu_settings['general']['dmg_customheight'] != '') {
    $height = (int)$menu_settings['general']['dmg_customheight'];
    $css_content .= "#megamenu-" . $mid . " .mm-container {top: " . $height . "px;}\n";
    $css_content .= "#megamenu-" . $mid . ".md-vertical .mm-container,\n";
    $css_content .= "#megamenu-" . $mid . " .mm-dropdown ul li ul.mm-container {top: 0;}\n";

    if (in_array('dmg_desc', $menu_settings['general']['dm_right'])) {
      $css_content .= "#megamenu-" . $mid . " .mm-item > a {height: " . 2*$height/3 . "px; line-height: " . 2*$height/3 . "px; padding-bottom: " . $height/3 . "px;}\n";
      $css_content .= "#megamenu-" . $mid . " .mm-arrow {top: 36%}\n";
    }
    else {
      $css_content .= "#megamenu-" . $mid . " .mm-item > a {height: " . $height . "px; line-height: " . $height . "px}\n";
    }
  }

  # Generate style config for link
  $css_content .= generate_top_link_style($mid, $menu_settings);
  $css_content .= generate_sub_link_style($mid, $menu_settings);

  # Generate style for header
  $css_content .= generate_header_style($mid, $menu_settings['text_typography']);

  # Css for vertical menu
  if ($menu_settings['general']['dmg_orientation'] == 'vertical' &&  $menu_settings['general']['dmg_submenuw'] != '') {
    $css_content .= "#megamenu-" . $mid . ".md-vertical ul.megamenu {width: " . $menu_settings['general']['dmg_submenuw'] . "px}\n";
    if ($menu_settings['design']['top_dms_bgc'] != "") {
      $css_content .= "#megamenu-" . $mid . ".md-vertical ul.megamenu > li {background-color: #" . $menu_settings['design']['top_dms_bgc'] . "}";
    }
  }

  # Generate css for fix menu
  $width = 0;
  if ($menu_settings['general']['dmg_fixed']) {
    if (!$menu_settings['general']['dmg_fullwidth'] && $menu_settings['general']['dmg_customwidth'] != '') {
      $width = (int)$menu_settings['general']['dmg_customwidth'];
      $css_content .= "#megamenu-" . $mid . ".mm-fixed-top,\n";
      $css_content .= "#megamenu-" . $mid . ".mm-fixed-bottom {\n";
      $css_content .= "width: " . $width . "px;\n";
      $css_content .= "margin-left: -" . (int)$width/2 . "px;\n";
      $css_content .= "}\n";
    }

    if ($height != 0 || $width != 0) {
      $css_content .= "#megamenu-" . $mid . " .mm-toggle {\n";
      $css_content .= ($height != 0) ? "height: " . $height . "px;\n" : "";
      $css_content .= ($width != 0) ? "margin: 0 auto 0 " . (int)(30 + $width/2) . "px;\n" : "";
      $css_content .= ($width != 0) ? "left: 50%; right: auto;\n" : "";
      $css_content .= "}\n";
    }
  }

  # Add custom css
  $css_content .= $menu_settings['design']['dms_custom'];

  # Create file custom css for menu
  $public_folder = variable_get('file_public_path', conf_path() . '/files');
  file_put_contents($public_folder . '/megamenu-' . $mid . '-custom.css', $css_content);

  # Could not create file when run on IIS
  #file_save_data($css_content, 'public://megamenu-' . $mid . '-custom.css', FILE_EXISTS_REPLACE);
}

function generate_css_by_level($level, $settings) {
  $output = "";

  if ($settings[$level . '_dms_bgc'] != '') {
    $output = "background-color: #" . $settings[$level . '_dms_bgc'] . ";\n";
  }

  if ($level == 'hoveritem' && $settings['hoveritem_dms_tc'] != '') {
    $output .= "color: #" . $settings['hoveritem_dms_tc'] . ";\n";
  }

  if ($settings[$level . '_border_radius_equal']) {
    if ($settings[$level . '_border_radius'] != '') {
      $output .= "-webkit-border-radius: " . $settings[$level . '_border_radius'] . "px;\n";
      $output .= "border-radius: " . $settings[$level . '_border_radius'] . "px;\n";
    }
  }
  else {
    if ($settings[$level . '_border_radius_tl'] != '' || $settings[$level . '_border_radius_tr'] != '' || $settings[$level . '_border_radius_br'] || $settings[$level . '_border_radius_bl'] != '') {
      $data = "";
      ($settings[$level . '_border_radius_tl'] != '') ? $data .= $settings[$level . '_border_radius_tl'] . "px " : "0px ";
      ($settings[$level . '_border_radius_tr'] != '') ? $data .= $settings[$level . '_border_radius_tr'] . "px " : "0px ";
      ($settings[$level . '_border_radius_br'] != '') ? $data .= $settings[$level . '_border_radius_br'] . "px " : "0px ";
      ($settings[$level . '_border_radius_bl'] != '') ? $data .= $settings[$level . '_border_radius_bl'] . "px " : "0px ";

      $output .= "-webkit-border-radius: " . $data . ";\n";
      $output .= "border-radius: " . $data . ";\n";
    }
  }

  if (!empty($settings[$level . '_border_where']) && $settings[$level . '_border_size'] != '' && $settings[$level . '_border_type'] != '0') {
    foreach ($settings[$level . '_border_where'] as $border) {
      if ($border === 0) {
        continue;
      }
      $data = "border-" . $border . ": " . $settings[$level . '_border_size'] . "px " . $settings[$level . '_border_type'] . " ";
      $data .= ($settings[$level . '_border_color'] != '') ? "#" . $settings[$level . '_border_color'] : "#FFF";
      $data .= ";\n";
      $output .= $data;
    }
  }

  return $output;
}

function generate_top_link_style($mid, $menu_settings) {
  $fonts = $menu_settings['text_typography'];
  $design = $menu_settings['design'];
  $output = "";
  $font_top = "";

  if ($fonts['typo_top_level'] != '') {
    $font_top = explode("|", $fonts['typo_top_level']);
    if (end($font_top) != '') {
      $output .= "#megamenu-" . $mid . " .mm-item > a {" . end($font_top) . "}\n";
    }
  }

  $response = generate_link_style('top', 'regular', $fonts, $design);
  if ($response != '') {
    $output .= "#megamenu-" . $mid . " .mm-item > a,\n";
    $output .= "#megamenu-" . $mid . " .mm-item > a:link {\n";
    $output .= $response . "}\n";
  }

  $response = generate_link_style('top', 'rollover', $fonts);
  if ($response != '') {
    $output .= "#megamenu-" . $mid . " .mm-item > a:hover {\n" . $response . "}\n";
  }

  $response = generate_link_style('top', 'visited', $fonts);
  if ($response != '') {
    $output .= "#megamenu-" . $mid . " .mm-item > a:visited {\n" . $response . "}\n";
  }

  $response = generate_link_style('top', 'on', $fonts);
  if ($response != '') {
    $output .= "#megamenu-" . $mid . " .mm-item > a:focus,\n";
    $output .= "#megamenu-" . $mid . " .mm-item > a:active,\n";
    $output .= "#megamenu-" . $mid . " .mm-item > a.active {\n";
    $output .= $response . "}\n";
  }

  return $output;
}

function generate_sub_link_style($mid, $menu_settings) {
  $fonts = $menu_settings['text_typography'];
  $design = $menu_settings['design'];
  $output = "";

  $response = generate_link_style('sub', 'regular', $fonts, $design);
  if ($response != '') {
    $output .= "#megamenu-" . $mid . " div.mm-container a,\n";
    $output .= "#megamenu-" . $mid . " div.mm-container a:link {\n";
    $output .= $response . "}\n";
  }

  $response = generate_link_style('sub', 'rollover', $fonts);
  if ($response != '') {
    $output .= "#megamenu-" . $mid . " div.mm-container a:hover {\n" . $response . "}\n";
  }

  $response = generate_link_style('sub', 'visited', $fonts);
  if ($response != '') {
    $output .= "#megamenu-" . $mid . " div.mm-container a:visited {\n" . $response . "}\n";
  }

  $response = generate_link_style('sub', 'on', $fonts);
  if ($response != '') {
    $output .= "#megamenu-" . $mid . " div.mm-container a:focus,\n";
    $output .= "#megamenu-" . $mid . " div.mm-container a:active,\n";
    $output .= "#megamenu-" . $mid . " div.mm-container a.active {\n";
    $output .= $response . "}\n";
  }

  return $output;
}

function generate_link_style($level, $state, $font_settings, $design_settings = NULL) {
  $output = "";

  if ($font_settings['l_' . $level . '_' . $state . '_color'] != '') {
    $output .= "color: #" . $font_settings['l_' . $level . '_' . $state . '_color'] . ";\n";
  }

  if ($font_settings['l_' . $level . '_' . $state . '_st']) {
    $output .= "text-decoration: line-through;\n";
  }

  if ($font_settings['l_' . $level . '_' . $state . '_hl']) {
    $output .= "background: #";
    $output .= ($font_settings['l_' . $level . '_' . $state . '_hlc'] != '') ? $font_settings['l_' . $level . '_' . $state . '_hlc'] : "FFF";
    $output .= ";\n";
  }

  if (!empty($font_settings['l_' . $level . '_' . $state . '_ts'])) {
    $output .= (in_array('bold', $font_settings['l_' . $level . '_' . $state . '_ts'])) ? "font-weight: bold;\n" : "";
    $output .= (in_array('italic', $font_settings['l_' . $level . '_' . $state . '_ts'])) ? "font-style: italic;\n" : "";
    $output .= (in_array('underline', $font_settings['l_' . $level . '_' . $state . '_ts'])) ? "text-decoration:underline;\n" : "";
  }

  if ($state == "regular" && in_array('top', $design_settings['sub_border_where'])
      && $design_settings['sub_border_size'] != '' && $design_settings['sub_border_type'] != '0'
  ) {
    $output .= "padding-bottom: " . $design_settings['sub_border_size'] . "px;\n";
  }

  return $output;
}

function generate_header_style($mid, $settings) {
  $i = 1;
  $output = "";

  while ($i <= 6) {
    $data_item = "";
    if ($settings['h' . $i . '_sub_level'] != '') {
      $font = explode('|', $settings['h' . $i . '_sub_level']);
      if (end($font) != '') {
        $data_item .= end($font) . "\n";
      }
    }

    if ($settings['h' . $i . '_sub_level_color'] != '') {
      $data_item .= "color: #" . $settings['h' . $i . '_sub_level_color'] . ";\n";
    }

    if ($data_item != "") {
      $output .= "#megamenu-" . $mid . ".mdmegamenu h" . $i . " {\n";
      $output .= $data_item . "}\n";
    }

    $i++;
  }

  $sub_header = "";
  if ($settings['header_sub_level'] != '') {
    $font = explode('|', $settings['header_sub_level']);
    $sub_header .= (end($font) != '') ? end($font) . "\n" : '';
  }

  if ($settings['header_sub_level_color'] != '') {
    $sub_header .= "color: #" . $settings['header_sub_level_color'] . ";\n";
  }

  if ($sub_header != "") {
    $output .= "#megamenu-" . $mid . " .mm-sub h3.mm-header {\n" . $sub_header . "}\n";
  }

  return $output;

}

function render_row_style($style) {
  $output = '';
  if ($style != NULL) {
    if ($style->elsbackground != '') {
      $output .= 'background: #' . $style->elsbackground . ';';
    }

    if ($style->elsborderw != '') {
      $output .= ' border: ' . $style->elsborderw . 'px ' . $style->elsborders;
      $output .= ($style->elsborderc != '') ? '#' . $style->elsborderc . ';' : '#FFF;';
    }
  }

  if ($output != '') {
    $output = ' style="' . $output . '"';
  }

  return $output;
}

function render_col_style($col_style, $row_style) {
  $div_col = array('margin' => '', 'bg' => '');
  $div_inner = '';

  if ($col_style != NULL) {
    if ($col_style->elsmargin) {
      $div_col['margin'] = 'withmargin';
    }

    if ($col_style->elsbackground != '') {
      $div_col['bg'] = 'style="background: #' . $col_style->elsbackground . '"';
    }

    if ($col_style->elsborderw != '') {
      $div_inner .= 'style="border: ' . $col_style->elsborderw . 'px ' . $col_style->elsborders;
      $div_inner .= ($col_style->elsborderc != '') ? ' #' . $col_style->elsborderc . ';"' : ' #FFF;"';
    }
  }
  else {
    if ($row_style != NULL && $row_style->elsmargin) {
      $div_col['margin'] = 'withmargin';
    }
  }

  return array($div_col, $div_inner);
}

function sort_modules(&$modules) {
  $sorted = array();

  if (array_key_exists('block', $modules)) {
    $sorted['block'] = $modules['block'];
    unset($modules['block']);
  }

  if (array_key_exists('views', $modules)) {
    $sorted['views'] = $modules['views'];
    unset($modules['views']);
  }

  if (array_key_exists('webform', $modules)) {
    $sorted['webform'] = $modules['webform'];
    unset($modules['webform']);
  }

  if (array_key_exists('forum', $modules)) {
    $sorted['forum'] = $modules['forum'];
    unset($modules['forum']);
  }

  if (array_key_exists('quicktabs', $modules)) {
    $sorted['quicktabs'] = $modules['quicktabs'];
    unset($modules['quicktabs']);
  }

  if (array_key_exists('user', $modules)) {
    $sorted['user'] = $modules['user'];
    unset($modules['user']);
  }

  # sort all others module
  ksort($modules);

  $modules = $sorted + $modules;
}

function is_active_link($path, $current) {
  $is_active = FALSE;
  switch ($path) {
    case '#':
      break;

    case '':
      break;

    case '<front>':
      if (drupal_is_front_page()) {
        $is_active = TRUE;
      }
      break;

    default:
      $current = url($current, array('absolute' => TRUE));
      $path = url($path, array('absolute' => TRUE));
      if ($path == $current || strpos($current, $path)!== FALSE) {
        $is_active = TRUE;
      }
  }

  return $is_active;
}

/**
 * Recast object to another class
 */
function _megamenu_recast($className, stdClass &$object) {
  if (!class_exists($className))
    throw new InvalidArgumentException(sprintf('Inexistant class %s.', $className));

  $new = new $className();

  foreach($object as $property => &$value)
  {
    $new->$property = &$value;
    unset($object->$property);
  }
  unset($value);
  $object = (unset) $object;

  return $new;
}
