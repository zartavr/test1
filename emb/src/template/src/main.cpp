#include <NamedType/named_type.hpp>
#include <libopencm3/stm32/gpio.h>
#include <yxml/yxml.h>

#include <hw/HwStub.hpp>  // it is just an example, remove it from actual project
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

    int32_t value = 0;
    while (true) {
        auto op_result =
          hw_stub.do_something([&value](int v) { return value + v; })
            .map([&value](auto e) { value += e; });

        if (!op_result) {
            while (true) {}
        }
    }

    return 0;
}
