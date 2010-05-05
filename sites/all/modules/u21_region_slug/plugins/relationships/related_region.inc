<?php // $Id$

/**
 * @file
 * Provide the region related to a node as a Panels relation.
 */

/**
 * Implementation of hook_ctools_relationships().
 */
function u21_region_slug_related_region_ctools_relationships() {
  $args = array();
  $args['related_region'] = array(
    'title' => t('Related region'),
    'keyword' => 'related_region',
    'description' => t('Finds the related region from a node context.'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'context' => 'u21_region_slug_related_region_context',
    'settings form' => 'u21_region_slug_related_region_settings_form',
  );
  return $args;
}

/**
 * Return a new context based on an existing context
 */
function u21_region_slug_related_region_context($context = NULL, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL
  if (empty($context->data)) {
    return ctools_context_create_empty('node');
  }

  if (isset($context->data->field_region_ref[0]) && $context->data->field_region_ref[0] > 0) {
    $node = node_load($context->data->field_region_ref[0]);
    if ($node) {
      return ctools_context_create('node', $node);
    }
  }
  return FALSE;
}

/**
 * Settings form for the relationship
 */
function u21_region_slug_related_region_settings_form($conf) {
  return $form;
}



