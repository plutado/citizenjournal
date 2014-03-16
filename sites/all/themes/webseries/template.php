<?php

/**
 * Add body classes if certain regions have content.
 */
function webseries_preprocess_html(&$variables) {
  $node = menu_get_object();

  if ($node && $node->nid) {
    $vars['theme_hook_suggestions'][] = 'html__' . $node->type;
  }

}

/**
 * Override or insert variables into the page template.
 */
function webseries_preprocess_page(&$vars, $hook) {

  if (isset($vars['node'])) {
    $suggest = "page__node__{$vars['node']->type}";
    $vars['theme_hook_suggestions'][] = $suggest;
  }

}

