<?php

/**
 * @file
 * A drush script for generating derivatives 
 *
 */

/**
 * Implements hook_drush_command().
 */
function coalliance_derivative_generation_drush_command() {
 $items = array();
 $items['coalliance_generate_derivatives'] = array(
    'callback' => 'coalliance_derivatives_generation',
    'description' => 'generates derivatives',
    'arguments' => array(
      'fedora_pid' => "The Fedora PID to process",
    ),
    'options' => array(),
    'examples' => array(
      'simple example' => 'drush -u 1 --root=/var/www/drupal7 -l http://codearl7.coalliance.org coalliance_generate_derivatives adrtest:1',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
  );

  return $items;
}

/**
 * derivative generation
 *
 *
 */
function coalliance_derivatives_generation($pid) {
  module_load_include('inc', 'islandora', 'includes/regenerate_derivatives.form');
  $batch = islandora_regenerate_object_derivatives_batch($object);
  batch_set($batch);
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();
}
