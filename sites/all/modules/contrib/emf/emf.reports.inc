<?php
// $Id: emf.reports.inc,v 1.2 2009/10/28 14:16:51 davyvandenbremt Exp $

/**
 * @file
 * Report functions and callbacks.
 *
 * @author Davy Van Den Bremt
 */

function emf_reports_subscriptions() {
  $header = array(t('List'), t('Subscribers'));

  $result = db_query("SELECT cl.lid, cl.name_api, count(cs.mail) AS subscribers FROM {emf_subscription} cs RIGHT JOIN {emf_list} cl ON cl.lid = cs.lid GROUP BY cl.lid");

  $rows = array();

  while ($list = db_fetch_object($result)) {
    $rows[] = array(
      l($list->name_api, 'admin/build/emf/'. $list->lid .'/manage'),
      $list->subscribers,
    );
  }

  if (empty($rows)) {
    $rows[] = array(array('data' => t('No lists synchronised yet or no lists available in your account. Run cron to synchronise your lists.'), 'colspan' => '4', 'class' => 'message'));
  }

  return theme('table', $header, $rows);
}

function emf_reports_requests() {
  $header = array(t('Mail'), t('List'), t('Type'), t('Date'));

  $result = pager_query("SELECT * FROM {emf_request} cr INNER JOIN {emf_list} cl ON cl.lid = cr.lid ORDER BY cr.timestamp DESC");

  $rows = array();

  while ($request = db_fetch_object($result)) {
    $rows[] = array(
      $request->mail,
      l($request->name_api, 'admin/build/emf/'. $request->lid .'/manage'),
      $request->type,
      t('!time ago', array('!time' => format_interval(time() - $request->timestamp))),
    );
  }

  if (empty($rows)) {
    $rows[] = array(array('data' => t('No requests pending.'), 'colspan' => '4', 'class' => 'message'));
  }

  return theme('table', $header, $rows) . theme('pager', array(), 50);
}