#pragma once

#include "data_structure/core/implicit_treap.hpp"

namespace lib {


template <class T0>
struct range_affine_range_sum : implicit_treap<T0,std::pair<T0, T0>> {
    using size_t = typename implicit_treap<T0,std::pair<T0, T0>>::size_t;
    using T1 = std::pair<T0, T0>;  // first * x + second

    template<class... Args>
    explicit range_affine_range_sum(Args&&... args) : implicit_treap<T0,T1>::implicit_treap(0, { 1, 0 }) {
        this->initialize(std::forward<Args>(args)...);
    }

    inline T0 f0(const T0 x, const T0 y) const override { return x + y; }
    inline T1 f1(const T1 x, const T1 y) const override { return { x.first * y.first, x.second * y.first + y.second }; }
    inline T0 g(const T0 x, const T1 y) const override { return y.first * x + y.second; }
    inline T1 p(const T1 x, const size_t len) const override { return { x.first, x.second * len }; }


    inline auto affine(const size_t first, const size_t last, const T0& a, const T0& b) { return this->apply(first, last, { a, b }); }
    inline auto affine(const size_t pos, const T0& a, const T0& b) { return this->apply(pos, { a, b }); }
    inline auto affine(const T0& a, const T0& b) { return this->apply({ a, b }); }

    inline auto set(const size_t first, const size_t last, const T0& val) { return this->apply(first, last, { 0, val }); }
    inline auto set(const size_t pos, const T0& val) { return this->apply(pos, { 0, val }); }
    inline auto set(const T0& val) { return this->apply({ 0, val }); }

    inline auto add(const size_t first, const size_t last, const T0& val) { return this->apply(first, last, { 1, val }); }
    inline auto add(const size_t pos, const T0& val) { return this->apply(pos, { 1, val }); }
    inline auto add(const T0& val) { return this->apply({ 1, val }); }

    inline auto times(const size_t first, const size_t last, const T0& val) { return this->apply(first, last, { val, 0 }); }
    inline auto times(const size_t pos, const T0& val) { return this->apply(pos, { val, 0 }); }
    inline auto times(const T0& val) { return this->apply({ val, 0 }); }


    inline auto sum(const size_t first, const size_t last) { return this->prod(first, last); }
    inline auto sum() { return this->prod(); }
};


} // namespace lib
