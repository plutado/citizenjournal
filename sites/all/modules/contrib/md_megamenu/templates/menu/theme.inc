<?php
/**
 * @file theme.inc
 * Contain process for themes
 */

/**
 * Implements preprocess for theme_menu()
 * @param array $vars
 */
function template_preprocess_megamenu_theme(&$variables) {
  $menu_settings = $variables['menu_settings'];
  $menu_tabs = $variables['menu_tabs'];

  $classes[] = 'mdmegamenu';
  $classes[] =  'md-' . $menu_settings['general']['dmg_orientation'];
  if ($menu_settings['general']['dmg_verdir'] == 'rtl')
    $classes[] = 'md-vertical-rtl';
  $classes[] = ' md-' . $menu_settings['design']['dms_predefine'];
  if ($menu_settings['design']['sub_dms_dropshadow'] != 0) {
    $classes[] = 'md-dropshadow';
  }

  $toogle_out = '';
  if ($menu_settings['general']['dmg_fixed']) {
    $toogle = 'mm-toggle';
    if ($menu_settings['general']['dmg_position'] == 'center_bottom') {
      $classes[] = 'mm-fixed-bottom';
    }
    elseif ($menu_settings['general']['dmg_position'] == 'center_top') {
      $classes[] = 'mm-fixed-top';
    }

    if ($menu_settings['general']['dmg_showfixed']) {
      $toogle_out = '<a href="#" class="' . $toogle . '"></a>';
    }
  }

  if (in_array('dmg_desc', $menu_settings['general']['dm_right'])) {
    $classes[] = 'md-withdesc';
  }

  $variables['show_button'] = $toogle_out;
  $variables['menu_classes'] = implode(" ", $classes);
  $variables['is_vertical'] = ($menu_settings['design']['dms_predefine'] == "vertical")? 'true' : 'false';

  if (count($menu_tabs) > 1) {
    $first = key($menu_tabs);
    end($menu_tabs);
    $last = key($menu_tabs);
    reset($menu_tabs);
    $item_index = 1;
    foreach ($menu_tabs as $key => &$tab) {
      $tab->icon_style = $menu_settings['design']['top_dmi_img'];
      $tab->item_icon_style = $menu_settings['design']['sub_dmi_img'];
      $tab->classes[] = 'mm-item';

      if ($tab->settings['general']['is_dropdown_menu']) {
        if (!empty($tab->items)) {
          $tab->classes[] = 'mm-dropdown';
          $tab->classes[] = 'mm-parent';
        }
      }
      else {
        $tab->classes[] = 'mm-parent';
      }

      # Add custom css class
      if ($tab->settings['general']['css_class']) {
        $tab->classes[] = $tab->settings['general']['css_class'];
      }

      switch ($key) {
        case $first:
          $tab->classes[] = 'first';
          $tab->classes[] = 'mm-item-1';
          break;

        case $last:
          $tab->classes[] = 'last';
          $tab->classes[] = 'mm-item-' . $item_index;
          break;

        default:
          $tab->classes[] = 'mm-item-' . $item_index;
          break;
      }

      # Render tab description
      render_tab_description($tab, $menu_settings['general']['dm_right'], $menu_settings['design']['top_dms_descc']);

      $item_index++;
    }
  }
  else {
    $menu_tabs[0]->icon_style = $menu_settings['design']['top_dmi_img'];
    $menu_tabs[0]->item_icon_style = $menu_settings['design']['sub_dmi_img'];
    $menu_tabs[0]->classes[] = 'first';
    $menu_tabs[0]->classes[] = 'last';
    $menu_tabs[0]->classes[] = 'mm-item';
    if ($menu_tabs[0]->settings['general']['is_dropdown_menu']) {
      if (!empty($menu_tabs[0]->items)) {
        $menu_tabs[0]->classes[] = 'mm-dropdown';
        $menu_tabs[0]->classes[] = 'mm-parent';
      }
    }
    else {
      $menu_tabs[0]->classes[] = 'mm-parent';
    }
    $menu_tabs[0]->classes[] = 'mm-item-1';

    # Add custom css class
    if ($menu_tabs[0]->settings['general']['css_class']) {
      $menu_tabs[0]->classes[] = $menu_tabs[0]->settings['general']['css_class'];
    }

    # Render tab description
    render_tab_description($menu_tabs[0], $menu_settings['general']['dm_right'], $menu_settings['design']['top_dms_descc']);
  }
  $variables['menu_tabs'] = $menu_tabs;

  $menu_animation = $menu_settings['animation'];

  $effect = array();
  $effect['effectTypeOpen'] = $menu_animation['dma_animation'];
  $effect['effectTypeClose'] = $menu_animation['dma_animation'];

  if ($menu_animation['dma_easing'] != '0') {
    $effect['effectOpen'] = $menu_animation['dma_easing'];
    $effect['effectClose'] = $menu_animation['dma_easing'];
  }

  if ($menu_animation['dma_delay'] != "") {
    $effect['effectSpeedClose'] = $menu_animation['dma_delay'];
    $effect['effectSpeedOpen'] = $menu_animation['dma_delay'];
  }

  $option['effects'] = $effect;

  if ($menu_animation['dma_show'] != "") {
    $option['timeBeforeOpening'] = $menu_animation['dma_show'];
  }

  if ($menu_animation['dma_hide'] != "") {
    $option['timeBeforeClosing'] = $menu_animation['dma_hide'];
  }

  $option['trigger'] = $menu_animation['dma_trigger'];

  if ($menu_settings['general']['dmg_orientation'] == 'vertical') {
    $option['vertical'] = TRUE;
  }

  if (in_array('dmg_arrow', $menu_settings['general']['dm_right'])) {
    $option['arrow'] = TRUE;
  }

  if (in_array('dmg_responsive', $menu_settings['general']['dm_right'])) {
    drupal_add_js(drupal_get_path('module', 'md_megamenu') . '/menu_styles/js/selectnav.min.js');
  }

  drupal_add_js(array('mmoptions_' . $variables['mid'] => $option), 'setting');

  load_text_typography_configure($menu_settings['text_typography']);
}

/**
 * Implements preprocess for theme_tab()
 * @param array $vars
 */
function template_preprocess_megamenu_tab_theme(&$variables) {
  $tab = $variables['tab'];

  $variables['row_extends'] = '';
  $classes = array();
  $classes[] = 'mm-container';
  if (!$tab->settings['layout']['is_full_width'] && $tab->settings['layout']['submenu_width'] != '') {
    $classes[] = 'mm-customwidth';
    $variables['row_extends'] = ' style="width: ' . $tab->settings['layout']['submenu_width'] . 'px;"';
    $variables['row_extends'] .= ' data-width="' . $tab->settings['layout']['submenu_width'] .'"';
  }
  else {
    $classes[] = 'mm-fullwidth';
  }
  $classes[] = 'mmcontainer_' . $tab->settings['layout']['col_grid'];
  $variables['row_classes'] = implode(' ', $classes);

  $rows = $tab->settings['layout']['rows_setting'];
  foreach ($rows as $row_id => $row) {
    foreach ($row->cols as $col_id => &$col) {
      $classes = array();
      $classes[] = 'mmg_' . $col->length*$tab->settings['layout']['col_grid']/48;
      $col_style = render_col_style($col->style, $row->style);
      if ($col_style[0]['margin'] != '') {
        $classes[] = $col_style[0]['margin'];
      }
      if ($col_style[0]['bg'] != '') {
        $classes[] = 'background-color';
      }
      $col->classes = implode(' ', $classes);
      $col->items['items'] = $tab->items[$row_id][$col_id];
      $col->items['icon_style'] = $tab->item_icon_style;
      $col->div_col = $col_style[0]['bg'];
      $col->inner = $col_style[1];
    }

    $row->style = render_row_style($row->style);
  }
  $variables['rows'] = $rows;
  $variables['items'] = $tab->items;
  $variables['title'] = ($tab->settings['general']['title_enable']) ? $tab->settings['general']['title'] : '';
  $variables['path'] = ($tab->settings['general']['path'] != '') ? $tab->settings['general']['path'] : '#';

  if (is_active_link($variables['path'], $_GET['q'])) {
    $tab->classes[] = 'mm-active';
  }
  $variables['tab_classes'] = implode(' ', $tab->classes);
}

function theme_megamenu_col_content(&$variables) {
  $items = $variables['items']['items'];
  $icon_style = $variables['items']['icon_style'];

  $output = '';
  foreach ($items as $item) {
    $item_out = '';
    if (isset($item->class)) {
      $item->class = urldecode($item->class);
    }

    switch ($item->type) {
      case 'header':
        if ($item->h_icon != '') {
          $icon_id = get_icon_id($item->h_icon);
          $icon = file_load($icon_id);
          if ($icon_style != '') {
            $item->h_icon = image_style_url($icon_style, $icon->uri);
          }
          else {
            $item->h_icon = file_create_url($icon->uri);
          }
        }

        $item->title = urldecode($item->title);
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'header', 'item' => $item));
        break;

      case 'img':
        if ($item->img_path != '') {
          $img_id = get_icon_id($item->img_path);
          $img = file_load($img_id);
          if ($item->img_style != '') {
            $item->img_path = image_style_url($item->img_style, $img->uri);
          }
          else {
            $item->img_path = file_create_url($img->uri);
          }

          if ($item->class != '') {
            $item->class = explode(' ', $item->class);
          }
          else {
            $item->class = array();
          };

          $item->img_alt = urldecode($item->img_alt);
          $item_out = theme('megamenu_essential_item_theme', array('type' => 'img', 'item' => $item));
        }
        break;

      case 'a':
        if ($item->a_icon != '') {
          $icon_id = get_icon_id($item->a_icon);
          $icon = file_load($icon_id);
          if ($icon_style != '') {
            $item->a_icon = image_style_url($icon_style, $icon->uri);
          }
          else {
            $item->a_icon = file_create_url($icon->uri);
          }
        }

        $attributes = array();
        if ($item->a_target != 'none') {
          $attributes['target'] = array($item->a_target);
        }

        if ($item->class != '') {
          $attributes['class'] = explode(' ', $item->class);
        }
        $item->attributes = $attributes;

        $item->a_path = urldecode($item->a_path);
        $item->a_title = urldecode($item->a_title);
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'a', 'item' => $item));
        break;

      case 'video':
        $item->video_link = urldecode($item->video_link);
        $iframe_par = "";
        if ($yt_id = md_megamenu_get_youtube_id_from_url($item->video_link)) {
          $item->video_link = "http://www.youtube.com/embed/{$yt_id}";
          $iframe_par = ' frameborder="0" allowfullscreen';
        }
        elseif ($vimeo_id = md_megamenu_get_vimeo_id_from_url($item->video_link)) {
          $item->video_link = "http://player.vimeo.com/video/{$vimeo_id}";
          $iframe_par = ' frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen';
        }
        $item->parameters = $iframe_par;

        if ($item->video_link != '') {
          $item_out = theme('megamenu_essential_item_theme', array('type' => 'video', 'item' => $item));
        }
        break;

      case 'html':
        $item->html = urldecode($item->html);
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'html', 'item' => $item));
        break;

      case 'iframe':
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'iframe', 'item' => $item));
        break;

      case 'block':
        $item_out = theme('megamenu_block_item', array('type' => 'header', 'item' => $item));
        break;

      case 'textblock':
        $item->textblock_text = urldecode($item->textblock_text);
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'textblock', 'item' => $item));
        break;

      case 'seperator':
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'seperator'));
        break;

      case 'seperatortext':
        $item->seperator_text = urldecode($item->seperator_text);
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'seperatortext', 'item' => $item));
        break;

      case 'flickr':
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'flickr', 'item' => $item));
        break;

      case 'gmap':
        $item->url = urldecode($item->gmap_link);
        if ($item->gmap_type != 'm') {
          $item->url .= '&t=' . $item->gmap_type;
        }

        if ((int)$item->gmap_zoom > 14) {
          $item->url .= '&z=' . $item->gmap_zoom;
        }
        $item->url .= '&output=embed';
        $item->url = htmlentities($item->url);
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'gmap', 'item' => $item));
        break;

      case 'twitter':
        drupal_add_js(drupal_get_path('module', 'md_megamenu') . '/menu_styles/js/jquery.tweet.min.js');
        $item_out = theme('megamenu_essential_item_theme', array('type' => 'twitter', 'item' => $item));
        break;
    }

    $output .= $item_out;
  }

  return $output;
}

/**
 * Implements preprocess for theme_block_item()
 * @param array $vars
 */
function theme_megamenu_block_item(&$variables) {
  $block = $variables['item'];
  $block_content = module_invoke($block->block_module, 'block_view', $block->block_id);

  $output = '';
  if (isset($block_content['content'])) {
    if (is_array($block_content['content'])) {
      $output = drupal_render($block_content['content']);
    }
    else {
      $output = $block_content['content'];
    }
  }

  return $output;
}

/**
 * Implements preprocess for theme_dropdown_tab()
 * @param array $vars
 */
function template_preprocess_megamenu_dropdown_tab(&$variables) {
  $tab = $variables['tab'];
  $tab_path = $tab->settings['general']['path'];
  $variables['items'] = $tab->items;

  $actived = is_active_link($tab_path, $_GET['q']);

  $children_active = FALSE;
  $variables['tab_content'] = render_dropdown_tab_frontend($tab->items, $children_active, $actived);

  if ($children_active || $actived) {
    $tab->classes[] = 'mm-active';
  }
  $variables['tab_classes'] = implode(' ', $tab->classes);
}

function render_dropdown_tab_frontend($items, &$active, $parent_actived = FALSE) {
  $html = "";

  if (count($items)) {
    $html = '<ul class="mm-container">';
    foreach ($items as $item) {
      $current_active = FALSE;
      $child_active = FALSE;
      $html_sub = '';
      $li_classes = array();
      $a_classes = array();

      $item_path = ($item->setting->a_path != '#') ? url($item->setting->a_path, array('absolute' => TRUE)) : '';
      if (!$parent_actived && is_active_link($item_path, $_GET['q'])) {
        $current_active = TRUE;
        $a_classes[] = 'active';
      }

      if (count($item->subItems)) {
        $li_classes[] = 'mm-parent';
        $html_sub = render_dropdown_tab_frontend($item->subItems, $child_active, $current_active);
      }

      if ($current_active || $child_active) {
        $active = TRUE;
        $li_classes[] = 'mm-active';
      }

      $options = array();
      if ($item_path == '') {
        $options['fragment'] = ' ';
        $options['external'] = TRUE;
      }

      if ($item->setting->class != '') {
        $a_classes += explode(',', $item->setting->class);
      }

      if (!empty($a_classes)) {
        $options['attributes']['class'] = $a_classes;
      }

      if ($item->setting->a_target != NULL && $item->setting->a_target != 'none') {
         $options['attributes']['target'] = array($item->setting->a_target);
      }

      $html .= '<li';
      $html .= (!empty($li_classes)) ? ' class="' . implode(' ', $li_classes) . '">' : '>';
      $html .= l($item->setting->a_title, $item_path, $options);
      $html .= $html_sub;
      $html .= '</li>';
    }

    $html .= '</ul>';
  }
  return $html;
}

function render_tab_description(&$tab, $general_dm_right, $desc_color) {
  $description = '';
  if (in_array('dmg_desc', $general_dm_right) && $tab->settings['general']['description'] != '') {
    $description = '<span class="mm-desc"';
    $description .= ($desc_color != '') ? ' style="color: #' . $desc_color . '">' : '>';
    $description .= $tab->settings['general']['description'] . '</span>';
  }
  $a_title = '';
  if ($tab->settings['general']['title_enable']) {
    $a_head = '<a';
    $a_title =  $tab->settings['general']['title'];
  }
  else {
    $a_head = '<a ';
  }

  $a_head .= ' href="' ;
  $a_head .= ($tab->settings['general']['path'] != '') ? url($tab->settings['general']['path'], array('absolute' => TRUE)) : '#';
  $a_head .= '">';

  $icon_html = '';
  if ($tab->settings['general']['icon'] != NULL && $tab->settings['general']['icon'] != '') {

    $icon_id = get_icon_id($tab->settings['general']['icon']);
    $icon = file_load($icon_id);
    if ($tab->icon_style != '') {
      $icon_url = image_style_url($tab->icon_style, $icon->uri);
    }
    else {
      $icon_url = file_create_url($icon->uri);
    }

    $icon_html = theme('image', array('path' => $icon_url, 'alt' => $tab->settings['general']['title']));
  }

  $output = $a_head . $icon_html . $a_title . $description . '</a>';
  $tab->content = $output;
}

function load_text_typography_configure($settings) {
  $theme_default = variable_get('theme_default', 'Bartik');

  if ($settings['dmf_ucf']) {
    $theme_fonts = theme_get_setting('googlewebfonts', $theme_default);
    # Check google font setting
    if ($settings['dmf_google'] != '' && $settings['dmf_google'] != $theme_fonts) {
      drupal_add_css($settings['dmf_google'], array('type' => 'external'));
    }

    # Check typekit setting
    $theme_typekit = theme_get_setting('typekit_id', $theme_default);
    if ($settings['dmf_typekit'] != '' && $settings['dmf_typekit'] != $theme_typekit) {
      drupal_add_js('http://use.typekit.net/' . $settings['dmf_typekit'] . '.js', 'external');
      drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
    }
  }
}
