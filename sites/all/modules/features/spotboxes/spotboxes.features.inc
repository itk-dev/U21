<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function spotboxes_imagecache_default_presets() {
  $items = array(
    'spotbox_blockimage' => array(
      'presetname' => 'spotbox_blockimage',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '300',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function spotboxes_node_info() {
  $items = array(
    'spotbox' => array(
      'name' => t('Spotbox'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
function spotboxes_views_api() {
  return array(
    'api' => '2',
  );
}
