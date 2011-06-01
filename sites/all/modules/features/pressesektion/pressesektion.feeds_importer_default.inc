<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function pressesektion_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'create_press_users';
  $feeds_importer->config = array(
    'name' => 'Press users',
    'description' => 'Automatisk oprettelse af akkrediterede pressebrugere på u21em.dk fra excel',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ';',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          8 => 8,
          3 => 0,
          7 => 0,
          6 => 0,
          9 => 0,
          4 => 0,
          5 => 0,
        ),
        'update_existing' => 0,
        'status' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'brugernavn',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'email',
            'target' => 'mail',
            'unique' => 0,
          ),
        ),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['create_press_users'] = $feeds_importer;
  return $export;
}
