<?php

  if (!empty($node->field_thumbnail)) {
    $image = theme(
      'image_style',
      array(
        'path' => $node->field_thumbnail[LANGUAGE_NONE][0]['uri'],
        'style_name' => '450x338'
      )
    );
  }

  if ($node->field_subheadline) {
    $teaser = '<div class="teaser">' . $node->field_subheadline[LANGUAGE_NONE][0]['value'] . '</div>';
  } else {
    $teaser = '';
  }

?>

<div class="teaser-wrapper">
  <?php if (!empty($node->field_thumbnail)) : ?>
    <?php print l($image, 'node/' . $node->nid, array('attributes' => array(), 'html' => TRUE)); ?>
  <?php endif; ?>
  <?php print l('<div class="title-teaser-wrapper">' . $title . $teaser . '</div>', 'node/' . $node->nid, array('attributes' => array(), 'html' => TRUE)); ?>
</div>
