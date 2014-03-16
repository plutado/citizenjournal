<?php
/**
 * @file
 * blog_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function blog_feature_taxonomy_default_vocabularies() {
  return array(
    'content_type' => array(
      'name' => 'Content Type',
      'machine_name' => 'content_type',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'topics' => array(
      'name' => 'Topics',
      'machine_name' => 'topics',
      'description' => '',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
