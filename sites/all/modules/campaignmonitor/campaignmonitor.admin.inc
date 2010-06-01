<?php

function campaignmonitor_admin_settings_form($form_state) {
  $form = array();

  // Setup API keys
  $form['campaignmonitor_api'] = array(
    '#type' => 'fieldset',
    '#title' => t('Campaign Monitor API Settings'),
    '#tree' => TRUE,
  );

  $api_keys = variable_get('campaignmonitor_api', array());
  $form['campaignmonitor_api']['api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API key'),
    '#description' => t('The key is found under "Account settings" under the main account.'),
    '#default_value' => $api_keys['api_key'],
  );

  $form['campaignmonitor_api']['client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('API client ID'),
    '#description' => t('The ID is found under "Client settings" under the client account.'),
    '#default_value' => $api_keys['client_id'],
  );

  // Get archive link
  $form['campaignmonitor_archive'] = array(
    '#type' => 'textfield',
    '#title' => t('JavaScript archive link'),
    '#description' => t('To display a list of sent campaings, you have to go into client settings under "Create newsletter archive" and create a JavaScript link for this setting'),
    '#default_value' => variable_get('campaignmonitor_archive', ''),
  );
  
  // Get systemet form elements
 return system_settings_form($form);
}

function campaignmonitor_admin_settings_form_validate($form, &$form_state) {

  // Validate that the api key is correct
  $api_key = $form_state['values']['campaignmonitor_api']['api_key'];
  $status = _campaignmonitor_check_connection($api_key);
  if ($status != 1) {
    form_set_error('api_key', $status);
  }
  else {
    // Validate that the client id is correct
    $client_id = $form_state['values']['campaignmonitor_api']['client_id'];
    if (!_campaignmonitor_validate_client_id($api_key, $client_id)) {
      form_set_error('client_id', 'A client with that ID was not found');
    }
  }
}

function campaignmonitor_admin_lists_form($form_state) {
  
  // Clear cache and get newste lists
  cache_clear_all('lists', 'cache_campaignmonitor');
  $api_keys = variable_get('campaignmonitor_api', array());
  $lists = _campaignmonitor_get_lists($api_keys['api_key'], $api_keys['client_id']);

  $form = array();

  // Setup API keys
  $form['campaignmonitor_lists'] = array(
    '#type' => 'fieldset',
    '#title' => t('Campaign Monitor list settings'),
  );
  
  $form['campaignmonitor_lists']['campaignmonitor_selected_lists'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select the list(s) that users can subscribe to.'),
    '#required' => TRUE,
    '#options' => $lists,
    '#description' => t(''),
    '#default_value' => variable_get('campaignmonitor_selected_lists', array()),
  );

  return system_settings_form($form);
}
