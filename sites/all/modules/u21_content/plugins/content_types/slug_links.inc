<?php
// $Id$

/**
 * @file library.inc
 * Provides panels_slug related panels content types.
 */


/**
 * Callback function to supply a list of content types.
 *
 * This is only required to make CTools know that we're providing
 * multiple types here (since we have no single => TRUE in the array).
 */
function u21_content_slug_links_ctools_content_types() {
  return array(
    'title' => t('Slug links'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function u21_content_slug_links_content_type_content_types() {
  $types = array(
    'slug_links' => array(
      'title' => t('Slug links'),
      'description' => t('Links box based on the node type and slugs.'),
      'category' => t('Region page'),
      'defaults' => array(
        'node_type' => NULL,
        'slug_path' => 'location/%slug/news',
        'global_path' => 'news',
      ),
    ),
  );
  return $types;
}

/**
 * Return the pane contents.
 */
function u21_content_slug_links_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  switch($subtype) {
    case 'slug_links':
      $block->title = t('Slug links');
      $block->content = theme('u21_content_slug_links', $node, $conf['node_type'],
                              $conf['slug_path'], $conf['global_path']);
      break;
  }
  return $block;
}

/**
 * Return the pane titles.
 */
function u21_content_slug_links_content_type_admin_title($subtype, $conf, $context) {
  switch($subtype) {
    case 'slug_links':
      return t('Slug links');
    break;
  }
}

/**
 * Returns an edit form for the content type.
 */
function u21_content_slug_links_content_type_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];
  switch ($form_state['subtype_name']) {
    case 'slug_links':
      // Load content types
      $form['node_type'] = array(
        '#type' => 'select',
        '#title' => t('Type of'),
        '#options' => array_filter(variable_get('panels_slug_selected_node_types', array())),
        '#default_value' => $conf['node_type'],
      );

      $form['global_path'] = array(
        '#type' => 'textfield',
        '#title' => t('Global path (e.g news)'),
        '#default_value' => $conf['global_path'],
      );

      $form['slug_path'] = array(
        '#type' => 'textfield',
        '#title' => t('Slug path (e.g location/%slug/news)'),
        '#default_value' => $conf['slug_path'],
      );
      break;
  }
}
/**
 * Submit handler for the content type editing form.
 */
function u21_content_slug_links_content_type_edit_form_submit(&$form, &$form_state) {
  switch ($form_state['subtype_name']) {
    case 'slug_links':
      $form_state['conf']['node_type'] = $form_state['values']['node_type'];
      $form_state['conf']['slug_path'] = $form_state['values']['slug_path'];
      $form_state['conf']['global_path'] = $form_state['values']['global_path'];
      break;
  }
}

