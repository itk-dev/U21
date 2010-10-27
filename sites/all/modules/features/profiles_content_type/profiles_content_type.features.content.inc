<?php

/**
 * Implementation of hook_content_default_fields().
 */
function profiles_content_type_content_default_fields() {
  $fields = array();

  // Exported field: field_profile_birth
  $fields['profile-field_profile_birth'] = array(
    'field_name' => 'field_profile_birth',
    'type_name' => 'profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'date_only_long',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'blank',
      'default_value_code2' => '',
      'input_format' => 'j M Y - H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Født',
      'weight' => '12',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_profile_clubs
  $fields['profile-field_profile_clubs'] = array(
    'field_name' => 'field_profile_clubs',
    'type_name' => 'profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '3',
          '_error_element' => 'default_value_widget][field_profile_clubs][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Klubber',
      'weight' => '13',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_height
  $fields['profile-field_profile_height'] = array(
    'field_name' => 'field_profile_height',
    'type_name' => 'profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_decimal',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => 'cm',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'precision' => '10',
    'scale' => '1',
    'decimal' => ',',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_height][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Højde',
      'weight' => '10',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_profile_position
  $fields['profile-field_profile_position'] = array(
    'field_name' => 'field_profile_position',
    'type_name' => 'profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'Målmand
Forsvar
Wing
Defensiv Midtbane
Midtbane
Offensiv Midtbane
Angriber',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Position',
      'weight' => '9',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_profile_teams
  $fields['profile-field_profile_teams'] = array(
    'field_name' => 'field_profile_teams',
    'type_name' => 'profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '3',
          '_error_element' => 'default_value_widget][field_profile_teams][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Landshold',
      'weight' => '14',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_profile_weight
  $fields['profile-field_profile_weight'] = array(
    'field_name' => 'field_profile_weight',
    'type_name' => 'profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_decimal',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => 'Kg',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'precision' => '10',
    'scale' => '1',
    'decimal' => '.',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profile_weight][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Vægt',
      'weight' => '11',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_profilephoto
  $fields['profile-field_profilephoto'] = array(
    'field_name' => 'field_profilephoto',
    'type_name' => 'profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'imceimage',
    'required' => '1',
    'multiple' => '0',
    'module' => 'imceimage',
    'active' => '1',
    'imceimage_file_types' => 'png,gif,jpg,jpeg',
    'semantic_cck_use_semantic_output' => 1,
    'semantic_cck_field_element' => 'div',
    'semantic_cck_field_class' => 'title-image',
    'semantic_cck_label_element_above' => 'h3',
    'semantic_cck_label_class_above' => '',
    'semantic_cck_label_class_inline' => '',
    'semantic_cck_label_suffix_above' => '',
    'semantic_cck_label_suffix_inline' => ':',
    'semantic_cck_label_element_inline' => 'span',
    'semantic_cck_multiple_items_element' => '',
    'semantic_cck_multiple_items_class' => '',
    'semantic_cck_multiple_item_element' => '',
    'semantic_cck_multiple_item_class' => '',
    'semantic_cck_use_singlevalue_settings' => 0,
    'semantic_cck_single_item_element' => '',
    'semantic_cck_single_item_class' => '',
    'semantic_cck_last_every_nth' => '0',
    'semantic_cck_first_class' => 'first',
    'semantic_cck_last_class' => 'last',
    'semantic_cck_striping_classes' => '',
    'widget' => array(
      'imceimage_file_types' => 'png,gif,jpg,jpeg',
      'default_value' => array(
        '0' => array(
          'imceimage_path' => '',
          'imceimage_width' => '',
          'imceimage_height' => '',
          'imceimage_alt' => '',
        ),
      ),
      'default_value_php' => NULL,
      'semantic_cck_use_semantic_instance' => 0,
      'label' => 'Profilbillede',
      'weight' => '-4',
      'description' => 'Profilfoto af spillerprofilen. Billedet vises øverst på profilsiderne.',
      'type' => 'imceimage',
      'module' => 'imceimage',
    ),
  );

  // Exported field: field_profilesecondary
  $fields['profile-field_profilesecondary'] = array(
    'field_name' => 'field_profilesecondary',
    'type_name' => 'profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_profilesecondary][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Bag om profilen',
      'weight' => '-2',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_profiletext
  $fields['profile-field_profiletext'] = array(
    'field_name' => 'field_profiletext',
    'type_name' => 'profile',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'nodeasblock full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'semantic_cck_use_semantic_output' => 1,
    'semantic_cck_field_element' => '',
    'semantic_cck_field_class' => '',
    'semantic_cck_label_element_above' => 'h3',
    'semantic_cck_label_class_above' => '',
    'semantic_cck_label_class_inline' => '',
    'semantic_cck_label_suffix_above' => '',
    'semantic_cck_label_suffix_inline' => ':',
    'semantic_cck_label_element_inline' => 'span',
    'semantic_cck_multiple_items_element' => '',
    'semantic_cck_multiple_items_class' => '',
    'semantic_cck_multiple_item_element' => '',
    'semantic_cck_multiple_item_class' => '',
    'semantic_cck_use_singlevalue_settings' => 1,
    'semantic_cck_single_item_element' => '',
    'semantic_cck_single_item_class' => '',
    'semantic_cck_last_every_nth' => '0',
    'semantic_cck_first_class' => '',
    'semantic_cck_last_class' => '',
    'semantic_cck_striping_classes' => '',
    'widget' => array(
      'rows' => '15',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '3',
          '_error_element' => 'default_value_widget][field_profiletext][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'semantic_cck_use_semantic_instance' => 0,
      'label' => 'Spillerprofil',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bag om profilen');
  t('Født');
  t('Højde');
  t('Klubber');
  t('Landshold');
  t('Position');
  t('Profilbillede');
  t('Spillerprofil');
  t('Vægt');

  return $fields;
}
