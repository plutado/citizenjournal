<?php
/**
 * @file
 * feature_paragraphs.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function feature_paragraphs_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_classic_body'
  $field_bases['field_classic_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_classic_body',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_classic_headline'
  $field_bases['field_classic_headline'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_classic_headline',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_classic_headline_element'
  $field_bases['field_classic_headline_element'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_classic_headline_element',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'h1' => 'h1',
        'h2' => 'h2',
        'h3' => 'h3',
        'h4' => 'h4',
        'h5' => 'h5',
        'h6' => 'h6',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_classic_media'
  $field_bases['field_classic_media'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_classic_media',
    'foreign keys' => array(),
    'indexes' => array(
      'sid' => array(
        0 => 'sid',
      ),
    ),
    'locked' => 0,
    'module' => 'atom_reference',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'atom_reference',
  );

  // Exported field_base: 'field_classic_media_alignment'
  $field_bases['field_classic_media_alignment'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_classic_media_alignment',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'left' => 'left',
        'right' => 'right',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_classic_media_width'
  $field_bases['field_classic_media_width'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_classic_media_width',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        100 => 'Full Width',
        50 => 'One-Half',
        33 => 'One-Third',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_classic_subtitle'
  $field_bases['field_classic_subtitle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_classic_subtitle',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_classic_text_align'
  $field_bases['field_classic_text_align'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_classic_text_align',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'left' => 'left',
        'right' => 'right',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_fullpage_slide_teaser'
  $field_bases['field_fullpage_slide_teaser'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fullpage_slide_teaser',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_fullpage_slide_title'
  $field_bases['field_fullpage_slide_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_fullpage_slide_title',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_options_background_color'
  $field_bases['field_options_background_color'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_options_background_color',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'rgba(0, 0, 0, 0.65)' => 'black',
        'rgba(255, 255, 255, 0.65)' => 'white',
        'rgba(255, 255, 255, 0)' => 'transparent',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_options_link'
  $field_bases['field_options_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_options_link',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_options_position_bottom'
  $field_bases['field_options_position_bottom'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_options_position_bottom',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        100 => '100%',
        99 => '99%',
        98 => '98%',
        97 => '97%',
        96 => '96%',
        95 => '95%',
        94 => '94%',
        93 => '93%',
        92 => '92%',
        91 => '91%',
        90 => '90%',
        89 => '89%',
        88 => '88%',
        87 => '87%',
        86 => '86%',
        85 => '85%',
        84 => '84%',
        83 => '83%',
        82 => '82%',
        81 => '81%',
        80 => '80%',
        79 => '79%',
        78 => '78%',
        77 => '77%',
        76 => '76%',
        75 => '75%',
        74 => '74%',
        73 => '73%',
        72 => '72%',
        71 => '71%',
        70 => '70%',
        69 => '69%',
        68 => '68%',
        67 => '67%',
        66 => '66%',
        65 => '65%',
        64 => '64%',
        63 => '63%',
        62 => '62%',
        61 => '61%',
        60 => '60%',
        59 => '59%',
        58 => '58%',
        57 => '57%',
        56 => '56%',
        55 => '55%',
        54 => '54%',
        53 => '53%',
        52 => '52%',
        51 => '51%',
        50 => '50%',
        49 => '49%',
        48 => '48%',
        47 => '47%',
        46 => '46%',
        45 => '45%',
        44 => '44%',
        43 => '43%',
        42 => '42%',
        41 => '41%',
        40 => '40%',
        39 => '39%',
        38 => '38%',
        37 => '37%',
        36 => '36%',
        35 => '35%',
        34 => '34%',
        33 => '33%',
        32 => '32%',
        31 => '31%',
        30 => '30%',
        29 => '29%',
        28 => '28%',
        27 => '27%',
        26 => '26%',
        25 => '25%',
        24 => '24%',
        23 => '23%',
        22 => '22%',
        21 => '21%',
        20 => '20%',
        19 => '19%',
        18 => '18%',
        17 => '17%',
        16 => '16%',
        15 => '15%',
        14 => '14%',
        13 => '13%',
        12 => '12%',
        11 => '11%',
        10 => '10%',
        9 => '9%',
        8 => '8%',
        7 => '7%',
        6 => '6%',
        5 => '5%',
        4 => '4%',
        3 => '3%',
        2 => '2%',
        1 => '1%',
        0 => '0%',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_options_position_left'
  $field_bases['field_options_position_left'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_options_position_left',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        100 => '100%',
        99 => '99%',
        98 => '98%',
        97 => '97%',
        96 => '96%',
        95 => '95%',
        94 => '94%',
        93 => '93%',
        92 => '92%',
        91 => '91%',
        90 => '90%',
        89 => '89%',
        88 => '88%',
        87 => '87%',
        86 => '86%',
        85 => '85%',
        84 => '84%',
        83 => '83%',
        82 => '82%',
        81 => '81%',
        80 => '80%',
        79 => '79%',
        78 => '78%',
        77 => '77%',
        76 => '76%',
        75 => '75%',
        74 => '74%',
        73 => '73%',
        72 => '72%',
        71 => '71%',
        70 => '70%',
        69 => '69%',
        68 => '68%',
        67 => '67%',
        66 => '66%',
        65 => '65%',
        64 => '64%',
        63 => '63%',
        62 => '62%',
        61 => '61%',
        60 => '60%',
        59 => '59%',
        58 => '58%',
        57 => '57%',
        56 => '56%',
        55 => '55%',
        54 => '54%',
        53 => '53%',
        52 => '52%',
        51 => '51%',
        50 => '50%',
        49 => '49%',
        48 => '48%',
        47 => '47%',
        46 => '46%',
        45 => '45%',
        44 => '44%',
        43 => '43%',
        42 => '42%',
        41 => '41%',
        40 => '40%',
        39 => '39%',
        38 => '38%',
        37 => '37%',
        36 => '36%',
        35 => '35%',
        34 => '34%',
        33 => '33%',
        32 => '32%',
        31 => '31%',
        30 => '30%',
        29 => '29%',
        28 => '28%',
        27 => '27%',
        26 => '26%',
        25 => '25%',
        24 => '24%',
        23 => '23%',
        22 => '22%',
        21 => '21%',
        20 => '20%',
        19 => '19%',
        18 => '18%',
        17 => '17%',
        16 => '16%',
        15 => '15%',
        14 => '14%',
        13 => '13%',
        12 => '12%',
        11 => '11%',
        10 => '10%',
        9 => '9%',
        8 => '8%',
        7 => '7%',
        6 => '6%',
        5 => '5%',
        4 => '4%',
        3 => '3%',
        2 => '2%',
        1 => '1%',
        0 => '0%',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_options_slabtext'
  $field_bases['field_options_slabtext'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_options_slabtext',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'yes' => 'yes',
        'no' => 'no',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_options_text_align'
  $field_bases['field_options_text_align'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_options_text_align',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'center' => 'center',
        'left' => 'left',
        'right' => 'right',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_options_width'
  $field_bases['field_options_width'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_options_width',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        100 => '100%',
        99 => '99%',
        98 => '98%',
        97 => '97%',
        96 => '96%',
        95 => '95%',
        94 => '94%',
        93 => '93%',
        92 => '92%',
        91 => '91%',
        90 => '90%',
        89 => '89%',
        88 => '88%',
        87 => '87%',
        86 => '86%',
        85 => '85%',
        84 => '84%',
        83 => '83%',
        82 => '82%',
        81 => '81%',
        80 => '80%',
        79 => '79%',
        78 => '78%',
        77 => '77%',
        76 => '76%',
        75 => '75%',
        74 => '74%',
        73 => '73%',
        72 => '72%',
        71 => '71%',
        70 => '70%',
        69 => '69%',
        68 => '68%',
        67 => '67%',
        66 => '66%',
        65 => '65%',
        64 => '64%',
        63 => '63%',
        62 => '62%',
        61 => '61%',
        60 => '60%',
        59 => '59%',
        58 => '58%',
        57 => '57%',
        56 => '56%',
        55 => '55%',
        54 => '54%',
        53 => '53%',
        52 => '52%',
        51 => '51%',
        50 => '50%',
        49 => '49%',
        48 => '48%',
        47 => '47%',
        46 => '46%',
        45 => '45%',
        44 => '44%',
        43 => '43%',
        42 => '42%',
        41 => '41%',
        40 => '40%',
        39 => '39%',
        38 => '38%',
        37 => '37%',
        36 => '36%',
        35 => '35%',
        34 => '34%',
        33 => '33%',
        32 => '32%',
        31 => '31%',
        30 => '30%',
        29 => '29%',
        28 => '28%',
        27 => '27%',
        26 => '26%',
        25 => '25%',
        24 => '24%',
        23 => '23%',
        22 => '22%',
        21 => '21%',
        20 => '20%',
        19 => '19%',
        18 => '18%',
        17 => '17%',
        16 => '16%',
        15 => '15%',
        14 => '14%',
        13 => '13%',
        12 => '12%',
        11 => '11%',
        10 => '10%',
        9 => '9%',
        8 => '8%',
        7 => '7%',
        6 => '6%',
        5 => '5%',
        4 => '4%',
        3 => '3%',
        2 => '2%',
        1 => '1%',
        0 => '0%',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_paragraph_bg_image'
  $field_bases['field_paragraph_bg_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_paragraph_bg_image',
    'foreign keys' => array(),
    'indexes' => array(
      'sid' => array(
        0 => 'sid',
      ),
    ),
    'locked' => 0,
    'module' => 'atom_reference',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'atom_reference',
  );

  // Exported field_base: 'field_paragraph_fullpage_body'
  $field_bases['field_paragraph_fullpage_body'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_paragraph_fullpage_body',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  // Exported field_base: 'field_paragraph_slide_subtitle'
  $field_bases['field_paragraph_slide_subtitle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_paragraph_slide_subtitle',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
