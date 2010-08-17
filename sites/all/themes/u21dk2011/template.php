<?php

/**
 * Add conditional stylesheets:
 * For more information: http://msdn.microsoft.com/en-us/library/ms537512.aspx
 * template.php implementation based on Genesis Theme by jmburnz.
 */
 
function u21dk2011_theme(&$existing, $type, $theme, $path){
  
  // Compute the conditional stylesheets.
  if (!module_exists('conditional_styles')) {
    include_once $base_path . drupal_get_path('theme', 'u21dk2011') . '/includes/template.conditional-styles.inc';
    // _conditional_styles_theme() only needs to be run once.
    if ($theme == 'u21dk2011') {
      _conditional_styles_theme($existing, $type, $theme, $path);
    }
  }  
  $templates = drupal_find_theme_functions($existing, array('phptemplate', $theme));
  $templates += drupal_find_theme_templates($existing, '.tpl.php', $path);
  return $templates;
}

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

  // Don't display empty help from node_help().
  if ($vars['help'] == "<div class=\"help\"> \n</div>") {
    $vars['help'] = '';
  }

  // Add conditional stylesheets.
  if (!module_exists('conditional_styles')) {
    $vars['styles'] .= $vars['conditional_styles'] = variable_get('conditional_styles_' . $GLOBALS['theme'], '');
  }


  // Set variables for the logo and site_name.
  if (!empty($vars['logo'])) {
    // Return the site_name even when site_name is disabled in theme settings.
    $vars['logo_alt_text'] = (empty($vars['logo_alt_text']) ? variable_get('site_name', '') : $vars['logo_alt_text']);
    $vars['site_logo'] = '<a id="site-logo" href="'. $vars['front_page'] .'" title="'. t('Home page') .'" rel="home"><img src="'. $vars['logo'] .'" alt="'. $vars['logo_alt_text'] .'" /></a>';
  }  
}

/**
 * Add current page to breadcrumb
 */

function u21dk2011_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    $title = drupal_get_title();
    if (!empty($title)) {
      $breadcrumb[]=$title;
    }
    return '<div class="breadcrumb">'. implode(' > ', $breadcrumb) .'</div>';
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

  $hover = '';
  if (isset($link['options']['attributes']['title']) && $link['options']['attributes']['title'] != '') {
    $hover = '<div class="menu-hover">'.$link['options']['attributes']['title'].'</div>';
  }

  return l($link['title'], $link['href'], $link['localized_options']) . $hover;
}

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

