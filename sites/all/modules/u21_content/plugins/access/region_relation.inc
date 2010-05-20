<?php // $Id$

/**
 * @file
 * Plugin to provide access control based upon a node's status relation
 * to a region.
 */

/**
 * Implementation of hook_ctools_access().
 */
function u21_content_region_relation_ctools_access() {
  $items = array();
  $items['region_relation'] = array(
    'title' => t('Region relation'),
    'description' => t('Control access by selection of region.'),
    'callback' => 'u21_content_region_relation_ctools_access_check',
    'default' => array('region_relation' => 'yes'),
    'settings form' => 'u21_content_region_relation_ctools_access_settings',
    'summary' => 'u21_content_region_relation_ctools_access_summary',
    'required context' => new ctools_context_required(t('Node'), 'node'),
  );
  return $items;
}

/**
 * Check for access.
 */
function u21_content_region_relation_ctools_access_check($conf, $context) {
  $selected = (isset($conf['region_relation'])) ? $conf['region_relation'] : 'yes';
  $node = $context->data;

  // If region is set on the node, we allow it to pass if the
  // selection is "yes".
  if (isset($node->field_slug_ref[0]['nid'])) {
    if ($selected == no) {
      return FALSE;
    }
    // Region is selected, so check if a specific region have been choosen
    elseif ($selected != yes) {
      if ($selected != $node->field_slug_ref[0]['nid']) {
        return FALSE;
      }
    }
  }
  else {
    if ($selected != 'no') {
      return FALSE;
    }
  }

  return TRUE;
}

/**
 * Add the type to the settings form.
 */
function u21_content_region_relation_ctools_access_settings(&$form, &$form_state, $conf) {

  // Build options based on regions
  $options = array(
    'yes' => t('Yes'),
    'no' => t('No'),
  );
  $regions = u21_content_region_relation_get_all_slugs();
  foreach ($regions as $nid => $value) {
    $options[$nid] = check_plain($value['title']). ' (' .check_plain($value['slug']). ')';
  }

  $form['settings']['region_relation'] = array(
    '#type' => 'radios',
    '#title' => t('Region relation'),
    '#options' => $options,
    '#default_value' => (isset($conf['region_relation'])) ? $conf['region_relation'] : 'yes',
    '#description' => t('Should node be related to a node to be shown.'),
  );
}

/**
 * Provide a summary description of what we checked.
 */
function u21_content_region_relation_ctools_access_summary($conf, $context) {
  $selected = (isset($conf['region_relation'])) ? $conf['region_relation'] : 'yes';
  return t('@identifier is related to region: "@selected"', array('@identifier' => $context->identifier, '@selected' => $selected));
}

/**
 * Get all slugs and corresponding node IDs
 *
 * @return array
 *    Regions title and slug indexed by node IDs.
 */
function u21_content_region_relation_get_all_slugs() {
  // Grab all the region nodes
  $query = db_query("SELECT node.nid, node.title, slugs.slug
                       FROM {node} AS node
                  LEFT JOIN {panels_slug} AS slugs ON (slugs.nid = node.nid)
                      WHERE node.type = 'region'
                   ORDER BY node.title");

  $slugs = array();
  while ($row = db_fetch_object($query)) {
    $slugs[$row->nid] = array('title' => $row->title, 'slug' => $row->slug);
  }

  return $slugs;
}