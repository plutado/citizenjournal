<?php
/**
 * @file
 * webisode.features.inc
 */

/**
 * Implements hook_views_api().
 */
function webisode_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function webisode_node_info() {
  $items = array(
    'episode' => array(
      'name' => t('episode'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
