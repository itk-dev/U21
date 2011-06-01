<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function profiles_content_type_taxonomy_default_vocabularies() {
  return array(
    'team' => array(
      'name' => 'National Teams',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '1',
      'tags' => '0',
      'module' => 'features_team',
      'weight' => '0',
      'nodes' => array(
        'profile' => 'profile',
      ),
    ),
  );
}
