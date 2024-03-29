**NOTE:** Check [embedded-php/ext-spi](https://github.com/embedded-php/ext-spi) instead.

# phpspi

Object-oriented PHP bindings for the [SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface) protocol using the [spidev](https://www.kernel.org/doc/Documentation/spi/spidev) linux kernel driver

## Requirements

- PHP >= 8.0 (either NTS or TS version);

## Building

```bash
phpize
./configure
make
make test
```

## SPI Modes

Mode | Constant   | Description
-----|------------|------------
00   | SPI\MODE_0 | Clock idle low, data valid at beginning of pulse (low to high)
01   | SPI\MODE_1 | Clock idle low, data valid at end of pulse (high to low)
10   | SPI\MODE_2 | Clock idle high, data valid at beginning of pulse (high to low)
11   | SPI\MODE_3 | Clock idle high, data valid at end of pulse (low to high)

## Stubs

After changing any of the [stubs](stubs/), the main [stub file](phpspi.stub.php) must be updated by running the command below.

```bash
php stubs/update-main-stup.php
```

Once the stub is updated, the regular build process can be executed.

**Note:** The main stub file ([phpspi.stub.php](phpspi.stub.php)) is a generated file, edit the files on the [stubs](stubs/) folder instead.

## Constants

All namespace defined constants can be seen in the [Constants.php](stubs/Constants.php) stub.

## Classes

Class                                | Description
-------------------------------------|------------
[SPI\Bus](stubs/Bus.php)             | Represents a SPI Bus.
[SPI\Exception](stubs/Exception.php) | Base exception.

## Resources

- [https://www.raspberrypi.org/documentation/hardware/raspberrypi/spi/README.md](https://www.raspberrypi.org/documentation/hardware/raspberrypi/spi/README.md)
- [https://github.com/topherCantrell/ER-OLEDM032-1](https://github.com/topherCantrell/ER-OLEDM032-1)

## Alternatives

- [frak/php_spi](https://github.com/frak/php_spi)
- [Volantus/berry-spi](https://github.com/Volantus/berry-spi)

## Other Languages

- Golang: [periph/conn](https://github.com/periph/conn)
- NodeJS: [alexeden/spi-node](https://github.com/alexeden/spi-node)
- NodeJS: [fivdi/spi-device](https://github.com/fivdi/spi-device)
- NodeJS: [natevw/pi-spi](https://github.com/natevw/pi-spi)
- Python: [doceme/py-spidev](https://github.com/doceme/py-spidev)

## License

This library is licensed under the [PHP License](LICENSE).
