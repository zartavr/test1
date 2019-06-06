#include <libopencm3/stm32/gpio.h>

#include <hw/HwStub.hpp>

namespace hw {
HwStub::HwStub(uint32_t gpioport, uint8_t pin)
{
    gpio_mode_setup(gpioport, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, pin);
    gpio_set(gpioport, pin);
}

int HwStub::do_something(const etl::delegate<int(int)>& something)
{
    __asm("nop");
    return something(1) + 1;
}
}  // namespace hw
