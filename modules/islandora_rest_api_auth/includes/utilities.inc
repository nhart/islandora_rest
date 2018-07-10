<?php

/**
 * @file
 * Helpers for the Islandora REST API Auth module.
 */

/**
 * Authenticates a token.
 *
 * @param string $username
 *   The name of the user authenticating.
 * @param string $token
 *   The token being used to authenticate.
 *
 * @return bool
 *   TRUE if the user has access, FALSE otherwise.
 */
function islandora_rest_api_auth_authenticate_token($username, $token) {
  module_load_include('inc', 'islandora_rest_api_auth', 'includes/db');
  require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');

  $user = user_load_by_name($username);
  if (!$user) {
    return FALSE;
  }
  // Retrieve the hash to auth against.
  $stored_hash = islandora_rest_api_auth_retrieve_token($user->uid);
  if (!$stored_hash) {
    return FALSE;
  }
  // XXX: Spoof a user object so we can use user_check_password. As password.inc
  // is able to be overwritten need to rely on the higher level functions that
  // need to be there as opposed to lower level things like _password_crypt in
  // core Drupal.
  $spoofed_user = new stdClass();
  $spoofed_user->pass = $stored_hash;
  return user_check_password($token, $spoofed_user);
}
