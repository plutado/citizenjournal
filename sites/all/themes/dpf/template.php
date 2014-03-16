<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * dpf theme.
 */

function pn_node($node, $mode = 'n') {
  if (!function_exists('prev_next_nid')) {
    return NULL;
  }

  switch($mode) {
    case 'p':
      $n_nid = prev_next_nid($node->nid, 'prev');
      $n_node = node_load($n_nid);
      $prev_img = "<img src='http://" . $_SERVER["SERVER_NAME"] . "/" . drupal_get_path('theme', 'dpf') . "/images/prev-blog.png' />";
      //$link_text =  'previous';
      $link_text =  $prev_img;
      if (isset($n_node->field_thumbnail[LANGUAGE_NONE][0]['uri'])) {
        $image = "‹";
        $image .= theme(
          'image_style',
          array(
            'path' => $n_node->field_thumbnail[LANGUAGE_NONE][0]['uri'],
            'style_name' => 'prev_next',
            'alt' => $n_node->title,
            'title' => $n_node->title,
            'attributes' => array('class' => 'prev-thumb'),
          )
        );
      }
      break;

    case 'n':
      $n_nid = prev_next_nid($node->nid, 'next');
      $n_node = node_load($n_nid);
      $next_img = "<img class='next-arrow' src='http://" . $_SERVER["SERVER_NAME"] . '/' . drupal_get_path('theme', 'dpf') . "/images/next-blog.png' />";
      // $link_text = 'next';
      $link_text = $next_img;
      //krumo();
      if (isset($n_node->field_thumbnail[LANGUAGE_NONE][0]['uri'])) {
        $image = theme(
          'image_style',
          array(
            'path' => $n_node->field_thumbnail[LANGUAGE_NONE][0]['uri'],
            'style_name' => 'prev_next',
            'alt' => $n_node->title,
            'title' => $n_node->title,
            'attributes' => array('class' => 'next-thumb'),
          )
        );
        $image .= "›";
      }
      break;

    default:
      return NULL;
  }

  if ($n_nid) {
    $n_node = node_load($n_nid);
    switch($n_node->type) {
      case 'blog_entry':
        if (isset($image)) {
          $thumb = $image;
        } else {
          $thumb = '';
        }
        // $html = l($n_node->title, "node/$n_nid", array('html' => TRUE));
        $html = l(/*$link_text .*/ $thumb, "node/$n_nid", array('html' => TRUE));
      return $html;
      default:
    }
  }

}

/**
 * Implements form_comment_form_alter().
 */
function dpf_form_comment_form_alter(&$form, &$form_state) {

  $form['comment_body'][LANGUAGE_NONE]['#after_build'][0] = 'dpf_customize_comment_form';

  $form['author']['_author']['#markup'] = '';

  // Adding copy to comment form.
  $form['comment_body'][LANGUAGE_NONE][0]['#attributes']['placeholder'] = t('Please share your comment here...');

  $form['author']['_author']['#title'] = '';

  $form['subject']['#title'] = '';

  $form['comment_body'][LANGUAGE_NONE][0]['#title'] = '';

  $form['actions']['submit']['#value'] = t('Post Comment');
}

/**
 * Remove comment text input info.
 */
function dpf_customize_comment_form($form) {
  $form[0]['format']['help']['#access'] = FALSE;
  $form[0]['format']['guidelines']['#access'] = FALSE;
  $form[0]['format']['format']['#access'] = FALSE;
  return $form;
}

