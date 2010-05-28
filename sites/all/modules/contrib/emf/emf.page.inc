<?php
// $Id: emf.page.inc,v 1.2 2009/10/28 14:16:51 davyvandenbremt Exp $

function emf_page($list = NULL) {
  module_load_include('inc', 'emf', 'emf.form');
  return drupal_get_form('emf_subscription_list_form', $list->lid);
}