--TEST--
Check if constants are defined
--SKIPIF--
<?php
if (! extension_loaded('phpspi')) {
  exit('skip');
}
?>
--FILE--
<?php
var_dump(defined('SPI\\CPHA'));
var_dump(SPI\CPHA);
var_dump(defined('SPI\\CPOL'));
var_dump(SPI\CPOL);
var_dump(defined('SPI\\MODE_0'));
var_dump(SPI\MODE_0);
var_dump(defined('SPI\\MODE_1'));
var_dump(SPI\MODE_1);
var_dump(defined('SPI\\MODE_2'));
var_dump(SPI\MODE_2);
var_dump(defined('SPI\\MODE_3'));
var_dump(SPI\MODE_3);
var_dump(defined('SPI\\EXTENSION_VERSION'));
var_dump(SPI\EXTENSION_VERSION);
?>
--EXPECT--
bool(true)
int(1)
bool(true)
int(2)
bool(true)
int(0)
bool(true)
int(1)
bool(true)
int(2)
bool(true)
int(3)
bool(true)
string(9) "0.0.1-dev"
