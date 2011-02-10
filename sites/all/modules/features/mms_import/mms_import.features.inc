<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mms_import_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function mms_import_imagecache_default_presets() {
  $items = array(
    'photo_gallery' => array(
      'presetname' => 'photo_gallery',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '400',
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
function mms_import_node_info() {
  $items = array(
    'imported_mms' => array(
      'name' => t('Imported MMS'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'photo' => array(
      'name' => t('Foto'),
      'module' => 'features',
      'description' => t('Fotos i mediagalleri / nyhedsside'),
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
