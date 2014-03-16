<?php
/**
 * @file theme.inc
 * Contain process for themes
 */

/**
 * Implements preprocess for theme_manage_links_memu
 * @param array $vars
 */
function template_preprocess_menu_admin_form(&$variables) {
  $url_parts = explode('/', $_GET['q']);
  $variables['menu'] = MDMegaMenu::getById($url_parts[array_search('md-megamenu', $url_parts) + 1]);
  $tabs= MDMegaTab::getTabsByMenu($variables['menu']->mid);

  $blocks_added = array();
  foreach ($tabs as $tab) {
    foreach ($tab->settings['layout']['rows_setting'] as &$row_settings) {
      if (is_array($row_settings)) {
        $row_settings = (object)$row_settings;
        foreach ($row_settings->cols as &$column) {
          if (is_array($column))
            $column = (object)$column;
        }
      }
    }

    if ($tab->settings['general']['is_dropdown_menu']) {
      _subitem_to_object($tab->items);
      continue;
    }


    foreach ($tab->items as &$row) {
      foreach ($row as &$col) {
        if (!count($col)) continue;

        foreach ($col as &$item) {
          $item = (object)$item;
          if ($item->type == 'block')
            $blocks_added[] = $item->block_id;
        }
      }
    }
  }

  $variables['menu_tabs']  = $tabs;

  $theme_default = variable_get('theme_default', 'bartik');
  $blocks = _block_rehash($theme_default);
  $block_by_module = array();
  foreach ($blocks as $block) {
    $block = (object) $block;

    # Not add blocks is created by this module
    if ($block->module != 'md_megamenu' && !isset($block_by_module[$block->module])) {
      $block_by_module[$block->module] = array();
    }
    if ($block->module != 'md_megamenu' && !in_array($block->delta, $blocks_added)) {
      $block_by_module[$block->module][] = $block;
    }
  }

  sort_modules($block_by_module);
  $variables['module_blocks_list'] = $block_by_module;
}

/**
 * Implements preprocess for theme_megamenu_item_admin
 * @param array $vars
 */
function template_preprocess_megamenu_item_admin(&$variables) {
  prepare_subitem_icon($variables['icon_style'], $variables['item']);
}

/**
 * Change array to object sub-item
 */
function _subitem_to_object(&$subitems) {
  if (count($subitems)) {
    foreach ($subitems as &$item) {
      $item = (object)$item;
      $item->setting = (object)$item->setting;
      _subitem_to_object($item->subItems);
    }
  }
}
