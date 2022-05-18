/**
 * THIS FILE SHOULD BE REMOVED FROM
 * ACTUAL PROJECT. THIS IS JUST A
 * STUB.
 */

#pragma once

#include <etl/delegate.h>
#include <nonstd/expected.hpp>

namespace hw {

enum class Error_t
{
    BAD_STUFF
};

template<typename T>
using expected = nonstd::expected<T, Error_t>;

class HwStub
{
 public:
    using Doable = etl::delegate<int(int)>;

    explicit HwStub(uint32_t gpioport, uint8_t pin);

    expected<int> do_something(const Doable& something);

 private:
    HwStub(const HwStub&)            = delete;
    HwStub(HwStub&&)                 = delete;
    HwStub& operator=(const HwStub&) = delete;
    HwStub& operator=(HwStub&&)      = delete;
};
}  // namespace hw
