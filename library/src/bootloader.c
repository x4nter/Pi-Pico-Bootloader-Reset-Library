#include "bootloader.h"
#include "pico/bootrom.h"

static volatile uint _reset_pin; // Pin number for the reset functionality

// GPIO interrupt handler for the reset pin
// If the interrupt is triggered on the specified reset pin, it calls reset_usb_boot
static void reset(uint gpio, uint32_t events)
{
    if (gpio != _reset_pin) return;

    if (events & (GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL))
        reset_usb_boot(0, 0);
}

// Initialize the bootloader reset ISR on the specified pin
// The pin is configured as input with a pull-up resistor and interrupt on both edges
void bootloader_reset_init(uint reset_pin)
{
    _reset_pin = reset_pin;

    gpio_init(reset_pin);
    gpio_set_dir(reset_pin, GPIO_IN);
    gpio_pull_up(reset_pin);
    gpio_set_irq_enabled_with_callback(reset_pin, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &reset);
}