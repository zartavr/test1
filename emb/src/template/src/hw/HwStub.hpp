/**
 * THIS FILE SHOULD BE REMOVED FROM
 * ACTUAL PROJECT. THIS IS JUST A
 * STUB.
 */

#pragma once

#include <etl/delegate.h>

namespace hw {
class HwStub
{
 public:
    explicit HwStub(uint32_t gpioport, uint8_t pin);
    int do_something(const etl::delegate<int(int)>& something);

 private:
    HwStub(const HwStub&) = delete;
    HwStub(HwStub&&) = delete;
    HwStub& operator=(const HwStub&) = delete;
    HwStub& operator=(HwStub&&) = delete;
};
}  // namespace hw
