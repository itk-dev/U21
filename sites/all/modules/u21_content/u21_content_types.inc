<?php

/**
 * The exported content type with CCK fields.
 *
 * @return array
 */
function u21_content_types_import() {
  $types = array();

  $content['type']  = array (
    'name' => 'Region',
    'type' => 'region',
    'description' => 'This content types is used to create regions',
    'title_label' => 'Region navn',
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
    'language_content_type' => '0',
    'old_type' => 'region',
    'orig_type' => '',
    'module' => 'node',
    'custom' => '1',
    'modified' => '1',
    'locked' => '0',
    'nodewords_edit_metatags' => 1,
    'nodewords_metatags_generation_method' => '0',
    'nodewords_metatags_generation_source' => '2',
    'nodewords_use_alt_attribute' => 1,
    'nodewords_filter_modules_output' =>
    array (
      'imagebrowser' => false,
      'img_assist' => false,
    ),
    'nodewords_filter_regexp' => '',
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
      'menu-region-menu' => true,
      'menu-aalborg-menu' => false,
      'admin' => false,
      'menu-aarhus-menu' => false,
      'devel' => false,
      'menu-herning-menu' => false,
      'primary-links' => false,
      'navigation' => false,
      'secondary-links' => false,
      'menu-viborg-menu' => false,
    ),
  );
  $content['fields']  = array (
    0 =>
    array (
      'label' => 'Menunavn',
      'field_name' => 'field_menu_ref',
      'type' => 'text',
      'widget_type' => 'optionwidgets_select',
      'change' => 'Change basic information',
      'weight' => '-4',
      'description' => '',
      'default_value' =>
      array (
        0 =>
        array (
          'value' => '',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' => NULL,
      'group' => false,
      'required' => 1,
      'multiple' => '0',
      'text_processing' => '0',
      'max_length' => '',
      'allowed_values' => '',
      'allowed_values_php' => '$all_menus = module_invoke_all(\'get_menus\');
  asort($all_menus);
  return $all_menus;',
      'op' => 'Save field settings',
      'module' => 'text',
      'widget_module' => 'optionwidgets',
      'columns' =>
      array (
        'value' =>
        array (
          'type' => 'text',
          'size' => 'big',
          'not null' => false,
          'sortable' => true,
          'views' => true,
        ),
      ),
      'display_settings' =>
      array (
        'label' =>
        array (
          'format' => 'above',
          'exclude' => 0,
        ),
        'teaser' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        'full' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        4 =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        'token' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
      ),
    ),
    1 =>
    array (
      'label' => 'Ekstern kalender',
      'field_name' => 'field_external_calendar',
      'type' => 'link',
      'widget_type' => 'link',
      'change' => 'Change basic information',
      'weight' => '-3',
      'description' => '',
      'default_value' =>
      array (
        0 =>
        array (
          'title' => '',
          'url' => '',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' =>
      array (
        'field_external_calendar' =>
        array (
          0 =>
          array (
            'title' => '',
            'url' => '',
          ),
        ),
      ),
      'group' => false,
      'required' => 0,
      'multiple' => '0',
      'validate_url' => 1,
      'url' => 0,
      'title' => 'required',
      'title_value' => '',
      'enable_tokens' => 0,
      'display' =>
      array (
        'url_cutoff' => '80',
      ),
      'attributes' =>
      array (
        'target' => 'default',
        'rel' => 'external',
        'class' => '',
        'title' => '',
      ),
      'op' => 'Save field settings',
      'module' => 'link',
      'widget_module' => 'link',
      'columns' =>
      array (
        'url' =>
        array (
          'type' => 'varchar',
          'length' => 2048,
          'not null' => false,
          'sortable' => true,
        ),
        'title' =>
        array (
          'type' => 'varchar',
          'length' => 255,
          'not null' => false,
          'sortable' => true,
        ),
        'attributes' =>
        array (
          'type' => 'text',
          'size' => 'medium',
          'not null' => false,
        ),
      ),
      'display_settings' =>
      array (
        'label' =>
        array (
          'format' => 'above',
          'exclude' => 0,
        ),
        'teaser' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        'full' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        4 =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
        'token' =>
        array (
          'format' => 'default',
          'exclude' => 0,
        ),
      ),
    ),
  );
  $content['extra']  = array (
    'title' => '-5',
    'revision_information' => '-1',
    'author' => '2',
    'options' => '3',
    'comment_settings' => '1',
    'menu' => '-2',
    'path' => '0',
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