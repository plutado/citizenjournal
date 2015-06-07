<?php
/**
 * @file
 * feature_paragraphs.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_paragraphs_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-paragraph_classic-field_classic_body'
  $field_instances['paragraphs_item-paragraph_classic-field_classic_body'] = array(
    'bundle' => 'paragraph_classic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_classic_body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'semantic_field_format' => '',
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_classic-field_classic_headline'
  $field_instances['paragraphs_item-paragraph_classic-field_classic_headline'] = array(
    'bundle' => 'paragraph_classic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_classic_headline',
    'label' => 'Headline',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'semantic_field_format' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_classic-field_classic_headline_element'
  $field_instances['paragraphs_item-paragraph_classic-field_classic_headline_element'] = array(
    'bundle' => 'paragraph_classic',
    'default_value' => array(
      0 => array(
        'value' => 'h2',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_classic_headline_element',
    'label' => 'Headline Element',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_classic-field_classic_media'
  $field_instances['paragraphs_item-paragraph_classic-field_classic_media'] = array(
    'bundle' => 'paragraph_classic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'semantic_field_format' => '',
        ),
        'type' => 'full',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_classic_media',
    'label' => 'Media',
    'required' => 0,
    'settings' => array(
      'referencable_types' => array(
        'file' => 0,
        'image' => 'image',
        'video' => 'video',
      ),
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'atom_reference',
      'settings' => array(
        'context' => 'sdl_editor_representation',
      ),
      'type' => 'atom_reference_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_classic-field_classic_media_alignment'
  $field_instances['paragraphs_item-paragraph_classic-field_classic_media_alignment'] = array(
    'bundle' => 'paragraph_classic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_classic_media_alignment',
    'label' => 'Media Alignment',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_classic-field_classic_media_width'
  $field_instances['paragraphs_item-paragraph_classic-field_classic_media_width'] = array(
    'bundle' => 'paragraph_classic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Choose the width.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_classic_media_width',
    'label' => 'Media Width',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_classic-field_classic_subtitle'
  $field_instances['paragraphs_item-paragraph_classic-field_classic_subtitle'] = array(
    'bundle' => 'paragraph_classic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_classic_subtitle',
    'label' => 'Subtitle',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'semantic_field_format' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_classic-field_classic_text_align'
  $field_instances['paragraphs_item-paragraph_classic-field_classic_text_align'] = array(
    'bundle' => 'paragraph_classic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_classic_text_align',
    'label' => 'Text Align',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage-field_paragraph_fullpage_body'
  $field_instances['paragraphs_item-paragraph_fullpage-field_paragraph_fullpage_body'] = array(
    'bundle' => 'paragraph_fullpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'semantic_field_format' => '',
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_paragraph_fullpage_body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'paragraph_classic' => -1,
        'paragraph_fullpage' => -1,
        'paragraph_fullpage_slide' => 'paragraph_fullpage_slide',
      ),
      'bundle_weights' => array(
        'paragraph_classic' => 5,
        'paragraph_fullpage' => 2,
        'paragraph_fullpage_slide' => 3,
      ),
      'default_edit_mode' => 'open',
      'semantic_field_format' => '',
      'title' => 'Row',
      'title_multiple' => 'Rows',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_fullpage_slide_teaser'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_fullpage_slide_teaser'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_fullpage_slide_teaser',
    'label' => 'Teaser',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'semantic_field_format' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_fullpage_slide_title'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_fullpage_slide_title'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'semantic_field_format' => 'default',
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_fullpage_slide_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'context' => 'no-access',
      'context_default' => 'no-access',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'semantic_field_format' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_options_background_color'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_options_background_color'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_key',
        'weight' => 8,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_options_background_color',
    'label' => 'Background Color',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_options_link'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_options_link'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_options_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'semantic_field_format' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'urlwidget',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_options_position_bottom'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_options_position_bottom'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_options_position_bottom',
    'label' => 'Bottom Position',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_options_position_left'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_options_position_left'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_options_position_left',
    'label' => 'Left Position',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_options_slabtext'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_options_slabtext'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Would you like to present this title as slabtext?',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_options_slabtext',
    'label' => 'SlabText',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_options_text_align'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_options_text_align'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => array(
      0 => array(
        'value' => 'center',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_options_text_align',
    'label' => 'Text Align',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_options_width'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_options_width'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '% width of container of title and subtitle fields',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_options_width',
    'label' => 'Width',
    'required' => 0,
    'settings' => array(
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_paragraph_bg_image'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_paragraph_bg_image'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'atom_reference',
        'settings' => array(
          'link' => 0,
          'semantic_field_format' => '',
        ),
        'type' => 'full',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_paragraph_bg_image',
    'label' => 'Background Image',
    'required' => 0,
    'settings' => array(
      'referencable_types' => array(
        'file' => 0,
        'image' => 'image',
        'video' => 0,
      ),
      'semantic_field_format' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'atom_reference',
      'settings' => array(
        'context' => 'sdl_editor_representation',
      ),
      'type' => 'atom_reference_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'paragraphs_item-paragraph_fullpage_slide-field_paragraph_slide_subtitle'
  $field_instances['paragraphs_item-paragraph_fullpage_slide-field_paragraph_slide_subtitle'] = array(
    'bundle' => 'paragraph_fullpage_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'semantic_field_format' => '',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_reset',
    'entity_type' => 'paragraphs_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_paragraph_slide_subtitle',
    'label' => 'Subtitle',
    'required' => 0,
    'settings' => array(
      'context' => 'debug',
      'context_default' => 'sdl_editor_representation',
      'dnd_enabled' => 0,
      'mee_enabled' => 0,
      'semantic_field_format' => '',
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('% width of container of title and subtitle fields');
  t('Background Color');
  t('Background Image');
  t('Body');
  t('Bottom Position');
  t('Choose the width.');
  t('Headline');
  t('Headline Element');
  t('Left Position');
  t('Link');
  t('Media');
  t('Media Alignment');
  t('Media Width');
  t('SlabText');
  t('Subtitle');
  t('Teaser');
  t('Text Align');
  t('Title');
  t('Width');
  t('Would you like to present this title as slabtext?');

  return $field_instances;
}
