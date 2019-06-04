#include <libopencm3/stm32/gpio.h>
#include <yxml/yxml.h>

#include <hw/HwStub.hpp>
#include <template/version.h>

int main()
{
    ////
    // Do meaningless stuff for a testing
    // opencm3, yxml and etl compilation
    ////

    volatile yxml_t just_test;
    just_test.total = 1;  // never do this

    hw::HwStub hw_stub(GPIOA, GPIO1);

    while (true) {
        static uint32_t value = 0;
        value += hw_stub.do_something([](int value) { return value + 666; });
    }

    return 0;
}