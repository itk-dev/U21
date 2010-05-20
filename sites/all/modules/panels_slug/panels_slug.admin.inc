<?php


function panels_slug_get_all_slugs_for_type($type) {
  $query = db_query('SELECT node.nid, node.title, slugs.slug
                       FROM {node} AS node
                  LEFT JOIN {panels_slug} AS slugs ON (slugs.nid = node.nid)
                      WHERE node.type = \'%s\'
                   ORDER BY node.title', array($type));
  
  $slugs = array();
  while ($row = db_fetch_object($query)) {
    array_push($slugs, $row);
  }

  return $slugs;
}

/**
 * Region slug editing form.
 */
function panels_slug_admin_settings_form(&$form_state) {
  // Confirmation form for changing existing slugs. The storage array
  // is set by the submit handler, and as long as it is non-empty, we're
  // returned to the form.
  if (!empty($form_state['storage']['slug_changes'])) {
    $changes_text = array();
    foreach ($form_state['storage']['slug_changes'] as $change) {
      $changes_text[] = t('Change slug for %node from !old to !new', array(
        '%node' => $change['title'],
        '!old' => '<tt>' . check_plain($change['old_slug']) . '</tt>',
        '!new' => '<tt>' . check_plain($change['new_slug']) . '</tt>',
      ));
    }

    return confirm_form(array(), t('Please confirm these slug changes'), $_GET['q'], theme('item_list', $changes_text), t('Confirm'), t('Cancel'));
  }

  $form = array();
  $existing = array();

  $form['records']['#tree'] = TRUE;

  // Get selected content-types an group slugs base on type
  $types = array_filter(variable_get('panels_slug_selected_node_types', array()));
  
  foreach ($types as $type) {
    $slugs = panels_slug_get_all_slugs_for_type($type);
    $form['records'][$type] = array(
      '#type' => 'fieldset',
      '#title' => check_plain($type),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    foreach ($slugs as $slug) {
      $form['records'][$type][$slug->nid] = array(
        '#type' => 'textfield',
        '#title' => $slug->title,
        '#default_value' => $slug->slug,
      );
      // Add the existing slugs to an array, so we'll be able to detect
      // overwriting in the validation.
      if (!empty($slug->slug)) {
        $existing[$slug->nid] = $slug->slug;
      }
    }
  }

  $form['existing_slugs'] = array(
    '#type' => 'value',
    '#value' => $existing,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
  );
  
  drupal_set_message(t("Here you can edit the identifying part of am URL, called “slug”. Be aware that changing the an existing slug will change the URLs too, resulting in dead links."), 'warning', FALSE);

  return $form;
}

/**
 * Submit handler for the slug editing form.
 */
function panels_slug_admin_settings_form_submit($form, &$form_state) {
  // If the there's slug changes in the storage array, it means that
  // we've been through the confirmation form, and should now proceeed
  // to change the slugs in the database.
  if (isset($form_state['storage']['slug_changes'])) {
    foreach ($form_state['storage']['slug_changes'] as $change) {
      db_query("UPDATE {panels_slug} SET slug = '%s', nodetype = '%s' WHERE nid = %d;", $change['new_slug'], $change['type'], $change['nid']);
    }

    // Unset the storage, so we'll won't get the confirmation page again.
    unset($form_state['storage']);
  }
  $slug_changes = array();

  // Get selected content-types an group slugs base on type
  $types = array_filter(variable_get('panels_slug_selected_node_types', array()));

  // Save slugs for each type
  foreach ($types as $type) {
    if (isset ($form_state['values']['records'][$type])) {
      foreach ($form_state['values']['records'][$type] as $nid => $slug) {
        if (!empty($slug)) {
          if (isset($form_state['values']['existing_slugs'][$nid]) && $form_state['values']['existing_slugs'][$nid] != $slug) {
            // Existing slug is being changed, store the changes so we can
            // create a confirmation form with it.
            $slug_changes[$nid] = array(
              'nid' => $nid,
              'type' => $type,
              'title' => $form['records'][$nid]['#title'],
              'old_slug' => $form_state['values']['existing_slugs'][$nid],
              'new_slug' => panels_slug_slugify($slug),
            );
          }
          else {
            // Create a new slug.
            if (!isset($form_state['values']['existing_slugs'][$nid])) {
              db_query("INSERT INTO {panels_slug} (slug, nid, nodetype) VALUES ('%s', %d, '%s')", panels_slug_slugify($slug), $nid, $type);
            }
          }
        }
      }
    }
  }

  // Print status message
  if (empty($slug_changes)) {
    drupal_set_message('Slugs settings have been saved.');
  }
  
  $form_state['storage']['slug_changes'] = $slug_changes;
}

/**
 * Admin form to select content type and define path prefix for the
 * select types.
 *
 * @param array $form_state
 * @return string
 */
function panels_slug_build_settings_form(&$form_state) {

  // Grab all node types
  $options = array();
  $types = node_get_types();
  foreach ($types as $key => $obj) {
    $options[$key] = $obj->name. ' (' .t($obj->description). ')';
  }

  $form['node_types']['panels_slug_selected_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Which content types should use panel slugs'),
    '#required' => TRUE,
    '#options' => $options,
    '#description' => t('The content types selected, will be available at admin/content/slugs'),
    '#default_value' => variable_get('panels_slug_selected_node_types', array()),
  );

  $form['path_prefix'] = array(
    '#type' => 'fieldset',
    '#title' => t('Path prefix for selected content types (e.i using news content type to have news both inside slug path and outside)'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  foreach ($types as $key => $obj) {
    $form['path_prefix']['panels_slug_' .$key. '_path_prefix'] = array(
      '#type' => 'textfield',
      '#title' => t('@type path prefix', array('@type' => $obj->name)),
      '#default_value' => variable_get('panels_slug_' .$key. '_path_prefix', ''),
    );
  }

  return system_settings_form($form);
}