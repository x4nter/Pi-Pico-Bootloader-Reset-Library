#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include <stdint.h>
#include "hardware/gpio.h"

// Initialize the bootloader reset ISR on the specified pin
// The pin is configured as input with a pull-up resistor and interrupt on both edges
void bootloader_reset_init(uint reset_pin);

#endif // BOOTLOADER_H