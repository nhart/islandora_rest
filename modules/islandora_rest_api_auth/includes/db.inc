<?php

/**
 * @file
 * Database helpers for the Islandora REST API Auth module.
 */

/**
 * Adds or updates a token for a user.
 *
 * @param string $uid
 *   The UID of the user.
 * @param string $token
 *   The token to be hashed.
 */
function islandora_rest_api_auth_upsert_token($uid, $token) {
  require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
  $hash = user_hash_password($token);
  db_merge('islandora_rest_api_auth_tokens')
    ->key(array('uid' => $uid))
    ->fields(array(
      'salted_token' => $hash,
    ))
    ->execute();
}

/**
 * Deletes a token entry when a user is deleted.
 *
 * @param string $uid
 *   The UID of the user.
 */
function islandora_rest_api_auth_delete_token($uid) {
  db_delete('islandora_rest_api_auth_tokens')
    ->condition('uid', $uid)
    ->execute();
}

/**
 * Retrieves a stored hash for a username.
 *
 * @param string $uid
 *   The UID of the user's token to be retrieved.
 *
 * @return string|bool
 *   The token if one exists for the user, FALSE otherwise.
 */
function islandora_rest_api_auth_retrieve_token($uid) {
  return db_select('islandora_rest_api_auth_tokens', 't')
    ->fields('t', array('salted_token'))
    ->condition('uid', $uid)
    ->execute()
    ->fetchField();
}
