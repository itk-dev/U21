<?php
// $Id$

/**
 * @file library.inc
 * Provides several region related panels content types.
 */


/**
 * Callback function to supply a list of content types.
 *
 * This is only required to make CTools know that we're providing 
 * multiple types here (since we have no single => TRUE in the array).
 */
function u21_region_slug_region_ctools_content_types() {
  return array(
    'title' => t('Region page'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function u21_region_slug_region_content_type_content_types() {
  $types = array(
    'region_menu' => array(
      'title' => t('Region title and menu'),
      'description' => t('The title and related menu for a region page.'),
    ),
  );

  // Append our default settings to every type.
  foreach ($types as $name => $type) {
    $types[$name] += array(
      'category' => t('Region page'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    );
  }
  
  return $types;
}

/**
 * Return the pane contents.
 */
function u21_region_slug_region_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  switch($subtype) {
    case 'region_menu':
      $block->content = theme('u21_region_slug_region_menu', $node);
      break;
  }
  return $block;
}

/**
 * Return the pane titles.
 */
function u21_region_slug_region_content_type_admin_title($subtype, $conf, $context) {
  switch($subtype) {
    case 'region_menu':
      return t('"@s":  Region title and menu', array('@s' => $context->identifier));
  }
}

/**
 * Returns an edit form for the content type.
 */
function u21_region_slug_region_content_type_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];
  switch ($form_state['subtype_name']) {
    case 'region_menu':
      /*
      $form['selected_region_menu'] = array(
        '#type' => 'textfield',
        '#title' => t('Menu to display'),
        '#description' => t('Defines which menu this panel should show as regional'),
        '#default_value' => $conf['selected_region_menu'],
      );
      */
      break;
  }
  return $form;
}
/**
 * Submit handler for the content type editing form.
 */
function u21_region_slug_region_content_type_edit_form_submit(&$form, &$form_state) {
  switch ($form_state['subtype_name']) {
    case 'region_title':
      /*
      $form_state['conf']['selected_region_menu'] = (bool) $form_state['values']['selected_region_menu'];
      */
      break;
  }
}