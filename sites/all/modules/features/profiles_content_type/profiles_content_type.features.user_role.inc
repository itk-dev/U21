<?php

/**
 * Implementation of hook_user_default_roles().
 */
function profiles_content_type_user_default_roles() {
  $roles = array();

  // Exported role: profil
  $roles['profil'] = array(
    'name' => 'profil',
  );

  return $roles;
}
