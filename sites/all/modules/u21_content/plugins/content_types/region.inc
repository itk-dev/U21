<?php
// $Id$

/**
 * @file region.inc
 * Provides several region related panels content types.
 */


/**
 * Callback function to supply a list of content types.
 *
 * This is only required to make CTools know that we're providing 
 * multiple types here (since we have no single => TRUE in the array).
 */
function u21_content_region_ctools_content_types() {
  return array(
    'title' => t('Region page'),
  );
}

/**
 * Callback function to supply a list of content types.
 */
function u21_content_region_content_type_content_types() {
  $types = array(
    'region_menu' => array(
      'title' => t('Region title and menu'),
      'description' => t('The title and related menu for a region page.'),
      'category' => t('Region page'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    ),
    'region_calendar_link' => array(
      'title' => t('Region calendar link '),
      'description' => t('Displays link to external calendar.'),
      'category' => t('Region page'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    ),
    'region_banner' => array(
      'title' => t('Region based banners loaded from blocks'),
      'description' => t('Displays banner blocks.'),
      'category' => t('Region page'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
    )
  );
  return $types;
}

/**
 * Return the pane contents.
 */
function u21_content_region_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $node = isset($context->data) ? drupal_clone($context->data) : NULL;
  switch($subtype) {
    case 'region_menu':
      $block->content = theme('u21_content_region_menu', $node);
      break;

    case 'region_calendar_link':
      $block->content = theme('u21_content_region_calendar_link', $node);
      break;

    case 'region_banner': // XXX HACK -> fix later
      $nid = $context->data->nid;
      switch ($nid) {
        case 1: // Aalborg
          $bid = 14;
          break;
        case 2: // Aarhus
          $bid = 11;
          break;
        case 3: // Viborg
          $bid = 12;
          break;
        case 4: // Herning
          $bid = 13;
          break;
      }
      $date = db_fetch_object(db_query('SELECT title, body
                                        FROM boxes bx, blocks bs
                                        WHERE bx.bid = bs.delta
                                          AND bx.bid = %d
                                          AND theme = "u21dk2011"', $bid));
      $block->content = '<div class="sms-updates"><h2>'.$data->title.'</h2>'.$data->body.'</div>';
      break;
  }
  return $block;
}

/**
 * Return the pane titles.
 */
function u21_content_region_content_type_admin_title($subtype, $conf, $context) {
  switch($subtype) {
    case 'region_menu':
      return t('"@s":  Region title and menu', array('@s' => $context->identifier));
    case 'region_calendar_link':
      return t('"@s":  Region calendar link', array('@s' => $context->identifier));
    case 'region_banner':
      return t('"@s":  Region banner blocks', array('@s' => $context->identifier));
  }
}

/**
 * Returns an edit form for the content type.
 */
function u21_content_region_content_type_edit_form(&$form, &$form_state) {
  return $form;
}
/**
 * Submit handler for the content type editing form.
 */
function u21_content_region_content_type_edit_form_submit(&$form, &$form_state) {
  
}