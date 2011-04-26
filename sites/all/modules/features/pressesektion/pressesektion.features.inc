<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function pressesektion_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function pressesektion_node_info() {
  $items = array(
    'press_section' => array(
      'name' => t('Pressemateriale'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Overskrift'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
