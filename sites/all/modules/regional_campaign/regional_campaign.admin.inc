<?php

// $Id$

/**
 * @file
 * Administration page callbacks for the XML export module
 */

/**
 * Form builder. Configure regional campaign
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function regional_campaign_admin_settings(&$form_state) {

  // Wrapper for types and more button
  $form['regional_campaign_type'] = array(
    '#tree' => FALSE,
    '#weight' => -4,
    '#prefix' => '<div class="clear-block" id="regional-campaign-type-wrapper">',
    '#suffix' => '</div>',
  );

  // Container for just the types
  $form['regional_campaign_type']['type'] = array(
      '#prefix' => '<div id="regional-campaign-types">',
      '#suffix' => '</div>',
      '#theme' => 'regional_campaign_types',
  );

  // Insert types
  if (isset($form_state['type_count'])) {
    for ($delta = 0; $delta < $form_state['type_count']; $delta++) {
      $text = isset($form_state['values']['type'][$delta]['bntext']) ? $form_state['values']['type'][$delta]['bntext'] : '';
      $count = isset($form_state['values']['type'][$delta]['bncount']) ? $form_state['values']['type'][$delta]['bncount'] : '';
      $form['regional_campaign_type']['type'][$delta] = _regional_campaign_type_form_element($delta, $text, $count, $form_state['values']['type'][$delta]['bnhidden']);
    }
  }
  else {
    // Load types
    $types = variable_get(REGIONAL_CAMPAIGN_SETTINGS_TYPE, array());
    
    // If non found set one empty
    if (count($types)) {
      $delta = 0;
      foreach ($types as $text => $count) {
        $form['regional_campaign_type']['type'][$delta] = _regional_campaign_type_form_element($delta, $text, $count, $text);
        $delta++;
      }
    }
    else {
      $form['regional_campaign_type']['type'][$delta] = _regional_campaign_type_form_element(0, '', '', '');
    }
  }

  // We name our button 'poll_more' to avoid conflicts with other modules using
  // AHAH-enabled buttons with the id 'more'.
  $form['regional_campaign_type']['type_more'] = array(
      '#type' => 'submit',
      '#value' => t('More types'),
      '#description' => t("If the amount of boxes above isn't enough, click here to add more types."),
      '#submit' => array('regional_campaign_more_types_submit'), // If no javascript action.
      '#ahah' => array(
        'path' => 'admin/content/regional_campaign/js',
        'wrapper' => 'regional-campaign-types',
        'effect' => 'fade',
      ),
  );

  // Submit button
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
  );

  // Validation function
  $form['#validate'][] = 'regional_campaign_admin_form_validate';
  $form['#submit'][] = 'regional_campaign_admin_form_submit';

  return $form;
}

/**
 * Submit handler to add more types to a campaign types form.
 */
function regional_campaign_more_types_submit($form, &$form_state) {
  // Make the changes we want to the form state.
  if ($form_state['values']['type_more']) {
    $n = $_GET['q'] == 'admin/content/regional_campaign/js' ? 1 : 5;
    $form_state['type_count'] = count($form_state['values']['type']) + $n;
  }
}

/**
 * Builds the form element to wrap a single type.
 *
 * @param int $delta
 * @param string $text
 * @param string $count
 * @param string $old
 * @return array form
 */
function _regional_campaign_type_form_element($delta, $text, $count, $old) {
  
  $form = array(
    '#tree' => TRUE,
  );

  $form['type_wrapper'] = array(
      '#prefix' => '<div id="regional-campaign-types">',
      '#suffix' => '</div>',
  );

  // We'll manually set the #parents property of these fields so that
  // their values appear in the $form_state['values']['type'] array.
  $form['type_wrapper']['bntext'] = array(
    '#type' => 'textfield',
    '#title' => t('Type @n', array('@n' => ($delta + 1))),
    '#default_value' => $text,
    '#parents' => array('type', $delta, 'bntext')
  );

  $form['type_wrapper']['bncount'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of campaign\'s for type @n', array('@n' => ($delta + 1))),
      '#default_value' => $count,
      '#size' => 5,
      '#maxlength' => 7,
      '#parents' => array('type', $delta, 'bncount'),
  );

  $form['type_wrapper']['bnhidden'] = array(
      '#type' => 'hidden',
      '#default_value' => $old,
      '#parents' => array('type', $delta, 'bnhidden'),
  );

  return $form;
}

/**
 * Javascript callback function for adding more types.
 */
function regional_campaign_types_js() {
  $form_state = array('storage' => NULL, 'submitted' => FALSE);
  $form_build_id = $_POST['form_build_id'];
  // Get the form from the cache.
  $form = form_get_cache($form_build_id, $form_state);
  $args = $form['#parameters'];
  $form_id = array_shift($args);
  // We will run some of the submit handlers so we need to disable redirecting.
  $form['#redirect'] = FALSE;
  // We need to process the form, prepare for that by setting a few internals
  // variables.
  $form['#post'] = $_POST;
  $form['#programmed'] = FALSE;
  $form_state['post'] = $_POST;
  // Build, validate and if possible, submit the form.
  drupal_process_form($form_id, $form, $form_state);
  // This call recreates the form relying solely on the form_state that the
  // drupal_process_form set up.
  $form = drupal_rebuild_form($form_id, $form_state, $args, $form_build_id);
  // Render the new output.
  $type_form = $form['regional_campaign_type']['type'];
  unset($type_form['#prefix'], $type_form['#suffix']); // Prevent duplicate wrappers.
  $output = theme('status_messages') . drupal_render($type_form);

  drupal_json(array('status' => TRUE, 'data' => $output));
}

/**
 * Implementation of form validation. If the form validates it's automatically saved
 *
 * @param array $form
 * @param array $form_state
 */
function regional_campaign_admin_form_validate($form, &$form_state) {
  $err = array();
  
  // If any errors, display them
  foreach ($err as $error) {
    form_set_error('regional-campaign-admin-settings', $error);
  }
}

/**
 * Submit handler for system configuration of campaign types.
 *
 * @param array $form
 * @param array $form_state
 */
function regional_campaign_admin_form_submit($form, &$form_state) {
  $op = isset($form_state['values']['op']) ? $form_state['values']['op'] : '';

  // Exclude unnecessary elements.
  unset($form_state['values']['submit'], $form_state['values']['reset'], $form_state['values']['form_id'], $form_state['values']['op'], $form_state['values']['form_token'], $form_state['values']['form_build_id']);

  // Handel types
  $types = array();
  foreach ($form_state['values']['type'] as $key => $value) {
    $text = $value['bntext'];
    $count = ($value['bncount'] != '') ? $value['bncount'] : 0;
    if ($text != '') {
      $types[$text] = $count;
      if ($value['bnhidden'] != $text) {
        _regional_campaign_update_name($value['bnhidden'], $text);
      }
    }
  }
  variable_set(REGIONAL_CAMPAIGN_SETTINGS_TYPE, $types);

  // Set return message
  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Updates the campaigns with the name type, if any exists with the old type.
 *
 * @param string $old
 * @param string $new
 */
function _regional_campaign_update_name($old, $new) {
  $result = db_query('UPDATE {content_type_regional_campaign}
                      SET field_campaign_type_value = \'%s\'
                      WHERE field_campaign_type_value = \'%s\'', $new, $old);
}