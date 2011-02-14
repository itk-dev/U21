<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function u21_photo_upload_admin_imagecache_default_presets() {
  $items = array(
    'u21_fotos_admin' => array(
      'presetname' => 'u21_fotos_admin',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '220',
            'height' => '220',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function u21_photo_upload_admin_views_api() {
  return array(
    'api' => '2',
  );
}
