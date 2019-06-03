#include <libopencm3/stm32/gpio.h>

#include <hw/HwStub.hpp>

int main()
{
    ////
    // Do meaningless stuff for a testing
    // opencm3 and etl compilation
    ////

    hw::HwStub hw_stub(GPIOA, GPIO1);

    while (true) {
        static uint32_t value = 0;
        value += hw_stub.do_something([](int value) { return value + 666; });
    }

    return 0;
}