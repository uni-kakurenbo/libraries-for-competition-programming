#pragma once


#include "numeric/internal/primality_test.hpp"
#include "numeric/internal/factorize.hpp"
#include "numeric/internal/divisors.hpp"


namespace lib {

namespace internal {


constexpr i64 INTERNAL_MODINT_ID = -(1UL << 62);


inline constexpr bool is_prime(const u64 n) noexcept(NO_EXCEPT) {
    return is_prime<dynamic_modint_32bit<INTERNAL_MODINT_ID>, dynamic_modint_64bit<INTERNAL_MODINT_ID>>(n);
}

template<u64 N>
inline constexpr bool is_prime() noexcept(NO_EXCEPT) {
    return is_prime<static_modint_32bit<N>, static_modint_64bit<N>>(N);
}


inline auto factorize(const u64 n) noexcept(NO_EXCEPT) {
    return internal::factorize<dynamic_modint_32bit<INTERNAL_MODINT_ID>, dynamic_modint_64bit<INTERNAL_MODINT_ID>>(n);
}


inline auto divisors(const u64 n) noexcept(NO_EXCEPT) {
    return internal::divisors<dynamic_modint_32bit<INTERNAL_MODINT_ID>, dynamic_modint_64bit<INTERNAL_MODINT_ID>>(n);
}


} // namespace internal

using internal::is_prime;
using internal::divisors;

inline vector<i64> factorize(const i64 n) noexcept(NO_EXCEPT) {
    assert(n >= 0);
    auto res = internal::factorize(n);
    std::ranges::sort(res);
    return res;
}

inline set<i64> prime_factors(const i64 n) noexcept(NO_EXCEPT) {
    assert(n >= 0);
    const auto factors = factorize(n);
    set<i64> res(ALL(factors));
    return res;
}

inline map<i64,i64> count_factors(const i64 n) noexcept(NO_EXCEPT) {
    assert(n >= 0);
    map<i64,i64> mp;
    for(auto &x : internal::factorize(n)) mp[x]++;
    return mp;
}


} // namespace lib
