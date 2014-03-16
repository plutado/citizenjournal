<?php
/**
 * @file
 * blog_feature.features.inc
 */

/**
 * Implements hook_node_info().
 */
function blog_feature_node_info() {
  $items = array(
    'blog_entry' => array(
      'name' => t('Blog entry'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
