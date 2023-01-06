#pragma once

#include <cstddef>

#include "internal/types.hpp"


namespace lib {

namespace actions {

namespace internal {

struct base {};

} // namespace internal



template<class operator_monoid = std::nullptr_t> struct base : internal::base {
    static operator_monoid fold(const operator_monoid& x, const lib::internal::size_t) { return x; }
};


} // namespace actions

} // namespace lib
