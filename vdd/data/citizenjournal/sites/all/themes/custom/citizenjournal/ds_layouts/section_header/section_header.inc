<?php
function ds_section_header() {
  return array(
    'label' => t('Section Header | Paragraph'),
    'regions' => array(
      'title' => t('Title'),
      'subhead' => t('Subhead'),
      'type' => t('Type'),
      'full_height' => t('Full Height'),
      'call_to_action' => t('Call To Action'),
      'link' => t('Link')
    ),
    'css' => false,
    'image' => false
  );
}
?>
