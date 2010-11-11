<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function profiles_content_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: view field_profile_birth
  $permissions['view field_profile_birth'] = array(
    'name' => 'view field_profile_birth',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_profile_clubs
  $permissions['view field_profile_clubs'] = array(
    'name' => 'view field_profile_clubs',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_profile_current_club
  $permissions['view field_profile_current_club'] = array(
    'name' => 'view field_profile_current_club',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_profile_height
  $permissions['view field_profile_height'] = array(
    'name' => 'view field_profile_height',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_profile_position
  $permissions['view field_profile_position'] = array(
    'name' => 'view field_profile_position',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_profile_teams
  $permissions['view field_profile_teams'] = array(
    'name' => 'view field_profile_teams',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_profile_weight
  $permissions['view field_profile_weight'] = array(
    'name' => 'view field_profile_weight',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_profilephoto
  $permissions['view field_profilephoto'] = array(
    'name' => 'view field_profilephoto',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_profilesecondary
  $permissions['view field_profilesecondary'] = array(
    'name' => 'view field_profilesecondary',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_profiletext
  $permissions['view field_profiletext'] = array(
    'name' => 'view field_profiletext',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_promote
  $permissions['view field_promote'] = array(
    'name' => 'view field_promote',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
