/**
 * THIS FILE SHOULD BE REMOVED FROM
 * ACTUAL PROJECT. THIS IS JUST A
 * STUB.
 */

#include <libopencm3/stm32/gpio.h>

#include <hw/HwStub.hpp>

namespace hw {

HwStub::HwStub(uint32_t gpioport, uint8_t pin)
{
    gpio_mode_setup(gpioport, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, pin);
    gpio_set(gpioport, pin);
}

expected<int> HwStub::do_something(const Doable& something)
{
    __asm("nop");

    if (something(1) > 1000) {
        return something(1) + 1;
    }

    return tl::make_unexpected(Error_t::BAD_STUFF);
}

}  // namespace hw
