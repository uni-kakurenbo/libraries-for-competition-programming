#pragma once

#include <iterator>
#include <vector>
#include <functional>
#include <numeric>

#include "internal/types.hpp"

namespace lib {

template<class T, class container = std::vector<T>>
struct adjacent_difference : container {
  public:
    adjacent_difference() {}

    template<class I, class Operator = std::minus<T>>
    adjacent_difference(const I first, const I last, const bool remove_first = true, const Operator op = std::minus<T>{}) {
        this->resize(std::distance(first, last));
        std::adjacent_difference(first, last, begin(*this), op);
        if(remove_first) this->erase(begin(*this));
    }
};

} // namespace lib
