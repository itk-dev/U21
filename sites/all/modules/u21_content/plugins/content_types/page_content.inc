<?php
// $Id$

/**
 * Callback function to supply a list of content types.
 *
 * This is only required to make CTools know that we're providing
 * multiple types here (since we have no single => TRUE in the array).
 */
function u21_content_page_content_ctools_content_types() {
  return array(
    'title' => t('Page content'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function u21_content_page_content_content_type_content_types() {
  $types = array(
    'static_file_links' => array(
      'title' => t('Static file(s) download'),
      'description' => t('Links box showing files uploaded to static page.'),
      'category' => t('Page content'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    ),
    'page_links' => array(
      'title' => t('Page links'),
      'description' => t('Links box for page links.'),
      'category' => t('Page content'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    ),
  );
  return $types;
}

/**
 * Return the pane contents.
 */
function u21_content_page_content_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  switch($subtype) {
    case 'static_file_links':
      $block->content = theme('u21_content_panels_content_static_file_links', $node);
      break;
    case 'page_links':
      $block->content = theme('u21_content_panels_content_page_links', $node);
      break;
  }
  return $block;
}

/**
 * Return the pane titles.
 */
function u21_content_page_content_content_type_admin_title($subtype, $conf, $context) {
  switch($subtype) {
    case 'static_file_links':
      return t('"@s":  Static file links', array('@s' => $context->identifier));
      break;
    case 'page_links':
      return t('"@s":  Page links', array('@s' => $context->identifier));
      break;
  }
}

/**
 * Returns an edit form for the content type.
 */
function u21_content_page_content_content_type_edit_form(&$form, &$form_state) { }

/**
 * Submit handler for the content type editing form.
 */
function u21_content_page_content_content_type_edit_form_submit(&$form, &$form_state) { }

