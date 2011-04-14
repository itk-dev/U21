<?php

function mms_calback_admin_form()  {
  $form = array(
    '#tree' => TRUE
  );

  $default = variable_get('mms_callback', array());
  $form['mms_callback']['path'] = array(
    '#type' => 'textfield',
    '#title' => 'Image upload path',
    '#description' => 'The path to download images to form the MMS gateway.',
    '#default_value' => isset($default['path']) ? $default['path'] : '',
  );

  // Time
  $form['mms_callback']['time'] = array(
    '#type' => 'textfield',
    '#title' => 'MMS time',
    '#description' => 'The number of seconds back in time that a MMS should be shown in the feed.',
    '#default_value' => isset($default['time']) ? $default['time'] : '4200',
  );

  // Callback url (sms gateway)
  $form['mms_callback']['gateway'] = array(
    '#type' => 'textfield',
    '#title' => 'SMS gateway',
    '#description' => 'The callback url used to answear MMS\'s.',
    '#default_value' => isset($default['gateway']) ? $default['gateway'] : 'http://www.smssys.dk/?user=U21+Denmark&pass=2866',
  );

  // Taxonomy to use
  $options = array();
  $vocabs = taxonomy_get_vocabularies();
  foreach ($vocabs as $vocab) {
    $options[$vocab->vid] = $vocab->name;
  }
  
  $form['mms_callback']['vocabulary'] = array(
    '#type' => 'select',
    '#title' => t('Keywords'),
    '#description' => t('The vocabulary to match secound keyword against.'),
    '#options' => $options,
    '#default_value' => isset($default['vocabulary']) ? $default['vocabulary'] : $options[0],
  );

  return system_settings_form($form);
}

function mms_calback_message_form()  {
  $form = array(
    '#tree' => TRUE,
  );

  // Load settings
  $settings = variable_get('mms_callback', array());
  if (empty($settings)) {
    drupal_set_message(t('You have not yet configured "MMS Callback". Click <a href="@link">here</a> to configure it.',
            array('@link' => url('admin/settings/mms'))));
    return $form;
  }

  // Load defaults
  $default = variable_get('mms_callback_messages', array());

  $form['mms_callback_messages']['default_msg'] = array(
    '#type' => 'textfield',
    '#title' => 'Default message',
    '#description' => 'Enter the message the send back to the user on repection as default',
    '#default_value' => isset($default['default_msg']) ? $default['default_msg'] : '',
  );

  $terms = taxonomy_get_tree($settings['vocabulary']);
  foreach ($terms as $term) {
    $form['mms_callback_messages'][$term->name] = array(
      '#type' => 'textfield',
      '#title' => 'Message for keyword (' .  check_plain($term->name) . ')',
      '#description' => 'Enter the message the send back to the user on repection of the keyword',
      '#default_value' => isset($default[$term->name]) ? $default[$term->name] : '',
    );
  }
  
  return system_settings_form($form);
}
