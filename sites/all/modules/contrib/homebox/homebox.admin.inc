<?php
// $Id: homebox.admin.inc,v 1.1.2.6 2010/04/30 09:13:31 jchatard Exp $

/**
 * @file
 * Home box admin file, takes care admin interface for homebox
 *
 * Defines home box pages, default layout, settings
 */

function homebox_admin_page() {
  $pid = arg(4);
  if ($pid) {
    // Display the edit page form.
    $page = db_fetch_object(db_query('SELECT * FROM {homebox_pages} WHERE pid = %d', $pid));
    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Page name'),
      '#default_value' => $page->name,
      '#size' => 30,
      '#required' => TRUE,
      '#maxlength' => 64,
      '#description' => t('The name for this page. Example: "dashboard", "editorial board", "site administrator".'),
    );

    // Path alias
    if (module_exists('path')) {
      $path = db_fetch_object(db_query("SELECT pid, dst FROM {url_alias} WHERE src = 'homebox/%d'", arg(4)));

      $form['path'] = array(
        '#type' => 'fieldset',
        '#title' => t('URL path settings'),
        '#collapsible' => TRUE,
        '#collapsed' => is_null($path),
        '#access' => user_access('create url aliases'),
        '#weight' => 1,
      );
      $form['path']['path'] = array(
        '#type' => 'textfield',
        '#default_value' => $path->dst,
        '#maxlength' => 128,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#description' => t('Optionally specify an alternative URL by which this page can be accessed. For example, type "dashboard" when creating a Dashboard page. Use a relative path and don\'t add a trailing slash or the URL alias won\'t work.'),
      );
      if ($path) {
        $form['path']['pid'] = array(
          '#type' => 'value',
          '#value' => $path->pid,
        );
      }
    }
    else {
      $form['path_module'] = array(
        '#value' => '<p>'. t('If you had the Path module enabled, you could specify an URL alias for that page.') .'</p>',
      );
    }

    $form['pid'] = array(
      '#type' => 'value',
      '#value' => $pid,
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save page'),
      '#weight' => 2,
    );
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete page'),
      '#weight' => 3,
    );
  }
  else {
    $form['name'] = array(
      '#type' => 'textfield',
      '#size' => 32,
      '#maxlength' => 64,
      '#prefix' => theme('advanced_help_topic', 'homebox', 'new-page'),
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Add page'),
    );
    $form['#submit'][] = 'homebox_admin_page_submit';
    $form['#validate'][] = 'homebox_admin_page_validate';
  }
  return $form;
}

/**
 * Theme the new-page form.
 *
 * @ingroup themeable
 */
function theme_homebox_admin_new_page($form) {

  $pages = homebox_pages();

  $header = array(t('Name'), array('data' => t('Operations'), 'colspan' => 3));
  if (is_array($pages) && !empty($pages)) {
    foreach ($pages as $page) {
      $layout = l(t('layout'), 'admin/build/homebox/layout/'. $page->pid);
      $settings = l(t('settings'), 'admin/build/homebox/settings/'. $page->pid);
      $rows[] = array(l($page->name, 'homebox/'. $page->pid), l(t('edit'), 'admin/build/homebox/edit/'. $page->pid), $layout, $settings);
    }
  }
  $rows[] = array(drupal_render($form['name']), array('data' => drupal_render($form['submit']), 'colspan' => 3));

  $output = drupal_render($form);
  $output .= theme('table', $header, $rows);

  return $output;
}

function homebox_admin_page_validate($form, &$form_state) {
  if ($form_state['values']['name']) {
    if ($form_state['values']['op'] == t('Save page')) {
      if (db_result(db_query("SELECT COUNT(*) FROM {homebox_pages} WHERE name = '%s' AND pid <> %d", $form_state['values']['name'], $form_state['values']['pid']))) {
        form_set_error('name', t('The page name %name already exists. Please choose another page name.', array('%name' => $form_state['values']['name'])));
      }
    }
    else if ($form_state['values']['op'] == t('Add page')) {
      if (db_result(db_query("SELECT COUNT(*) FROM {homebox_pages} WHERE name = '%s'", $form_state['values']['name']))) {
        form_set_error('name', t('The page name %name already exists. Please choose another page name.', array('%name' => $form_state['values']['name'])));
      }
    }
  }
  else {
    form_set_error('name', t('You must specify a valid page name.'));
  }
}

function homebox_admin_page_submit($form, &$form_state) {
  if ($form_state['values']['op'] == t('Save page')) {
    // We need the old homebox name to update permission name
    $old_name = db_result(db_query("SELECT name FROM {homebox_pages} WHERE pid = %d", $form_state['values']['pid']));
    $filter = '![^abcdefghijklmnopqrstuvwxyz0-9-_]+!s';
    $old_name = preg_replace($filter, '-', drupal_strtolower($old_name));

    db_query("UPDATE {homebox_pages} SET name = '%s' WHERE pid = %d", $form_state['values']['name'], $form_state['values']['pid']);

    $res = db_query('SELECT rid, perm FROM {permission}');
    $perms = array();

    while ($p = db_fetch_object($res)) {
      $perm = $p->perm;

      foreach (homebox_pages() as $page) {
        $filter = '![^abcdefghijklmnopqrstuvwxyz0-9-_]+!s';
        $safe_name = preg_replace($filter, '-', drupal_strtolower($form_state['values']['name']));
        $perm = preg_replace('/access homebox '. $old_name . '/', 'access homebox '. $safe_name, $perm);
      }

      $perms[$p->rid] = $perm;
    }

    foreach ($perms as $rid => $permission) {
      db_query("UPDATE {permission} SET perm = '%s' WHERE rid = %d", $permission, $rid);
    }

    if ((user_access('create url aliases') || user_access('administer url aliases')) && module_exists('path')) {
      $path = trim($form_state['values']['path']);
      $path = ($path == '') ? NULL : $path;

      $pid = db_result(db_query("SELECT pid FROM {url_alias} WHERE src = 'homebox/%d'", $form_state['values']['pid']));

      path_set_alias('homebox/'. $form_state['values']['pid'], isset($path) ? $path : NULL, isset($pid) ? $pid : NULL);
    }

    drupal_set_message(t('Changes have been saved.'));
  }
  else if ($form_state['values']['op'] == t('Delete page')) {
    db_query('DELETE FROM {homebox_pages} WHERE pid = %d', $form_state['values']['pid']);
    db_query('DELETE FROM {homebox_default} WHERE pid = %d', $form_state['values']['pid']);
    // Update the users who have this role set:
    db_query('DELETE FROM {homebox_users} WHERE pid = %d', $form_state['values']['pid']);

    // Delete variables
    variable_del('homebox_column_count_'. $form_state['values']['pid']);
    variable_del('homebox_users_use_colors_'. $form_state['values']['pid']);
    // Colors
    for ($i = 0; $i < HOMEBOX_NUMBER_OF_COLOURS; $i++) {
      variable_del('homebox_color_'. $form_state['values']['pid'] .'_'. $i);
    }

    if (module_exists('path')) {
      $path = 'homebox/'. $form_state['values']['pid'];
      if (drupal_get_path_alias($path) != $path) {
        path_set_alias($path);
      }
    }

    drupal_set_message(t('The page has been deleted.'));
  }
  else if ($form_state['values']['op'] == t('Add page')) {
    db_query("INSERT INTO {homebox_pages} (name) VALUES ('%s')", $form_state['values']['name']);
    drupal_set_message(t('The page has been added.'));
  }
  $form_state['redirect'] = 'admin/build/homebox';
  menu_rebuild();
  return;
}

/**
 * Form builder function for module settings.
 */
function homebox_layout($pid) {
  $page_name = _homebox_get_profile_name($pid);
  drupal_set_title(t('!page_name layout', array('!page_name' => $page_name)));

  // Gets admin build block helper for usort function
  require_once(drupal_get_path('module', 'block') .'/block.admin.inc');

  // Fetch and sort blocks
  $blocks = _block_rehash();

  $home_blocks = array();

  $result = db_query("SELECT * FROM {homebox_default} WHERE pid = %d", $pid);

  while ($record = db_fetch_object($result)) {
    $home_blocks["$record->bid"] = $record;
  }

  foreach ($blocks as $key => &$block) {
    // We don't want to list exposed views blocks
    if (strpos($block['delta'], '-exp-') === 0) {
       // Remove exposed views blocks
       unset($blocks[$key]);
       continue;
    }
    $bid = $block['bid'];

    $block['pid'] = $pid;
    if (isset($home_blocks[$bid])) {
      $hb = $home_blocks[$bid];
      $block['weight']  = $hb->weight;
      $block['movable'] = (bool) $hb->movable;
      $block['status']  = (bool) $hb->status;
      $block['open']    = (bool) $hb->open;
    }
    // Set defaults.
    else {
      $block['weight']  = 99;
      $block['movable'] = TRUE;
      $block['status']  = TRUE;
      $block['open']    = TRUE;
    }
  }

  usort($blocks, '_homebox_block_compare');

  return drupal_get_form('homebox_admin_display_form', $blocks, $pid, $theme = NULL);
}

/**
 * Generate main blocks administration form.
 */
function homebox_admin_display_form(&$form_state, $blocks, $pid, $theme = NULL) {
  global $theme_key, $custom_theme;

  // Add CSS
  drupal_add_css(drupal_get_path('module', 'block') .'/block.css', 'module', 'all', FALSE);

  // If non-default theme configuration has been selected, set the custom theme.
  $custom_theme = isset($theme) ? $theme : variable_get('theme_default', 'garland');

  $columns = homebox_named_columns($pid);

  $block_regions = $columns + array(HOMEBOX_REGION_NONE => '<'. t('none') .'>');

  // Weights range from -delta to +delta, so delta should be at least half
  // of the amount of blocks present. This makes sure all blocks in the same
  // region get an unique weight.
  $weight_delta = round(count($blocks) / 2);

  // Build form tree
  $form = array(
    '#tree' => TRUE,
  );
  // Iterate on each block
  foreach ($blocks as $i => $block) {
    $key = $block['module'] .'_'. $block['delta'];
    $form[$key]['module'] = array(
      '#type' => 'value',
      '#value' => $block['module'],
    );
    $form[$key]['delta'] = array(
      '#type' => 'value',
      '#value' => $block['delta'],
    );
    $form[$key]['info'] = array(
      '#value' => check_plain($block['info'])
    );

    $form[$key]['weight'] = array(
      '#type' => 'weight',
      '#default_value' => $block['weight'],
      '#delta' => $weight_delta,
    );

    // Get default region/column for block
    $column = db_result(db_query("SELECT region FROM {homebox_default} WHERE bid = %d AND pid = %d", $block['bid'], $pid));
    // If not set assign to <none>
    $column = ($column != 0) ? $column : HOMEBOX_REGION_NONE;

    $form[$key]['region'] = array(
      '#type' => 'select',
      '#default_value' => $column,
      '#options' => $block_regions,
    );
    $form[$key]['status'] = array(
      '#type' => 'checkbox',
      '#default_value' => $block['status'],
    );
    $form[$key]['open'] = array(
      '#type' => 'checkbox',
      '#default_value' => $block['open'],
    );
    $form[$key]['movable'] = array(
      '#type' => 'checkbox',
      '#default_value' => $block['movable'],
    );
    $form[$key]['bid'] = array(
      '#type' => 'hidden',
      '#value' => $block['bid'],
    );
  }

  $form['pid'] = array(
    '#type' => 'hidden',
    '#value' => $pid,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save blocks'),
  );

  return $form;
}

/**
 * Process main home blocks administration form submission.
 */
function homebox_admin_display_form_submit($form, &$form_state) {
  // Page pid
  $pid = $form_state['values']['pid'];

  // We can safely remove old records
  db_query("DELETE FROM {homebox_default} WHERE pid = %d", $pid);

  foreach ($form_state['values'] as $key => $block) {
    // Check to see if this is a block
    // We check $block['region'] == 0, since we don't want to store block that are not enabled
    if (is_array($block) && is_numeric($block['bid']) && $block['bid'] != 0 && is_numeric($block['region']) && (int) $block['region'] > 0) {
      db_query("INSERT INTO {homebox_default} (bid, pid, weight, region, movable, status, open) VALUES (%d, %d, %d, %d, %d, %d, %d)", $block['bid'], $pid, $block['weight'], $block['region'], $block['movable'], $block['status'], $block['open']);
    }
  }

  // We remove blocks from the homebox_users table that are no longer in the homebox_default table
  $result = db_query("DELETE FROM {homebox_users} WHERE pid = %d AND bid NOT IN (SELECT bid FROM {homebox_default})", $pid);
  menu_rebuild();
  drupal_set_message(t('Home box layout settings have been updated.'));
}

/**
 * Process variables for homebox-admin-display.tpl.php.
 *
 * @param $variables
 * @see theme_homebox_admin_display()
 */
function template_preprocess_homebox_admin_display_form(&$variables) {

  global $theme_key;
  drupal_add_css($path = drupal_get_path('module', 'homebox') .'/homebox.css', $type = 'module', $media = 'all', $preprocess = TRUE);

  $block_regions = homebox_named_columns($variables['form']['pid']['#value']);
  $variables['block_regions'] = $block_regions + array(HOMEBOX_REGION_NONE => t('Disabled'));
  foreach ($block_regions as $key => $value) {
    // Initialize an empty array for the region.
    $variables['block_listing'][$key] = array();
  }

  // Initialize disabled blocks array.
  $variables['block_listing'][BLOCK_REGION_NONE] = array();

  // Set up to track previous region in loop.
  $last_region = '';
  foreach (element_children($variables['form']) as $i) {
    $block = &$variables['form'][$i];
    // Only take form elements that are blocks.
    if (isset($block['info'])) {
      // Fetch region for current block.
      $region = $block['region']['#default_value'];

      // Set special classes needed for table drag and drop.
      $variables['form'][$i]['region']['#attributes']['class'] = 'block-region-select block-region-'. $region;
      $variables['form'][$i]['weight']['#attributes']['class'] = 'block-weight block-weight-'. $region;

      $variables['block_listing'][$region][$i]->row_class = isset($block['#attributes']['class']) ? $block['#attributes']['class'] : '';
      $variables['block_listing'][$region][$i]->block_modified = isset($block['#attributes']['class']) && strpos($block['#attributes']['class'], 'block-modified') !== FALSE ? TRUE : FALSE;
      $variables['block_listing'][$region][$i]->block_title =  drupal_render($block['info']);
      $variables['block_listing'][$region][$i]->region_select = drupal_render($block['region']) . drupal_render($block['theme']);
      $variables['block_listing'][$region][$i]->weight_select = drupal_render($block['weight']);
      $variables['block_listing'][$region][$i]->status = drupal_render($block['status']);
      $variables['block_listing'][$region][$i]->open = drupal_render($block['open']);
      $variables['block_listing'][$region][$i]->movable = drupal_render($block['movable']);
      $variables['block_listing'][$region][$i]->bid = drupal_render($block['bid']);
      $variables['block_listing'][$region][$i]->printed = FALSE;

      $last_region = $region;
    }
  }

  $variables['form_submit'] = drupal_render($variables['form']);
}

/**
 * Forms for administration settings
 *
 * @param $form_state
 * @return
 *  $form
 */
function homebox_configure_form(&$form_state, $pid) {
  $page_name = _homebox_get_profile_name($pid);
  drupal_set_title(t('!page_name settings', array('!page_name' => $page_name)));

  $form['columns'] = array(
    '#type' => 'select',
    '#title' => t('Number of columns'),
    '#default_value' => variable_get('homebox_column_count_'. $pid, 3),
    '#options' => array('1' => 1, '2' => 2, '3' => 3, '4' => 4, '5' => 5, '6' => 6, '7' => 7, '8' => 8, '9' => 9),
    '#description' => t('Set the number of columns you want to activate for this Home box page.'),
  );

  $form['homebox_cache_enabled_'. $pid] = array(
    '#type' => 'select',
    '#title' => t('Use blocks cache?'),
    '#default_value' => variable_get('homebox_cache_enabled_'. $pid, 0),
    '#options' => array(0 => t('Don\'t use'), 1 => t('Use if available')),
    '#description' => t('Homebox will use the blocks cache if available for the rendering of the blocks. This can greatly improve performances, but has the drawback to break Views blocks that uses Ajax AND are using <strong>Block settings: Caching</strong>. You can use this option only if the Views blocks used in your homebox that use Ajax are set to <strong>Block settings: Caching:</strong> Do not cache.'),
  );

  $form['color'] = array(
    '#type' => 'fieldset',
    '#title' => t('Boxes colors customization'),
    '#description' => t('Here you can set colors that users can use to customize their boxes.'),
  );

  $form['color']['colors_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Can users set custom colors for each boxes?'),
    '#default_value' => variable_get('homebox_users_use_colors_'. $pid, FALSE),
  );

  if (module_exists('colorpicker')) {
    $form['color']['homebox_colorpicker'] = array(
      '#type' => 'colorpicker',
      '#title' => t('Color picker'),
      '#description' => t('Click an input to choose a color.'),
    );

    for ($i=0; $i < HOMEBOX_NUMBER_OF_COLOURS; $i++) {
      $form['color']['homebox_color_'. $pid .'_'. $i] = array(
        '#type' => 'colorpicker_textfield',
        '#title' => t('Color #!number', array('!number' => $i)),
        '#description' => t('Enter an hexadecimal value prefixed with #.'),
        '#default_value' => variable_get('homebox_color_'. $pid .'_'. $i, '#E4F0F8'),
        '#colorpicker' => 'homebox_colorpicker',
      );
    }
  }
  else {
    for ($i=0; $i < HOMEBOX_NUMBER_OF_COLOURS; $i++) {
      $form['color']['homebox_color_'. $pid .'_'. $i] = array(
        '#type' => 'textfield',
        '#title' => t('Color #!number', array('!number' => $i)),
        '#description' => t('Enter an hexadecimal value, ex: #ff33dd'),
        '#default_value' => variable_get('homebox_color_'. $pid .'_'. $i, '#E4F0F8'),
      );
    }
    $form['color']['message'] = array(
      '#type' => 'markup',
      '#value' => t('If you had the <a href="@url">Color picker</a> module enabled you could choose colors more easily.', array('@url' => 'http://drupal.org/project/colorpicker')),
    );
  }

  $form['pid'] = array(
    '#type' => 'hidden',
    '#value' => $pid,
  );

  $form['#validate'] = array('homebox_configure_form_validate');
  $form['#submit'] = array('homebox_configure_form_submit');

  return system_settings_form($form);
}

/**
 * Forms for administration settings
 *
 * @param $form
 * @param $form_state
 */
function homebox_configure_form_validate($form, &$form_state) {
  $columns = (int) $form_state['values']['columns'];
  if ($columns < 1 ||  $columns > 9) {
    form_set_error('columns', t('You must enter a value between 1 and 9.'));
  }
}

/**
 * Forms for administration settings
 *
 * @param $form
 * @param $form_state
 */
function homebox_configure_form_submit($form, &$form_state) {
  // profile id
  $pid = $form_state['values']['pid'];

  $column_count = (int)$form_state['values']['columns'];
  variable_set('homebox_column_count_'. $pid, $column_count);

  // we need to update default placement in {homebox_default}
  db_query("UPDATE {homebox_default} SET region = %d WHERE pid = %d AND region > %d", $column_count, $pid, $column_count);
  db_query("UPDATE {homebox_users} SET region = %d WHERE pid = %d AND region > %d", $column_count, $pid, $column_count);

  variable_set('homebox_users_use_colors_'. $pid, (bool)$form_state['values']['colors_enabled']);
}

/**
 * Helper function for sorting blocks on admin/build/homebox.
 *
 * Active blocks are sorted by region, then by weight.
 * Disabled blocks are sorted by name.
 *
 * @param $a
 *  An array
 * @param $b
 *  An array
 * @return
 *  Comparison result
 */
function _homebox_block_compare($a, $b) {
  // Sort by weight.
  $weight = $a['weight'] - $b['weight'];
  if ($weight) {
    return $weight;
  }
  // Sort by title.
  return strcmp($a['info'], $b['info']);
}

/**
 * Returns a keyed array containing regions/columns named base on Drupal variable homebox_column_count
 *
 * @return
 *  A keyed array like array(1 => 'Column 1', 2 => 'Column 2')
 */
function homebox_named_columns($pid) {
  $columns = array();
  for ($i = 1; $i <= variable_get('homebox_column_count_'. $pid, 3); $i++) {
    $columns[$i] = t('Column !count', array('!count' => $i));
  }
  return $columns;
}
