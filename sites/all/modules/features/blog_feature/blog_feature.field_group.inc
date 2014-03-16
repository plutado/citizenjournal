<?php
/**
 * @file
 * blog_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function blog_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blog_tags|node|blog_entry|form';
  $field_group->group_name = 'group_blog_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomy';
  $field_group->data = array(
    'label' => 'Blog tags',
    'weight' => '3',
    'children' => array(
      0 => 'field_blog_tags',
      1 => 'field_content_type',
      2 => 'field_topic',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blog_tags|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ht_links|node|blog_entry|form';
  $field_group->group_name = 'group_ht_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_links';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '27',
    'children' => array(
      0 => 'group_redirect',
      1 => 'group_ht_weblinks',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_ht_links|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ht_weblinks|node|blog_entry|form';
  $field_group->group_name = 'group_ht_weblinks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ht_links';
  $field_group->data = array(
    'label' => 'Web Links',
    'weight' => '28',
    'children' => array(
      0 => 'field_weblinks',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ht_weblinks|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_thumbnail|node|blog_entry|form';
  $field_group->group_name = 'group_image_thumbnail';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_media_h_group';
  $field_group->data = array(
    'label' => 'Thumbnail',
    'weight' => '20',
    'children' => array(
      0 => 'field_thumbnail',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_image_thumbnail|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_h_group|node|blog_entry|form';
  $field_group->group_name = 'group_media_h_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_images';
  $field_group->data = array(
    'label' => 'Media Assets',
    'weight' => '20',
    'children' => array(
      0 => 'group_image_thumbnail',
      1 => 'group_photo_inserts',
      2 => 'group_photo_gallery',
      3 => 'group_video',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_media_h_group|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_gallery|node|blog_entry|form';
  $field_group->group_name = 'group_photo_gallery';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_media_h_group';
  $field_group->data = array(
    'label' => 'Photo Gallery',
    'weight' => '22',
    'children' => array(
      0 => 'field_feature_photo',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_gallery|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_inserts|node|blog_entry|form';
  $field_group->group_name = 'group_photo_inserts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_media_h_group';
  $field_group->data = array(
    'label' => 'Photo Inserts',
    'weight' => '21',
    'children' => array(
      0 => 'field_top_photo',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo_inserts|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_redirect|node|blog_entry|form';
  $field_group->group_name = 'group_redirect';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ht_links';
  $field_group->data = array(
    'label' => 'Redirect URL',
    'weight' => '27',
    'children' => array(
      0 => 'field_link',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_redirect|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_subheadline|node|blog_entry|form';
  $field_group->group_name = 'group_subheadline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomy';
  $field_group->data = array(
    'label' => 'Subheadline',
    'weight' => '2',
    'children' => array(
      0 => 'field_subheadline',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_subheadline|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|blog_entry|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '3',
    'children' => array(
      0 => 'group_images',
      1 => 'group_blog_tags',
      2 => 'group_subheadline',
      3 => 'group_links',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_taxonomy|node|blog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video|node|blog_entry|form';
  $field_group->group_name = 'group_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_media_h_group';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '23',
    'children' => array(
      0 => 'field_video_embed',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_video|node|blog_entry|form'] = $field_group;

  return $export;
}
