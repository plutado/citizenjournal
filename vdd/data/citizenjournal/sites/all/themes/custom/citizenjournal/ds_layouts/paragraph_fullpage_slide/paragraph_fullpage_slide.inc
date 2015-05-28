<?php
  function ds_paragraph_fullpage_slide() {
    return array(
      'label' => t('Full Page Slide | Paragraph'),
      'regions' => array(
        'title' => t('Title'),
        'subtitle' => t('Subtitle'),
        'teaser' => t('Teaser'),
        'bg' => t('Background Image'),
        'width' => t('Width'),
        'text_align' => t('Text Align'),
        'bottom_position' => t('Bottom Position'),
        'left_position' => t('Left Position'),
        'background_color' => t('Background Color'),
        'link' => t('Link'),
        'slabtext' => t('Slabtext'),
      ),
      'css' => false,
      'image' => false
    );
  }
?>
