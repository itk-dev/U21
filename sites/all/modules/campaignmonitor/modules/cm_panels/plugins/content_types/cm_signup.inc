<?php
// $Id$

/**
 * @file cm_signup.inc
 * Provides signup form for Campaign monitor news later as panels content type.
 */


/**
 * Callback function to supply a list of content types.
 *
 * This is only required to make CTools know that we're providing
 * multiple types here (since we have no single => TRUE in the array).
 */
function cm_panels_cm_signup_ctools_content_types() {
  return array(
    'title' => t('Newsletter'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function cm_panels_cm_signup_content_type_content_types() {
  $types = array(
    'cm_signup_form' => array(
      'title' => t('Campaign monitor signup form'),
      'description' => t('Form to enable user to signup for newsletters.'),
      'category' => t('Newsletters'),
    ),
  );

  return $types;
}

/**
 * Return the pane contents.
 */
function cm_panels_cm_signup_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  switch($subtype) {
    case 'cm_signup_form':
      $block->content = '<div id="cm-signup-block-form">' .drupal_get_form('campaignmonitor_signup_form'). '</div>';
      break;
  }
  return $block;
}

/**
 * Return the pane titles.
 */
function cm_panels_cm_signup_content_type_admin_title($subtype, $conf, $context) {
  switch($subtype) {
    case 'cm_signup_form':
      return t('Campaign monitor signup form');
  }
}

/**
 * Returns an edit form for the content type.
 */
function cm_panels_cm_signup_content_type_edit_form(&$form, &$form_state) {
  return $form;
}
/**
 * Submit handler for the content type editing form.
 */
function cm_panels_cm_signup_content_type_edit_form_submit(&$form, &$form_state) {
}