<?php
/**
 * @file
 * feature_paragraphs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_paragraphs_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_classic_main|paragraphs_item|paragraph_classic|form';
  $field_group->group_name = 'group_classic_main';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'paragraph_classic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_classic_body',
      1 => 'field_classic_headline',
      2 => 'field_classic_subtitle',
      3 => 'field_classic_media',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Main Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-classic-main field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_classic_main|paragraphs_item|paragraph_classic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_classic_options|paragraphs_item|paragraph_classic|form';
  $field_group->group_name = 'group_classic_options';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'paragraph_classic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Options',
    'weight' => '1',
    'children' => array(
      0 => 'field_classic_media_width',
      1 => 'field_classic_media_alignment',
      2 => 'field_classic_headline_element',
      3 => 'field_classic_text_align',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Options',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-classic-options field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_classic_options|paragraphs_item|paragraph_classic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fullpage_slide_main|paragraphs_item|paragraph_fullpage_slide|form';
  $field_group->group_name = 'group_fullpage_slide_main';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'paragraph_fullpage_slide';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_fullpage_slide_title',
      1 => 'field_paragraph_bg_image',
      2 => 'field_paragraph_slide_subtitle',
      3 => 'field_fullpage_slide_teaser',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Main Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-fullpage-slide-main field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_fullpage_slide_main|paragraphs_item|paragraph_fullpage_slide|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fullpage_slide_options|paragraphs_item|paragraph_fullpage_slide|form';
  $field_group->group_name = 'group_fullpage_slide_options';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'paragraph_fullpage_slide';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Options',
    'weight' => '1',
    'children' => array(
      0 => 'field_options_width',
      1 => 'field_options_text_align',
      2 => 'field_options_position_left',
      3 => 'field_options_position_bottom',
      4 => 'field_options_background_color',
      5 => 'field_options_link',
      6 => 'field_options_slabtext',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Options',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-fullpage-slide-options field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_fullpage_slide_options|paragraphs_item|paragraph_fullpage_slide|form'] = $field_group;

  return $export;
}
