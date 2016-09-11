<?php
/**
 * @file
 * This file documents all available hook functions to manipulate data.
 */

/**
 * Notify modules of requests to Islandora REST endpoints other than 'solr'.
 *
 * @param string $endpoint
 *   The REST endpoint.
 * @param string $request_method
 *   The HTTP request method.
 * @param string $pid
 *   The PID of the Islanora object.
 * @param string $dsid
 *   The DSID.
 * @param array $path_parameters
 *   An array containing all URL parameters included in the request.
 */
function hook_islandora_rest_response($endpoint, $request_method, $pid, $dsid, $path_parameters) {
  watchdog('islandora_rest', 'Islandora REST %method request for object: %object',
     array('%method' => $request_method, '%object' => $pid));
}

/**
 * Notify modules of requests to Islandora REST 'solr' endpoint.
 *
 * @param string $query
 *   The Solr query.
 * @param array $parameters
 *   An array containing all Solr query parameters included in the request.
 */
function hook_islandora_rest_solr_response($query, $parameters) {
  watchdog('islandora_rest', 'Islandora REST Solr query: %query', array('%query' => $query));
}
