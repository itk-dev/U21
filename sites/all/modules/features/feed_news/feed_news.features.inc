<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function feed_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function feed_news_node_info() {
  $items = array(
    'feed_imported' => array(
      'name' => t('Imported Feed'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'feed_news' => array(
      'name' => t('Feed News'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function feed_news_views_api() {
  return array(
    'api' => '2',
  );
}
