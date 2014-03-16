<?php
/**
 * @file
 * Define all class for megamenu
 *
 *  @author Duy Nguyen
 */

class MDMegaMenu {
  public $mid;
  public $title;
  public $description;
  public $machine_name;
  public $settings;

  public function initialize() {
    if (is_string($this->settings)) {
      $this->settings = unserialize($this->settings);
      foreach ($this->settings as $cate => &$setting) {
        if (is_array($setting)) {
          $setting = array_merge(MDMegaMenu::getDefaultSettings($cate), $setting);
        }
      }
    };
  }

  public function dbFields() {
    return array('title', 'description', 'machine_name', 'settings');
  }

  public static function create($title, $description, $machine_name = NULL, $settings = NULL) {
    $default_settings = MDMegaMenu::getDefaultSettings();
    if ($settings) {
      $settings = array_merge($default_settings, $settings);
    }
    else {
      $settings = $default_settings;
    }

    # Create new MDMegaMenu object
    $mgMenu = new MDMegaMenu();
    $mgMenu->title = $title;
    $mgMenu->description = $description;
    $mgMenu->machine_name = $machine_name ? $machine_name : uniqid('mgm-');
    $mgMenu->settings = $settings ? $settings : array();

    # Save menu to database
    $mgMenu->save();

    return $mgMenu;
  }

  /**
   * Save menu to md_megamenus table
   * @return boolean
   */
  public function save() {
    $fields = array();

    foreach ($this->dbFields() as $field_name) {
      $fields[$field_name] = $this->{$field_name};
    }

    if (!is_string($fields['settings'])) {
      $fields['settings'] = serialize($fields['settings']);
    }

    # check update or create new
    if (!$this->mid) {
      $mid = db_insert('md_megamenus')
      ->fields($fields)
      ->execute();

      if (!$mid) {
        return FALSE;
      }
      $this->mid = $mid;
    }
    else {
      # update for menu
      db_update('{md_megamenus}')
      ->condition('mid', $this->mid)
      ->fields($fields)
      ->execute();
    }

    # Generate css custom for menu
    generate_menu_css_configure($this->mid, $this->settings);

    return TRUE;
  }

  /**
   * Get menu by id
   * @param int $mid - id of menu
   * @return MDMegaMenu object
   */
  public static function getById($mid) {
    $results = db_select('{md_megamenus}', 'mmn')
    ->fields('mmn')
    ->condition('mid', $mid, '=')
    ->execute()
    ->fetchAll(PDO::FETCH_CLASS, 'MDMegaMenu');

    # Check list results
    if (!count($results)) {
      return NULL;
    }

    # Run initialize object function
    foreach ($results as &$menu) {
      if ($menu instanceof stdClass)
        $menu = _megamenu_recast('MDMegaMenu', $menu);

      $menu->initialize();
    }

    return array_shift($results);
  }

  public static function get_by_ids($mids) {
    $results = db_select('{md_megamenus}', 'mmn')
      ->fields('mmn')
      ->condition('mid', $mids, 'IN')
      ->execute()
      ->fetchAll(PDO::FETCH_CLASS, 'MDMegaMenu');

    # Check list results
    if (!count($results)) {
      return NULL;
    }

    # Run initialize object function
    foreach ($results as &$menu) {
      if ($menu instanceof stdClass)
        $menu = _megamenu_recast('MDMegaMenu', $menu);
      $menu->initialize();
    }

    return $results;
  }

  /**
   * Get all menu in md_megamenus table
   * @return array MDMegaMenu objects
   */
  public static function getAll() {
    $results = db_select('{md_megamenus}', 'mmn')
    ->fields('mmn')
    ->execute()
    ->fetchAll(PDO::FETCH_CLASS, 'MDMegaMenu');

    if (!count($results)) {
      return array();
    }

    # Run object initialize
    foreach ($results as &$menu) {
      if ($menu instanceof stdClass)
        $menu = _megamenu_recast('MDMegaMenu', $menu);

      $menu->initialize();
    }

    # Return list menus
    return $results;
  }

  public static function delete($mid) {
    # delete all tabs of menu
    MDMegaTab::detele_menu_tabs($mid);

    # delete menu in md_megamenus table
    db_delete('{md_megamenus}')
    ->condition('mid', $mid)
    ->execute();
  }

  public static function getDefaultSettings($key = NULL) {
    static $default_settings = array(
        'general' => array(
            'dmg_orientation' => 'horizontal',
            'dmg_submenuw' => '',
            'dmg_verdir' => 'ltr',
            'dmg_fullwidth' => 1,
            'dmg_customwidth' => '',
            'dmg_defaultheight' => 0,
            'dmg_customheight' => '',
            'dmg_fixed' => 0,
            'dmg_showfixed' => 0,
            'dmg_position' => 'center_bottom',
            'dm_right' => array('dmg_responsive', 'dmg_pushing', 'dmg_clickoutside', ),
        ),
        'animation' => array(
            'dma_animation' => 'slide',
            'dma_trigger' => 'hover_intent',
            'dma_easing' => 0,
            'dma_show' => '',
            'dma_hide' => '',
            'dma_delay' => '',
        ),
        'design' => array(
            'dms_predefine' => 'style1',
            'dms_custom' => '',
            'top_dms_descc' => '',
            'top_dms_bgc' => '',
            'top_border_radius_equal' => 1,
            'top_border_radius' => '',
            'top_border_radius_tl' => '',
            'top_border_radius_tr' => '',
            'top_border_radius_br' => '',
            'top_border_radius_bl' => '',
            'top_border_where' => array(),
            'top_border_size' => '',
            'top_border_type' => 0,
            'top_border_color' => '',
            'top_dmi_img' => '',
            'sub_dms_bgc' => '',
            'sub_dms_dropshadow' => 0,
            'sub_border_radius_equal' => 1,
            'sub_border_radius' => '',
            'sub_border_radius_tl' => '',
            'sub_border_radius_tr' => '',
            'sub_border_radius_br' => '',
            'sub_border_radius_bl' => '',
            'sub_border_where' => array(),
            'sub_border_size' => '',
            'sub_border_type' => 0,
            'sub_border_color' => '',
            'sub_dmi_img' => '',
            'hoveritem_dms_tc' => '',
            'hoveritem_dms_bgc' => '',
            'hoveritem_border_radius_equal' => 1,
            'hoveritem_border_radius' => '',
            'hoveritem_border_radius_tl' => '',
            'hoveritem_border_radius_tr' => '',
            'hoveritem_border_radius_br' => '',
            'hoveritem_border_radius_bl' => '',
            'hoveritem_border_where' => array(),
            'hoveritem_border_size' => '',
            'hoveritem_border_type' => 0,
            'hoveritem_border_color' => '',
        ),
        'text_typography' => array(
            'dmf_ucf' => 0,
            'dmf_google' => '',
            'dmf_typekit' => '',
            'typo_top_level' => '',
            'l_top_regular_color' => '',
            'l_top_regular_st' => 0,
            'l_top_regular_hl' => 0,
            'l_top_regular_hlc' => '',
            'l_top_regular_ts' => array(),
            'l_top_rollover_color' => '',
            'l_top_rollover_st' => 0,
            'l_top_rollover_hl' => 0,
            'l_top_rollover_hlc' => '',
            'l_top_rollover_ts' => array(),
            'l_top_visited_color' => '',
            'l_top_visited_st' => 0,
            'l_top_visited_hl' => 0,
            'l_top_visited_hlc' => '',
            'l_top_visited_ts' => array(),
            'l_top_on_color' => '',
            'l_top_on_st' => 0,
            'l_top_on_hl' => 0,
            'l_top_on_hlc' => '',
            'l_top_on_ts' => array(),
            'l_sub_regular_color' => '',
            'l_sub_regular_st' => 0,
            'l_sub_regular_hl' => 0,
            'l_sub_regular_hlc' => '',
            'l_sub_regular_ts' => array(),
            'l_sub_rollover_color' => '',
            'l_sub_rollover_st' => 0,
            'l_sub_rollover_hl' => 0,
            'l_sub_rollover_hlc' => '',
            'l_sub_rollover_ts' => array(),
            'l_sub_visited_color' => '',
            'l_sub_visited_st' => 0,
            'l_sub_visited_hl' => 0,
            'l_sub_visited_hlc' => '',
            'l_sub_visited_ts' => array(),
            'l_sub_on_color' => '',
            'l_sub_on_st' => 0,
            'l_sub_on_hl' => 0,
            'l_sub_on_hlc' => '',
            'l_sub_on_ts' => array(),
            'text_sub_level' => '',
            'text_sub_level_color' => '',
            'header_sub_level' => '',
            'header_sub_level_color' => '',
            'h1_sub_level_color' => '',
            'h1_sub_level' => '',
            'h2_sub_level' => '',
            'h2_sub_level_color' => '',
            'h3_sub_level' => '',
            'h3_sub_level_color' => '',
            'h4_sub_level' => '',
            'h4_sub_level_color' => '',
            'h5_sub_level' => '',
            'h5_sub_level_color' => '',
            'h6_sub_level' => '',
            'h6_sub_level_color' => '',
        ),
        'savedcolor' => '',
    );

    if ($key) {
      return $default_settings[$key];
    }

    return $default_settings;
  }
}

class MDMegaTab {
  public $tid;
  public $mid;
  public $position;
  public $settings;
  public $items;

  public function initialize() {
    if (is_string($this->settings)) {
      $this->settings = unserialize($this->settings);
    };

    if (is_string($this->items)) {
      $this->items = unserialize($this->items);
    }
  }

  public function dbFields() {
    return array('mid', 'position', 'settings', 'items');
  }

  public static function create($mid, $position, $items, $settings = NULL) {
    $default_settings = MDMegaTab::getDefaultSettings();
    if ($settings != NULL) {
      $settings = array_merge($default_settings, $settings);
    }
    else {
      $settings = $default_settings;
    }

    #Create new tab
    $tab = new MDMegaTab();

    $tab->mid = $mid;
    $tab->position = $position;
    $tab->settings = $settings;
    $tab->items = $items;

    if (!$tab->save()) {
      return NULL;
    }

    return $tab;
  }

  /**
   * save tab
   * @return TRUE|FALSE
   */
  public function save() {
    $fields = array();

    foreach ($this->dbFields() as $fieldName) {
      $fields[$fieldName] = $this->{$fieldName};
    }

    if (!is_string($fields['settings'])) {
      $fields['settings'] = serialize($fields['settings']);
    }

    if (!is_string($fields['items'])) {
      $fields['items'] = serialize($fields['items']);
    }

    if ($this->tid) {
      #update existed tab
      return db_update('{md_megamenu_tabs}')
      ->condition('tid', $this->tid)
      ->fields($fields)
      ->execute();
    }
    else {
      #insert new tab in table
      $tid = db_insert('md_megamenu_tabs')
      ->fields($fields)
      ->execute();

      if ($tid) {
        $this->tid = $tid;
      }
      else {
        return FALSE;
      }
    }

    return TRUE;
  }

  /**
   * get list tab of menu
   * @param int $menu_id
   * @return array $results: array MDMegaTab objects
   */
  public static function getTabsByMenu($menu_id) {
    $results = array();

    $results = db_select('{md_megamenu_tabs}', 'mgmt')
    ->fields('mgmt')
    ->condition('mid', $menu_id, '=')
    ->orderBy('position')
    ->execute()
    ->fetchAll(PDO::FETCH_CLASS, 'MDMegaTab');

    if ($results) {
      foreach ($results as &$tab) {
        if ($tab instanceof stdClass)
          $tab = _megamenu_recast('MDMegaTab', $tab);
        $tab->initialize();
      }
    }

    return $results;
  }

  /**
   * get list tab of menu
   * @param int $menu_id
   * @return array $results: array MDMegaTab objects
   */
  public static function get_tabs_by_menus($mids) {
    $results = array();

    $results = db_select('{md_megamenu_tabs}', 'mgmt')
      ->fields('mgmt')
      ->condition('mid', $mids, 'IN')
      ->orderBy('position')
      ->execute()
      ->fetchAll(PDO::FETCH_CLASS, 'MDMegaTab');

    if ($results) {
      foreach ($results as &$tab) {
        if ($tab instanceof stdClass)
          $tab = _megamenu_recast('MDMegaTab', $tab);
        $tab->initialize();
      }
    }

    return $results;
  }

  /**
   * get tab by tab_id
   * @param int $tab_id
   * @return MDMegaTab object
   */
  public static function getTabById($tab_id) {
    $result = db_select('{md_megamenu_tabs}', 'mgmt')
    ->fields('mgmt')
    ->condition('tid', $tab_id)
    ->execute()
    ->fetchAll(PDO::FETCH_CLASS, 'MDMegaTab');

    if (!count($result)) {
      return NULL;
    }

    foreach ($result as &$tab) {
      if ($tab instanceof stdClass)
        $tab = _megamenu_recast('MDMegaTab', $tab);

      $tab->initialize();
    }

    return array_shift($result);
  }

  public static function delete($tab_id) {
    return db_delete('{md_megamenu_tabs}')
    ->condition('tid', $tab_id)
    ->execute();
  }

  public static function detele_menu_tabs($mid) {
    db_delete('{md_megamenu_tabs}')
    ->condition('mid', $mid)
    ->execute();
  }

  public static function getDefaultSettings($key = NULL) {
    static $default_settings = array(
        'general' => array(
            'is_dropdown_menu' => FALSE,
            'title_enable' => TRUE,
            'title' => 'Home',
            'path' => '',
            'description' => '',
            'icon' => '',
            'css_class' => '',
        ),
        'layout' => array(
            'col_grid' => 12,
            'rows_setting' => array(
                '0' => array('style' => NULL, 'cols' => array(48)),
                '1' => array('style' => NULL, 'cols' => array(24, 24)),
            ),
            'is_full_width' => TRUE,
            'submenu_width' => '',
        ),
    );

    if ($key) {
      return $default_settings[$key];
    }

    return $default_settings;
  }
}
