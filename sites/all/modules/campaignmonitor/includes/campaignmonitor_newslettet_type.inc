<?php

function _campaignmonitor_newsletter_content_types_import() {
  $content = array();
  $content['type']  = array (
    'name' => 'Nyhedsbrev',
    'type' => 'newsletter',
    'description' => 'E-mail nyhedsbrev udsendt via Campaignmonitor (blive automatisk oprettet).',
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
    'old_type' => 'newsletter',
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
      'menu-aalborg-menu' => false,
      'admin' => false,
      'menu-aarhus-menu' => false,
      'menu-herning-menu' => false,
      'primary-links' => false,
      'navigation' => false,
      'menu-region-menu' => false,
      'secondary-links' => false,
      'menu-viborg-menu' => false,
    ),
  );
  $content['fields']  = array (
    0 =>
    array (
      'label' => 'Dato',
      'field_name' => 'field_news_date',
      'type' => 'date',
      'widget_type' => 'date_popup',
      'change' => 'Change basic information',
      'weight' => '-4',
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'input_format' => 'd/m/Y',
      'input_format_custom' => '',
      'year_range' => '-3:+3',
      'increment' => '1',
      'advanced' =>
      array (
        'label_position' => 'above',
        'text_parts' =>
        array (
          'year' => 0,
          'month' => 0,
          'day' => 0,
          'hour' => 0,
          'minute' => 0,
          'second' => 0,
        ),
      ),
      'label_position' => 'above',
      'text_parts' =>
      array (
      ),
      'description' => '',
      'group' => false,
      'required' => 1,
      'multiple' => '0',
      'repeat' => 0,
      'todate' => '',
      'granularity' =>
      array (
        'year' => 'year',
        'month' => 'month',
        'day' => 'day',
      ),
      'default_format' => 'medium',
      'tz_handling' => 'none',
      'timezone_db' => '',
      'op' => 'Save field settings',
      'module' => 'date',
      'widget_module' => 'date',
      'columns' =>
      array (
        'value' =>
        array (
          'type' => 'varchar',
          'length' => 20,
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
      'label' => 'Sideindhold',
      'field_name' => 'field_content',
      'type' => 'text',
      'widget_type' => 'text_textarea',
      'change' => 'Change basic information',
      'weight' => '-3',
      'rows' => '5',
      'size' => 60,
      'description' => '',
      'default_value' =>
      array (
        0 =>
        array (
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_content][0][value',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' =>
      array (
        'field_content' =>
        array (
          0 =>
          array (
            'value' => '',
            'format' => '1',
            '_error_element' => 'default_value_widget][field_content][0][value',
          ),
        ),
      ),
      'group' => false,
      'required' => 1,
      'multiple' => '0',
      'text_processing' => '1',
      'max_length' => '',
      'allowed_values' => '',
      'allowed_values_php' => '',
      'op' => 'Save field settings',
      'module' => 'text',
      'widget_module' => 'text',
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
        'format' =>
        array (
          'type' => 'int',
          'unsigned' => true,
          'not null' => false,
          'views' => false,
        ),
      ),
      'display_settings' =>
      array (
        'weight' => '-4',
        'parent' => '',
        'label' =>
        array (
          'format' => 'above',
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
    2 =>
    array (
      'label' => 'Link',
      'field_name' => 'field_email_view',
      'type' => 'text',
      'widget_type' => 'text_textfield',
      'change' => 'Change basic information',
      'weight' => '-2',
      'rows' => 5,
      'size' => '60',
      'description' => '',
      'default_value' =>
      array (
        0 =>
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_email_view][0][value',
        ),
      ),
      'default_value_php' => '',
      'default_value_widget' =>
      array (
        'field_email_view' =>
        array (
          0 =>
          array (
            'value' => '',
            '_error_element' => 'default_value_widget][field_email_view][0][value',
          ),
        ),
      ),
      'group' => false,
      'required' => 1,
      'multiple' => '0',
      'text_processing' => '0',
      'max_length' => '',
      'allowed_values' => '',
      'allowed_values_php' => '',
      'op' => 'Save field settings',
      'module' => 'text',
      'widget_module' => 'text',
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
  );
  $content['extra']  = array (
    'title' => '-5',
    'revision_information' => '0',
    'comment_settings' => '2',
    'menu' => '-1',
    'path' => '1',
  );

  return $content;
}

/**
 * Install the newsletter content types.
 *
 */
function campaignmonitor_content_type_install() {
  // Get CCK content.
  $content = _campaignmonitor_newsletter_content_types_import();

  // CCK content_copy.module may not be enabled, so make sure it is included.
  include_once './' . drupal_get_path('module', 'content') . '/modules/content_copy/content_copy.module';

  $form_state['values']['type_name'] = '<create>';
  $form_state['values']['macro'] = '$content = ' . var_export(_campaignmonitor_newsletter_content_types_import(), TRUE) . ';';

  // Form provided by content_copy.module
  drupal_execute('content_copy_import_form', $form_state);

  content_clear_type_cache();
}

function campaignmonitor_content_type_uninstall() {
  node_type_delete('newsletter');
}
