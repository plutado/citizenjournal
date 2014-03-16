<?php
/**
 * @file
 * configuration file for blog--node-blog-entry.tpl.php
 * display suite template for story content type
 */

?>

<?php

/**
 * Display suite regions for story content type.
 */
function ds_blog() {
  return array(
    'label' => t('Blog'),
    'regions' => array(
      'title' => ('Title'),
      'subtitle' => ('Sub Headline'),
      'author_byline' => ('Byline'),
      'timestamp' => ('Post Date'),
      'gallery_photos' => ('Gallery Photos'),
      'video_embed' => ('Video Embed'),
      'body' => ('Body'),
      'comments' => t('Comments'),
      'sidebar' => t('Sidebar'),
    ),
    'css' => FALSE,
    'image' => TRUE,
  );
}

