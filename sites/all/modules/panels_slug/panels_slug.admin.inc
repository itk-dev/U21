<?php

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
      $changes_text[] = t('Change slug for %region from !old to !new', array(
        '%region' => $change['title'],
        '!old' => '<tt>' . check_plain($change['old_slug']) . '</tt>',
        '!new' => '<tt>' . check_plain($change['new_slug']) . '</tt>',
      ));
    }

    return confirm_form(array(), t('Please confirm these slug changes'), $_GET['q'], theme('item_list', $changes_text), t('Confirm'), t('Cancel'));
  }

  // Grab all the region nodes
  $query = db_query("SELECT node.nid, node.title, slugs.slug
                       FROM {node} AS node
                  LEFT JOIN {panels_slug} AS slugs ON (slugs.nid = node.nid)
                      WHERE node.type = 'region'
                   ORDER BY node.title");

  $existing = array();
  $form = array();

  drupal_set_message(t("Here you can edit the identifying part of a region's URL, called “slugs”. Be aware that changing the existing slugs will change the URLs too, resulting in dead links."), 'warning');

  $form['records']['#tree'] = TRUE;
  while ($row = db_fetch_object($query)) {
    $form['records'][$row->nid] = array(
      '#type' => 'textfield',
      '#title' => $row->title,
      '#default_value' => $row->slug,
    );
    // Add the existing slugs to an array, so we'll be able to detect
    // overwriting in the validation.
    if (!empty($row->slug)) {
      $existing[$row->nid] = $row->slug;
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
      db_query("UPDATE {panels_slug} SET slug = '%s' WHERE nid = %d;", $change['new_slug'], $change['nid']);
    }

    // Unset the storage, so we'll won't get the confirmation page again.
    unset($form_state['storage']);
  }
  $slug_changes = array();

  if (isset ($form_state['values']['records'])) {
    foreach ($form_state['values']['records'] as $nid => $slug) {
      if (!empty($slug)) {
        if (isset($form_state['values']['existing_slugs'][$nid]) && $form_state['values']['existing_slugs'][$nid] != $slug) {
          // Existing slug is being changed, store the changes so we can
          // create a confirmation form with it.
          $slug_changes[$nid] = array(
            'nid' => $nid,
            'title' => $form['records'][$nid]['#title'],
            'old_slug' => $form_state['values']['existing_slugs'][$nid],
            'new_slug' => panels_slug_slugify($slug),
          );
        }
        else {
          // Create a new slug.
          if (!isset($form_state['values']['existing_slugs'][$nid])) {
            db_query("INSERT INTO {panels_slug} (slug, nid) VALUES ('%s', %d)", panels_slug_slugify($slug), $nid);
          }
        }
      }
    }
  }
  // Print status message
  drupal_set_message('Slugs settings have been saved.');

  $form_state['storage']['slug_changes'] = $slug_changes;
}