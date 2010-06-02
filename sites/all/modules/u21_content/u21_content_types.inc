<?php

/**
 * The exported content type with CCK fields.
 *
 * @return array
 */
function u21_content_types_import() {
  $types = array();

  $content = array();
  $content['type']  = array (
    'name' => 'Region',
    'type' => 'region',
    'description' => 'This content types is used to create regions',
    'title_label' => 'Title',
    'body_label' => '',
    'min_word_count' => '0',
    'help' => '',
    'node_options' =>
    array (
      'status' => true,
      'promote' => false,
      'sticky' => false,
      'revision' => false,
    ),
    'old_type' => 'region',
    'orig_type' => '',
    'module' => 'node',
    'custom' => '1',
    'modified' => '1',
    'locked' => '0',
    'comment' => '0',
    'comment_default_mode' => '4',
    'comment_default_order' => '1',
    'comment_default_per_page' => '50',
    'comment_controls' => '3',
    'comment_anonymous' => 0,
    'comment_subject_field' => '1',
    'comment_preview' => '1',
    'comment_form_location' => '0',
    'menu' =>
    array (
      'admin' => false,
      'navigation' => false,
      'primary-links' => false,
      'secondary-links' => false,
    ),
  );

  $types[$content['type']['name']] = $content;

  return $types;
}

/**
 * Install the u21 content types.
 *
 */
function u21_content_types_install() {
  // CCK content_copy.module may not be enabled, so make sure it is included.
  include_once './' . drupal_get_path('module', 'content') . '/modules/content_copy/content_copy.module';

  $types = u21_content_types_import();
  foreach ($types as $type) {
    $form_state['values']['type_name'] = '<create>';
    $form_state['values']['macro'] = '$content = ' . var_export($type, TRUE) . ';';

    // Form provided by content_copy.module
    drupal_execute('content_copy_import_form', $form_state);

    // Clear form state
    unset ($form_state);
  }
  content_clear_type_cache();
}

function u21_content_types_uninstall() {
  //node_type_delete('region');
}