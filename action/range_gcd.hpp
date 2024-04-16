#pragma once


#include "action/base.hpp"
#include "action/helpers.hpp"

#include "algebraic/gcd.hpp"



namespace uni {

namespace actions {


template<class T>
using range_gcd = make_operatable_t<uni::algebraic::gcd<T>>;


} // namespace actions

} // namespace uni
