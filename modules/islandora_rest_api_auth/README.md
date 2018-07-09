# Islandora API Rest Auth

## Introduction

Allows Islandora REST to take configurable user tokens for authentication.

## Requirements

This module requires the following modules/libraries:

* [Islandora REST](https://github.com/discoverygarden/islandora_rest)

## Installation

Install as usual, see 
[this](https://drupal.org/documentation/install/modules-themes/modules-7) for 
further information.

## Configuration

Users with access to use Islandora REST will have a place present on their user
page: My account » Edit (user/uidoftheuser/edit) to enter a token to
authenticate against. This token is salted using the same mechanism as Drupal
passwords and stored.

## Usage

To authenticate for a REST request the user needs to provide a Basic
Authorization Header that specifies their username and the token.
NOTE: For Basic Authorization the username and token are separated by a colon
and then base64 encoded.

For example:
```
GET /islandora/rest/v1/object/islandora:root HTTP/1.1
Host: an.example.host
Authorization: Basic dGVzdDp0ZXN0
```

## Troubleshooting/Issues

Having problems or solved a problem? Contact 
[discoverygarden](http://support.discoverygarden.ca).

## Maintainers/Sponsors

Current maintainers:

* [discoverygarden](http://www.discoverygarden.ca)

## Development

If you would like to contribute to this module, please check out the helpful
[Documentation](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers),
[Developers](http://islandora.ca/developers) section on Islandora.ca and
contact [discoverygarden](http://support.discoverygarden.ca).

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
