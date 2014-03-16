<?php
/**
 * @file
 * webisode.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function webisode_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'webseries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'webseries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'webseries';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  /* Field: Content: Youtube Video ID */
  $handler->display->display_options['fields']['field_youtube_video_id']['id'] = 'field_youtube_video_id';
  $handler->display->display_options['fields']['field_youtube_video_id']['table'] = 'field_data_field_youtube_video_id';
  $handler->display->display_options['fields']['field_youtube_video_id']['field'] = 'field_youtube_video_id';
  $handler->display->display_options['fields']['field_youtube_video_id']['label'] = '';
  $handler->display->display_options['fields']['field_youtube_video_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_youtube_video_id']['alter']['text'] = '<div class="video_id_[counter]">[field_youtube_video_id-value]</div>';
  $handler->display->display_options['fields']['field_youtube_video_id']['element_type'] = '0';
  $handler->display->display_options['fields']['field_youtube_video_id']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_youtube_video_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_youtube_video_id']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_youtube_video_id']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="title_[counter]"><span class="title">[title]<span></div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Subheading */
  $handler->display->display_options['fields']['field_subheading']['id'] = 'field_subheading';
  $handler->display->display_options['fields']['field_subheading']['table'] = 'field_data_field_subheading';
  $handler->display->display_options['fields']['field_subheading']['field'] = 'field_subheading';
  $handler->display->display_options['fields']['field_subheading']['label'] = '';
  $handler->display->display_options['fields']['field_subheading']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_subheading']['alter']['text'] = '<div class="subheading_[counter]">[field_subheading]</div>';
  $handler->display->display_options['fields']['field_subheading']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="body-[counter]">[body]</div>';
  /* Field: Content: Transcript */
  $handler->display->display_options['fields']['field_transcript']['id'] = 'field_transcript';
  $handler->display->display_options['fields']['field_transcript']['table'] = 'field_data_field_transcript';
  $handler->display->display_options['fields']['field_transcript']['field'] = 'field_transcript';
  $handler->display->display_options['fields']['field_transcript']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_transcript']['alter']['text'] = '<div class="transcript-[counter]">[field_transcript]</div>';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'index';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['webseries'] = $view;

  return $export;
}
