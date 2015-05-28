<?php
/**
 * @file
 * feature_page_manager.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function feature_page_manager_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__panels_everywhere';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'panels everywhere',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panels_everywhere',
  );
  $display = new panels_display();
  $display->layout = 'everywhere_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => NULL,
      'second' => NULL,
      'third' => NULL,
      'menu' => NULL,
      'header' => NULL,
      'main_content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0e5dddd4-b087-4882-b921-ef9a28e8317b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-080d219f-9737-4ace-b55b-65605f808d37';
    $pane->panel = 'main_content';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '080d219f-9737-4ace-b55b-65605f808d37';
    $display->content['new-080d219f-9737-4ace-b55b-65605f808d37'] = $pane;
    $display->panels['main_content'][0] = 'new-080d219f-9737-4ace-b55b-65605f808d37';
    $pane = new stdClass();
    $pane->pid = 'new-25b6b90b-94df-4a93-b1e8-6db9f5c6379e';
    $pane->panel = 'main_content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '25b6b90b-94df-4a93-b1e8-6db9f5c6379e';
    $display->content['new-25b6b90b-94df-4a93-b1e8-6db9f5c6379e'] = $pane;
    $display->panels['main_content'][1] = 'new-25b6b90b-94df-4a93-b1e8-6db9f5c6379e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__panels_everywhere'] = $handler;

  return $export;
}
