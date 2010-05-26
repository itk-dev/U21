<?php

/**
 * Implementation of hook_ctools_arguments().
 */
function panels_slug_panels_slug_ctools_arguments() {
  $args = array();
  $args['panels_slug'] = array(
    'title' => t('Panels slug'),
    'keyword' => 'node',
    'description' => t('Finds the node context based on the "slug" name for it.'),
    'context' => 'panels_slug_context',
  );
  return $args;
}

/**
 * Lookup an argument to see if it corresponds to a region.
 */
function panels_slug_context($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if ($empty) {
    return ctools_context_create_empty('node');
  }

  // We can accept either a node object or a pure nid.
  if (is_object($arg)) {
    return ctools_context_create('node', $arg);
  }

  // Cast argument to an integer to see if it looks like a node ID.
  $num = intval($arg);
  if (is_numeric($num) && $num > 0) {
    $nid = $num;
  }
  // Try looking up the argument as a slug
  elseif (strlen($arg) > 1) {
    $nid = db_result(db_query("SELECT nid FROM {panels_slug} WHERE slug='%s'", $arg));
  }
  else {
    return FALSE;
  }

  if (!$nid || !is_numeric($nid)) {
    return FALSE;
  }

  $node = node_load($nid);
  if (!$node) {
    return FALSE;
  }

  return ctools_context_create('node', $node);
}
