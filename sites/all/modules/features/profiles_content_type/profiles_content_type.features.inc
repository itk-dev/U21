<?php

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
