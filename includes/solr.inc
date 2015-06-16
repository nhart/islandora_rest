<?php

/**
 * @file
 * Generate responses for the solr rest end point.
 */

/**
 * Responds to a SOLR GET request.
 *
 * @param array $parameters
 *   An associative array containing relevent data for this request.
 *   - path: The GET parameters from the URL path.
 *     - query: The SOLR query.
 *   - request: The request parameters passed onto SOLR.
 *     - See the SOLR documentation for more information.
 *
 * @return array
 *   The un-encoded response containing the generated SOLR results.
 */
function islandora_rest_solr_get_response(array $parameters) {
  $query = $parameters['path']['query'];
  $request = $parameters['request'];
  // XXX: This will not respect XACML or other built in restrictions but will
  // allow for direct access to Solr through Islandora that may otherwise be
  // locked down.
  $path_parts = parse_url(variable_get('islandora_solr_url', 'localhost:8080/solr'));
  $solr = new Apache_Solr_Service($path_parts['host'], $path_parts['port'], $path_parts['path'] . '/');
  $solr->setCreateDocuments(0);
  // Query is executed.
  try {
    $results = $solr->search($query, 0, isset($request['limit']) ? $request['limit'] : 10, $request, 'GET');
  }
  catch (Exception $e) {
    drupal_set_message(check_plain(t('Error searching Solr index')) . ' ' . $e->getMessage(), 'error');
    return NULL;
  }
  return json_decode($results->getRawResponse(), TRUE);
}
