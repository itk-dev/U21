<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function mms_import_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'mms';
  $feeds_importer->config = array(
    'name' => 'MMS',
    'description' => 'Import MMS feed',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'mmsParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'photo',
        'input_format' => '0',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'text',
            'target' => 'field_message',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'images',
            'target' => 'field_photo_gallery',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'uploaded',
            'target' => 'field_user_uploaded',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'taxonomy',
            'target' => 'taxonomy:features_mms_keywords',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
      ),
    ),
    'content_type' => 'imported_mms',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['mms'] = $feeds_importer;
  return $export;
}
