<?php

/**
 * Implementation of hook_user_default_roles().
 */
function pressesektion_user_default_roles() {
  $roles = array();

  // Exported role: presse
  $roles['presse'] = array(
    'name' => 'presse',
  );

  return $roles;
}
