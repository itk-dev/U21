<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function profiles_content_type_imagecache_default_presets() {
  $items = array(
    'profile_image' => array(
      'presetname' => 'profile_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '460px',
            'height' => '225px',
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
function profiles_content_type_node_info() {
  $items = array(
    'profile' => array(
      'name' => t('Profil'),
      'module' => 'features',
      'description' => t('Præsentation af spiller- og trænerprofiler'),
      'has_title' => '1',
      'title_label' => t('Navn'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
