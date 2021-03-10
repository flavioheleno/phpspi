/*
   +----------------------------------------------------------------------+
   | Copyright (c) The PHP Group                                          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Flavio Heleno <https://github.com/flavioheleno>              |
   +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "phpspi.h"
#include "phpspi_arginfo.h"

#include "src/bus.h"
#include "src/exception.h"

// #include <gpiod.h>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
  ZEND_PARSE_PARAMETERS_START(0, 0) \
  ZEND_PARSE_PARAMETERS_END()
#endif

/* Class entry pointers (global resources) */
zend_class_entry *zceBus;
zend_class_entry *zceException;

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(phpspi) {
  #if defined(ZTS) && defined(COMPILE_DL_PHPSPI)
    ZEND_TSRMLS_CACHE_UPDATE();
  #endif

  return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(phpspi) {
  /* Extension constants */
  REGISTER_LONG_CONSTANT("SPI\\CPHA", 0x01, CONST_CS | CONST_PERSISTENT);
  REGISTER_LONG_CONSTANT("SPI\\CPOL", 0x02, CONST_CS | CONST_PERSISTENT);
  REGISTER_LONG_CONSTANT("SPI\\MODE_0", 0, CONST_CS | CONST_PERSISTENT);
  REGISTER_LONG_CONSTANT("SPI\\MODE_1", 0x01, CONST_CS | CONST_PERSISTENT);
  REGISTER_LONG_CONSTANT("SPI\\MODE_2", 0x02, CONST_CS | CONST_PERSISTENT);
  REGISTER_LONG_CONSTANT("SPI\\MODE_3", 0x02 | 0x01, CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SPI\\EXTENSION_VERSION", PHP_PHPSPI_VERSION, CONST_CS | CONST_PERSISTENT);

  /* Class Registration (from each *.h file) */
  zceBus = registerBusClass();
  zceException = registerExceptionClass();

  return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(phpspi) {
  php_info_print_table_start();
  php_info_print_table_header(2, "phpspi support", "enabled");
  php_info_print_table_row(2, "Extension version", PHP_PHPSPI_VERSION);
  php_info_print_table_end();
}
/* }}} */

/* {{{ phpspi_module_entry */
zend_module_entry phpspi_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_PHPSPI_EXTNAME, /* Extension name */
  NULL,               /* zend_function_entry */
  PHP_MINIT(phpspi),  /* PHP_MINIT - Module initialization */
  NULL,               /* PHP_MSHUTDOWN - Module shutdown */
  PHP_RINIT(phpspi),  /* PHP_RINIT - Request initialization */
  NULL,               /* PHP_RSHUTDOWN - Request shutdown */
  PHP_MINFO(phpspi),  /* PHP_MINFO - Module info */
  PHP_PHPSPI_VERSION, /* Version */
  STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHPSPI
  #ifdef ZTS
    ZEND_TSRMLS_CACHE_DEFINE()
  #endif
  ZEND_GET_MODULE(phpspi)
#endif
