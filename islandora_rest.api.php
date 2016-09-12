<?php
/**
 * @file
 * This file documents all available hook functions to manipulate data.
 */

/**
 * Notify modules of requests to Islandora REST endpoints other than 'solr'.
 *
 * @param string $http_response_code
 *   The HTTP response code generated for the response.
 * @param string $endpoint
 *   The REST endpoint.
 * @param string $request_method
 *   The HTTP request method.
 * @param string $pid
 *   The PID of the Islanora object.
 * @param string $dsid
 *   The DSID.
 * @param array $request_parameters
 *   An array containing all request parameters.
 */
function hook_islandora_rest_response($http_response_code, $endpoint, $request_method, $pid, $dsid, $request_parameters) {
  watchdog('islandora_rest', 'Islandora REST %method request for object: %object',
     array('%method' => $request_method, '%object' => $pid));
}

/**
 * Notify modules of requests to Islandora REST 'solr' endpoint.
 *
 * @param string $http_response_code
 *   The HTTP response code generated for the response.
 * @param string $query
 *   The Solr query.
 * @param array $solr_parameters
 *   An array containing all Solr query parameters included in the request.
 */
function hook_islandora_rest_solr_response($http_response_code, $query, $solr_parameters) {
  watchdog('islandora_rest', 'Islandora REST Solr query: %query', array('%query' => $query));
}
