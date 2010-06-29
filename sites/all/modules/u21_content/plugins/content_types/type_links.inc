<?php
// $Id$

/**
 * Callback function to supply a list of content types.
 *
 * This is only required to make CTools know that we're providing
 * multiple types here (since we have no single => TRUE in the array).
 */
function u21_content_type_links_ctools_content_types() {
  return array(
    'title' => t('News type links'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function u21_content_type_links_content_type_content_types() {
  $types = array(
    'type_links' => array(
      'title' => t('News type links'),
      'description' => t('News type links box.'),
      'category' => t('News panes'),
    ),
  );
  return $types;
}

/**
 * Return the pane contents.
 */
function u21_content_type_links_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  switch($subtype) {
    case 'type_links':
      // Get selected content type names
      foreach (array_filter($conf['node_type']) as $type) {
        $ret_type[$type] = node_get_types('type', $type)->name;
      }
      $block->title = t('New type links');
      $block->content = theme('u21_content_type_links', $panel_args, $ret_type);
      break;
  }
  return $block;
}

/**
 * Return the pane titles.
 */
function u21_content_type_links_content_type_admin_title($subtype, $conf, $context) {
  switch($subtype) {
    case 'type_links':
      return t('News type links');
    break;
  }
}

/**
 * Returns an edit form for the content type.
 */
function u21_content_type_links_content_type_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];
  switch ($form_state['subtype_name']) {
    case 'type_links':

      // Load content types
      foreach (node_get_types() as $type) {
        $types[$type->type] = $type->name;
      }

      // Load content types
      $form['node_type'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Type of'),
        '#options' => $types,
        '#default_value' => $conf['node_type'],
      );
    break;
  }
}
/**
 * Submit handler for the content type editing form.
 */
function u21_content_type_links_content_type_edit_form_submit(&$form, &$form_state) {
  switch ($form_state['subtype_name']) {
    case 'type_links':
      foreach (array('node_type') as $key) {
        $form_state['conf'][$key] = $form_state['values'][$key];
      }
      break;
  }
}

