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
function u21_content_region_ctools_content_types() {
  return array(
    'title' => t('Region page'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function u21_content_region_content_type_content_types() {
  $types = array(
    'region_menu' => array(
      'title' => t('Region title and menu'),
      'description' => t('The title and related menu for a region page.'),
      'category' => t('Region page'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    ),
    'region_static_menu' => array(
      'title' => t('Region static menu'),
      'description' => t('Static menu for the region in the current context.'),
      'category' => t('Region page'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    ),
  );  
  return $types;
}

/**
 * Return the pane contents.
 */
function u21_content_region_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  switch($subtype) {
    case 'region_menu':
      $block->content = theme('u21_content_region_menu', $node);
      break;

    case 'region_static_menu':
      $block->content = theme('u21_content_region_static_menu', $node);
      break;
  }
  return $block;
}

/**
 * Return the pane titles.
 */
function u21_content_region_content_type_admin_title($subtype, $conf, $context) {
  switch($subtype) {
    case 'region_menu':
      return t('"@s":  Region title and menu', array('@s' => $context->identifier));
    case 'region_static_menu':
      return t('"@s": Region static menu', array('@s' => $context->identifier));
  }
}

/**
 * Returns an edit form for the content type.
 */
function u21_content_region_content_type_edit_form(&$form, &$form_state) {
  return $form;
}
/**
 * Submit handler for the content type editing form.
 */
function u21_content_region_content_type_edit_form_submit(&$form, &$form_state) {
  
}