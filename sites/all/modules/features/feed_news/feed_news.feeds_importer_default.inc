<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function feed_news_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'meltwater_news';
  $feeds_importer->config = array(
    'name' => 'Meltwater News',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'feed_news',
        'input_format' => '1',
        'update_existing' => '0',
        'expire' => '2419200',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'field_content',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'url',
            'target' => 'field_links:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'author' => 0,
      ),
    ),
    'content_type' => 'feed_imported',
    'update' => 0,
    'import_period' => '3600',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['meltwater_news'] = $feeds_importer;
  return $export;
}
