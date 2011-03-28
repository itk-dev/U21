<?php

/**
 * Add conditional stylesheets:
 * For more information: http://msdn.microsoft.com/en-us/library/ms537512.aspx
 * template.php implementation based on Genesis Theme by jmburnz.
 */

/* 
function u21dk2011_theme(&$existing, $type, $theme, $path){
  global $theme_path;

  // Compute the conditional stylesheets.
  if (!module_exists('conditional_styles')) {
    include_once $theme_path . '/includes/template.conditional-styles.inc';
    // _conditional_styles_theme() only needs to be run once.
    if ($theme == 'u21dk2011') {
      _conditional_styles_theme($existing, $type, $theme, $path);
    }
  }  
  $templates = drupal_find_theme_functions($existing, array('phptemplate', $theme));
  $templates += drupal_find_theme_templates($existing, '.tpl.php', $path);
  return $templates;
}
*/

/**
 * Override or insert variables into page templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called.
 */
function u21dk2011_preprocess_page(&$vars, $hook) {
  global $theme;
  global $theme_path;

  // Detect if page is shown in a regional context
  $vars['is_region'] = FALSE;
  if ($hook == 'page') {
    if ($vars['node']->field_slug_ref[0]['nid']) {
      $vars['is_region'] = TRUE;
    }
  }

  // Don't display empty help from node_help().
  if ($vars['help'] == "<div class=\"help\"> \n</div>") {
    $vars['help'] = '';
  }
  
  // Set variables for the logo and site_name.
  if (!empty($vars['logo'])) {
    // Return the site_name even when site_name is disabled in theme settings.
    $vars['logo_alt_text'] = (empty($vars['logo_alt_text']) ? variable_get('site_name', '') : $vars['logo_alt_text']);
    $vars['site_logo'] = '<a id="site-logo" href="'. $vars['front_page'] .'" title="'. t('Home page') .'" rel="home"><img src="'. $vars['logo'] .'" alt="'. $vars['logo_alt_text'] .'" /></a>';
  }  

  $vars['tournament_logo'] = '<img id="tournament-logo" src="/'. $theme_path .'/images/graphic-dk2011.png" alt="Denmark 2011" />';
  
  if (!empty($vars['site_slogan'])) {
    $vars['tournament_date'] = '<img id="tournament-date" src="/'. $theme_path .'/images/graphic-date.png" alt="'. $vars['site_slogan'] .'" />';
  } else {
    $vars['tournament_date'] = '';
  }
  
  // Add regional context to body classes
  if (!$vars['is_front']) {
    $path_request = explode('/', $_SERVER['REQUEST_URI']);
    if ($path_request[1] == "location") {
      $vars['body_classes'] .= ' page-regional';
    }
  }

  // Add profiles js
  if (isset($vars['node'])) {
    $node = $vars['node'];
    if ($node->type == 'profile') {
      jquery_ui_add('ui.tabs');
      drupal_add_js(path_to_theme().'/scripts/profiles.js');
      $vars['scripts'] = drupal_get_js();
    }
  }
}

/**
 * Add current page to breadcrumb
 */
function u21dk2011_breadcrumb($breadcrumb) {

  if (!empty($breadcrumb)) {
    $title = drupal_get_title();
    // Fix 2x title in breadcrumb
    if (!empty($title) && strstr($breadcrumb[count($breadcrumb)-1], $title)) {
      // Remove title
      array_pop($breadcrumb);
    }

    // Add title, but not as link
    if (!empty($title)) {
      $breadcrumb[] = $title;
    }

    // Get the request uri
    $uri = split('/', $_SERVER['REQUEST_URI']);

    // Fix profiles (/profile)
    if ($uri[1] == 'profile') {
      $tmp = $breadcrumb;
      $breadcrumb = array();
      $breadcrumb[] = array_shift($tmp);
      $breadcrumb[] = l(t('Profiles'), 'profile/jonas-l-ssl');
      $breadcrumb[] = $title;
    }

    // Fix /news and /events
    $type = $uri[count($uri)-1];
    if ($type == 'news') {
      $breadcrumb[] = 'Nyheder';
    }
    if ($type == 'events') {
      $breadcrumb[] = 'Arrangementer';
    }
    
    // Fix all under regions (/location)
    if ($uri[1] == 'location' && $uri[2] != strtolower($title)) {
      $tmp = $breadcrumb;
      $breadcrumb = array();
      $breadcrumb[] = array_shift($tmp);
      if (count($tmp))
        $breadcrumb[] = l(ucfirst($uri[2]), $uri[1] . '/' . $uri[2]);
      else {
        $breadcrumb[] = ucfirst($uri[2]);
      }

      // Fix events and news
      if (strstr($tmp[0], 'href="/news"')) {
        $breadcrumb[] = l('Nyheder', $uri[1] . '/' . $uri[2] . '/news');
        array_shift($tmp);
      }
      if (strstr($tmp[0], 'href="/events"')) {
        $breadcrumb[] = l('Arrangementer', $uri[1] . '/' . $uri[2] . '/events');
        array_shift($tmp);
      }

      // Put the rest back.
      while (!empty($tmp)) {
        $breadcrumb[] = array_shift($tmp);
      }
    }

    return '<div class="breadcrumb">' . implode(' > ', $breadcrumb) . '</div>';
  }
}

/**
 * Generate the HTML output for a menu item and submenu.
 *
 * @ingroup themeable
 */
function u21dk2011_menu_item_link($link) {
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }
  
  // Add mlid to all menu-items and not only $primary-links and $secondary-links
  if (empty($link['localized_options']['attributes']['class'])) {
    $link['localized_options']['attributes']['class'] = 'menu-'. $link['mlid'];
  }
  else {
  }

  // Create variable with link title wrapped in div. 
  // Used to supply additional information about a menu item on hover.
  $hover = '';
  if (isset($link['options']['attributes']['title']) && $link['options']['attributes']['title'] != '') {
    $hover = '<div class="menu-hover">'.$link['options']['attributes']['title'].'</div>';
  }

  // THIS IS A HACK XXXXX FIX ME LATER
  $region_links = array('node/1','node/2','node/3','node/4');
  if (in_array($link['href'], $region_links)) {
    $tmp = split('/', $_SERVER[ 'REQUEST_URI']);
    if ($tmp[2] == 'herning' && $link['href'] == 'node/4') {
        $link['localized_options']['attributes']['class'] = 'active-trail';
        return l($link['title'], $link['href'], $link['localized_options']) . $hover;
    }
    else if ($tmp[2] == 'viborg' && $link['href'] == 'node/3') {
        $link['localized_options']['attributes']['class'] = 'active-trail';
        return l($link['title'], $link['href'], $link['localized_options']) . $hover;
    }
    else if ($tmp[2] == 'aarhus' && $link['href'] == 'node/2') {
        $link['localized_options']['attributes']['class'] = 'active-trail';
        return l($link['title'], $link['href'], $link['localized_options']) . $hover;
    }
    else if ($tmp[2] == 'aalborg' && $link['href'] == 'node/1') {
        $link['localized_options']['attributes']['class'] = 'active-trail';
        return l($link['title'], $link['href'], $link['localized_options']) . $hover;
    }
  }

  return l($link['title'], $link['href'], $link['localized_options']) . $hover;
}



// What?
function u21dk2011_views_slideshow_singleframe_controls($vss_id, $view, $options) {
  $classes = array(
    'views_slideshow_singleframe_controls',
    'views_slideshow_controls',
  );

  $attributes['class'] = implode(' ', $classes);
  $attributes['id'] = "views_slideshow_singleframe_controls_" . $vss_id;
  $attributes = drupal_attributes($attributes);

  $output .= theme('views_slideshow_singleframe_control_previous', $vss_id, $view, $options);
  $output .= theme('views_slideshow_singleframe_control_next', $vss_id, $view, $options);
  
  return $output;
}

/**
 * Implementation of theme_webform_element.
 * Move form descriptions to a position above form fields instead of below
 * Ideally this function should target only forms created by Webform Module
 */

 function u21dk2011_form_element($element, $value) {
  
  $wrapper_classes = array(
   'form-item',
  );

  $output = "<div class=\"form-item form-item-" . $element['#type'] . " \" ";
  if (!empty($element['#id'])) {
    $output .= ' id="'. $element['#id'] .'-wrapper"';
  }
  $output .= ">\n";

  $required = !empty($element['#required']) ? '<span class="form-required" title="'. t('This field is required.') .'">*</span>' : '';

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    if (!empty($element['#id'])) {
      $output .= ' <label for="'. $element['#id'] .'">'. t('!title: !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
    else {
      $output .= ' <label>'. t('!title: !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
    
    if (!empty($element['#description'])) {
      $output .= ' <div class="description">'. $element['#description'] ."</div>\n";
    }
    $output .= " $value\n";
  }
  else{
    $output .= " $value\n";
    if (!empty($element['#description'])) {
      $output .= ' <div class="description">'. $element['#description'] ."</div>\n";
    }
  }

  $output .= "</div>\n";
  return $output;
}


