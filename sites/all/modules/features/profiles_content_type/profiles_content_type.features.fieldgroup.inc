<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function profiles_content_type_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_faktaboks
  $groups['profile-group_faktaboks'] = array(
    'group_type' => 'standard',
    'type_name' => 'profile',
    'group_name' => 'group_faktaboks',
    'label' => 'Faktaboks',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'nodeasblock teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'nodeasblock full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '3',
    'fields' => array(
      '0' => 'field_profile_position',
      '1' => 'field_profile_current_club',
      '2' => 'field_profile_weight',
      '3' => 'field_profile_height',
      '4' => 'field_profile_birth',
      '5' => 'field_profile_clubs',
      '6' => 'field_profile_teams',
    ),
  );

  // Exported group: group_lineup
  $groups['profile-group_lineup'] = array(
    'group_type' => 'standard',
    'type_name' => 'profile',
    'group_name' => 'group_lineup',
    'label' => 'Holdoversigt',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'nodeasblock teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'nodeasblock full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '5',
    'fields' => array(
      '0' => 'field_profilepos_x',
      '1' => 'field_profilepos_y',
      '2' => 'field_profile_shirtname',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Faktaboks');
  t('Holdoversigt');

  return $groups;
}
