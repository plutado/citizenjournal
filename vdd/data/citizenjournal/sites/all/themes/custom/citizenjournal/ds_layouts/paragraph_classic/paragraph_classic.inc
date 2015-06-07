<?php
  function ds_paragraph_classic() {
    return array(
      'label' => t('Classic | Paragraph'),
      'regions' => array(
        'headline' => t('Headline'),
        'subtitle' => t('Subtitle'),
        'body_copy' => t('Body Copy'),
        'media' => t('Media'),
        'media_width' => t('Media Width'),
        'media_alignment' => t('Media Alignment'),
        'headline_size' => t('Headline Size'),
        'text_align' => t('Text Align'),
      ),
      'css' => false,
      'image' => false
    );
  }
?>
