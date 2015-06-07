<?php
/**
 * @file
 * feature_paragraphs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_paragraphs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function feature_paragraphs_paragraphs_info() {
  $items = array(
    'paragraph_classic' => array(
      'name' => 'Classic',
      'bundle' => 'paragraph_classic',
      'locked' => '1',
    ),
    'paragraph_fullpage' => array(
      'name' => 'Full Page',
      'bundle' => 'paragraph_fullpage',
      'locked' => '1',
    ),
    'paragraph_fullpage_slide' => array(
      'name' => 'Full Page Slide',
      'bundle' => 'paragraph_fullpage_slide',
      'locked' => '1',
    ),
  );
  return $items;
}
