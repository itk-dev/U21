<?php
// $Id$

/**
 * @file region.inc
 * Provides several event related panels content types.
 */


/**
 * Callback function to supply a list of content types.
 *
 * This is only required to make CTools know that we're providing
 * multiple types here (since we have no single => TRUE in the array).
 */
function u21_content_events_ctools_content_types() {
  return array(
    'title' => t('Event details'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function u21_content_events_content_type_content_types() {
  $types = array(
    'event_details' => array(
      'title' => t('Event details'),
      'description' => t('Display event details (Date, time, prise and location).'),
      'category' => t('Event panes'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    ),
  );

  return $types;
}

/**
 * Return the pane contents.
 */
function u21_content_events_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  switch($subtype) {
    case 'event_details':
      $block->title = t('Practical');
      $block->content = theme('u21_content_event_details', $node);
      break;
  }
  return $block;
}

/**
 * Return the pane titles.
 */
function u21_content_events_content_type_admin_title($subtype, $conf, $context) {
  switch($subtype) {
    case 'event_details':
      return t('"@s":  Event details', array('@s' => $context->identifier));
  }
}

/**
 * Returns an edit form for the content type.
 */
function u21_content_events_content_type_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];
  switch ($form_state['subtype_name']) {
    case 'event_details':
      break;
  }
  return $form;
}
/**
 * Submit handler for the content type editing form.
 */
function u21_content_events_content_type_edit_form_submit(&$form, &$form_state) {
  switch ($form_state['subtype_name']) {
    case 'event_details':
      break;
  }
}
