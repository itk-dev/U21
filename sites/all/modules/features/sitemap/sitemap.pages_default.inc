<?php

/**
 * Implementation of hook_default_page_manager_pages().
 */
function sitemap_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'sitemap';
  $page->task = 'page';
  $page->admin_title = 'sitemap';
  $page->admin_description = '';
  $page->path = 'sitemap';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Sitemap',
    'name' => 'secondary-links',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_sitemap_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'sitemap';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'stacked_3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'center' => NULL,
      'right' => NULL,
      'lower_left' => NULL,
      'lower_right' => NULL,
      'middel' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'bottom';
    $pane->type = 'slug_links';
    $pane->subtype = 'slug_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'node_type' => 'region',
      'slug_path' => 'location/%slug/news',
      'global_path' => 'news',
      'override_title' => 1,
      'override_title_text' => 'Nyheder',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['bottom'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'bottom';
    $pane->type = 'slug_links';
    $pane->subtype = 'slug_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'node_type' => 'region',
      'slug_path' => 'location/%slug/events',
      'global_path' => 'events',
      'override_title' => 1,
      'override_title_text' => 'Arrangementer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['bottom'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'middle';
    $pane->type = 'menu_tree';
    $pane->subtype = 'menu-viborg-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'menu-viborg-menu',
      'parent_mlid' => 0,
      'title_link' => 1,
      'admin_title' => '',
      'level' => '1',
      'follow' => 0,
      'depth' => 0,
      'expanded' => 1,
      'sort' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['middle'][0] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'middle';
    $pane->type = 'menu_tree';
    $pane->subtype = 'menu-herning-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'menu-herning-menu',
      'parent_mlid' => 0,
      'title_link' => 1,
      'admin_title' => '',
      'level' => '1',
      'follow' => 0,
      'depth' => 0,
      'expanded' => 1,
      'sort' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-4'] = $pane;
    $display->panels['middle'][1] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'middle';
    $pane->type = 'menu_tree';
    $pane->subtype = 'menu-aarhus-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'menu-aarhus-menu',
      'parent_mlid' => 0,
      'title_link' => 1,
      'admin_title' => '',
      'level' => '1',
      'follow' => 0,
      'depth' => 0,
      'expanded' => 1,
      'sort' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-5'] = $pane;
    $display->panels['middle'][2] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'middle';
    $pane->type = 'menu_tree';
    $pane->subtype = 'menu-aalborg-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'menu-aalborg-menu',
      'parent_mlid' => 0,
      'title_link' => 1,
      'admin_title' => '',
      'level' => '1',
      'follow' => 0,
      'depth' => 0,
      'expanded' => 1,
      'sort' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-6'] = $pane;
    $display->panels['middle'][3] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'top';
    $pane->type = 'menu_tree';
    $pane->subtype = 'primary-links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'primary-links',
      'parent_mlid' => '1121',
      'title_link' => 1,
      'admin_title' => '',
      'level' => '1',
      'follow' => 0,
      'depth' => 0,
      'expanded' => 1,
      'sort' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-7'] = $pane;
    $display->panels['top'][0] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'top';
    $pane->type = 'menu_tree';
    $pane->subtype = 'primary-links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'primary-links',
      'parent_mlid' => '1129',
      'title_link' => 1,
      'admin_title' => '',
      'level' => '1',
      'follow' => 0,
      'depth' => 0,
      'expanded' => 1,
      'sort' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-8'] = $pane;
    $display->panels['top'][1] = 'new-8';
    $pane = new stdClass;
    $pane->pid = 'new-9';
    $pane->panel = 'top';
    $pane->type = 'menu_tree';
    $pane->subtype = 'secondary-links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'secondary-links',
      'parent_mlid' => 0,
      'title_link' => 1,
      'admin_title' => '',
      'level' => '1',
      'follow' => 0,
      'depth' => 0,
      'expanded' => 1,
      'sort' => 0,
      'override_title' => 1,
      'override_title_text' => 'Andre sider',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-9'] = $pane;
    $display->panels['top'][2] = 'new-9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['sitemap'] = $page;

 return $pages;

}
