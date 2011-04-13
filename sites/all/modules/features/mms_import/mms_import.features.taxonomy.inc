<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function mms_import_taxonomy_default_vocabularies() {
  return array(
    'mms_keywords' => array(
      'name' => 'MMS Keywords',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_mms_keywords',
      'weight' => '0',
      'nodes' => array(
        'photo' => 'photo',
      ),
    ),
  );
}
