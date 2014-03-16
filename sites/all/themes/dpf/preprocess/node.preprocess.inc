<?php

/**
 * @file
 * Preprocessing variables for node.tpl.php
 */

/**
 * Override or insert variables into the node template.
 */
function dpf_preprocess_node(&$vars) {

  // add fitvid plugin
  if ($vars['type'] == 'blog_entry' && !empty($vars['field_video_embed'])) {
    $file = drupal_get_path('theme', 'dpf') . '/js/jquery.fitvids.js';
    drupal_add_js($file);
  }

}
