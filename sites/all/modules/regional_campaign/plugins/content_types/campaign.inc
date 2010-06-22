<?php
// $Id$

/**
 * @file region.inc
 * Provides several region related panels content types.
 */


/**
 * Callback function to supply a list of content types.
 *
 * This is only required to make CTools know that we're providing 
 * multiple types here (since we have no single => TRUE in the array).
 */
function regional_campaign_campaign_ctools_content_types() {
  return array(
    'title' => t('Regional campaign'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function regional_campaign_campaign_content_type_content_types() {
  $types = array(
    'regional_campaign' => array(
      'title' => t('Regional campaigns'),
      'description' => t('Display regional campaigns'),
      'category' => t('Region page'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    ),
  );  
  return $types;
}

/**
 * Return the pane contents.
 */
function regional_campaign_campaign_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  switch($subtype) {
    case 'regional_campaign':
      $block->content = theme('regional_campagin_panels_plugin', $node);
      break;
  }
  return $block;
}

/**
 * Return the pane titles.
 */
function regional_campaign_campaign_content_type_admin_title($subtype, $conf, $context) {
  switch($subtype) {
    case 'regional_campaign':
      return t('"@s":  Regional campaings', array('@s' => $context->identifier));
  }
}

/**
 * Returns an edit form for the content type.
 */
function regional_campaign_campaign_content_type_edit_form(&$form, &$form_state) {
  return $form;
}
/**
 * Submit handler for the content type editing form.
 */
function regional_campaign_campaign_content_type_edit_form_submit(&$form, &$form_state) {
  
}