#line 1 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
#pragma once

/* #expanded [adapter/input.hpp] */
#line 1 "adapter/input.hpp"



#include <atcoder/modint>

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <utility>
#include <tuple>

/* #expanded [internal/dev_env.hpp] */
#line 1 "internal/dev_env.hpp"


#ifdef LOCAL_JUDGE
    constexpr bool DEV_ENV = true;
    constexpr bool NO_EXCEPT = false;
#else
    constexpr bool DEV_ENV = false;
    constexpr bool NO_EXCEPT = true;
#endif // LOCAL_JUDGE
/* [internal/dev_env.hpp] */
#line 14 "adapter/input.hpp"
/* #expanded [internal/resolving_rank.hpp] */
#line 1 "internal/resolving_rank.hpp"


namespace lib {

namespace internal {

template<int P> struct resolving_rank : resolving_rank<P-1> {};
template<> struct resolving_rank<0> {};

} // namespace internal

} // namespace lib
/* [internal/resolving_rank.hpp] */
#line 15 "adapter/input.hpp"


namespace lib {


template<class source = std::istream>
struct input_adapter {
  private:
    template<class T>
    auto _set(lib::internal::resolving_rank<4>, T *const val) noexcept(NO_EXCEPT) -> decltype(std::declval<source&>() >> *val, 0) {
        *this->in >> *val;
        return 0;
    }
    template<class T>
    auto _set(lib::internal::resolving_rank<3>, T *const val) noexcept(NO_EXCEPT) -> decltype(std::begin(*val), std::end(*val), 0) {
        (*this)(std::begin(*val), std::end(*val));
        return 0;
    }
    template<class T>
    auto _set(lib::internal::resolving_rank<2>, T *const val) noexcept(NO_EXCEPT) -> decltype(val->first, val->second, 0) {
        (*this)(&*val);
        return 0;
    }
    template<class T>
    auto _set(lib::internal::resolving_rank<1>, T *const val) noexcept(NO_EXCEPT) -> decltype(std::get<0>(*val), 0) {
        std::apply([this](auto&... args) constexpr { ((*this >> args), ...); }, *val);
        return 0;
    }
    template<class T>
    auto _set(lib::internal::resolving_rank<0>, T *const val) noexcept(NO_EXCEPT) -> std::enable_if_t<atcoder::internal::is_modint<T>::value,int> {
        long long v; std::cin >> v;
        *val = { v };
        return 0;
    }

  protected:
    template<class T>
    source *set(T& val) noexcept(NO_EXCEPT) {
        this->_set(lib::internal::resolving_rank<10>{}, &val);
        return this->in;
    }
    template<class T>
    source *set(T&& _val) noexcept(NO_EXCEPT) {
        T val = _val;
        this->_set(lib::internal::resolving_rank<10>{}, &val);
        return this->in;
    }

  public:
    using char_type = typename source::char_type;

    source *in;

    input_adapter(source *_in = &std::cin) noexcept(NO_EXCEPT) : in(_in) {}

    template<class T> inline input_adapter& operator>>(T&& s) noexcept(NO_EXCEPT) {
        this->set(std::forward<T>(s));
        return *this;
    }

    template<class T> inline T one() noexcept(NO_EXCEPT) {
        T val; *this >> val;
        return val;
    }

    template<class T> inline void operator()(T*const val) noexcept(NO_EXCEPT) {
        *this >> *val;
    }

    template<class T, class... Args> inline void operator()(T *const head, Args *const... tail) noexcept(NO_EXCEPT) {
        *this >> *head;
        (*this)(tail...);
    }

    template<class I, class = typename std::iterator_traits<I>::value_type> inline void operator()(I first, I last) noexcept(NO_EXCEPT) {
        for(I itr=first; itr!=last; ++itr) *this >> *itr;
    }

    template<class F, class S> inline void operator()(std::pair<F,S> *const p) noexcept(NO_EXCEPT) {
        *this >> p->first >> p->second;
    }
};


} // namespace lib
/* [adapter/input.hpp] */
#line 4 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [adapter/output.hpp] */
#line 1 "adapter/output.hpp"




#include <iomanip>



#include <variant>





namespace lib {


template<class destination = std::ostream>
struct output_adapter {
  private:
    template<class T>
    auto _put(lib::internal::resolving_rank<4>, const T& val) noexcept(NO_EXCEPT)-> decltype(std::declval<destination&>() << val, 0) {
        *this->out << val;
        return 0;
    }
    template<class T>
    auto _put(lib::internal::resolving_rank<3>, const T& val) noexcept(NO_EXCEPT)-> decltype(val.val(), 0) {
        this->put(val.val());
        return 0;
    }
    template<class T>
    auto _put(lib::internal::resolving_rank<2>, const T& val) noexcept(NO_EXCEPT)-> decltype(std::begin(val), std::end(val), 0) {
        (*this)(std::begin(val), std::end(val), false);
        return 0;
    }
    template<class T>
    auto _put(lib::internal::resolving_rank<1>, const T& val) noexcept(NO_EXCEPT) -> decltype(val.first, val.second, 0) {
        (*this)(val);
        return 0;
    }
    template<class T>
    auto _put(lib::internal::resolving_rank<0>, const T& val) noexcept(NO_EXCEPT) -> decltype(std::get<0>(val), 0) {
        std::apply([this](const auto&... args) constexpr { ((*this << args), ...); }, val);
        return 0;
    }

  protected:
    template<class T>
    destination *put(const T &val) noexcept(NO_EXCEPT){
        this->_put(lib::internal::resolving_rank<10>{}, val);
        return this->out;
    }

  public:
    using char_type = typename destination::char_type;

    static constexpr auto sendl = std::endl<char_type,std::char_traits<char_type>>;
    static constexpr auto sflush = std::flush<char_type,std::char_traits<char_type>>;

  protected:
    using sfunc_type = std::remove_const_t<decltype(output_adapter::sendl)>;

  public:
    using separator_type = std::variant<std::string,sfunc_type>;

    destination *out;
    separator_type endline;
    separator_type separator;

  protected:
    void put_separator() noexcept(NO_EXCEPT) {
        if(this->separator.index() == 0) *this->out << std::get<std::string>(this->separator);
        if(this->separator.index() == 1) *this->out << std::get<sfunc_type>(this->separator);
    }
    void put_endline() noexcept(NO_EXCEPT) {
        if(this->endline.index() == 0) *this->out << std::get<std::string>(this->endline);
        if(this->endline.index() == 1) *this->out << std::get<sfunc_type>(this->endline);
    }

  public:
    template<class Terminator = std::string, class Separator = std::string>
    output_adapter(destination *des = &std::cout, Terminator endl = "\n", Separator sep = " ") noexcept(NO_EXCEPT)
      : out(des), endline(endl), separator(sep)
    {
        *this << std::fixed << std::setprecision(20);
    }

    inline auto& seekp(const typename destination::off_type off, const std::ios_base::seekdir dir = std::ios_base::cur) noexcept(NO_EXCEPT){ this->out->seekp(off, dir); return *this; };

    template<class T> inline output_adapter& operator<<(const T &s) noexcept(NO_EXCEPT){
        this->put(s);
        return *this;
    }

    template<class T = std::string> inline void operator()(const T &val = "") noexcept(NO_EXCEPT){
        *this << val, this->put_endline();
    }

    template<class T, class ...Args> inline void operator()(const T &head, const Args& ...tail) noexcept(NO_EXCEPT){
        *this << head, this->put_separator();
        (*this)(tail...);
    }

    template<class I, class = typename std::iterator_traits<I>::iterator_category> inline void operator()(const I first, const I last, const bool terminate = true) noexcept(NO_EXCEPT){
        for(I itr=first; itr!=last;) {
            *this << *itr;
            if(++itr == last) {
                if(terminate) this->put_endline();
            }
            else this->put_separator();
        }
    }

    template<class T> inline void operator()(const std::initializer_list<T> vals) noexcept(NO_EXCEPT){
        std::vector wrapped(vals.begin(), vals.end());
        (*this)(wrapped.begin(), wrapped.end());
    }

    template<class F, class S> inline void operator()(const std::pair<F,S> &p) noexcept(NO_EXCEPT){
        (*this)(p.first, p.second);
    }
};


} // namespace lib
/* [adapter/output.hpp] */
#line 5 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [adapter/array.hpp] */
#line 1 "adapter/array.hpp"



#include <array>
#include <algorithm>
/* #expanded [adapter/internal/sequence.hpp] */
#line 1 "adapter/internal/sequence.hpp"







namespace lib {

namespace internal {


template<class Base>
struct extended_sequence : Base {
    using Base::Base;

    inline auto& sort() noexcept(NO_EXCEPT) {
        std::sort(std::begin(*this), std::end(*this));
        return *this;
    }

    template<class F>
    inline auto& sort(const F&& f) noexcept(NO_EXCEPT) {
        std::sort(std::begin(*this), std::end(*this), f);
        return *this;
    }

    inline auto& reverse() noexcept(NO_EXCEPT) {
        std::reverse(std::begin(*this), std::end(*this));
        return *this;
    }

    template<class T>
    inline auto binary_search(const T& v) noexcept(NO_EXCEPT) {
        return std::binary_search(std::begin(*this), std::end(*this), v);
    }

    template<class T>
    inline auto lower_bound(const T& v) noexcept(NO_EXCEPT) {
        return std::lower_bound(std::begin(*this), std::end(*this), v);
    }

    template<class T>
    inline auto upper_bound(const T& v) noexcept(NO_EXCEPT) {
        return std::upper_bound(std::begin(*this), std::end(*this), v);
    }
};


} // namespace internal

} // namespace lib
/* [adapter/internal/sequence.hpp] */
#line 7 "adapter/array.hpp"


namespace lib {


template<class... Args>
using array = internal::extended_sequence<std::array<Args...>>;


} // namespace lib
/* [adapter/array.hpp] */
#line 7 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [adapter/string.hpp] */
#line 1 "adapter/string.hpp"









namespace lib {


using string = internal::extended_sequence<std::string>;


} // namespace lib
/* [adapter/string.hpp] */
#line 8 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [adapter/valarray.hpp] */
#line 1 "adapter/valarray.hpp"



#include <cassert>
#include <valarray>

#include <type_traits>

#include <initializer_list>


/* #expanded [internal/types.hpp] */
#line 1 "internal/types.hpp"


#include <cstdint>

namespace lib {

namespace internal {

using size_t = std::int32_t;

using int128_t = __int128_t;
using uint128_t = __uint128_t;

}

} // namespace lib
/* [internal/types.hpp] */
#line 13 "adapter/valarray.hpp"




namespace lib {


template<class T> struct valarray : internal::extended_sequence<std::valarray<T>> {
  private:
    using base = internal::extended_sequence<std::valarray<T>>;

  public:
    using size_type = internal::size_t;

    using iterator = T*;
    using const_iterator = const T*;

  protected:
    inline bool _validate_index_in_right_open([[maybe_unused]] const size_type p) const noexcept(NO_EXCEPT) {
        return 0 <= p and p < this->size();
    }
    inline bool _validate_index_in_closed([[maybe_unused]] const size_type p) const noexcept(NO_EXCEPT) {
        return 0 <= p and p <= this->size();
    }
    inline bool _validate_rigth_open_interval([[maybe_unused]] const size_type l, [[maybe_unused]] const size_type r) const noexcept(NO_EXCEPT) {
        return 0 <= l and l <= r and r <= this->size();
    }

    inline size_type _positivize_index(const size_type p) const noexcept(NO_EXCEPT) {
        return p < 0 ? this->size() + p : p;
    }

  public:
    valarray() noexcept(NO_EXCEPT) {}

    valarray(const std::size_t length, const T& val = T{}) noexcept(NO_EXCEPT) : base(std::forward<const T>(val), length) {}

    template<class I, typename std::iterator_traits<I>::value_type* = nullptr>
    valarray(const I first, const I last) noexcept(NO_EXCEPT) : base(first, std::distance(first, last)) {}

    template<class U> valarray(const std::initializer_list<U>& init) noexcept(NO_EXCEPT) : valarray(std::begin(init), std::end(init)) {}


    inline auto size() const noexcept(NO_EXCEPT) { return static_cast<size_type>(this->base::size()); }

    inline void reserve(const size_type) noexcept(NO_EXCEPT) { /* do nothing */ }

    template<class I, typename std::iterator_traits<I>::value_type* = nullptr>
    inline void assign(const I first, const I last) noexcept(NO_EXCEPT) {
        this->resize(std::distance(first, last));
        std::copy(first, last, std::begin(*this));
    }

    inline void assign(const std::size_t length, const T& val = T{}) noexcept(NO_EXCEPT) {
        this->base::resize(length, val);
    }

    inline void resize(const std::size_t length, const T& val = T{}) noexcept(NO_EXCEPT) {
        base temp = *this;
        this->assign(length, val);
        std::move(std::begin(temp), std::min(std::end(temp), std::next(std::begin(temp), length)), std::begin(*this));
    }

    inline const T& operator[](size_type pos) const noexcept(NO_EXCEPT) {
        pos = this->_positivize_index(pos), assert(this->_validate_index_in_right_open(pos));
        return this->base::operator[](pos);
    }
    inline T& operator[](size_type pos) noexcept(NO_EXCEPT) {
        pos = this->_positivize_index(pos), assert(this->_validate_index_in_right_open(pos));
        return this->base::operator[](pos);
    }

    inline const T& back() const noexcept(NO_EXCEPT) { return *std::prev(this->end()); }
    inline T& back() noexcept(NO_EXCEPT) { return *std::prev(this->end()); }

    inline const T& front() const noexcept(NO_EXCEPT) { return *this->begin(); }
    inline T& front() noexcept(NO_EXCEPT) { return *this->begin(); }

    inline const T* begin() const noexcept(NO_EXCEPT) { return this->size() ? std::addressof((*this)[0]) : nullptr; }
    inline T* begin() noexcept(NO_EXCEPT) { return this->size() ? std::addressof((*this)[0]) : nullptr; }

    inline const T* end() const noexcept(NO_EXCEPT) { if(auto n = this->size()) { return std::addressof((*this)[0]) + n; } else { return nullptr; } }
    inline T* end() noexcept(NO_EXCEPT) { if(auto n = this->size()) { return std::addressof((*this)[0]) + n; } else { return nullptr; } }
};


} // namespace lib
/* [adapter/valarray.hpp] */
#line 9 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [adapter/vector.hpp] */
#line 1 "adapter/vector.hpp"








namespace lib {


template<class... Args>
using vector = internal::extended_sequence<std::vector<Args...>>;


} // namespace lib
/* [adapter/vector.hpp] */
#line 10 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [adapter/map.hpp] */
#line 1 "adapter/map.hpp"



#include <map>
#include <unordered_map>


/* #expanded [internal/exception.hpp] */
#line 1 "internal/exception.hpp"


namespace lib {

namespace internal {


template<class... T> constexpr bool EXCEPTION = false;
template<const int T> constexpr bool EXCEPTION_INT = false;


} // namespace internal

} // namespace lib
/* [internal/exception.hpp] */
#line 9 "adapter/map.hpp"

/* #expanded [adapter/set.hpp] */
#line 1 "adapter/set.hpp"



#include <set>
#include <unordered_set>

#include <optional>




/* #expanded [utility/functional.hpp] */
#line 1 "utility/functional.hpp"



#include <functional>


/* #expanded [numeric/arithmetic.hpp] */
#line 1 "numeric/arithmetic.hpp"




#include <cstring>





#include <atcoder/math.hpp>

/* #expanded [snippet/aliases.hpp] */
#line 1 "snippet/aliases.hpp"








/* #expanded [snippet/internal/types.hpp] */
#line 1 "snippet/internal/types.hpp"




namespace lib {


using i16 = std::int16_t;
using u16 = std::uint16_t;

using i32 = std::int32_t;
using u32 = std::uint32_t;

using i64 = std::int64_t;
using u64 = std::uint64_t;

#ifdef __GNUC__
using i128 = __int128_t;
using u128 = __uint128_t;
#endif

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;


} // namespace lib
/* [snippet/internal/types.hpp] */
#line 10 "snippet/aliases.hpp"


#define until(...) while(!(__VA_ARGS__))

#define ALL(x) std::begin((x)),std::end((x))
#define RALL(x) std::rbegin((x)),std::rend((x))

#define $F first
#define $S second

namespace lib {

template<class T> using spair = std::pair<T,T>;

}

namespace std {

using bit_reference = std::vector<bool>::reference;

bit_reference operator |= (bit_reference a, const bool b) noexcept(NO_EXCEPT) { return a = a | b; }
bit_reference operator &= (bit_reference a, const bool b) noexcept(NO_EXCEPT) { return a = a & b; }

}
/* [snippet/aliases.hpp] */
#line 14 "numeric/arithmetic.hpp"
/* #expanded [snippet/iterations.hpp] */
#line 1 "snippet/iterations.hpp"



/* #expanded [snippet/internal/overload.hpp] */
#line 1 "snippet/internal/overload.hpp"


#define $OVERLOAD2(arg0, arg1, cmd, ...) cmd
#define $OVERLOAD3(arg0, arg1, arg2, cmd, ...) cmd
#define $OVERLOAD4(arg0, arg1, arg2, arg3, cmd, ...) cmd
#define $OVERLOAD5(arg0, arg1, arg2, arg3, arg4, cmd, ...) cmd
/* [snippet/internal/overload.hpp] */
#line 5 "snippet/iterations.hpp"

#define LOOP(n) REPI($_, (n))

#define REPI(i,n) for(int i=0, i##_length=static_cast<int>(n); i<i##_length; ++i)
#define REPF(i,l,r) for(std::common_type_t<std::decay_t<decltype(l)>,std::decay_t<decltype(r)>> i=(l), i##_last=(r); i<i##_last; ++i)
#define REPIS(i,l,r,s) for(std::common_type_t<std::decay_t<decltype(l)>,std::decay_t<decltype(r)>,std::decay_t<decltype(s)>> i=(l), i##_last=(r); i<i##_last; i+=(s))

#define REPR(i,n) for(auto i=(n); --i>=0;)
#define REPB(i,l,r) for(std::common_type_t<std::decay_t<decltype(l)>,std::decay_t<decltype(r)>> i=(r), i##_last=(l); --i>=i##_last;)
#define REPRS(i,l,r,s) for(std::common_type_t<std::decay_t<decltype(l)>,std::decay_t<decltype(r)>,std::decay_t<decltype(s)>> i=(l)+((r)-(l)-1)/(s)*(s), i##_last=(l); i>=i##_last; (i-=(s)))

#define REP(...) $OVERLOAD4(__VA_ARGS__, REPIS, REPF, REPI, LOOP)(__VA_ARGS__)
#define REPD(...) $OVERLOAD4(__VA_ARGS__, REPRS, REPB, REPR)(__VA_ARGS__)

#define FORO(i,n) for(int i=0, i##_last=static_cast<int>(n); i<=i##_last; ++i)
#define FORI(i,l,r) for(std::common_type_t<std::decay_t<decltype(l)>,std::decay_t<decltype(r)>> i=(l), i##_last=(r); i<=i##_last; ++i)
#define FORIS(i,l,r,s) for(std::common_type_t<std::decay_t<decltype(l)>,std::decay_t<decltype(r)>,std::decay_t<decltype(s)>> i=(l), i##_last=(r); i<=i##_last; i+=(s))

#define FORRO(i,n) for(auto i=(n); i>=0; --i)
#define FORR(i,l,r) for(std::common_type_t<std::decay_t<decltype(l)>,std::decay_t<decltype(r)>> i=(r), i##_last=(l); i>=i##_last; --i)
#define FORRS(i,l,r,s) for(std::common_type_t<std::decay_t<decltype(l)>,std::decay_t<decltype(r)>,std::decay_t<decltype(s)>> i=(l)+((r)-(l))/(s)*(s), i##_last=(l); i>=i##_last; i-=(s))

#define FOR(...) $OVERLOAD4(__VA_ARGS__, FORIS, FORI, FORO)(__VA_ARGS__)
#define FORD(...) $OVERLOAD4(__VA_ARGS__, FORRS, FORR, FORRO)(__VA_ARGS__)

#define ITR1(e0,v) for(const auto &e0 : (v))
#define ITRP1(e0,v) for(auto e0 : (v))
#define ITRR1(e0,v) for(auto &e0 : (v))

#define ITR2(e0,e1,v) for(const auto [e0, e1] : (v))
#define ITRP2(e0,e1,v) for(auto [e0, e1] : (v))
#define ITRR2(e0,e1,v) for(auto &[e0, e1] : (v))

#define ITR3(e0,e1,e2,v) for(const auto [e0, e1, e2] : (v))
#define ITRP3(e0,e1,e2,v) for(auto [e0, e1, e2] : (v))
#define ITRR3(e0,e1,e2,v) for(auto &[e0, e1, e2] : (v))

#define ITR4(e0,e1,e2,e3,v) for(const auto [e0, e1, e2, e3] : (v))
#define ITRP4(e0,e1,e2,e3,v) for(auto [e0, e1, e2, e3] : (v))
#define ITRR4(e0,e1,e2,e3,v) for(auto &[e0, e1, e2, e3] : (v))

#define ITR(...) $OVERLOAD5(__VA_ARGS__, ITR4, ITR3, ITR2, ITR1)(__VA_ARGS__)
#define ITRP(...) $OVERLOAD5(__VA_ARGS__, ITRP4, ITRP3, ITRP2, ITRP1)(__VA_ARGS__)
#define ITRR(...) $OVERLOAD5(__VA_ARGS__, ITRR4, ITRR3, ITRR2, ITRR1)(__VA_ARGS__)
/* [snippet/iterations.hpp] */
#line 15 "numeric/arithmetic.hpp"




/* #expanded [numeric/internal/number_base.hpp] */
#line 1 "numeric/internal/number_base.hpp"




#include <cstddef>








namespace lib {


template<std::size_t B = 2, class T>
std::string base_n_string(T v) noexcept(NO_EXCEPT) {
    constexpr char CHARS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static_assert(0 < B and B <= std::strlen(CHARS));
    assert(0 <= v);

    std::string res;
    while(v > 0) {
        res += CHARS[v%B];
        v /= B;
    }
    std::reverse(ALL(res));

    return res;
}


template<class T>
std::string base_n_string(T v, std::size_t b) noexcept(NO_EXCEPT) {
    constexpr char CHARS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    assert(1 < b && b <= std::strlen(CHARS));
    assert(0 <= v);

    std::string res;
    while(v > 0) {
        res += CHARS[v%b];
        v /= b;
    }
    std::reverse(ALL(res));

    return res;
}

template<class T>
std::vector<T> base_n_vector(T v, std::size_t b = 2) noexcept(NO_EXCEPT) {
    assert(1 < b);
    assert(0 <= v);

    std::vector<T> res;
    while(v > 0) {
        res.push_back(v%b);
        v /= b;
    }
    std::reverse(ALL(res));

    return res;
}


} // namespace lib
/* [numeric/internal/number_base.hpp] */
#line 20 "numeric/arithmetic.hpp"

/* #expanded [iterable/operation.hpp] */
#line 1 "iterable/operation.hpp"






#include <sstream>




#include <numeric>






/* #expanded [internal/type_traits.hpp] */
#line 1 "internal/type_traits.hpp"



#ifndef $TYPE_TRAITS // for debuggers
#define $TYPE_TRAITS








namespace lib {

namespace internal {


template<class T, class... Us>
using are_same = std::conjunction<std::is_same<T,Us>...>;

template<class T, class... Us>
inline constexpr bool are_same_v = std::conjunction_v<std::is_same<T,Us>...>;


template<class Base, class... Derived>
using are_base_of = std::conjunction<std::is_base_of<Base,Derived>...>;

template<class Base, class... Derived>
inline constexpr bool are_base_of_v = std::conjunction_v<std::is_same<Base,Derived>...>;


template<class T> struct remove_cvref {
  using type = typename std::remove_cv_t<std::remove_reference_t<T>>;
};

template<class T> using remove_cvref_t = typename remove_cvref<T>::type;


template<class T> struct literal_operator { static constexpr const char* value = ""; };
template<> struct literal_operator<unsigned> { static constexpr const char* value = "U"; };
template<> struct literal_operator<long> { static constexpr const char* value = "L"; };
template<> struct literal_operator<long double> { static constexpr const char* value = "L"; };
template<> struct literal_operator<unsigned long> { static constexpr const char* value = "UL"; };
template<> struct literal_operator<long long> { static constexpr const char* value = "LL"; };
template<> struct literal_operator<unsigned long long> { static constexpr const char* value = "ULL"; };

template<class T> inline constexpr auto literal_operator_v = literal_operator<T>::value;


template<template <class...> class Template, class Arg> struct is_template : std::false_type {};
template<template <class...> class Template, class... Args> struct is_template<Template, Template<Args...>> : std::true_type {};

template<template <class...> class Template, class... Args>
inline constexpr bool  is_template_v = is_template<Template,Args...>::value;


template<class T> struct is_loggable {
    template<class U>
    static constexpr auto External(U &&v) -> decltype(_debug(v), std::true_type());
    static constexpr std::false_type External(...);

    template<class U>
    static constexpr auto Member(U &&v) -> decltype(v._debug(), std::true_type());
    static constexpr std::false_type Member(...);

    static constexpr bool value = (
      decltype(External(std::declval<T>()))::value ||
      decltype(Member(std::declval<T>()))::value
    );

};

template<class T> inline constexpr auto is_loggable_v = is_loggable<T>::value;


template<class T> struct _has_iterator {
    template<class U>
    static constexpr auto ADL(U &&v) -> decltype(begin(v), end(v), std::true_type());
    static constexpr std::false_type ADL(...);

    template<class U>
    static constexpr auto STL(U &&v) -> decltype(std::begin(v), std::end(v), std::true_type());
    static constexpr std::false_type STL(...);

    template<class U>
    static constexpr auto Member(U &&v) -> decltype(v.begin(), v.end(), std::true_type());
    static constexpr std::false_type Member(...);
};

template<class T> struct has_iterator {
  struct ADL : decltype(_has_iterator<T>::ADL(std::declval<T>())) {};
  struct STL : decltype(_has_iterator<T>::STL(std::declval<T>())) {};
  struct Member : decltype(_has_iterator<T>::Member(std::declval<T>())) {};

  static constexpr auto ADL_v = ADL::value;
  static constexpr auto STL_v = STL::value;
  static constexpr auto Member_v = Member::value;
};


template<class T> struct is_iterable {
    static constexpr bool value =  has_iterator<T>::ADL_v || has_iterator<T>::STL_v || has_iterator<T>::Member_v;
};

template<class T> inline constexpr auto is_iterable_v = is_iterable<T>::value;


template<class T> struct iterator_resolver {
  template<typename U>
  static auto begin(U&& v){
    using U_t = remove_cvref_t<U>;

    static_assert(std::is_same_v<U_t, remove_cvref_t<T>>);
    static_assert(is_iterable_v<T>);

    if constexpr (has_iterator<T>::Member_v){
      return v.begin();
    } else {
      using std::begin;
      return begin(std::forward<U>(v));
    }
  }

  template<typename U>
  static auto end(U&& v){
    using U_t = remove_cvref_t<U>;

    static_assert(std::is_same_v<U_t, remove_cvref_t<T>>);
    static_assert(is_iterable_v<T>);

    if constexpr (has_iterator<T>::Member_v){
      return v.end();
    } else {
      using std::end;
      return end(std::forward<U>(v));
    }
  }
};


template<class C> using iterator_t = decltype(iterator_resolver<C>::begin(std::declval<C&>()));

template<class C> using container_size_t = decltype(std::size(std::declval<C&>()));


}  // namespace internal

}  // namespace atcoder

#endif //ifndef $TYPE_TRAITS
/* [internal/type_traits.hpp] */
#line 20 "iterable/operation.hpp"


/* #expanded [iterable/z_array.hpp] */
#line 1 "iterable/z_array.hpp"






#line 7 "iterable/z_array.hpp"


namespace lib {


// Thanks to: atcoder::z_algorithm
template<class SizeType = internal::size_t, class Container = valarray<SizeType>>
struct z_array : Container {
    using size_type = SizeType;

    template<class I>
    explicit z_array(const I first, const I last) : Container(std::distance(first, last), {}) {
        const size_type n = static_cast<size_type>(std::distance(first, last));
        if(n == 0) return;
        for(size_type i=1, j=0; i<n; ++i) {
            size_type& k = this->operator[](i);
            k = (j + this->operator[](j) <= i) ? 0 : std::min(j + this->operator[](j) - i, this->operator[](i - j));
            while(i + k < n and first[k] == first[i + k]) ++k;
            if(j + this->operator[](j) < i + this->operator[](i)) j = i;
        }
        *this->begin() = n;
    }
};


} // namespace lib
/* [iterable/z_array.hpp] */
#line 23 "iterable/operation.hpp"

#line 24 "iterable/operation.hpp"

/* #expanded [constants.hpp] */
#line 1 "constants.hpp"








/* #expanded [numeric/limits.hpp] */
#line 1 "numeric/limits.hpp"



#include <limits>




namespace lib {


template<class T>
struct numeric_limits : std::numeric_limits<T> {
    static constexpr T arithmetic_infinity() noexcept(NO_EXCEPT) {
        return std::numeric_limits<T>::max() / 2 - 1;
    }

    static constexpr T arithmetic_negative_infinity() noexcept(NO_EXCEPT) {
        return std::numeric_limits<T>::lowest() / 2 + 1;
    }
};


} // namespace lib
/* [numeric/limits.hpp] */
#line 10 "constants.hpp"

/* #expanded [numeric/modint.hpp] */
#line 1 "numeric/modint.hpp"












namespace lib {


using atcoder::dynamic_modint;
using atcoder::modint;

template<u32> struct static_modint_32bit;
template<u32 Mod> using static_modint = static_modint_32bit<Mod>;
using modint998244353 = static_modint_32bit<998244353>;
using modint1000000007 = static_modint_32bit<1000000007>;

template<int> struct dynamic_modint_64bit;
using modint64 = dynamic_modint_64bit<-1>;


} // namespace lib


namespace lib {


// Thanks to: https://hackmd.io/@tatyam-prime/rkVCOcwQn
template<u32 Mod> class static_modint_32bit {
    using u32 = uint32_t;
    using i32 = int32_t;
    using i64 = int64_t;

    using mint = static_modint_32bit;
    u32 _v = 0;

    static constexpr bool prime = []() -> bool {
        if(Mod == 1) return 0;
        if(Mod == 2 || Mod == 7 || Mod == 61) return 1;
        if(Mod % 2 == 0) return 0;
        u32 d = Mod - 1;
        while(d % 2 == 0) d /= 2;
        for(const u32 a : {2, 7, 61}) {
            u32 t = d;
            mint y = mint(a).pow(t);
            while(t != Mod - 1 && y != 1 && y != Mod - 1) {
                y *= y; t <<= 1;
            }
            if(y != Mod - 1 && t % 2 == 0) return 0;
        }
        return 1;
    }();

    static constexpr std::pair<i32,i32> inv_gcd(const i32 a, const i32 b) {
        if(a == 0) return { b, 0 };
        i32 s = b, t = a, m0 = 0, m1 = 1;
        while(t) {
            const i32 u = s / t;
            s -= t * u; m0 -= m1 * u;
            std::swap(s, t), std::swap(m0, m1);
        }
        if(m0 < 0) m0 += b / s;
        return { s, m0 };
    }
public:
    static constexpr mint raw(const u32 v) { mint a; a._v = v; return a; }
    constexpr static_modint_32bit() {}

    template <class T>
    constexpr static_modint_32bit(const T v) {
        static_assert(std::is_integral_v<T>, "T is not integral type.");
        if constexpr(std::is_signed_v<T>) {
            i64 x = i64(v % i64(Mod));
            if(x < 0) x += Mod; _v = u32(x);
        }
        else _v = u32(v % Mod);
    }

    static constexpr u32 mod() { return Mod; }

    constexpr u32 val() const { return _v; }

    constexpr mint& operator++() { return *this += 1; }
    constexpr mint& operator--() { return *this -= 1; }

    constexpr mint operator++(int) { mint res = *this; ++*this; return res; }
    constexpr mint operator--(int) { mint res = *this; --*this; return res; }

    constexpr mint& operator+=(mint rhs) {
        if(_v >= Mod - rhs._v) _v -= Mod;
        _v += rhs._v; return *this;
    }

    constexpr mint& operator-=(mint rhs) {
        if(_v < rhs._v) _v += Mod;
        _v -= rhs._v; return *this;
    }

    constexpr mint& operator*=(mint rhs) { return *this = *this * rhs; }
    constexpr mint& operator/=(mint rhs) { return *this *= rhs.inv(); }
    constexpr mint operator+() const { return *this; }
    constexpr mint operator-() const { return mint{} - *this; }

    constexpr mint pow(long long n) const {
        assert(0 <= n);
        if(n == 0) return 1;
        mint x = *this, r = 1;
        while(1) {
            if(n & 1) r *= x; n >>= 1;
            if(n == 0) return r;
            x *= x;
        }
    }

    constexpr mint inv() const {
        if constexpr(prime) {
            assert(_v);
            return pow(Mod - 2);
        } else {
            auto eg = inv_gcd(_v, Mod);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend constexpr mint operator+(mint lhs, mint rhs) { return lhs += rhs; }
    friend constexpr mint operator-(mint lhs, mint rhs) { return lhs -= rhs; }
    friend constexpr mint operator*(mint lhs, mint rhs) { return u64(lhs._v) * rhs._v; }
    friend constexpr mint operator/(mint lhs, mint rhs) { return lhs /= rhs; }
    friend constexpr bool operator==(mint lhs, mint rhs) { return lhs._v == rhs._v; }
    friend constexpr bool operator!=(mint lhs, mint rhs) { return lhs._v != rhs._v; }
};

//Thanks to: https://github.com/NyaanNyaan/library/blob/master/modint/modint-montgomery64.hpp
template <int id> struct dynamic_modint_64bit : atcoder::internal::modint_base {
  private:
    using mint = dynamic_modint_64bit;

    using i64 = std::int64_t;
    using u64 = std::uint64_t;
    using u128 = internal::uint128_t;

  protected:
    static u64 _mod;
    static u64 r;
    static u64 n2;

    static u64 get_r() noexcept(NO_EXCEPT) {
        u64 res = _mod;
        for(i64 i = 0; i < 5; ++i)
            res *= 2 - _mod * res;
        return res;
    }

    static u64 reduce(const u128 &b) noexcept(NO_EXCEPT) {
        return static_cast<u64>((b + static_cast<u128>(static_cast<u64>(b) * static_cast<u64>(-r)) * _mod) >> 64);
    }


  public:
    static u64 mod() noexcept(NO_EXCEPT) { return _mod; }

    static void set_mod(const u64 m) noexcept(NO_EXCEPT) {
        assert(m < (1UL << 63));
        assert((m & 1) == 1);
        _mod = m;
        n2 = static_cast<u64>(-static_cast<u128>(m) % m);
        r = get_r();
        assert(r * _mod == 1);
    }

    u64 _val;

    dynamic_modint_64bit() noexcept(NO_EXCEPT) : _val(0) {}
    dynamic_modint_64bit(const i64 b) noexcept(NO_EXCEPT)
    : _val(this->reduce((static_cast<u128>(b) + this->_mod) * this->n2)) {};

    mint &operator+=(const mint &b) noexcept(NO_EXCEPT) {
        if(static_cast<i64>(_val += b._val - 2 * _mod) < 0) this->_val += 2 * this->_mod;
        return *this;
    }

    mint &operator-=(const mint &b) noexcept(NO_EXCEPT) {
        if(static_cast<i64>(this->_val -= b._val) < 0)
            this->_val += 2 * this->_mod;
        return *this;
    }

    mint &operator*=(const mint &b) noexcept(NO_EXCEPT) {
        this->_val = reduce(static_cast<u128>(this->_val) * b._val);
        return *this;
    }

    mint &operator/=(const mint &b) noexcept(NO_EXCEPT) {
        *this *= b.inv();
        return *this;
    }

    mint operator+(const mint &b) const noexcept(NO_EXCEPT) { return mint(*this) += b; }
    mint operator-(const mint &b) const noexcept(NO_EXCEPT) { return mint(*this) -= b; }
    mint operator*(const mint &b) const noexcept(NO_EXCEPT) { return mint(*this) *= b; }
    mint operator/(const mint &b) const noexcept(NO_EXCEPT) { return mint(*this) /= b; }

    bool operator==(const mint &b) const noexcept(NO_EXCEPT) {
        return (this->_val >= this->_mod ? this->_val - this->_mod : this->_val) == (b._val >= this->_mod ? b._val - this->_mod : b._val);
    }
    bool operator!=(const mint &b) const noexcept(NO_EXCEPT) {
        return (this->_val >= this->_mod ? this->_val - this->_mod : this->_val) != (b._val >= this->_mod ? b._val - this->_mod : b._val);
    }

    mint operator-() const noexcept(NO_EXCEPT) { return mint{} - static_cast<mint>(*this); }

    mint pow(u128 n) const noexcept(NO_EXCEPT) {
        mint res(1), mul(*this);
        while(n > 0) {
            if(n & 1)
                res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    mint inv() const noexcept(NO_EXCEPT) { return this->pow(this->_mod - 2); }

    u64 val() const noexcept(NO_EXCEPT) {
        u64 res = this->reduce(this->_val);
        return res >= this->_mod ? res - this->_mod : res;
    }
};

template<int id> typename dynamic_modint_64bit<id>::u64 dynamic_modint_64bit<id>::_mod;
template<int id> typename dynamic_modint_64bit<id>::u64 dynamic_modint_64bit<id>::r;
template<int id> typename dynamic_modint_64bit<id>::u64 dynamic_modint_64bit<id>::n2;


} // namespace lib
/* [numeric/modint.hpp] */
#line 12 "constants.hpp"


namespace lib {


i32 INF32 = numeric_limits<i32>::arithmetic_infinity();
i64 INF64 = numeric_limits<i64>::arithmetic_infinity();

template<class T>
constexpr T INF = numeric_limits<T>::arithmetic_infinity();

template<const unsigned v, const unsigned mod = 998244353>
const unsigned INV = lib::static_modint<mod>{v}.inv().val();

constexpr char LN = '\n';
constexpr char SPC = ' ';

constexpr std::pair<int,int> DIRS4[] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
constexpr std::pair<int,int> DIRS8[] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };


enum class comp : std::uint8_t {
    equal_to,
    not_equal_to,

    equals = equal_to,
    eq = equal_to,

    under,
    over,
    or_under,
    or_over,

    less = under,
    more = over,

    less_than = under,
    more_than = over,
    not_less_than = or_over,
    not_more_than = or_under,

    leq = or_under,
    geq = or_over
};

enum class interval : std::uint8_t {
    right_open,
    left_open,
    open,
    closed,
};

enum class replacement_policy : std::uint8_t {
    insert_sync,
    overwrite_sync,
    overwrite_async
};


} // namespace lib
/* [constants.hpp] */
#line 26 "iterable/operation.hpp"
/* #expanded [view/concat.hpp] */
#line 1 "view/concat.hpp"











/* #expanded [internal/iterator.hpp] */
#line 1 "internal/iterator.hpp"














namespace lib {

namespace internal {


template<class T>
struct iterator_interface {
    using iterator_category = std::output_iterator_tag;

    using difference_type = size_t;
    using value_type = T;

    using pointer = T*;
    using reference = T&;

    // virtual T operator*() const noexcept(NO_EXCEPT) { return 0; };
};

template<class T>
struct forward_iterator : iterator_interface<T> {
    using iterator_category = std::forward_iterator_tag;

    // virtual bidirectional_iterator_interface& operator++() = 0;
};

template<class T>
struct bidirectional_iterator_interface : forward_iterator<T> {
    using iterator_category = std::bidirectional_iterator_tag;

    // virtual bidirectional_iterator_interface& operator--() = 0;
};

template<class T>
struct random_access_iterator_base : bidirectional_iterator_interface<T> {
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = typename bidirectional_iterator_interface<T>::difference_type;

  public:
    // virtual random_access_iterator_base& operator+=(const difference_type count) = 0;
    // virtual random_access_iterator_base& operator-=(const difference_type count) = 0;

    friend inline random_access_iterator_base operator+(random_access_iterator_base itr, const difference_type count) noexcept(NO_EXCEPT) { return itr += count, itr; }
    friend inline random_access_iterator_base operator-(random_access_iterator_base itr, const difference_type count) noexcept(NO_EXCEPT) { return itr -= count, itr; }

};

template<class T, class container>
struct container_iterator_interface : public random_access_iterator_base<T> {
    using difference_type = typename bidirectional_iterator_interface<T>::difference_type;

  protected:
    const container *const _ref;
    difference_type _pos;
    container_iterator_interface(const container *const ref, const difference_type& pos) noexcept(NO_EXCEPT) : _ref(ref), _pos(pos) {}

  public:
    inline const container* ref() const noexcept(NO_EXCEPT) { return this->_ref; }

    inline difference_type pos() const noexcept(NO_EXCEPT) { return this->_pos; }
    inline difference_type& pos() { return this->_pos; }

    inline container_iterator_interface& operator++() noexcept(NO_EXCEPT) { return ++this->pos(), *this; }
    inline container_iterator_interface& operator--() noexcept(NO_EXCEPT) { return --this->pos(), *this; }

    inline container_iterator_interface operator++(int) noexcept(NO_EXCEPT) { const auto res = *this; return ++this->pos(), res; }
    inline container_iterator_interface operator--(int) noexcept(NO_EXCEPT) { const auto res = *this; return --this->pos(), res; }

    inline container_iterator_interface& operator+=(const difference_type count) noexcept(NO_EXCEPT) { return this->pos() += count, *this; }
    inline container_iterator_interface& operator-=(const difference_type count) noexcept(NO_EXCEPT) { return this->pos() -= count, *this; }

    inline difference_type operator-(const container_iterator_interface& other) const noexcept(NO_EXCEPT) { return this->pos() - other.pos(); }

    inline bool operator<(const container_iterator_interface& other) const noexcept(NO_EXCEPT) { return *this - other < 0; }
    inline bool operator>(const container_iterator_interface& other) const noexcept(NO_EXCEPT) { return *this - other > 0; }

    inline bool operator<=(const container_iterator_interface& other) const noexcept(NO_EXCEPT) { return not (*this > other); }
    inline bool operator>=(const container_iterator_interface& other) const noexcept(NO_EXCEPT) { return not (*this < other); }

    inline bool operator!=(const container_iterator_interface& other) const noexcept(NO_EXCEPT) { return this->ref() != other.ref() or *this < other or *this > other; }
    inline bool operator==(const container_iterator_interface& other) const noexcept(NO_EXCEPT) { return not (*this != other); }
};


template<class V, class I>
inline auto to_non_const_iterator(V v, const I itr) noexcept(NO_EXCEPT) { return std::next(std::begin(v), std::distance(std::cbegin(v), itr)); }


namespace iterator_impl {


template<class... Tags>
using is_all_random_access_iterator = are_base_of<std::random_access_iterator_tag,Tags...>;

template<class... Tags>
using is_all_bidirectional_iterator = are_base_of<std::bidirectional_iterator_tag,Tags...>;

template<class... Tags>
using is_all_forward_iterator = are_base_of<std::forward_iterator_tag,Tags...>;

template<class... Tags>
using is_all_input_iterator = are_base_of<std::input_iterator_tag,Tags...>;


template<class... Tags>
constexpr auto _most_primitive_iterator_tag() {
    if constexpr(is_all_random_access_iterator<Tags...>::value) {
        return std::random_access_iterator_tag{};
    }
    else if constexpr(is_all_bidirectional_iterator<Tags...>::value) {
        return std::bidirectional_iterator_tag{};
    }
    else if constexpr(is_all_forward_iterator<Tags...>::value) {
        return std::forward_iterator_tag{};
    }
    else {
        return std::input_iterator_tag{};
    }
}


} // namespace iterator_impl


template<class... Tags>
using most_primitive_iterator_tag = decltype(iterator_impl::_most_primitive_iterator_tag<Tags...>());


template<class T, class = void>
struct is_iterator {
   static constexpr bool value = false;
};

template<class T>
struct is_iterator<T, typename std::enable_if<!std::is_same<typename std::iterator_traits<T>::value_type, void>::value>::type> {
   static constexpr bool value = true;
};

template<class T>
constexpr bool is_iterator_v = is_iterator<T>::value;

template<class T>
using is_iterator_t = std::enable_if_t<is_iterator_v<T>>;


} // namespace internal

} // namespace lib
/* [internal/iterator.hpp] */
#line 13 "view/concat.hpp"


/* #expanded [view/internal/base.hpp] */
#line 1 "view/internal/base.hpp"








namespace lib {

namespace internal {

namespace view_impl {


struct base {};

struct iterator_base {};


template<class T> using is_view = std::is_base_of<base,T>;
template<class T> inline constexpr auto is_view_v = is_view<T>::value;
template<class T> using is_view_t = std::enable_if_t<is_view_v<T>>;

template<class T> using is_view_iterator = std::is_base_of<iterator_base,T>;
template<class T> inline constexpr auto is_view_iterator_v = is_view_iterator<T>::value;
template<class T> using is_view_iterator_t = std::enable_if_t<is_view_iterator_v<T>>;


} // namespace view_impl

} // namespace internal

} // namespace lib
/* [view/internal/base.hpp] */
#line 16 "view/concat.hpp"
/* #expanded [view/range.hpp] */
#line 1 "view/range.hpp"











namespace lib {

namespace internal {

namespace view_impl {

template<class I>
struct range_view : internal::view_impl::base {
    using size_type = internal::size_t;
    using value_type = typename std::iterator_traits<I>::value_type;

    using iterator = I;

  protected:
    I _first, _last;
    size_type _size = -1;

    range_view() {}

  public:
    explicit range_view(I first, I last) : _first(first), _last(last) { }

    inline size_type size() const {
        if(this->_size < 0) this->_size = std::distance(this->_first, this->_last);
        return this->_size;
    }

    inline auto begin() { return this->_first; }
    inline auto end() { return this->_last; }

    inline auto begin() const { return this->_first; }
    inline auto end() const { return this->_last; }

    inline auto cbegin() const { return this->_first; }
    inline auto cend() const { return this->_last; }
};


} // namespace view_impl


template<class,bool,bool> struct _range_view;

template<class Itr> struct _range_view<Itr,false,false> : internal::view_impl::range_view<Itr> {
  protected:
    using base = internal::view_impl::range_view<Itr>;
    using base::base;

    static_assert(internal::is_iterator_v<Itr>);
};


template<class Range> struct _range_view<Range,true,false> : _range_view<iterator_t<Range>,false,false> {
  protected:
    using base = _range_view<iterator_t<Range>,false,false>;
    static_assert(internal::is_iterable_v<Range>);

  public:
    explicit _range_view(Range& view) : base(std::begin(view), std::end(view)) {}
};

template<class Range> struct _range_view<Range,true,true> : _range_view<iterator_t<Range>,false,false> {
  protected:
    using base = _range_view<iterator_t<Range>,false,false>;
    static_assert(internal::is_iterable_v<Range>);

  public:
    Range _base;
    explicit _range_view(const Range view) : _base(view) {
        // debug(_base);
        this->base::_first = std::begin(this->_base);
        this->base::_last = std::end(this->_base);
    }
};

} // namespace internal

template<class ItrOrRange> struct range_view : internal::_range_view<ItrOrRange,internal::is_iterable_v<ItrOrRange>,internal::view_impl::is_view_v<ItrOrRange>> {
  protected:
    using base = internal::_range_view<ItrOrRange,internal::is_iterable_v<ItrOrRange>,internal::view_impl::is_view_v<ItrOrRange>>;
    using base::base;
};


template<class ItrOrRange, internal::is_iterator_t<ItrOrRange>* = nullptr>
explicit range_view(const ItrOrRange, const ItrOrRange) -> range_view<ItrOrRange>;

template<class ItrOrRange, internal::view_impl::is_view_t<ItrOrRange>* = nullptr>
explicit range_view(const ItrOrRange) -> range_view<ItrOrRange>;

template<class ItrOrRange, std::enable_if_t<internal::is_iterable_v<ItrOrRange> && !internal::view_impl::is_view_v<ItrOrRange>>* = nullptr>
explicit range_view(const ItrOrRange&) -> range_view<ItrOrRange>;


namespace views {


template<class Itr>
inline auto range(const Itr& first, const Itr& last) noexcept(NO_EXCEPT) { return range_view(first, last); }

template<class View>
inline auto range(View&& views) noexcept(NO_EXCEPT) { return range_view(std::forward<View>(views)); }


} // namespace views


}
/* [view/range.hpp] */
#line 17 "view/concat.hpp"


namespace lib {

namespace internal {

namespace view_impl {


template<class,class> struct concat_view;
template<class> struct concat_view_iterator;


template<class View>
inline typename concat_view_iterator<View>::difference_type operator-(
    const concat_view_iterator<View>& lhs,
    const concat_view_iterator<View>& rhs
) noexcept(NO_EXCEPT) {
    if(lhs._block == rhs._block) {
        return lhs._block == 0 ? std::distance(rhs._itr0, lhs._itr0) : std::distance(rhs._itr1, lhs._itr1);
    }
    if(lhs._block > rhs._block) return std::distance(rhs._itr0, rhs._super->_l0) + std::distance(lhs._super->_f1, lhs._itr1);
    if(lhs._block < rhs._block) return -std::distance(lhs, rhs);
    assert(false);
}


template<class View>
struct concat_view_iterator : view_impl::iterator_base {
  protected:
    using iterator0_t = typename View::iterator0_t;
    using iterator1_t = typename View::iterator1_t;

    using ptr_val = std::common_type_t<typename std::iterator_traits<iterator0_t>::pointer, typename std::iterator_traits<iterator1_t>::pointer>;

    using ref_val0_t = typename std::iterator_traits<iterator0_t>::reference;
    using ref_val1_t = typename std::iterator_traits<iterator1_t>::reference;

    using ref_val_t = std::common_type_t<ref_val0_t,ref_val1_t>;

    static constexpr bool IS_CONST = std::is_const_v<ref_val0_t> || std::is_const_v<ref_val1_t> || std::is_const_v<View>;

  public:
    using difference_type = std::common_type_t<typename std::iterator_traits<iterator0_t>::difference_type, typename std::iterator_traits<iterator1_t>::difference_type>;
    using value_type = std::common_type_t<typename std::iterator_traits<iterator0_t>::value_type, typename std::iterator_traits<iterator1_t>::value_type>;
    using pointer = std::conditional_t<IS_CONST, const ptr_val, ptr_val>;
    using reference = std::conditional_t<IS_CONST, const ref_val_t, ref_val_t>&;
    using iterator_category = most_primitive_iterator_tag<typename std::iterator_traits<iterator0_t>::iterator_category, typename std::iterator_traits<iterator1_t>::iterator_category>;

  protected:
    const View* _super;
    bool _block = 0;
    iterator0_t _itr0;
    iterator1_t _itr1;

  public:
    concat_view_iterator() {}

    template<class Itr>
    explicit concat_view_iterator(
        const View *const super,
        const size_t block,
        Itr itr
    ) noexcept(NO_EXCEPT)
        : _super(super), _block(block)
    {
        if constexpr(std::is_same_v<iterator0_t,iterator1_t>) {
            if(block == 0) this->_itr0 = itr;
            else this->_itr1 = itr;
        }
        else {
            if constexpr(std::is_same_v<iterator0_t,Itr>) {
                assert(block == 0);
                this->_itr0 = itr;
            }
            else {
                assert(block == 1);
                this->_itr1 = itr;
            }
        }
    }

    inline reference operator*() noexcept(NO_EXCEPT) { return this->_block == 0 ? *this->_itr0 : *this->_itr1; }
    inline const reference operator*() const noexcept(NO_EXCEPT) { return this->_block == 0 ? *this->_itr0 : *this->_itr1; }

    inline concat_view_iterator& operator+=(const difference_type count) noexcept(NO_EXCEPT) {
        if(count < 0) return *this -= (-count);

        if(this->_block == 0) {
            const auto dist = static_cast<difference_type>(std::distance(this->_itr0, _super->_l0));
            if(count < dist) {
                this->_itr0 += count;
            }
            else {
                this->_block = 1;
                this->_itr1 = std::next(_super->_f1, dist - count);
            }
        }
        else {
            this->_itr1 += count;
        }

        return *this;
    }

    inline concat_view_iterator& operator-=(const difference_type count) noexcept(NO_EXCEPT) {
        if(count < 0) return *this += (-count);

        if(this->_block == 1) {
            const auto dist = static_cast<difference_type>(std::distance(_super->_f1, this->_itr1));
            if(count < dist) {
                this->_itr1 -= count;
            }
            else {
                this->_block = 0;
                this->_itr0 = std::prev(_super->_l0, dist - count);
            }
        }
        else {
            this->_itr0 -= count;
        }

        return *this;
    }

    inline concat_view_iterator& operator++() noexcept(NO_EXCEPT) {
        if(this->_block == 0) {
            if(++this->_itr0 == _super->_l0) {
                this->_block = 1;
                this->_itr1 = _super->_f1;
            }
        }
        else {
            ++this->_itr1;
        }
        return *this;
    }
    inline concat_view_iterator& operator--() noexcept(NO_EXCEPT) {
        if(this->_block == 1) {
            if(this->_itr1-- == _super->_f1) {
                this->_block = 0;
                this->_itr0 = std::prev(_super->_l0);
            }
        }
        else {
            --this->_itr0;
        }
        return *this;
    }

    inline concat_view_iterator operator++(int) noexcept(NO_EXCEPT) { const auto res = *this; return ++(*this), res; }
    inline concat_view_iterator operator--(int) noexcept(NO_EXCEPT) { const auto res = *this; return --(*this), res; }

    friend inline concat_view_iterator operator+(concat_view_iterator lhs, const difference_type rhs) noexcept(NO_EXCEPT) { return lhs += rhs; }
    friend inline concat_view_iterator operator-(concat_view_iterator lhs, const difference_type rhs) noexcept(NO_EXCEPT) { return lhs -= rhs; }

    friend inline bool operator==(const concat_view_iterator& lhs, const concat_view_iterator& rhs) noexcept(NO_EXCEPT) {
        if(lhs._block != rhs._block) return false;
        return lhs._block == 0 ? lhs._itr0 == rhs._itr0 : lhs._itr1 == rhs._itr1;
    }
    friend inline bool operator!=(const concat_view_iterator& lhs, const concat_view_iterator& rhs) noexcept(NO_EXCEPT) { return !(lhs == rhs); }

    friend difference_type operator-<View>(const concat_view_iterator&, const concat_view_iterator&);
};


template<class V0, class V1>
struct concat_view : view_impl::base {
    static_assert(is_view_v<V0> and is_view_v<V1>);

    using size_type = std::common_type_t<container_size_t<V0>,container_size_t<V1>>;

  protected:
    using iterator0_t = iterator_t<V0>;
    using iterator1_t = iterator_t<V1>;

    V0 _v0;
    V1 _v1;

    size_type _s0 = -1, _s1 = -1;
    iterator0_t _f0, _l0;
    iterator1_t _f1, _l1;

  public:
    using iterator = concat_view_iterator<concat_view>;
    using const_iterator = concat_view_iterator<const concat_view>;

    friend iterator;
    friend const_iterator;

    friend typename iterator::difference_type operator-<concat_view>(const iterator&, const iterator&);
    friend typename const_iterator::difference_type operator-<const concat_view>(const const_iterator&, const const_iterator&);

    explicit concat_view(const V0 v0, const V1 v1) noexcept(NO_EXCEPT)
      : _v0(std::move(v0)), _v1(std::move(v1)),
        _f0(std::begin(this->_v0)), _l0(std::end(this->_v0)), _f1(std::begin(this->_v1)), _l1(std::end(this->_v1))
    {};

    inline iterator begin() noexcept(NO_EXCEPT) { return iterator(this, 0, this->_f0); }
    inline iterator end() noexcept(NO_EXCEPT) { return iterator(this, 1, this->_l1); }

    inline const const_iterator begin() const noexcept(NO_EXCEPT) { return const_iterator(this, 0, this->_f0); }
    inline const const_iterator end() const noexcept(NO_EXCEPT) { return const_iterator(this, 1, this->_l1); }

    inline size_type size() const noexcept(NO_EXCEPT) {
        if(this->_s0 < 0) this->_s0 = std::distance(this->_f0, this->_l0);
        if(this->_s1 < 0) this->_s1 = std::distance(this->_f1, this->_l1);
        return this->_s0 + this->_s1;
    }

    template<class Container>
    inline Container to() const noexcept(NO_EXCEPT) {
        Container res(this->begin(), this->end());
        return res;
    }
};

} // namespace view_impl

} // namespace internal


template<class...> struct concat_view;

template<class V> struct concat_view<V> : range_view<V> {
    explicit concat_view(const V v) noexcept(NO_EXCEPT) : range_view<V>(v) {}
};

template<class V0, class V1> struct concat_view<V0,V1> : internal::view_impl::concat_view<V0,V1> {
    explicit concat_view(const V0 v0, const V1 v1) noexcept(NO_EXCEPT) : internal::view_impl::concat_view<V0,V1>(v0, v1) {}
};

template<class V0, class V1, class... Vs> struct concat_view<V0,V1,Vs...> : concat_view<concat_view<V0,V1>,Vs...> {
  public:
    explicit concat_view(const V0 v0, const V1 v1, const Vs... cs) noexcept(NO_EXCEPT) : concat_view<concat_view<V0,V1>,Vs...>(concat_view<V0,V1>(v0, v1), cs...) {}
};

template<class V>
explicit concat_view(const V) -> concat_view<V>;

template<class V0, class V1>
explicit concat_view(const V0, const V1) -> concat_view<V0,V1>;

template<class V0, class V1, class... Vs>
explicit concat_view(const V0, const V1, const Vs...) -> concat_view<V0,V1,Vs...>;


namespace views {


template<class... Views>
inline auto concat(Views&&... views) noexcept(NO_EXCEPT) { return concat_view(range(views)...); };


} // namespace views


} // namespace lib
/* [view/concat.hpp] */
#line 27 "iterable/operation.hpp"


namespace lib {


template<class I, class = typename std::iterator_traits<I>::iterator_category>
std::string join(const I first, const I last, const char * sep = "") noexcept(NO_EXCEPT) {
    std::ostringstream res;
    std::copy(first, last, std::ostream_iterator<typename std::iterator_traits<I>::value_type>(res, sep));
    return res.str();
}

template<class V>
std::string join(const V& v, const char * sep = "") noexcept(NO_EXCEPT) {
    return join(ALL(v), sep);
}


template<class V, class U>
V concat(const V& v, const U& u) noexcept(NO_EXCEPT) {
    V res(std::size(v) + std::size(u));
    std::copy(ALL(v), std::begin(res));
    std::copy(ALL(u), std::next(std::begin(res), std::size(v)));
    return res;
}

template<class V, class... Us>
V concat(const V& v, const Us&... tails) noexcept(NO_EXCEPT) {
    return lib::concat(v, lib::concat(tails...));
}


template<class I, class T = typename std::iterator_traits<I>::value_type>
T sum(const I first, const I second, const T& base = 0) noexcept(NO_EXCEPT) {
    return std::accumulate(first, second, base);
}

template<class V, class T = typename V::value_type>
auto sum(const V& v, T base = 0) noexcept(NO_EXCEPT) {
    return sum(ALL(v), base);
}


template<
    class I,
    class T = typename std::iterator_traits<I>::value_type,
    class = typename std::iterator_traits<I>::value_type
>
T mex(const I first, const I last, const T& base = 0) noexcept(NO_EXCEPT) {
    std::vector<T> val(first, last);
    std::sort(ALL(val));
    val.erase(std::unique(ALL(val)), val.end());
    val.erase(val.begin(), std::lower_bound(ALL(val), base));

    internal::size_t i = 0;
    while(i < (internal::size_t)val.size() and val[i] == T{i} + base) ++i;

    return T{i} + base;
}

template<class T>
auto mex(const std::initializer_list<T> v) noexcept(NO_EXCEPT) {
    return mex(ALL(v));
}

template<class T>
auto mex(std::initializer_list<T> v, const T& base) noexcept(NO_EXCEPT) {
    return mex(ALL(v), base);
}


template<class R, class I, class D>
auto split(const I first, const I last, const D& delim = ' ') noexcept(NO_EXCEPT) {
    R res;

    for(auto itr=first, fnd=first; ; itr=std::next(fnd)) {
        fnd = find(itr, last, delim);
        res.emplace_back(itr, fnd);
        if(fnd == last) break;
    }

    return res;
}

template<class R, class V, class D, std::enable_if_t<!internal::is_iterable_v<D>>* = nullptr>
auto split(const V& v, const D& d) noexcept(NO_EXCEPT) { return split<R>(ALL(v), d); }

template<class R, class V, class Ds, std::enable_if_t<internal::is_iterable_v<Ds>>* = nullptr>
auto split(const V& v, const Ds& ds) noexcept(NO_EXCEPT) {
    R res = { v };
    ITR(d, ds) {
        R tmp;
        ITR(p, res) tmp = concat(tmp, split<R>(p, d));
        res = std::move(tmp);
    }
    return res;
}

template<class R, class V, class T> auto split(const V& v, const std::initializer_list<T> ds) noexcept(NO_EXCEPT){
    return split<R,V>(v, std::vector<T>(ALL(ds)));
}


template<class I>
vector<I> find(const I source_first,  const I source_last, const I query_first, const I query_last) noexcept(NO_EXCEPT) {
    using value_type = typename std::iterator_traits<I>::value_type;

    const auto joined = views::concat(views::range(query_first, query_last), views::range(source_first, source_last));
    std::vector<value_type> pre_z(std::begin(joined), std::end(joined));
    z_array z_arr(ALL(pre_z));

    const internal::size_t query_size = std::distance(query_first, query_last);

    vector<I> res;

    {
        auto itr = source_first;
        REP(i, query_size, z_arr.size()) {
            if(z_arr[i] >= query_size) res.emplace_back(itr);
            ++itr;
        }
    }

    return res;
}

template<class V>
auto find(const V& source, const V& query) noexcept(NO_EXCEPT) { return find(ALL(source), ALL(query)); }


template<class V, replacement_policy POLICY = replacement_policy::insert_sync>
auto replace(const V& source, const V& from, const V& to) noexcept(NO_EXCEPT) {
    V res;

    if constexpr(POLICY == replacement_policy::insert_sync) {
        const auto found = find(source, from);
        auto itr = std::begin(source);
        ITRR(fn, found) {
            std::copy(itr, fn, std::back_inserter(res));
            std::copy(ALL(to), std::back_inserter(res));
            itr = std::next(fn, std::size(from));
        }
        std::copy(itr, std::end(source), std::back_inserter(res));
    }
    else {
        res = source;
        res.resize(std::size(source) + std::size(to));

        const auto found = find(res, from);
        auto prev = std::begin(res);
        ITRR(fn, found) {
            if constexpr(POLICY == replacement_policy::overwrite_sync) {
                if(prev <= fn) prev = std::copy(ALL(to), internal::to_non_const_iterator(res, fn));
            }
            else {
                std::copy(ALL(to), internal::to_non_const_iterator(res, fn));
            }
        }

        res.resize(std::size(source));
    }

    return res;
}


} // namespace lib
/* [iterable/operation.hpp] */
#line 22 "numeric/arithmetic.hpp"


namespace lib {


template<class T, class R = T>
R nPr(const T n, const T r) noexcept(NO_EXCEPT) {
    assert(0 <= n);
    assert(0 <= r);
    if(n < r) return 0;

    R res = 1;
    REP(i, r) res *= n-i;

    return res;
}

template<class T, class R = T>
R nCr(const T n, T r) noexcept(NO_EXCEPT) {
    assert(0 <= n);
    assert(0 <= r);
    if(n == r) return 1;
    if(n < r) return 0;

    if(n < r*2) r = n-r;
    R p = 1, q = 1;
    REP(i, r) p *= n-i, q *= r-i;

    return p / q;
}


template<class T, class U>
T pow(T x, U n) noexcept(NO_EXCEPT) {
    T res = 1;
    while(n > 0) {
        if(n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

using atcoder::pow_mod;
using atcoder::inv_mod;
using atcoder::crt;


template<class T> T sign(const T& x) noexcept(NO_EXCEPT) {
    if(x == 0) return 0;
    return (x > 0) ? 1 : -1;
}

template<class T, T FROM_MIN, T FROM_MAX, T TO_MIN, T TO_MAX> inline constexpr T mapping(const T x) {
    return (x - FROM_MIN) * (TO_MAX - TO_MIN) / (FROM_MAX - FROM_MIN) + TO_MIN;
}
template<class T> inline constexpr T mapping(const T x, const T from_min, const T from_max, const T to_min, const T to_max) {
    return (x - from_min) * (to_max - to_min) / (from_max - from_min) + to_min;
}

template<class... Args>
const std::common_type_t<Args...> min(const Args&... args) noexcept(NO_EXCEPT) {
    return std::min({ static_cast<std::common_type_t<Args...>>(args)... });
}

template<class... Args>
const std::common_type_t<Args...> max(const Args&... args) noexcept(NO_EXCEPT) {
    return std::max({ static_cast<std::common_type_t<Args...>>(args)... });
}

template<class... Args>
const std::common_type_t<Args...> mex(const Args&... args) noexcept(NO_EXCEPT) {
    return mex({ static_cast<std::common_type_t<Args...>>(args)... });
}

template<class T, class U, std::enable_if_t<(std::is_integral_v<T> and std::is_integral_v<U>)>* = nullptr>
std::optional<std::common_type_t<T,U>> add_overflow(const T& a, const U& b) noexcept(NO_EXCEPT) {
    std::common_type_t<T,U> res;
    if(__builtin_add_overflow(a, b, &res)) return {};
    else return res;
}

template<class T, class U, std::enable_if_t<(std::is_integral_v<T> and std::is_integral_v<U>)>* = nullptr>
std::optional<std::common_type_t<T,U>> sub_overflow(const T& a, const U& b) noexcept(NO_EXCEPT) {
    std::common_type_t<T,U> res;
    if(__builtin_sub_overflow(a, b, &res)) return {};
    else return res;
}

template<class T, class U, std::enable_if_t<(std::is_integral_v<T> and std::is_integral_v<U>)>* = nullptr>
std::optional<std::common_type_t<T,U>> mul_overflow(const T& a, const U& b) noexcept(NO_EXCEPT) {
    std::common_type_t<T,U> res;
    if(__builtin_mul_overflow(a, b, &res)) return {};
    else return res;
}


template<class T, class U, class V>
inline bool mul_over(const T x, const U y, const V s) noexcept(NO_EXCEPT) {
    using Com = std::common_type_t<T,U,V>;
    const auto res = mul_overflow<Com,Com>(x, y);
    if(!res) return !((x < 0) xor (y < 0));
    return *res > s;
}

template<class T, class U, class V>
inline bool mul_or_over(const T x, const U y, const V s) noexcept(NO_EXCEPT) {
    using Com = std::common_type_t<T,U,V>;
    const auto res = mul_overflow<Com,Com>(x, y);
    if(!res) return !((x < 0) xor (y < 0));
    return *res >= s;
}

template<class T, class U, class V>
inline bool mul_under(const T x, const U y, const V s) noexcept(NO_EXCEPT) {
    using Com = std::common_type_t<T,U,V>;
    const auto res = mul_overflow<Com,Com>(x, y);
    if(!res) return ((x < 0) xor (y < 0));
    return *res < s;
}

template<class T, class U, class V>
inline bool mul_or_under(const T x, const U y, const V s) noexcept(NO_EXCEPT) {
    using Com = std::common_type_t<T,U,V>;
    const auto res = mul_overflow<Com,Com>(x, y);
    if(!res) return ((x < 0) xor (y < 0));
    return *res <= s;
}

template<class T>
T sqrt_floor(const T x) noexcept(NO_EXCEPT) {
    T ok = 0, ng = x / 2 + 2;
    while(ng - ok > 1) {
        T mid = (ok + ng) / 2;
        (x / mid < mid ? ng : ok) = mid;
    }
    return ok;
}

template<class T>
T sqrt_ceil(const T x) noexcept(NO_EXCEPT) {
    T ok = 0, ng = x / 2 + 2;
    while(ng - ok > 1) {
        T mid = (ok + ng) / 2;
        (mul_over(mid-1, mid-1, x-1) ? ng : ok) = mid;
    }
    return ok;
}


} // namespace lib
/* [numeric/arithmetic.hpp] */
#line 8 "utility/functional.hpp"


namespace lib {

namespace internal {


template<class T> constexpr T plus(const T a, const T b) { return std::plus<T>{}(a, b); }
template<class T> constexpr T minus(const T a, const T b) { return std::minus<T>{}(a, b); }

template<class T> constexpr T bitxor(const T a, const T b) { return a xor b; }


} // namespace internal


template<class T1, class T2> inline auto mod(T1 x, T2 r) { return (x%r+r)%r; }

template<class T1, class T2> inline bool chmin(T1 &a, const T2& b) { return (a>b ? a=b, true : false); }
template<class T1, class T2> inline bool chmax(T1 &a, const T2& b) { return (a<b ? a=b, true : false); }

template<class T1, class... Args> inline bool chmin(T1 &a, Args... b) { return chmin(a, min(b...)); }
template<class T1, class... Args> inline bool chmax(T1 &a, Args... b) { return chmax(a, max(b...)); }


} // namespace lib
/* [utility/functional.hpp] */
#line 13 "adapter/set.hpp"


namespace lib {

namespace internal {


template<class Set> struct set_wrapper : Set {
    using Set::Set;
    using size_type = internal::size_t;

    inline size_type size() const noexcept(NO_EXCEPT) { return this->Set::size(); }

    inline bool contains(const typename Set::key_type& key) const noexcept(NO_EXCEPT) { return static_cast<bool>(this->count(key)); }

    inline std::optional<typename Set::iterator> remove(const typename Set::key_type& key) noexcept(NO_EXCEPT) {
        const auto itr = this->Set::find(key);
        if(itr == this->Set::end()) return {};
        return this->erase(itr);
    }

    inline auto min_element() const noexcept(NO_EXCEPT) { return this->begin(); }
    inline auto max_element() const noexcept(NO_EXCEPT) { return std::prev(this->end()); }

    inline auto min() const noexcept(NO_EXCEPT) { return *this->begin(); }
    inline auto max() const noexcept(NO_EXCEPT) { return *std::prev(this->end()); }

    inline auto pop_min() noexcept(NO_EXCEPT) { this->erase(this->begin()); return *this; }
    inline auto pop_max() noexcept(NO_EXCEPT) { this->erase(std::prev(this->end())); return *this; }

    inline auto next_element(const typename Set::key_type& key, const size_type _count = 0) const noexcept(NO_EXCEPT) {
        size_type count = std::abs(_count);
        auto itr = this->lower_bound(key);
        const auto begin = this->begin(), end = this->end();
        if(itr == end) return this->end();
        if(itr == begin) return this->begin();
        while(count--) {
            if(_count < 0) if(itr-- == begin) return this->begin();
            if(_count > 0) if(++itr == end) return this->end();
        }
        return itr;
    }
    inline auto prev_element(const typename Set::key_type& key, const size_type _count = 0) const noexcept(NO_EXCEPT) {
        size_type count = std::abs(_count);
        auto itr = this->upper_bound(key);
        const auto begin = this->begin(), end = this->end();
        if(itr == end) return this->end();
        if(itr-- == begin) return this->begin();
        while(count--) {
            if(_count < 0) if(itr-- == begin) return this->begin();
            if(_count > 0) if(++itr == end) return this->end();
        }
        return itr;
    }

    inline std::optional<typename Set::value_type> next(const typename Set::key_type& key, size_type count = 0) const noexcept(NO_EXCEPT) {
        auto itr = this->lower_bound(key);
        const auto end = this->end();
        if(itr == end) return {};
        while(count--) if(++itr == end) return {};
        return { *itr };
    }

    inline std::optional<typename Set::value_type> prev(const typename Set::key_type& key, size_type count = 0) const noexcept(NO_EXCEPT) {
        auto itr = this->upper_bound(key);
        const auto begin = this->begin();
        if(itr-- == begin) return {};
        while(count--) if(itr-- == begin) return {};
        return { *itr };
    }

    friend inline set_wrapper operator|(set_wrapper s, const set_wrapper t) noexcept(NO_EXCEPT) {
        s.merge(t);
        return s;
    }
};


} //namespace internal


template<class... Args> using set = internal::set_wrapper<std::set<Args...>>;
template<class... Args> using unordered_set = internal::set_wrapper<std::unordered_set<Args...>>;
template<class... Args> using multiset = internal::set_wrapper<std::multiset<Args...>>;
template<class... Args> using unordered_multiset = internal::set_wrapper<std::unordered_multiset<Args...>>;


} // namespace lib
/* [adapter/set.hpp] */
#line 11 "adapter/map.hpp"


namespace lib {

namespace internal {


template<class Map>
using map_wrapper_base = set_wrapper<Map>;


template<class Map> struct map_wrapper : map_wrapper_base<Map> {
  private:
    using base = map_wrapper_base<Map>;

  public:
    using base::base;
    using mapped_type = typename base::mapped_type;
    using key_type = typename base::key_type;

  protected:
    bool _default_type = 0;
    mapped_type _default_val = {};
    mapped_type (*_default_func)(void);

    inline mapped_type _get_default() const noexcept(NO_EXCEPT) {
        return this->_default_type ? this->_default_func() : this->_default_val;
    }

  public:
    inline auto& set_default(const mapped_type& val) noexcept(NO_EXCEPT) {
        this->_default_val = val;
        this->_default_type = 0;
        return *this;
    }

    inline auto& set_default(mapped_type (*const func)(void)) noexcept(NO_EXCEPT) {
        this->_default_func = func;
        this->_default_type = 1;
        return *this;
    }

    inline auto& operator[](const key_type key) noexcept(NO_EXCEPT) {
        auto found = this->base::find(key);
        if(found == this->base::end()) return this->base::operator[](key) = this->_get_default();
        return found->second;
    }

    inline const auto& operator[](const key_type key) const noexcept(NO_EXCEPT) {
        const auto found = this->base::find(key);
        if(found == this->base::end()) return this->base::operator[](key) = this->_get_default();
        return found->second;
    }

    inline auto& operator()(const key_type key) noexcept(NO_EXCEPT) {
        return this->base::operator[](key);
    }

    inline const auto& operator()(const key_type key) const noexcept(NO_EXCEPT) {
        return this->base::operator[](key);
    }
};


} // namespace internal


template<class... Args> using map = internal::map_wrapper<std::map<Args...>>;
template<class... Args> using unordered_map = internal::map_wrapper<std::unordered_map<Args...>>;
template<class... Args> using multimap = internal::map_wrapper<std::multimap<Args...>>;
template<class... Args> using unordered_multimap = internal::map_wrapper<std::unordered_multimap<Args...>>;


} // namespace lib
/* [adapter/map.hpp] */
#line 12 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 13 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [adapter/range_extractor.hpp] */
#line 1 "adapter/range_extractor.hpp"






namespace lib {


template<class Container>
struct range_extractor : Container {
    using Container::Container;
    using size_type = typename Container::size_type;
    using value_type = typename Container::value_type;

  protected:
    size_type _begin = 0;
    size_type _end;

    bool _default_type = 0;
    value_type _default_val = {};
    value_type (*_default_func)(void);
    inline static value_type _tmp;

    inline value_type _get_default() const noexcept(NO_EXCEPT) {
        return this->_default_type ? this->_default_func() : this->_default_val;
    }

  public:
    template<class... Args>
    explicit range_extractor(const Args&... args) noexcept(NO_EXCEPT) : Container(args...) {
        this->_begin = 0;
        this->_end = this->size();
    }

    inline auto& extract(const size_type begin, const size_type end) noexcept(NO_EXCEPT) {
        assert(begin <= end);
        this->_begin = begin, this->_end = end;
        return *this;
    }


    inline auto& set_default(const value_type& val) noexcept(NO_EXCEPT) {
        this->_default_val = val;
        this->_default_type = 0;
        return *this;
    }

    inline auto& set_default(value_type (*const func)(void)) noexcept(NO_EXCEPT) {
        this->_default_func = func;
        this->_default_type = 1;
        return *this;
    }


    inline auto& operator[](const size_type pos) noexcept(NO_EXCEPT) {
        if(pos < this->_begin or this->_end <= pos) return range_extractor::_tmp = this->_get_default();
        return this->Container::operator[](pos);
    }

    inline const auto& operator[](const size_type pos) const noexcept(NO_EXCEPT) {
        if(pos < this->_begin or this->_end <= pos) return this->_get_default();
        return this->Container::operator[](pos);
    }

    inline auto& operator()(const size_type pos) noexcept(NO_EXCEPT) {
        return this->Container::operator[](pos);
    }

    inline const auto& operator()(const size_type pos) const noexcept(NO_EXCEPT) {
        return this->Container::operator[](pos);
    }
};


}
/* [adapter/range_extractor.hpp] */
#line 15 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [algebraic/addition.hpp] */
#line 1 "algebraic/addition.hpp"



/* #expanded [algebraic/internal/base.hpp] */
#line 1 "algebraic/internal/base.hpp"





namespace lib {

namespace algebraic {

namespace internal {


template<class T>
struct base {
    using value_type = T;

  protected:
    value_type _value;

  public:
    base(const value_type& value = {}) noexcept(NO_EXCEPT) : _value(value) {};

    inline operator value_type() const noexcept(NO_EXCEPT) { return this->_value; }
    inline value_type val() const noexcept(NO_EXCEPT) { return this->_value; };

    inline const value_type* operator->() const noexcept(NO_EXCEPT) { return &this->_value; };
    inline value_type* operator->() noexcept(NO_EXCEPT) { return &this->_value; };

    friend inline bool operator==(const base& lhs, const base& rhs) noexcept(NO_EXCEPT) { return lhs._value == rhs._value; };
    friend bool operator!=(const base& lhs, const base& rhs) noexcept(NO_EXCEPT) { return lhs._value != rhs._value; };
};


struct commutative {};

struct invertible {};


struct magma {};

struct semigroup : magma {};

struct monoid : semigroup {};

struct group : monoid, invertible {};


} // namespace internal

} // namespace algebraic

} // namespace lib
/* [algebraic/internal/base.hpp] */
#line 5 "algebraic/addition.hpp"

namespace lib {

namespace algebraic {


template<class T> struct addition : internal::base<T>, internal::group, internal::commutative {
    using internal::base<T>::base;
    addition() noexcept(NO_EXCEPT) : internal::base<T>() {};
    friend inline addition operator+(const addition& lhs, const addition& rhs) noexcept(NO_EXCEPT) { return lhs.val() + rhs.val(); }
    inline addition operator-() const noexcept(NO_EXCEPT) { return -this->val(); }
};


} // namespace algebraic

} // namespace lib
/* [algebraic/addition.hpp] */
#line 17 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [algebraic/affine.hpp] */
#line 1 "algebraic/affine.hpp"







namespace lib {

namespace algebraic {


template<class T, bool REVERSE = false> struct affine : internal::base<std::pair<T,T>>, internal::monoid {
    using internal::base<std::pair<T,T>>::base;
    affine() noexcept(NO_EXCEPT) : internal::base<std::pair<T,T>>({ 1, 0 }) {};
    friend inline affine operator+(const affine& lhs, const affine& rhs) noexcept(NO_EXCEPT) {
        if constexpr(REVERSE) return affine({ rhs->first * lhs->first, rhs->first * lhs->second + rhs->second });
        return affine({ lhs->first * rhs->first, lhs->first * rhs->second + lhs->second });
    }
};


} // namespace algebraic

} // namespace lib
/* [algebraic/affine.hpp] */
#line 18 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [algebraic/assignment.hpp] */
#line 1 "algebraic/assignment.hpp"







namespace lib {

namespace algebraic {


template<class T> struct assignment : internal::base<std::optional<T>>, internal::monoid, internal::commutative {
    using internal::base<std::optional<T>>::base;
    assignment() noexcept(NO_EXCEPT) : internal::base<std::optional<T>>() {};
    friend inline assignment operator+(const assignment& lhs, const assignment& rhs) noexcept(NO_EXCEPT) {
        if(rhs->has_value()) return rhs.val();
        return lhs;
    }
};


} // namespace algebraic

} // namespace lib
/* [algebraic/assignment.hpp] */
#line 19 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [algebraic/bitxor.hpp] */
#line 1 "algebraic/bitxor.hpp"





namespace lib {

namespace algebraic {


template<class T> struct bitxor : internal::base<T>, internal::group, internal::commutative {
    using internal::base<T>::base;
    bitxor() noexcept(NO_EXCEPT) : internal::base<T>() {};
    friend inline bitxor operator+(const bitxor& lhs, const bitxor& rhs) noexcept(NO_EXCEPT) { return lhs.val() xor rhs.val(); }
    inline bitxor operator-() const noexcept(NO_EXCEPT) { return this->val(); }
};


} // namespace algebraic

} // namespace lib
/* [algebraic/bitxor.hpp] */
#line 20 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [algebraic/gcd.hpp] */
#line 1 "algebraic/gcd.hpp"








namespace lib {

namespace algebraic {


template<class T> struct gcd : internal::base<T>, internal::monoid, internal::commutative {
    using internal::base<T>::base;
    gcd() noexcept(NO_EXCEPT) : internal::base<T>() {};
    friend inline gcd operator+(const gcd& lhs, const gcd& rhs) noexcept(NO_EXCEPT) { return std::gcd(lhs.val(), rhs.val()); }
};


} // namespace algebraic

} // namespace lib
/* [algebraic/gcd.hpp] */
#line 21 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [algebraic/maximum.hpp] */
#line 1 "algebraic/maximum.hpp"










namespace lib {

namespace algebraic {


template<class T> struct maximum : internal::base<T>, internal::monoid, internal::commutative {
    using internal::base<T>::base;
    maximum() noexcept(NO_EXCEPT) : internal::base<T>(std::numeric_limits<T>::lowest()) {};
    friend inline maximum operator+(const maximum& lhs, const maximum& rhs) noexcept(NO_EXCEPT) { return std::max(lhs.val(), rhs.val()); }
};


} // namespace algebraic

} // namespace lib
/* [algebraic/maximum.hpp] */
#line 22 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [algebraic/minimum.hpp] */
#line 1 "algebraic/minimum.hpp"










namespace lib {

namespace algebraic {


template<class T> struct minimum : internal::base<T>, internal::monoid, internal::commutative {
    using internal::base<T>::base;
    minimum() noexcept(NO_EXCEPT) : internal::base<T>(std::numeric_limits<T>::max()) {};
    friend inline minimum operator+(const minimum& lhs, const minimum& rhs) noexcept(NO_EXCEPT) { return std::min(lhs.val(), rhs.val()); }
};


} // namespace algebraic

} // namespace lib
/* [algebraic/minimum.hpp] */
#line 23 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [algebraic/minmax.hpp] */
#line 1 "algebraic/minmax.hpp"











namespace lib {

namespace algebraic {


template<class T> struct minmax : internal::base<std::pair<T,T>>, internal::monoid, internal::commutative {
    using internal::base<std::pair<T,T>>::base;
    minmax() noexcept(NO_EXCEPT) : internal::base<std::pair<T,T>>({ std::numeric_limits<T>::max(), std::numeric_limits<T>::lowest() }) {};
    friend inline minmax operator+(const minmax& lhs, const minmax& rhs) noexcept(NO_EXCEPT) { return minmax({ std::min(lhs.val().first, rhs->first), std::max(lhs.val().second, rhs->second) }); }
};


} // namespace algebraic

} // namespace lib
/* [algebraic/minmax.hpp] */
#line 24 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [algebraic/null.hpp] */
#line 1 "algebraic/null.hpp"







namespace lib {

namespace algebraic {


template<class T> struct null : internal::base<T>, internal::magma {
    using internal::base<T>::base;
    inline null operator+(const null&) const noexcept(NO_EXCEPT) { return *this; }
};


} // namespace algebraic

} // namespace lib
/* [algebraic/null.hpp] */
#line 25 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [convolution/sum.hpp] */
#line 1 "convolution/sum.hpp"



#include <atcoder/convolution>


namespace lib {


using atcoder::convolution;
using atcoder::convolution_ll;


template<class I1, class I2>
auto convolution(const I1 a_first, const I1 a_last, const I2 b_first, const I2 b_last) {
    std::vector<typename std::iterator_traits<I1>::value_type> a(a_first, a_last);
    std::vector<typename std::iterator_traits<I2>::value_type> b(b_first, b_last);
    return atcoder::convolution(a, b);
}

template<class I1, class I2>
auto convolution_ll(const I1 a_first, const I1 a_last, const I2 b_first, const I2 b_last) {
    std::vector<typename std::iterator_traits<I1>::value_type> a(a_first, a_last);
    std::vector<typename std::iterator_traits<I2>::value_type> b(b_first, b_last);
    return atcoder::convolution_ll(a, b);
}


} // namespace lib
/* [convolution/sum.hpp] */
#line 27 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [convolution/gcd.hpp] */
#line 1 "convolution/gcd.hpp"






/* #expanded [numeric/divisor_multiple_transform.hpp] */
#line 1 "numeric/divisor_multiple_transform.hpp"








/* #expanded [numeric/prime_enumerator.hpp] */
#line 1 "numeric/prime_enumerator.hpp"



#include <cmath>








/* #expanded [internal/endian.hpp] */
#line 1 "internal/endian.hpp"







namespace lib {

namespace internal {


enum class endian : std::uint8_t {
    little,
    big,
    other
};


endian discern_endian() {
  #ifdef __BYTE_ORDER__

    if constexpr(__BYTE_ORDER == __BIG_ENDIAN) return endian::big;
    if constexpr(__BYTE_ORDER == __LITTLE_ENDIAN) return endian::little;
    return {};

  #else
    static std::optional<endian> res;
    if(res) return res.value();

    union U {
        short s;
        char c[2];
    };
    U u = { .s = 0x0001 };

    if(u.c[0] == 0x00 && u.c[1] == 0x01) return *(res = endian::big);
    if(u.c[0] == 0x01 && u.c[1] == 0x00) return *(res = endian::little);
    return *(res = endian::other);

  #endif
}


} // namespace internal

} // namespace lib
/* [internal/endian.hpp] */
#line 14 "numeric/prime_enumerator.hpp"


/* #expanded [numeric/bit.hpp] */
#line 1 "numeric/bit.hpp"



#include <immintrin.h>








namespace lib {

#define LIB_STATUC_ASSERT_UNSIGNED(T) static_assert(std::is_unsigned_v<T>, "only unsigned type is supported")


template<class T>
__attribute__((target("bmi,bmi2,popcnt"))) inline constexpr int popcount(const T v) noexcept(NO_EXCEPT) {
    LIB_STATUC_ASSERT_UNSIGNED(T);

    using u = unsigned int;
    using ul = unsigned long;
    using ull = unsigned long long;

    if constexpr(std::is_same_v<T,u>) return __builtin_popcount(v);
    else if constexpr(std::is_same_v<T,ul>) return __builtin_popcountl(v);
    else if constexpr(std::is_same_v<T,ull>) return __builtin_popcountll(v);
    else return __builtin_popcountll(static_cast<ull>(v));
}

template<class T>
__attribute__((target("bmi,bmi2,lzcnt"))) inline constexpr int countl_zero(const T v) noexcept(NO_EXCEPT) {
    LIB_STATUC_ASSERT_UNSIGNED(T);

    using u = unsigned int;
    using ul = unsigned long;
    using ull = unsigned long long;

    constexpr int DIGITS = std::numeric_limits<T>::digits;
    if(v == 0) return DIGITS;

    constexpr int DIGITS_U = std::numeric_limits<u>::digits;
    constexpr int DIGITS_UL = std::numeric_limits<ul>::digits;
    constexpr int DIGITS_ULL = std::numeric_limits<ull>::digits;

    if constexpr(DIGITS <= DIGITS_U) return __builtin_clz(v) - DIGITS_U + DIGITS;
    if constexpr(DIGITS <= DIGITS_UL) return __builtin_clzl(v) - DIGITS_UL + DIGITS;
    if constexpr(DIGITS <= DIGITS_ULL) return __builtin_clzll(v) - DIGITS_ULL + DIGITS;
    else {
        static_assert(DIGITS <= DIGITS_ULL << 1);

        constexpr ull MAX_ULL = std::numeric_limits<ull>::max();

        const ull high = v >> DIGITS_ULL;
        const ull low = v & MAX_ULL;

        if(high != 0) return __builtin_clzll(high) - (DIGITS_ULL << 1) + DIGITS;
        return  __builtin_clzll(low) - DIGITS_ULL + DIGITS;
    }
}

template<class T>
inline constexpr int bit_width(const T v) noexcept(NO_EXCEPT) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    return std::numeric_limits<T>::digits - countl_zero(v);
}

template<class T>
inline constexpr int highest_bit_pos(const T v) noexcept(NO_EXCEPT) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    return bit_width(v) - 1;
}

template<class T>
__attribute__((target("bmi,bmi2,lzcnt")))
inline constexpr int lowest_bit_pos(const T v) noexcept(NO_EXCEPT) {
    LIB_STATUC_ASSERT_UNSIGNED(T);

    using u = unsigned int;
    using ul = unsigned long;
    using ull = unsigned long long;

    constexpr int DIGITS = std::numeric_limits<T>::digits;

    constexpr int DIGITS_U = std::numeric_limits<u>::digits;
    constexpr int DIGITS_UL = std::numeric_limits<ul>::digits;
    constexpr int DIGITS_ULL = std::numeric_limits<ull>::digits;

    if constexpr(DIGITS <= DIGITS_U) return __builtin_ffs(v) - 1;
    if constexpr(DIGITS <= DIGITS_UL) return __builtin_ffsl(v) - 1;
    if constexpr(DIGITS <= DIGITS_ULL) return __builtin_ffsll(v) - 1;
    else {
        static_assert(DIGITS <= DIGITS_ULL << 1);

        constexpr ull MAX_ULL = std::numeric_limits<ull>::max();

        const ull high = v >> DIGITS_ULL;
        const ull low = v & MAX_ULL;

        if(low != 0) return __builtin_ffsll(low) - 1;
        return __builtin_ffsll(high) + DIGITS_ULL - 1;
    }
}

template<class T>
inline constexpr int countr_zero(const T v) noexcept(NO_EXCEPT) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    if(v == 0) return std::numeric_limits<T>::digits;
    return lowest_bit_pos(v);
}

template<class T> constexpr int countl_one(const T x) { return countl_zero<T>(~x); }

template<class T> constexpr int countr_one(const T x) { return countr_zero<T>(~x); }


template<class T>
inline constexpr T bit_ceil(const T v) noexcept(NO_EXCEPT) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    if(v <= 1U) return 1;
    if constexpr(std::is_same_v<T,decltype(+v)>) return T{1} << bit_width<T>(v - 1);
    else {
        constexpr int d = std::numeric_limits<unsigned>::digits - std::numeric_limits<T>::digits;
        return T(1U << bit_width<T>(v - 1) + d) >> d;
    }
}

template<class T>
__attribute__((target("bmi2"))) inline constexpr T clear_higher_bits(const T v, const T p) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    constexpr int DIGITS = std::numeric_limits<T>::digits;
    assert(p < DIGITS);
    if constexpr(DIGITS <= 32) return _bzhi_u64(v, p);
    if constexpr(DIGITS <= 64) return _bzhi_u64(v, p);
    else {
        static_assert(DIGITS <= 128);

        constexpr std::uint64_t MAX64 = std::numeric_limits<std::uint64_t>::max();

        const std::uint64_t high = v >> 64;
        const std::uint64_t low = v & MAX64;

        if(p < 64) return _bzhi_u64(low, p);
        return low | (T{_bzhi_u64(high, p - 64)} << 64);
    }
}

template<class T> constexpr bool has_single_bit(const T x) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    return (x != 0) and (x & (x - 1)) == 0;
}

template<class T> constexpr T shiftl(const T, const int);
template<class T> constexpr T shiftr(const T, const int);

template<class T> constexpr T shiftl(const T x, const int n) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    constexpr int DIGITS = std::numeric_limits<T>::digits;
    if(n < 0) return shiftr(x, -n);
    if(n >= DIGITS) return 0;
    return x << n;
}

template<class T> constexpr T shiftr(const T x, const int n) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    constexpr int DIGITS = std::numeric_limits<T>::digits;
    if(n < 0) return shiftl(x, -n);
    if(n >= DIGITS) return 0;
    return x >> n;
}

template<class T> constexpr T rotl(const T x, const int n) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    constexpr int DIGITS = std::numeric_limits<T>::digits;
    if constexpr(has_single_bit(DIGITS)) {
        constexpr unsigned U_DIGITS = static_cast<unsigned>(DIGITS);
        const unsigned r = static_cast<unsigned>(n);
        return (x << (r % U_DIGITS)) | (x >> ((-r) % U_DIGITS));
    }
    const int r = n % DIGITS;
    if(r == 0) return x;
    if(r > 0) return (x << r) | (x >> ((DIGITS - r) % DIGITS));
    return (x >> (-r)) | (x << ((DIGITS + r) % DIGITS)); // rotr
}

template<class T> constexpr T rotr(const T x, const int n) {
    LIB_STATUC_ASSERT_UNSIGNED(T);
    constexpr int DIGITS = std::numeric_limits<T>::digits;
    if constexpr(has_single_bit(DIGITS)) {
        constexpr unsigned U_DIGITS = static_cast<unsigned>(DIGITS);
        const unsigned r = static_cast<unsigned>(n);
        return (x >> (r % U_DIGITS)) | (x << ((-r) % U_DIGITS)); // rotl
    }
    const int r = n % DIGITS;
    if(r == 0) return x;
    if(r > 0) return (x >> r) | (x << ((DIGITS - r) % DIGITS));
    return (x << (-r)) | (x >> ((DIGITS + r) % DIGITS));
}

#undef LIB_STATUC_ASSERT_UNSIGNED

} // namespace lib
/* [numeric/bit.hpp] */
#line 17 "numeric/prime_enumerator.hpp"


namespace lib {


// Thanks to: https://qiita.com/peria/items/e0ab38f95d16a5f7cc58
template<class T>
struct prime_enumerator {
    using value_type = T;
    using size_type = internal::size_t;
    using impl_type = std::uint32_t;

    impl_type n = 0;

  protected:
    using small_bit_type = std::uint8_t;
    using large_bit_type = std::uint64_t;

    mutable size_type _size = -1;

    impl_type _sqrt_n = 0, _sqrt_ni = 0, _quart_n = 0;

    std::valarray<small_bit_type> _small;
    std::valarray<large_bit_type> _large;
    std::vector<impl_type> _indecies;

    small_bit_type* _flag = nullptr;

    static constexpr impl_type SEGMENT_SIZE = 1'000'000;
    static constexpr impl_type  MOD30[] = { 1, 7, 11, 13, 17, 19, 23, 29 };
    static constexpr small_bit_type MASK[][8] = {
        { 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f },
        { 0xfd, 0xdf, 0xef, 0xfe, 0x7f, 0xf7, 0xfb, 0xbf },
        { 0xfb, 0xef, 0xfe, 0xbf, 0xfd, 0x7f, 0xf7, 0xdf },
        { 0xf7, 0xfe, 0xbf, 0xdf, 0xfb, 0xfd, 0x7f, 0xef },
        { 0xef, 0x7f, 0xfd, 0xfb, 0xdf, 0xbf, 0xfe, 0xf7 },
        { 0xdf, 0xf7, 0x7f, 0xfd, 0xbf, 0xfe, 0xef, 0xfb },
        { 0xbf, 0xfb, 0xf7, 0x7f, 0xfe, 0xef, 0xdf, 0xfd },
        { 0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe },
    };
    static constexpr impl_type C0[][8] = {
        { 0, 0, 0, 0, 0, 0, 0, 1 }, { 1, 1, 1, 0, 1, 1, 1, 1 },
        { 2, 2, 0, 2, 0, 2, 2, 1 }, { 3, 1, 1, 2, 1, 1, 3, 1 },
        { 3, 3, 1, 2, 1, 3, 3, 1 }, { 4, 2, 2, 2, 2, 2, 4, 1 },
        { 5, 3, 1, 4, 1, 3, 5, 1 }, { 6, 4, 2, 4, 2, 4, 6, 1 },
    };
    static constexpr impl_type C1[] = { 6, 4, 2, 4, 2, 4, 6, 2 };

    void _init(const value_type n, const impl_type size) noexcept(NO_EXCEPT) {
        const size_type blocks = size >> 3;
        this->_large.resize(blocks + 2, ~0UL);
        this->_flag = reinterpret_cast<small_bit_type*>(&(this->_large[0]));

        this->_flag[0] = 0xfe;

        value_type r = n % 30;
        if(r <= 1) this->_flag[size - 1] = 0x0;
        else if(r <= 7) this->_flag[size - 1] = 0x1;
        else if(r <= 11) this->_flag[size - 1] = 0x3;
        else if(r <= 13) this->_flag[size - 1] = 0x7;
        else if(r <= 17) this->_flag[size - 1] = 0xf;
        else if(r <= 19) this->_flag[size - 1] = 0x1f;
        else if(r <= 23) this->_flag[size - 1] = 0x3f;
        else if(r <= 29) this->_flag[size - 1] = 0x7f;

        if(n < 30) this->_flag[0] &= 0xfe;

        this->_large[blocks] <<= 64 - ((size & 7) << 3);
        this->_large[blocks] >>= 64 - ((size & 7) << 3);
        this->_large[blocks + 1] = 0;
    }

    void _gen_small() noexcept(NO_EXCEPT) {
        const impl_type quart_ni = this->_quart_n / 30 + 1;

        this->_small.resize(this->_sqrt_ni, 0xff);
        this->_small[0] = 0xfe;

        REP(i, quart_ni) {
            for(small_bit_type flags = this->_small[i]; flags; flags &= flags - 1) {
                const int ibit = lowest_bit_pos(flags);
                const impl_type m = prime_enumerator::MOD30[ibit];
                const impl_type pm = 30 * i + 2 * m;
                for(
                    impl_type j = i * pm + (m * m) / 30, k = ibit;
                    j < this->_sqrt_ni;
                    j += i * prime_enumerator::C1[k] + prime_enumerator::C0[ibit][k], k = (k + 1) & 7
                ) {
                    this->_small[j] &= prime_enumerator::MASK[ibit][k];
                }
            }
        }

        REP(i, this->_sqrt_ni) {
            for(small_bit_type flags = this->_small[i]; flags; flags &= flags - 1) {
                int ibit = lowest_bit_pos(flags);
                const impl_type m = prime_enumerator::MOD30[ibit];
                impl_type j = i * (30 * i + 2 * m) + (m * m) / 30;
                this->_indecies.emplace_back(((j + prime_enumerator::SEGMENT_SIZE) << 3) | ibit);
            }
        }
    }

    void _gen_core(small_bit_type *const flags, const impl_type size) noexcept(NO_EXCEPT) {
        auto p_index = this->_indecies.begin();
        REP(i, this->_sqrt_ni) {
            for(small_bit_type primes = this->_small[i]; primes; primes &= primes - 1) {
                const int ibit = lowest_bit_pos(primes);
                impl_type j = (*p_index >> 3) - prime_enumerator::SEGMENT_SIZE;
                impl_type k = *p_index & 7;
                for(; j < size; j += i * prime_enumerator::C1[k] + prime_enumerator::C0[ibit][k], k = (k + 1) & 7) {
                    flags[j] &= prime_enumerator::MASK[ibit][k];
                }
                *p_index = ((j << 3) | k);
                ++p_index;
            }
        }
    }

    using iterator_interface = internal::bidirectional_iterator_interface<const value_type>;

  public:
    struct iterator;
    using const_iterator = iterator;

    prime_enumerator(const value_type n) noexcept(NO_EXCEPT) : n(n) {
        assert(n >= 0);
        assert(internal::discern_endian() == internal::endian::little);

        this->_sqrt_n = static_cast<impl_type>(sqrt_ceil(this->n + 1));
        this->_sqrt_ni = this->_sqrt_n / 30 + 1;
        this->_quart_n = static_cast<impl_type>(sqrt_ceil(this->_sqrt_n));

        this->_gen_small();

        impl_type size = this->n / 30 + 1;
        this->_init(this->n + 1, size);

        for(small_bit_type* seg = this->_flag; ; seg += prime_enumerator::SEGMENT_SIZE) {
            if(size < prime_enumerator::SEGMENT_SIZE) {
                this->_gen_core(seg, size);
                break;
            };
            this->_gen_core(seg, prime_enumerator::SEGMENT_SIZE);
            size -= prime_enumerator::SEGMENT_SIZE;
        }
    }

    size_type size() const noexcept(NO_EXCEPT) {
        if(this->_size < 0) {
            this->_size = (this->n >= 2) + (this->n >= 3) + (this->n >= 5);
            for(const large_bit_type f : this->_large) this->_size += popcount(f);
        }
        return this->_size;
    }

    inline bool is_prime(const T v) const noexcept(NO_EXCEPT) {
        assert(0 <= v and v <= this->n);

        if(v == 0 or v == 1) return false;
        if(v == 2 or v == 3 or v == 5) return true;
        if((v & 1) == 0 or v % 3 == 0 or v % 5 == 0) return false;

        REP(i, 8) {
            if(prime_enumerator::MOD30[i] == v % 30) {
                return static_cast<bool>((this->_flag[v / 30] >> i) & 1);
            }
        }

        assert(false);
    }

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this->n, &this->_large, 0); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this->n, &this->_large, -1); }

    inline auto rbegin() noexcept(NO_EXCEPT) { return std::make_reverse_iterator(this->end()); }
    inline auto rend() noexcept(NO_EXCEPT) { return std::make_reverse_iterator(this->begin()); }

    struct iterator : virtual iterator_interface {
        using reference = value_type;

      protected:
        const value_type n = 0;
        const std::valarray<large_bit_type> *const _flags = nullptr;
        size_type _block = -1, _flag_size;
        int _bit = 0;

        inline value_type _value() const noexcept(NO_EXCEPT) {
            if(this->_bit < 0) return std::numeric_limits<value_type>::max();
            if(this->_block < 0) {
                if(this->_bit == 0) return 2;
                if(this->_bit == 1) return 3;
                if(this->_bit == 2) return 5;
            }
            return (
                value_type{30} * ((this->_block << 3) + (this->_bit >> 3)) +
                prime_enumerator::MOD30[this->_bit & 7]
            );
        }

      public:
        iterator() {}
        iterator(const value_type n, const std::valarray<large_bit_type> *const flags, const int bit) noexcept(NO_EXCEPT)
          : n(n), _flags(flags), _flag_size(static_cast<size_type>(flags->size())), _bit(bit) {
            if(bit < 0) {
                this->_block = static_cast<size_type>(flags->size()) - 1;
            }
        }

        friend inline bool operator==(const iterator& lhs, const iterator& rhs) noexcept(NO_EXCEPT) { return *lhs == *rhs; };
        friend inline bool operator!=(const iterator& lhs, const iterator& rhs) noexcept(NO_EXCEPT) { return *lhs != *rhs; };

        inline value_type operator*() const noexcept(NO_EXCEPT) {
            const value_type res = this->_value();
            return res > this->n ? -1 : res;
        }

        inline iterator& operator++() noexcept(NO_EXCEPT) {
            if(this->_value() > this->n) return *this;

            if(this->_block < 0) {
                this->_bit++;
                if(this->_bit > 2) this->_block = 0, this->_bit = 1;
                return *this;
            }

            int next;
            while(true) {
                const large_bit_type mask = this->_bit >= 63 ? 0UL : ~((1UL << (this->_bit + 1)) - 1);
                next = lowest_bit_pos(this->_flags->operator[](this->_block) & mask);
                if(next >= 0) break;
                this->_block++;
                this->_bit = -1;
                if(this->_block >= this->_flag_size) break;
            }
            this->_bit = next;

            return *this;
        }

        inline iterator& operator--() noexcept(NO_EXCEPT) {
            if(this->_block < 0) {
                if(this->_bit > 0) this->_bit--;
                return *this;
            }

            int prev = -1;
            while(true) {
                if(0 < this->_bit) {
                    const large_bit_type mask = this->_bit >= 64 ? ~0UL : ((1UL << this->_bit) - 1);
                    prev = highest_bit_pos(this->_flags->operator[](this->_block) & mask);
                }
                if(prev >= 0) break;
                this->_block--;
                this->_bit = 64;
                if(this->_block < 0) {
                    this->_bit = (this->n >= 3) + (this->n >= 5);
                    return *this;
                }
            }

            this->_bit = prev;

            return *this;
        }

        inline iterator operator++(int) noexcept(NO_EXCEPT) { const auto res = *this; ++(*this); return res; }
        inline iterator operator--(int) noexcept(NO_EXCEPT) { const auto res = *this; --(*this); return res; }
    };
};


} // namespace lib
/* [numeric/prime_enumerator.hpp] */
#line 10 "numeric/divisor_multiple_transform.hpp"


// Thanks to: https://nyaannyaan.github.io/library/multiplicative-function/divisor-multiple-transform.hpp.html
namespace lib {

namespace divisor_transform {


using size_type = internal::size_t;

template<class I>
auto zeta(const I first, const I last) noexcept(NO_EXCEPT) -> decltype((*first) += (*first), void()) {
    const auto n = static_cast<size_type>(std::distance(first, last));
    ITR(p, lib::prime_enumerator(n)) {
        for(size_type k=1; k*p <= n; ++k) first[k*p-1] += first[k-1];
    }
}

template<class I>
auto mobius(const I first, const I last) noexcept(NO_EXCEPT) -> decltype((*first) += (*first), void()) {
    const auto n = static_cast<size_type>(std::distance(first, last));
    ITR(p, lib::prime_enumerator(n)) {
        for(size_type k=n/p; k>0; --k) first[k*p-1] -= first[k-1];
    }
}

template<class I>
auto zeta(const I first, const I last) noexcept(NO_EXCEPT) -> decltype(first->first, first->second, void()) {
    for(auto itr1 = last; itr1-- != first; ) {
        for(auto itr2 = first; itr2 != last; ++itr2) {
            if(itr1->first == itr2->first) break;
            if(itr1->first % itr2->first == 0) itr1->second += itr2->second;
        }
    }
}

template<class I>
auto mobius(const I first, const I last) noexcept(NO_EXCEPT) -> decltype(first->first, first->second, void()) {
    for(auto itr2 = first; itr2 != last; ++itr2) {
        for(auto itr1 = last; (itr1--) != first; ) {
            if(itr1->first == itr2->first) break;
            if(itr1->first % itr2->first == 0) itr1->second -= itr2->second;
        }
    }
}


} // namespace divisor_transform


namespace multiple_transform  {


using size_type = internal::size_t;

template<class I>
auto zeta(const I first, const I last) noexcept(NO_EXCEPT) -> decltype((*first) += (*first), void()) {
    const auto n = static_cast<size_type>(std::distance(first, last));
    ITR(p, lib::prime_enumerator(n)) {
        for(size_type k=n/p; k>0; --k) first[k-1] += first[k*p-1];
    }
}

template<class I>
auto mobius(const I first, const I last) noexcept(NO_EXCEPT) -> decltype((*first) += (*first), void()) {
    const auto n = static_cast<size_type>(std::distance(first, last));
    ITR(p, lib::prime_enumerator(n)) {
        for(size_type k=1; k*p <= n; ++k) first[k-1] -= first[k*p-1];
    }
}

template<class I>
auto zeta(const I first, const I last) noexcept(NO_EXCEPT) -> decltype(first->first, first->second, void()) {
    for(auto itr2 = first; itr2 != last; ++itr2) {
        for(auto itr1 = last; --itr1 != itr2; ) {
            if(itr1->first % itr2->first == 0) itr2->second += itr1->second;
        }
    }
}

template<class I>
auto mobius(const I first, const I last) noexcept(NO_EXCEPT) -> decltype(first->first, first->second, void()) {
    for(auto itr2 = last; itr2-- != first; ) {
        for(auto itr1 = last; --itr1 != itr2; ) {
            if(itr1->first % itr2->first == 0) itr2->second -= itr1->second;
        }
    }
}


} // namespace multiple_transform

} // namespace lib
/* [numeric/divisor_multiple_transform.hpp] */
#line 8 "convolution/gcd.hpp"


namespace lib {


template<class I1, class I2>
auto gcd_convolution(const I1 a_first, const I1 a_last, const I2 b_first, const I2 b_last) {
    std::vector<typename std::iterator_traits<I1>::value_type> a(a_first, a_last);
    std::vector<typename std::iterator_traits<I2>::value_type> b(b_first, b_last);

    assert(a.size() == b.size());

    multiple_transform::zeta(ALL(a)), multiple_transform::zeta(ALL(b));
    for(std::size_t i=0; i<a.size(); ++i) a[i] *= b[i];
    multiple_transform::mobius(ALL(a));
    return a;
}


} // namespace lib
/* [convolution/gcd.hpp] */
#line 28 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [convolution/lcm.hpp] */
#line 1 "convolution/lcm.hpp"








namespace lib {


template<class I1, class I2>
auto lcm_convolution(const I1 a_first, const I1 a_last, const I2 b_first, const I2 b_last) {
    std::vector<typename std::iterator_traits<I1>::value_type> a(a_first, a_last);
    std::vector<typename std::iterator_traits<I2>::value_type> b(b_first, b_last);


    assert(a.size() == b.size());

    debug(a, b);
    divisor_transform::zeta(ALL(a)), divisor_transform::zeta(ALL(b));
    debug(a, b);
    for(std::size_t i=0; i<a.size(); ++i) a[i] *= b[i];
    divisor_transform::mobius(ALL(a));
    return a;
}


} // namespace lib
/* [convolution/lcm.hpp] */
#line 29 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [data_structure/adapter/set.hpp] */
#line 1 "data_structure/adapter/set.hpp"












/* #expanded [data_structure/internal/declarations.hpp] */
#line 1 "data_structure/internal/declarations.hpp"



namespace lib {

namespace internal {

namespace fenwick_tree_impl {

template<class,class> struct core;

} // namespace implici_treap_impl


namespace segment_tree_impl {

template<class,class> struct core;

} // namespace segment_tree_impl


namespace lazy_segment_tree_impl {

template<class> struct core;

} // namespace lazy_segment_tree_impl


namespace implicit_treap_impl {

template<class> struct core;

} // namespace implici_treap_impl


namespace disjoint_sparse_table_impl {

template<class,class> struct core;

} // namespace disjoint_sparse_table_impl


} // namespace internal


template<class> struct fenwick_tree;
template<class> struct segment_tree;
template<class> struct lazy_segment_tree;
template<class> struct implicit_treap;
template<class> struct disjoint_sparse_table;


} // namespace lib
/* [data_structure/internal/declarations.hpp] */
#line 14 "data_structure/adapter/set.hpp"
/* #expanded [data_structure/range_action/range_add_range_sum.hpp] */
#line 1 "data_structure/range_action/range_add_range_sum.hpp"







/* #expanded [data_structure/range_action/base.hpp] */
#line 1 "data_structure/range_action/base.hpp"








namespace lib {

namespace actions {

namespace internal {

struct base {};

} // namespace internal



template<class operation = std::nullptr_t> struct base : internal::base {
    static operation fold(const operation& x, const lib::internal::size_t) noexcept(NO_EXCEPT) { return x; }
};


} // namespace actions

} // namespace lib
/* [data_structure/range_action/base.hpp] */
#line 9 "data_structure/range_action/range_add_range_sum.hpp"
/* #expanded [data_structure/range_action/flags.hpp] */
#line 1 "data_structure/range_action/flags.hpp"




/* #expanded [internal/bit_field.hpp] */
#line 1 "internal/bit_field.hpp"








namespace lib {

namespace internal {

namespace bit_field {


template<class Flag> struct base {
    using flag = Flag;
    using bit_type = typename std::underlying_type_t<flag>;

  private:
    const bit_type _bits;

  public:
    constexpr bit_type bits() const noexcept(NO_EXCEPT) { return this->_bits; }


    template<class... Flags>
    constexpr base(Flags... flags) : _bits(set(flags...)) {}

    constexpr bool none() const noexcept(NO_EXCEPT) { return this->_bits == 0; }

    template<class... Tail>
    static constexpr bit_type set(flag head, Tail... tail) noexcept(NO_EXCEPT) {
        return static_cast<bit_type>(head) | set(tail...);
    }

    static constexpr bit_type set() noexcept(NO_EXCEPT) { return 0; }

    template<class... Tail> constexpr bool has(flag head, Tail... tail) const noexcept(NO_EXCEPT) {
        return (this->bits() & static_cast<bit_type>(head)) and has(tail...);
    }
    constexpr bool has() const noexcept(NO_EXCEPT) { return true; }
};


} // namespace bit_field

} // namespace internal

} // namespace lib
/* [internal/bit_field.hpp] */
#line 6 "data_structure/range_action/flags.hpp"


namespace lib {

namespace actions {

namespace internal {


enum class tags : std::uint8_t {
    range_folding = 1 << 0,
    range_operation = 1 << 1,
};


} // namespace internal


struct flags : lib::internal::bit_field::base<internal::tags> {
    using lib::internal::bit_field::base<internal::tags>::base;

    static constexpr internal::tags range_folding = internal::tags::range_folding;
    static constexpr internal::tags range_operation = internal::tags::range_operation;
};


} // namespace actions

} // namespace lib
/* [data_structure/range_action/flags.hpp] */
#line 10 "data_structure/range_action/range_add_range_sum.hpp"


#line 12 "data_structure/range_action/range_add_range_sum.hpp"


namespace lib {

namespace actions {


template<class T> struct range_add_range_sum : base<> {
    static constexpr flags tags{ flags::range_folding, flags::range_operation };

    using operand = algebraic::addition<T>;
    using operation = algebraic::addition<T>;

    static operand map(const operand& x, const operation& y) noexcept(NO_EXCEPT) { return x.val() + y.val(); }
    static operation fold(const operation& x, const lib::internal::size_t length) noexcept(NO_EXCEPT) { return x.val() * length; }
};


} // namespace actions


template<class T> struct lazy_segment_tree<actions::range_add_range_sum<T>> : internal::lazy_segment_tree_impl::core<actions::range_add_range_sum<T>> {
  private:
    using base = internal::lazy_segment_tree_impl::core<actions::range_add_range_sum<T>>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator-=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline range_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }
        inline range_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }
        inline range_reference& operator-=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }

        inline auto sum() const noexcept(NO_EXCEPT) { return this->_super->fold(this->_begin, this->_end); }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto& add(const size_type first, const size_type last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, val); return *this; }
    inline auto& add(const size_type pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, val); return *this; }
    inline auto& add(const T& val) noexcept(NO_EXCEPT) { this->apply(val); return *this; }

    inline auto sum(const size_type first, const size_type last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto sum() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_add_range_sum.hpp] */
#line 15 "data_structure/adapter/set.hpp"

namespace lib {


template<template<class> class Tree = lib::fenwick_tree, class Size = internal::size_t>
struct set_adapter {
    using size_type = Size;
    using key_type = internal::size_t;
    using value_type = size_type;

  protected:
    set_adapter() noexcept(NO_EXCEPT) {}

    using Impl = Tree<actions::range_add_range_sum<value_type>>;

    Impl _data;
    size_type _elem = 0;

  public:
    set_adapter(const size_type sup) noexcept(NO_EXCEPT) : _data(sup) {};

    template<class I>
    set_adapter(const I first, const I last) noexcept(NO_EXCEPT) : _data(*std::max_element(first, last)+1) {
        valarray<bool> bits(this->_data.size());
        REP(itr, first, last) {
            assert(0 <= *itr && *itr < this->_data.size());
            bits[*itr] = true;
        }
        this->build_from_bits(ALL(bits));
    };


    template<class I>
    inline auto& build_from_bits(const I first, const I last) noexcept(NO_EXCEPT) {
        assert(std::distance(first, last) == this->_data.size());
        using T = typename std::iterator_traits<I>::value_type;
        static_assert(std::is_same_v<bool,T>, "bit type must be bool");
        static_assert(std::is_same_v<Size,std::common_type_t<Size,T>>, "counter type must be narrower than size_type");
        this->_data.assign(first, last);
        return *this;
    };


    inline size_type size() const noexcept(NO_EXCEPT) { return this->_elem; }
    inline bool empty() const noexcept(NO_EXCEPT) { return this->size() == 0; }

    inline size_type count(const key_type& k) const noexcept(NO_EXCEPT) { return this->_data.get(k); }
    inline bool contains(const key_type& k) const noexcept(NO_EXCEPT) { return this->_data.get(k) > 0; }

    inline bool insert(const key_type& k) noexcept(NO_EXCEPT) {
        assert(0 <= k && k < this->_data.size());
        const bool res = !this->_data.get(k);
        if(res) this->_data.apply(k, 1), ++this->_elem;
        return res;
    }

    inline bool remove(const key_type& k) noexcept(NO_EXCEPT) {
        assert(0 <= k && k < this->_data.size());
        const bool res = this->_data.get(k);
        if(res) this->_data.apply(k, -1), --this->_elem;
        return res;
    }

    inline std::optional<value_type> next(const key_type& k, const size_type count = 0) const noexcept(NO_EXCEPT) {
        const value_type v = this->_data.max_right(k, [count](const size_type p) { return p <= count; });
        if(v == this->_data.size()) return {};
        return { v };
    }
    inline std::optional<value_type> prev(const key_type& k, const size_type count = 0) const noexcept(NO_EXCEPT) {
        const value_type v = this->_data.min_left(k+1, [count](const size_type p) { return p <= count; });
        if(v == 0) return {};
        return { v - 1 };
    }

    inline auto kth_smallest(const size_type k) const noexcept(NO_EXCEPT) { return this->next(0, k); }
    inline auto kth_largest(const size_type k) const noexcept(NO_EXCEPT) { return this->prev(this->_data.size()-1, k); }

    inline value_type min() const noexcept(NO_EXCEPT) { return this->kth_smallest(0); }
    inline value_type max() const noexcept(NO_EXCEPT) { return this->kth_largest(0); }

    inline size_type count_under(const value_type& v) const noexcept(NO_EXCEPT) { return this->_data.fold(0, v); }
    inline size_type count_over(const value_type& v) const noexcept(NO_EXCEPT) { return this->_data.fold(v+1, this->_data.size()); }
    inline size_type count_or_under(const value_type& v) const noexcept(NO_EXCEPT) { return this->_data.fold(0, v+1); }
    inline size_type count_or_over(const value_type& v) const noexcept(NO_EXCEPT) { return this->_data.fold(v, this->_data.size()); }

    template<comp com = comp::equal_to>
    inline size_type count(const value_type& v) const noexcept(NO_EXCEPT) {
        if constexpr(com == comp::eq) return this->count(v);
        if constexpr(com == comp::under) return this->count_under(v);
        if constexpr(com == comp::over) return this->count_over(v);
        if constexpr(com == comp::or_under) return this->count_or_under(v);
        if constexpr(com == comp::or_over) return this->count_or_over(v);
        assert(false);
    }

    inline const auto& _debug() const noexcept(NO_EXCEPT) { return this->_data; }
};


template<template<class> class Tree = lib::fenwick_tree, class Size = std::int64_t>
struct multiset_adapter : protected set_adapter<Tree,Size> {
    using size_type = Size;
    using key_type = internal::size_t;
    using value_type = key_type;

  private:
    using base = set_adapter<Tree,Size>;

  public:
    multiset_adapter(const size_type sup) noexcept(NO_EXCEPT) : base(sup) {};

    template<class I>
    multiset_adapter(const I first, const I last) noexcept(NO_EXCEPT) : base(*max_element(first, last)+1) {
        vector<size_type> bits(this->_data.size());
        REP(itr, first, last) {
            assert(0 <= *itr && *itr < this->_data.size());
            bits[*itr]++;
        }
        this->build_from_histogram(ALL(bits));
    };

    template<class I>
    inline auto& build_from_histogram(const I first, const I last) noexcept(NO_EXCEPT) {
        assert(std::distance(first, last) == this->_data.size());
        using T = typename std::iterator_traits<I>::value_type;
        static_assert(std::is_integral_v<T>, "counter type must be integal");
        static_assert(std::is_same_v<Size,std::common_type_t<Size,T>>, "counter type must be narrower than size_type");
        this->_data.assign(first, last);
        return *this;
    };

    inline void insert(const key_type& k, const size_type count = 1) noexcept(NO_EXCEPT) {
        assert(0 <= k && k < this->_data.size());
        this->_data.apply(k, count);
        this->_elem += count;
    }

    inline void remove(const key_type& k, const size_type count = 1) noexcept(NO_EXCEPT) {
        assert(0 <= k && k < this->_data.size());
        this->_data.apply(k, -count);
        this->_elem -= count;
    }



    inline std::optional<value_type> next(const key_type& k, const size_type count = 0) const noexcept(NO_EXCEPT) {
        const value_type v = this->_data.max_right(k, [count](const size_type p) { return p <= count; });
        if(v == this->_data.size()) return {};
        return { v };
    }
    inline std::optional<value_type> prev(const key_type& k, const size_type count = 0) const noexcept(NO_EXCEPT) {
        const value_type v = this->_data.min_left(k+1, [count](const size_type p) { return p <= count; });
        if(v == 0) return {};
        return { v - 1 };
    }

    using base::kth_smallest;
    using base::kth_largest;

    using base::min;
    using base::max;

    using base::count_under;
    using base::count_over;
    using base::count_or_under;
    using base::count_or_over;
    using base::count;

    using base::_debug;

};


} // namespace lib
/* [data_structure/adapter/set.hpp] */
#line 31 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"


#line 33 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 34 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/null.hpp] */
#line 1 "data_structure/range_action/null.hpp"













#line 14 "data_structure/range_action/null.hpp"


namespace lib {

namespace actions {


template<class T> struct null : base<algebraic::null<T>> {
    static constexpr flags tags{ flags::range_folding, flags::range_operation };

    using operand = algebraic::addition<T>;
    using operation = algebraic::null<T>;

    static operand map(const operand& x, const operation&) noexcept(NO_EXCEPT) { return x; }
};


} // namespace actions


template<class T> struct implicit_treap<actions::null<T>> : internal::implicit_treap_impl::core<actions::null<T>> {
    using internal::implicit_treap_impl::core<actions::null<T>>::core;

    template<class... Args> void apply(const Args&... args) = delete;
    template<class... Args> void fold(const Args&... args) = delete;
};


} // namespace lib
/* [data_structure/range_action/null.hpp] */
#line 35 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_add.hpp] */
#line 1 "data_structure/range_action/range_add.hpp"








/* #expanded [internal/point_reference.hpp] */
#line 1 "internal/point_reference.hpp"











namespace lib {

namespace internal {


template<class Super> struct point_reference {
    using size_type = typename Super::size_type;
    using iterator = typename Super::iterator;

  protected:
    Super *const _super;
    const size_type _pos;

    point_reference(Super *const super, const size_type pos) noexcept(NO_EXCEPT) : _super(super), _pos(pos) {}
};


} // namespace internal

} // namespace lib
/* [internal/point_reference.hpp] */
#line 10 "data_structure/range_action/range_add.hpp"
/* #expanded [internal/range_reference.hpp] */
#line 1 "internal/range_reference.hpp"











namespace lib {

namespace internal {


template<class Super> struct range_reference {
    using size_type = typename Super::size_type;
    using iterator = typename Super::iterator;

  protected:
    Super *const _super;
    const size_type _begin, _end;

    range_reference(Super *const super, const size_type begin, const size_type end) noexcept(NO_EXCEPT) : _super(super), _begin(begin), _end(end) {}

  public:
    inline iterator begin() const noexcept(NO_EXCEPT) { return std::next(_super->begin(), this->_begin); }
    inline iterator end() const noexcept(NO_EXCEPT) { return std::next(_super->begin(), this->_end); }

    inline size_type size() const noexcept(NO_EXCEPT) { return this->_end - this->_begin; }

  protected:
    inline range_reference sub_range(size_type l, size_type r) const noexcept(NO_EXCEPT) {
        l = _super->_positivize_index(l), r = _super->_positivize_index(r);
        assert(0 <= l and l <= r and r <= this->size());

        return range_reference(_super, this->_begin + l, this->_begin + r);
    }

  public:
    template<lib::interval rng = lib::interval::right_open>
    inline range_reference range(const size_type l, const size_type r) const noexcept(NO_EXCEPT) {
        if constexpr(rng == lib::interval::right_open) return this->sub_range(l, r);
        if constexpr(rng == lib::interval::left_open) return this->sub_range(l+1, r+1);
        if constexpr(rng == lib::interval::open) return this->sub_range(l+1, r);
        if constexpr(rng == lib::interval::closed) return this->sub_range(l, r+1);
    }
    inline range_reference range() const noexcept(NO_EXCEPT) { return range_reference(this->_begin, this->_end); }

    inline range_reference operator()(const size_type l, const size_type r) const noexcept(NO_EXCEPT) { return this->sub_range(l, r); }

    inline range_reference subseq(const size_type p, const size_type c) const noexcept(NO_EXCEPT) { return this->sub_range(p, p+c); }
    inline range_reference subseq(const size_type p) const noexcept(NO_EXCEPT) { return this->sub_range(p, this->size()); }
};


} // namespace internal

} // namespace lib
/* [internal/range_reference.hpp] */
#line 11 "data_structure/range_action/range_add.hpp"

/* #expanded [data_structure/range_action/range_sum.hpp] */
#line 1 "data_structure/range_action/range_sum.hpp"













namespace lib {

namespace actions {


template<class T> struct range_sum : base<> {
    static constexpr flags tags{ flags::range_folding };

    using operand = algebraic::addition<T>;
};


} // namespace actions


template<class T> struct fenwick_tree<actions::range_sum<T>> : internal::fenwick_tree_impl::core<actions::range_sum<T>,void> {
  private:
    using base = internal::fenwick_tree_impl::core<actions::range_sum<T>,void>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator-=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, -val); return *this; }
        inline point_reference& operator++(int) noexcept(NO_EXCEPT) { return *this += 1; }
        inline point_reference& operator--(int) noexcept(NO_EXCEPT) { return *this -= 1; }
        inline point_reference& operator++() noexcept(NO_EXCEPT) { const auto res = *this; *this += 1; return res; }
        inline point_reference& operator--() noexcept(NO_EXCEPT) { const auto res = *this; *this -= 1; return res; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline auto sum() const { return this->_super->fold(this->_begin, this->_end); }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto& add(const size_type first, const size_type last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, val); return *this; }
    inline auto& add(const size_type pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, val); return *this; }
    inline auto& add(const T& val) noexcept(NO_EXCEPT) { this->apply(val); return *this; }
    inline auto& operator+=(const T& val) noexcept(NO_EXCEPT) { this->apply(this->_pos, val); return *this; }
    inline auto& operator-=(const T& val) noexcept(NO_EXCEPT) { this->apply(this->_pos, -val); return *this; }
    inline auto& operator++(int) noexcept(NO_EXCEPT) { return *this += 1; }
    inline auto& operator--(int) noexcept(NO_EXCEPT) { return *this -= 1; }
    inline auto& operator++() noexcept(NO_EXCEPT) { const auto res = *this; *this += 1; return res; }
    inline auto& operator--() noexcept(NO_EXCEPT) { const auto res = *this; *this -= 1; return res; }

    inline auto sum(const size_t first, const size_t last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto sum() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_sum.hpp] */
#line 13 "data_structure/range_action/range_add.hpp"



namespace lib {

namespace actions {

template<class T> struct range_add {
    static constexpr flags tags{ flags::range_operation };
};

} // namespace actions


template<class T> struct fenwick_tree<actions::range_add<T>> : fenwick_tree<actions::range_sum<T>> {
  private:
    using core = fenwick_tree<actions::range_sum<T>>;

  public:
    using value_type = typename core::value_type;
    using size_type = typename core::size_type;

  protected:
    inline bool _validate_index_in_right_open([[maybe_unused]] const size_type p) const noexcept(NO_EXCEPT) {
        return 0 <= p and p < this->size();
    }
    inline bool _validate_index_in_closed([[maybe_unused]] const size_type p) const noexcept(NO_EXCEPT) {
        return 0 <= p and p <= this->size();
    }
    inline bool _validate_rigth_open_interval([[maybe_unused]] const size_type l, [[maybe_unused]] const size_type r) const noexcept(NO_EXCEPT) {
        return 0 <= l and l <= r and r <= this->size();
    }

    inline size_type _positivize_index(const size_type p) const noexcept(NO_EXCEPT) {
        return p < 0 ? this->size() + p : p;
    }

  public:
    explicit fenwick_tree(const size_type size = 0) noexcept(NO_EXCEPT) : core(size+1) {}
    explicit fenwick_tree(const size_type size, const value_type& val) noexcept(NO_EXCEPT) : core(size+1, val) {}

    template<class U> fenwick_tree(const std::initializer_list<U>& init_list) noexcept(NO_EXCEPT) : fenwick_tree(ALL(init_list)) {}

    template<class I, std::void_t<typename std::iterator_traits<I>::value_type>* = nullptr>
    fenwick_tree(const I first, const I last) noexcept(NO_EXCEPT) : fenwick_tree(std::distance(first, last)) {
        size_type pos = 0;
        for(auto itr=first; itr!=last; ++itr, ++pos) this->apply(pos, *itr);
    }

    inline size_type size() const noexcept(NO_EXCEPT) { return this->core::size() - 1; }


    struct point_reference : internal::point_reference<fenwick_tree> {
        point_reference(fenwick_tree *const super, const size_type p) noexcept(NO_EXCEPT)
          : internal::point_reference<fenwick_tree>(super, super->_positivize_index(p))
        {
            this->_super->_validate_index_in_right_open(this->_pos);
        }

        operator value_type() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }
        value_type val() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }

        inline point_reference& set(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }
        inline point_reference& operator=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }

        inline point_reference& apply(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
        inline point_reference& operator<<=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }

        inline point_reference& add(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
        inline point_reference& operator+=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
        inline point_reference& operator-=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, -v);
            return *this;
        }
    };

    struct range_reference : internal::range_reference<fenwick_tree> {
        range_reference(fenwick_tree *const super, const size_type l, const size_type r) noexcept(NO_EXCEPT)
          : internal::range_reference<fenwick_tree>(super, super->_positivize_index(l), super->_positivize_index(r))
        {
            this->_super->_validate_rigth_open_interval(this->_begin, this->_end);
        }

        inline range_reference& apply(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_begin, this->_end, v);
            return *this;
        }
        inline range_reference& operator<<=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_begin, this->_end, v);
            return *this;
        }

        inline range_reference& add(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_begin, this->_end, v);
            return *this;
        }
        inline range_reference& operator+=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_begin, this->_end, v);
            return *this;
        }
        inline range_reference& operator-=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_begin, this->_end, -v);
            return *this;
        }
    };


    inline auto& add(const size_type first, const size_type last, const value_type& v) noexcept(NO_EXCEPT) {
        this->core::apply(first, v), this->core::apply(last, -v);
        return *this;
    }
    inline auto& add(const size_type p, const value_type& v) noexcept(NO_EXCEPT) { this->apply(p, p+1, v); return *this; }
    inline auto& add(const value_type& v) noexcept(NO_EXCEPT) { this->apply(0, this->size(), v); return *this; }

    inline auto& apply(const size_type first, const size_type last, const value_type& v) noexcept(NO_EXCEPT) {
        this->core::apply(first, v), this->core::apply(last, -v);
        return *this;
    }
    inline auto& apply(const size_type p, const value_type& v) noexcept(NO_EXCEPT) { this->apply(p, p+1, v); return *this; }
    inline auto& apply(const value_type& v) noexcept(NO_EXCEPT) { this->apply(0, this->size(), v); return *this; }

    inline auto& set(const size_type p, const value_type& v) noexcept(NO_EXCEPT) { this->add(p, v + -this->get(p)).val(); return *this; }

    inline value_type get(const size_type p) const noexcept(NO_EXCEPT) {
        assert(0 <= p and p < this->size());
        return this->core::fold(p+1);
    }
    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }

    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

  protected:
    using iterator_interface = internal::container_iterator_interface<value_type,fenwick_tree>;

  public:
    struct iterator : virtual iterator_interface {
        iterator(const fenwick_tree *const ref, const size_type pos) noexcept(NO_EXCEPT) : iterator_interface(ref, pos) {}

        inline value_type operator*() const noexcept(NO_EXCEPT) { return this->ref()->get(this->pos()); }
        inline value_type operator[](const typename iterator_interface::difference_type count) const noexcept(NO_EXCEPT) { return *(*this + count); }
    };

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this, 0); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this, this->size()); }
};


} // namespace lib
/* [data_structure/range_action/range_add.hpp] */
#line 36 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_add_range_max.hpp] */
#line 1 "data_structure/range_action/range_add_range_max.hpp"











#line 12 "data_structure/range_action/range_add_range_max.hpp"




namespace lib {

namespace actions {


template<class T> struct range_add_range_max : base<algebraic::addition<T>> {
    static constexpr flags tags{ flags::range_folding, flags::range_operation };

    using operand = algebraic::maximum<T>;
    using operation = algebraic::addition<T>;

    static operand map(const operand& x, const operation& y) noexcept(NO_EXCEPT) { return x.val() + y.val(); }
};


} // namespace actions


template<class T> struct lazy_segment_tree<actions::range_add_range_max<T>> : internal::lazy_segment_tree_impl::core<actions::range_add_range_max<T>> {
  private:
    using base = internal::lazy_segment_tree_impl::core<actions::range_add_range_max<T>>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator-=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, -val); return *this; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline range_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }
        inline range_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }
        inline range_reference& operator-=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, -val); return *this; }

        inline auto max() const noexcept(NO_EXCEPT) { return this->_super->fold(this->_begin, this->_end); }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto& add(const size_type first, const size_type last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, val); return *this; }
    inline auto& add(const size_type pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, val); return *this; }
    inline auto& add(const T& val) noexcept(NO_EXCEPT) { this->apply(val); return *this; }

    inline auto max(const size_type first, const size_type last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto max() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_add_range_max.hpp] */
#line 37 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_add_range_min.hpp] */
#line 1 "data_structure/range_action/range_add_range_min.hpp"











#line 12 "data_structure/range_action/range_add_range_min.hpp"



namespace lib {

namespace actions {


template<class T> struct range_add_range_min : base<algebraic::addition<T>> {
    static constexpr flags tags{ flags::range_folding, flags::range_operation };

    using operand = algebraic::minimum<T>;
    using operation = algebraic::addition<T>;

    static operand map(const operand& x, const operation& y) noexcept(NO_EXCEPT) { return x.val() + y.val(); }
};


} // namespace actions


template<class T> struct lazy_segment_tree<actions::range_add_range_min<T>> : internal::lazy_segment_tree_impl::core<actions::range_add_range_min<T>> {
  private:
    using base = internal::lazy_segment_tree_impl::core<actions::range_add_range_min<T>>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator-=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline range_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }
        inline range_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }
        inline range_reference& operator-=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }

        inline auto min() const { return this->_super->fold(this->_begin, this->_end); }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto& add(const size_type first, const size_type last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, val); return *this; }
    inline auto& add(const size_type pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, val); return *this; }
    inline auto& add(const T& val) noexcept(NO_EXCEPT) { this->apply(val); return *this; }

    inline auto min(const size_type first, const size_type last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto min() noexcept(NO_EXCEPT) { return this->fold(); }
};



} // namespace lib
/* [data_structure/range_action/range_add_range_min.hpp] */
#line 38 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 39 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_affine_range_minmax.hpp] */
#line 1 "data_structure/range_action/range_affine_range_minmax.hpp"











#line 12 "data_structure/range_action/range_affine_range_minmax.hpp"

#line 13 "data_structure/range_action/range_affine_range_minmax.hpp"



namespace lib {


namespace actions {


template<class T> struct range_affine_range_minmax : base<algebraic::affine<T>> {
    static constexpr flags tags{ flags::range_folding, flags::range_operation };

    using operand = algebraic::minmax<T>;
    using operation = algebraic::affine<T>;

    static operand map(const operand& x, const operation& y) noexcept(NO_EXCEPT) {
        auto res = operand({ x->first * y->first + y->second, x->second * y->first + y->second });
        if (y->first < 0) std::swap(res->first, res->second);
        return res;
    }
};


} // namespace actions


template<class T> struct lazy_segment_tree<actions::range_affine_range_minmax<T>> : internal::lazy_segment_tree_impl::core<actions::range_affine_range_minmax<T>> {
  private:
    using base = internal::lazy_segment_tree_impl::core<actions::range_affine_range_minmax<T>>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& affine(const T& a, const T& b) noexcept(NO_EXCEPT) { return this->_super->apply(this->_pos, { a, b }); return *this; }

        inline point_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { 0, val }); return *this; }
        inline point_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { 0, val }); return *this; }

        inline point_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { 1, val }); return *this; }
        inline point_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { 1, val }); return *this; }

        inline point_reference& times(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { val, 0 }); return *this; }
        inline point_reference& operator*=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { val, 0 }); return *this; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline range_reference& affine(const T& a, const T& b) noexcept(NO_EXCEPT) { return this->_super->apply(this->_begin, this->_end, { a, b }); return *this; }

        inline range_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { 0, val }); return *this; }
        inline range_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { 0, val }); return *this; }

        inline range_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { 1, val }); return *this; }
        inline range_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { 1, val }); return *this; }

        inline range_reference& times(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { val, 0 }); return *this; }
        inline range_reference& operator*=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { val, 0 }); return *this; }

        inline auto minmax() const { return this->_super->fold(this->_begin, this->_end); }
        inline auto min() const { return this->_super->fold(this->_begin, this->_end).first; }
        inline auto max() const { return this->_super->fold(this->_begin, this->_end).second; }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto& affine(const size_t first, const size_t last, const T& a, const T& b) noexcept(NO_EXCEPT) { this->apply(first, last, { a, b }); return *this; }
    inline auto& affine(const size_t pos, const T& a, const T& b) noexcept(NO_EXCEPT) { this->apply(pos, { a, b }); return *this; }
    inline auto& affine(const T& a, const T& b) noexcept(NO_EXCEPT) { this->apply({ a, b }); return *this; }

    inline auto& set(const size_t first, const size_t last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, { 0, val }); return *this; }
    inline auto& set(const size_t pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, { 0, val }); return *this; }
    inline auto& set(const T& val) noexcept(NO_EXCEPT) { this->apply({ 0, val }); return *this; }

    inline auto& add(const size_type first, const size_type last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, { 1, val }); return *this; }
    inline auto& add(const size_type pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, { 1, val }); return *this; }
    inline auto& add(const T& val) noexcept(NO_EXCEPT) { this->apply({ 1, val }); return *this; }

    inline auto& times(const size_t first, const size_t last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, { val, 0 }); return *this; }
    inline auto& times(const size_t pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, { val, 0 }); return *this; }
    inline auto& times(const T& val) noexcept(NO_EXCEPT) { this->apply({ val, 0 }); return *this; }


    inline auto minmax(const size_t first, const size_t last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto minmax() noexcept(NO_EXCEPT) { return this->fold(); }

    inline auto min(const size_t first, const size_t last) noexcept(NO_EXCEPT) { return this->fold(first, last).first; }
    inline auto min() noexcept(NO_EXCEPT) { return this->fold().first; }

    inline auto max(const size_t first, const size_t last) noexcept(NO_EXCEPT) { return this->fold(first, last).second; }
    inline auto max() noexcept(NO_EXCEPT) { return this->fold().second; }
};


} // namespace lib
/* [data_structure/range_action/range_affine_range_minmax.hpp] */
#line 40 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_affine_range_sum.hpp] */
#line 1 "data_structure/range_action/range_affine_range_sum.hpp"















namespace lib {

namespace actions {


template<class T> struct range_affine_range_sum : base<> {
    static constexpr flags tags{ flags::range_folding, flags::range_operation };

    using operand = algebraic::addition<T>;
    using operation = algebraic::affine<T>;

    static operand map(const operand& x, const operation& y) noexcept(NO_EXCEPT) { return y->first * x.val() + y->second; }
    static operation fold(const operation& x, const lib::internal::size_t length) noexcept(NO_EXCEPT) { return operation({ x->first, x->second * length }); }
};


} // namespace actions


template<class T>
struct lazy_segment_tree<actions::range_affine_range_sum<T>> : internal::lazy_segment_tree_impl::core<actions::range_affine_range_sum<T>> {
  private:
    using base = internal::lazy_segment_tree_impl::core<actions::range_affine_range_sum<T>>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& affine(const T& a, const T& b) noexcept(NO_EXCEPT) { return this->_super->apply(this->_pos, { a, b }); return *this; }

        inline point_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { 0, val }); return *this; }
        inline point_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { 0, val }); return *this; }

        inline point_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { 1, val }); return *this; }
        inline point_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { 1, val }); return *this; }

        inline point_reference& times(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { val, 0 }); return *this; }
        inline point_reference& operator*=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, { val, 0 }); return *this; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline range_reference& affine(const T& a, const T& b) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { a, b }); return *this; }

        inline range_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { 0, val }); return *this; }
        inline range_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { 0, val }); return *this; }

        inline range_reference& add(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { 1, val }); return *this; }
        inline range_reference& operator+=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { 1, val }); return *this; }
        inline range_reference& operator-=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { 1, -val }); return *this; }

        inline range_reference& times(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { val, 0 }); return *this; }
        inline range_reference& operator*=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, { val, 0 }); return *this; }

        inline auto sum() const { return this->_super->fold(this->_begin, this->_end); }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto& affine(const size_t first, const size_t last, const T& a, const T& b) noexcept(NO_EXCEPT) { this->apply(first, last, { a, b }); return *this; }
    inline auto& affine(const size_t pos, const T& a, const T& b) noexcept(NO_EXCEPT) { this->apply(pos, { a, b }); return *this; }
    inline auto& affine(const T& a, const T& b) noexcept(NO_EXCEPT) { this->apply({ a, b }); return *this; }

    inline auto& set(const size_t first, const size_t last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, { 0, val }); return *this; }
    inline auto& set(const size_t pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, { 0, val }); return *this; }
    inline auto& set(const T& val) noexcept(NO_EXCEPT) { this->apply({ 0, val }); return *this; }

    inline auto& add(const size_type first, const size_type last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, { 1, val }); return *this; }
    inline auto& add(const size_type pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, { 1, val }); return *this; }
    inline auto& add(const T& val) noexcept(NO_EXCEPT) { this->apply({ 1, val }); return *this; }

    inline auto& times(const size_t first, const size_t last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, { val, 0 }); return *this; }
    inline auto& times(const size_t pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, { val, 0 }); return *this; }
    inline auto& times(const T& val) noexcept(NO_EXCEPT) { this->apply({ val, 0 }); return *this; }


    inline auto sum(const size_t first, const size_t last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto sum() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_affine_range_sum.hpp] */
#line 41 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_bitxor.hpp] */
#line 1 "data_structure/range_action/range_bitxor.hpp"











#line 12 "data_structure/range_action/range_bitxor.hpp"



namespace lib {

namespace actions {


template<class T> struct range_bitxor : base<> {
    static constexpr flags tags{ flags::range_folding };

    using operand = algebraic::bitxor<T>;
};

} // namespace actions


template<class T> struct fenwick_tree<actions::range_bitxor<T>> : internal::fenwick_tree_impl::core<actions::range_bitxor<T>,void> {
  private:
    using base = internal::fenwick_tree_impl::core<actions::range_bitxor<T>,void>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& operator^=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline auto bitxor() const noexcept(NO_EXCEPT) { return this->_super->fold(this->_begin, this->_end); }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }
};


} // namespace lib
/* [data_structure/range_action/range_bitxor.hpp] */
#line 42 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_gcd.hpp] */
#line 1 "data_structure/range_action/range_gcd.hpp"











#line 12 "data_structure/range_action/range_gcd.hpp"



namespace lib {

namespace actions {


template<class T> struct range_gcd : base<> {
    static constexpr flags tags{ flags::range_folding };

    using operand = algebraic::gcd<T>;
};


} // namespace actions


template<class T> struct segment_tree<actions::range_gcd<T>> : internal::segment_tree_impl::core<actions::range_gcd<T>,void> {
  private:
    using base = internal::segment_tree_impl::core<actions::range_gcd<T>,void>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline auto gcd() const noexcept(NO_EXCEPT) { return this->_super->fold(this->_begin, this->_end); }
    };

    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto gcd(const size_t first, const size_t last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto gcd() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_gcd.hpp] */
#line 43 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_max.hpp] */
#line 1 "data_structure/range_action/range_max.hpp"














namespace lib {

namespace actions {


template<class T> struct range_max : base<> {
    static constexpr flags tags{ flags::range_folding };

    using operand = algebraic::maximum<T>;
};


} // namespace actions


template<class T> struct segment_tree<actions::range_max<T>> : internal::segment_tree_impl::core<actions::range_max<T>,void> {
  private:
    using base = internal::segment_tree_impl::core<actions::range_max<T>,void>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline auto max() const noexcept(NO_EXCEPT) { return this->_super->fold(this->_begin, this->_end); }
    };

    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto max(const size_t first, const size_t last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto max() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_max.hpp] */
#line 44 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_min.hpp] */
#line 1 "data_structure/range_action/range_min.hpp"














namespace lib {

namespace actions {


template<class T> struct range_min : base<> {
    static constexpr flags tags{ flags::range_folding };

    using operand = algebraic::minimum<T>;
};


} // namespace actions


template<class T> struct segment_tree<actions::range_min<T>> : internal::segment_tree_impl::core<actions::range_min<T>,void> {
  private:
    using base = internal::segment_tree_impl::core<actions::range_min<T>,void>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline auto min() const noexcept(NO_EXCEPT) { return this->_super->fold(this->_begin, this->_end); }
    };

    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto min(const size_t first, const size_t last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto min() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_min.hpp] */
#line 45 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_set_range_max.hpp] */
#line 1 "data_structure/range_action/range_set_range_max.hpp"












#line 13 "data_structure/range_action/range_set_range_max.hpp"


namespace lib {

namespace actions {


template<class T> struct range_set_range_max : base<algebraic::assignment<T>>  {
    static constexpr flags tags{ flags::range_folding, flags::range_operation };

    using operand = algebraic::maximum<T>;
    using operation = algebraic::assignment<T>;

    static operand map(const operand& x, const operation& y) noexcept(NO_EXCEPT) { return y->value_or(x.val()); }
};


} // namespace actions


template<class T> struct lazy_segment_tree<actions::range_set_range_max<T>> : internal::lazy_segment_tree_impl::core<actions::range_set_range_max<T>> {
  private:
    using base = internal::lazy_segment_tree_impl::core<actions::range_set_range_max<T>>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline range_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }
        inline range_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }

        inline auto max() const { return this->_super->fold(this->_begin, this->_end); }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto& set(const size_type first, const size_type last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, val); return *this; }
    inline auto& set(const size_type pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, val); return *this; }
    inline auto& set(const T& val) noexcept(NO_EXCEPT) { this->apply(val); return *this; }

    inline auto max(const size_type first, const size_type last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto max() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_set_range_max.hpp] */
#line 46 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_set_range_min.hpp] */
#line 1 "data_structure/range_action/range_set_range_min.hpp"














namespace lib {

namespace actions {


template<class T> struct range_set_range_min : base<algebraic::assignment<T>> {
    static constexpr flags tags{ flags::range_folding, flags::range_operation };

    using operand = algebraic::minimum<T>;
    using operation = algebraic::assignment<T>;

    static operand map(const operand& x, const operation& y) noexcept(NO_EXCEPT) { return y->value_or(x.val()); }
};


} // namespace actions


template<class T> struct lazy_segment_tree<actions::range_set_range_min<T>> : internal::lazy_segment_tree_impl::core<actions::range_set_range_min<T>> {
  private:
    using base = internal::lazy_segment_tree_impl::core<actions::range_set_range_min<T>>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline range_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }
        inline range_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }

        inline auto min() const { return this->_super->fold(this->_begin, this->_end); }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto& set(const size_type first, const size_type last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, val); return *this; }
    inline auto& set(const size_type pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, val); return *this; }
    inline auto& set(const T& val) noexcept(NO_EXCEPT) { this->apply(val); return *this; }

    inline auto min(const size_type first, const size_type last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto min() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_set_range_min.hpp] */
#line 47 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/range_action/range_set_range_sum.hpp] */
#line 1 "data_structure/range_action/range_set_range_sum.hpp"














namespace lib {

namespace actions {


template<class T> struct range_set_range_sum : base<> {
    static constexpr flags tags{ flags::range_folding, flags::range_operation };

    using operand = algebraic::addition<T>;
    using operation = algebraic::assignment<T>;

    static operand map(const operand& x, const operation& y) noexcept(NO_EXCEPT) { return y->value_or(x.val()); }
    static operation fold(const operation& x, const lib::internal::size_t length) noexcept(NO_EXCEPT) {
        if(x->has_value()) return operation(x->operator*() * length);
        return x;
    }
};


} // namespace actions


template<class T> struct lazy_segment_tree<actions::range_set_range_sum<T>> : internal::lazy_segment_tree_impl::core<actions::range_set_range_sum<T>> {
  private:
    using base = internal::lazy_segment_tree_impl::core<actions::range_set_range_sum<T>>;

  public:
    using base::base;
    using size_type = typename base::size_type;

    struct point_reference : base::point_reference {
        using base::point_reference::point_reference;

        inline point_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
        inline point_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_pos, val); return *this; }
    };

    struct range_reference : base::range_reference {
        using base::range_reference::range_reference;

        inline range_reference& set(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }
        inline range_reference& operator=(const T& val) noexcept(NO_EXCEPT) { this->_super->apply(this->_begin, this->_end, val); return *this; }

        inline auto sum() const { return this->_super->fold(this->_begin, this->_end); }
    };

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto& set(const size_type first, const size_type last, const T& val) noexcept(NO_EXCEPT) { this->apply(first, last, val); return *this; }
    inline auto& set(const size_type pos, const T& val) noexcept(NO_EXCEPT) { this->apply(pos, val); return *this; }
    inline auto& set(const T& val) noexcept(NO_EXCEPT) { this->apply(val); return *this; }

    inline auto sum(const size_type first, const size_type last) noexcept(NO_EXCEPT) { return this->fold(first, last); }
    inline auto sum() noexcept(NO_EXCEPT) { return this->fold(); }
};


} // namespace lib
/* [data_structure/range_action/range_set_range_sum.hpp] */
#line 48 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 49 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [data_structure/bit_vector.hpp] */
#line 1 "data_structure/bit_vector.hpp"














namespace lib {


// Thanks to: https://github.com/NyaanNyaan/library/blob/master/data-structure-2d/wavelet-matrix.hpp
struct bit_vector {
    using size_type = std::uint_fast32_t;

  private:
    static constexpr size_type w = 64;
    std::vector<std::uint64_t> _block;
    std::vector<size_type> _count;
    size_type _n, _zeros;

  public:
    bit_vector(const size_type _n = 0) noexcept(NO_EXCEPT) { this->init(_n); }

    template<class I> explicit bit_vector(const I first, const I last) noexcept(NO_EXCEPT) : bit_vector(std::distance(first, last)) {
        size_type pos = 0;
        for(auto itr=first; itr != last; ++pos, ++itr) if(*itr) this->set(pos);
    }
    template<class T> bit_vector(const std::initializer_list<T>& init_list) noexcept(NO_EXCEPT) : bit_vector(std::begin(init_list), std::end(init_list)) {}

    inline size_type size() const noexcept(NO_EXCEPT) { return this->_n; }

    inline size_type zeros() const noexcept(NO_EXCEPT) { return this->_zeros; }
    inline size_type ones() const noexcept(NO_EXCEPT) { return this->_n - this->_zeros; }

    inline void set(const size_type k) noexcept(NO_EXCEPT) { this->_block[k / w] |= 1LL << (k % w); }
    inline bool get(const size_type k) const noexcept(NO_EXCEPT) { return std::uint32_t(this->_block[k / w] >> (k % w)) & 1U; }

    __attribute__((optimize("O3", "unroll-loops"))) void init(const size_type _n) noexcept(NO_EXCEPT) {
        this->_n = this->_zeros = _n;
        this->_block.resize(_n / w + 1, 0);
        this->_count.resize(this->_block.size(), 0);
    }

    void build() noexcept(NO_EXCEPT) {
        for(auto k = 1UL; k < this->_block.size(); ++k) this->_count[k] = this->_count[k-1] + static_cast<size_type>(lib::popcount(this->_block[k-1]));
        this->_zeros = this->rank0(this->_n);
    }

    inline size_type rank1(const size_type k) const noexcept(NO_EXCEPT) {
        return this->_count[k / w] + static_cast<size_type>(lib::popcount(lib::clear_higher_bits(this->_block[k / w], k % w)));
    }
    inline size_type rank0(size_type k) const noexcept(NO_EXCEPT) { return k - this->rank1(k); }

    inline size_type rank(const bool bit, const size_type k) const noexcept(NO_EXCEPT) {
        return bit ? this->rank1(k) : this->rank0(k);
    }

    inline size_type select(const bool bit, const size_type rank) const noexcept(NO_EXCEPT) {
        if (!bit and rank > this->zeros()) { return this->_n + 1; }
        if (bit and rank > this->ones()) { return this->_n + 1; }

        size_type block_pos = 0;
        {
            size_type ng = -1, ok = static_cast<size_type>(this->_count.size());
            while(ok - ng > 1) {
                size_type mid = (ng + ok) / 2;

                size_type cnt = this->_count[mid];
                if(!bit) cnt = mid * w - cnt;

                (cnt >= rank ? ok : ng) = mid;
            }
            block_pos = ok;
        }

        const size_type base_index = (block_pos - 1) * w;
        const size_type count = this->_count[block_pos - 1];
        const std::uint64_t block = this->_block[block_pos - 1];

        size_type ng = -1, ok = w;
        while(ok - ng > 1) {
            const size_type mid = (ok + ng) / 2;
            size_type r = count + static_cast<size_type>(lib::popcount(lib::clear_higher_bits(block, mid)));
            if(!bit) r = base_index + mid - r;
            (r >= rank ? ok : ng) = mid;
        }

        return base_index + ok;
    }

    inline size_type select0(const size_type k) const noexcept(NO_EXCEPT) { return this->select(0, k); }
    inline size_type select1(const size_type k) const noexcept(NO_EXCEPT) { return this->select(1, k); }


    struct iterator : virtual internal::container_iterator_interface<bool,bit_vector> {
        using internal::container_iterator_interface<bool,bit_vector>::difference_type;

        iterator(const bit_vector *const ref, const size_type pos)
            noexcept(NO_EXCEPT) : internal::container_iterator_interface<bool,bit_vector>(ref, static_cast<difference_type>(pos)) {

            }

        inline bool operator*() const noexcept(NO_EXCEPT) { return this->ref()->get(this->pos()); }
    };

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this, 0); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this, this->size()); }
};


} // namespace lib
/* [data_structure/bit_vector.hpp] */
#line 51 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/disjoint_set_union.hpp] */
#line 1 "data_structure/disjoint_set_union.hpp"










// #include <atcoder/dsu>


namespace lib {

//Thanks to: atcoder::dsu
struct dsu {
    using size_type = internal::size_t;

  private:
    size_type _n, _group_count;
    // root node: -1 * component size
    // otherwise: parent
    mutable std::vector<size_type> _parent_or_size;

  public:
    dsu() noexcept(NO_EXCEPT) : _n(0) {}
    explicit dsu(const size_type n) noexcept(NO_EXCEPT) : _n(n), _group_count(n), _parent_or_size(n, -1) {}

    inline size_type size() const noexcept(NO_EXCEPT) { return this->_n; }
    inline size_type group_count() const noexcept(NO_EXCEPT) { return this->_group_count; }

    inline size_type merge(const size_type a, const size_type b) noexcept(NO_EXCEPT) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        size_type x = this->leader(a), y = this->leader(b);
        if (x == y) return x;
        --this->_group_count;
        if (-this->_parent_or_size[x] < -this->_parent_or_size[y]) std::swap(x, y);
        this->_parent_or_size[x] += this->_parent_or_size[y];
        this->_parent_or_size[y] = x;
        return x;
    }

    inline bool same(const size_type a, const size_type b) const noexcept(NO_EXCEPT) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return this->leader(a) == this->leader(b);
    }

    inline size_type leader(const size_type a) const noexcept(NO_EXCEPT) {
        assert(0 <= a && a < _n);
        if (_parent_or_size[a] < 0) return a;
        return _parent_or_size[a] = this->leader(_parent_or_size[a]);
    }

    inline size_type size(const size_type a) const noexcept(NO_EXCEPT) {
        assert(0 <= a && a < _n);
        return -_parent_or_size[this->leader(a)];
    }

    inline std::vector<std::vector<size_type>> groups() const noexcept(NO_EXCEPT) {
        std::vector<size_type> leader_buf(_n), group_size(_n);
        for (size_type i = 0; i < _n; i++) {
            leader_buf[i] = this->leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<size_type>> result(_n);
        for (size_type i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (size_type i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<size_type>& v) { return v.empty(); }),
            result.end());
        return result;
    }
};


} // namespace lib
/* [data_structure/disjoint_set_union.hpp] */
#line 52 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/disjoint_sparse_table.hpp] */
#line 1 "data_structure/disjoint_sparse_table.hpp"














/* #expanded [algebraic/internal/traits.hpp] */
#line 1 "algebraic/internal/traits.hpp"








namespace lib {

namespace algebraic {

namespace internal {


template<class T> using is_magma = std::is_base_of<magma,T>;
template<class T> inline constexpr auto is_magma_v = is_magma<T>::value;
template<class T> using is_magma_t = std::enable_if_t<is_magma_v<T>>;


template<class T> using is_semigroup = std::is_base_of<semigroup,T>;
template<class T> inline constexpr auto is_semigroup_v = is_semigroup<T>::value;
template<class T> using is_semigroup_t = std::enable_if_t<is_semigroup_v<T>>;

template<class T> using is_monoid = std::is_base_of<monoid,T>;
template<class T> inline constexpr auto is_monoid_v = is_monoid<T>::value;
template<class T> using is_monoid_t = std::enable_if_t<is_monoid_v<T>>;

template<class T> using is_group = std::is_base_of<group,T>;
template<class T> inline constexpr auto is_group_v = is_group<T>::value;
template<class T> using is_group_t = std::enable_if_t<is_group_v<T>>;

template<class T> using is_commutative = std::is_base_of<commutative,T>;
template<class T> inline constexpr auto is_commutative_v = is_commutative<T>::value;
template<class T> using is_commutative_t = std::enable_if_t<is_commutative_v<T>>;

template<class T> using is_invertible = std::is_base_of<invertible,T>;
template<class T> inline constexpr auto is_invertible_v = is_invertible<T>::value;
template<class T> using is_invertible_t = std::enable_if_t<is_invertible_v<T>>;


} // namespace internal

} // namespace algebraic

} // namespace lib
/* [algebraic/internal/traits.hpp] */
#line 16 "data_structure/disjoint_sparse_table.hpp"
/* #expanded [data_structure/internal/is_action.hpp] */
#line 1 "data_structure/internal/is_action.hpp"






namespace lib {

namespace internal {


template<class T> using is_action = std::is_base_of<actions::internal::base,T>;
template<class T> inline constexpr auto is_action_v = is_action<T>::value;
template<class T> using is_action_t = std::enable_if_t<is_action_v<T>>;


} // namespace internal

} // namespace lib
/* [data_structure/internal/is_action.hpp] */
#line 17 "data_structure/disjoint_sparse_table.hpp"



namespace lib {

namespace internal {

namespace disjoint_sparse_table_impl {

// Thanks to: https://noshi91.hatenablog.com/entry/2018/05/08/183946
template<class S>
struct base {
    using size_type = internal::size_t;
    using iterator = std::vector<std::vector<S>>;

  private:
    size_type _n = 0, _depth = 0;
    bool _built = false;

  protected:
    std::vector<std::vector<S>> _table = {};

  public:
    explicit base(const size_type n = 0) noexcept(NO_EXCEPT) : _n(n) {
        this->_depth = bit_width<std::make_unsigned_t<size_type>>(n);
        this->_table.resize(this->_depth+1, std::vector<S>(n));
    }

    template<bool FORCE = false>
    inline auto& build() noexcept(NO_EXCEPT) {
        if(!FORCE and this->_built) return *this;
        for(size_type i=2; i<=this->_depth; ++i) {
            const size_type len = 1 << i;
            for(size_type l = 0, m = len/2; m < this->_n; l += len, m = l + len/2) {
                this->_table[i-1][m - 1] = this->_table.front()[m - 1];
                for(size_type j = m-2; j>=l; --j) {
                    this->_table[i-1][j] = this->_table[i-1][j + 1] + this->_table.front()[j];
                }
                this->_table[i-1][m] = this->_table.front()[m];
                for(size_type j = m+1; j<std::min(l + len, this->_n); ++j) {
                    this->_table[i-1][j] = this->_table[i-1][j - 1] +  this->_table.front()[j];
                }
            }
        }
        this->_built = true;
        return *this;
    }

    inline auto& raw() noexcept(NO_EXCEPT) {
        this->_built = false;
        return this->_table.front();
    }
    inline const auto& raw() const noexcept(NO_EXCEPT) { return this->_table.front(); }
    inline const auto& data() const noexcept(NO_EXCEPT) { return this->_table.front(); }

    size_type size() const noexcept(NO_EXCEPT) { return this->_n; }

    S fold(const size_type l, size_type r) {
        if(l == r) return S{};
        if(l == --r) return this->_table.front()[l];

        this->build();

        const size_type p = highest_bit_pos<std::make_unsigned_t<size_type>>(l ^ r);
        return this->_table[p][l] + this->_table[p][r];
    }
};


template<class, class = std::void_t<>> struct core {};

template<class semigroup>
struct core<semigroup, std::void_t<typename algebraic::internal::is_semigroup_t<semigroup>>> : base<semigroup> {
    using value_type = semigroup;
    using size_type = internal::size_t;

  private:
    using base = internal::disjoint_sparse_table_impl::base<semigroup>;

  protected:
    inline size_type _positivize_index(const size_type p) const noexcept(NO_EXCEPT) {
        return p < 0 ? this->size() + p : p;
    }

  public:
    using base::base;

    explicit core(const size_type n, const semigroup& val) noexcept(NO_EXCEPT) : core(n) {
        this->_table.begin()->assign(n, val);
    }

    template<class I>
    explicit core(const I first, const I last) noexcept(NO_EXCEPT) : core(static_cast<size_type>(std::distance(first, last))) {
        std::copy(first, last, this->_table.begin()->begin());
    }

    struct range_reference : internal::range_reference<core> {
        range_reference(core *const super, const size_type l, const size_type r) noexcept(NO_EXCEPT)
          : internal::range_reference<core>(super, super->_positivize_index(l), super->_positivize_index(r))
        {
            assert(0 <= this->_begin && this->_begin <= this->_end && this->_end <= this->_super->size());
        }

        inline value_type fold() noexcept(NO_EXCEPT) {
            return this->_super->fold(this->_begin, this->_end);
        }
        inline value_type operator*() noexcept(NO_EXCEPT) {
            return this->_super->fold(this->_begin, this->_end);
        }
    };

    inline value_type fold(size_type l, size_type r) noexcept(NO_EXCEPT) {
        l = this->_positivize_index(l), r = this->_positivize_index(r);
        assert(0 <= l && l <= r && r <= this->size());
        return this->base::fold(l, r);
    }
    inline value_type fold() noexcept(NO_EXCEPT) { return this->fold(0, this->size()); }

    inline auto operator[](const size_type index) const noexcept(NO_EXCEPT) { return this->_table.front()[index]; }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline auto begin() const noexcept(NO_EXCEPT) { return this->_table.begin()->begin(); }
    inline auto end() const noexcept(NO_EXCEPT) { return this->_table.begin()->end(); }
};


template<class Action>
struct core<Action, std::void_t<typename internal::is_action_t<Action>>> : core<typename Action::operand> {
    using action = Action;
    using core<typename action::operand>::core;

    static_assert(action::tags.none() or action::tags.has(actions::flags::range_folding));
};


} // namespace disjoint_sparse_table_impl

} // namespace internal


template<class semigroup> struct disjoint_sparse_table : internal::disjoint_sparse_table_impl::core<semigroup> {
    using internal::disjoint_sparse_table_impl::core<semigroup>::core;
};


} // namespace lib
/* [data_structure/disjoint_sparse_table.hpp] */
#line 53 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/fenwick_tree.hpp] */
#line 1 "data_structure/fenwick_tree.hpp"






















namespace lib {

namespace internal {

namespace fenwick_tree_impl {


// Thanks to: atcoder::fenwick_tree
template<class S>
struct base {
    using size_type = internal::size_t;

  private:
    size_type _n = 0, _bit_ceil = 0;
    S *const _data = nullptr;

  protected:
    base() noexcept(NO_EXCEPT) {}

    inline void initialize() noexcept(NO_EXCEPT) {
        FOR(i, 1, this->_n) {
            size_type j = i + (i & -i);
            if(j <= this->_n) this->_data[j-1] = this->_data[j-1] + this->_data[i-1];
        }
    }

    explicit base(const size_type n) noexcept(NO_EXCEPT)
      : _n(n), _bit_ceil(lib::bit_ceil<std::make_unsigned_t<size_type>>(n)), _data(new S[n]())
    {}

    ~base() { delete[] this->_data; }

    inline size_type size() const noexcept(NO_EXCEPT) { return this->_n; }

    inline S* data() noexcept(NO_EXCEPT) { return this->_data; }
    inline const S* data() const noexcept(NO_EXCEPT) { return this->_data; }

    inline void apply(size_type p, const S& x) noexcept(NO_EXCEPT) {
        for(p++; p<=this->_n; p += p & -p) this->_data[p-1] = this->_data[p-1] + x;
    }

    inline void set(const size_type p, const S& x) noexcept(NO_EXCEPT) {
        assert(this->get(p) == this->fold(p, p+1));
        this->apply(p, x + -this->get(p));
    }

    inline S fold(size_type r) const noexcept(NO_EXCEPT) {
        S s = S{};
        for(; r>0; r -= r & -r) s = s + this->_data[r-1];
        return s;
    }
    inline S fold(size_type l, size_type r) const noexcept(NO_EXCEPT) {
        S s = S{};
        for(; l < r; r -= r & -r) s = s + this->_data[r-1];
        for(; r < l; l -= l & -l) s = s + -this->_data[l-1];
        return s;
    }

    inline S get(size_type p) const noexcept(NO_EXCEPT) { return this->fold(p, p+1); }

  public:
    template<class F> inline size_type max_right(size_type l, const F& f) const noexcept(NO_EXCEPT) {
        assert(0 <= l && l <= this->_n);
        assert(f(S{}));
        if(l == this->_n) return this->_n;
        S fold_l_inv = -this->fold(l);
        size_type p = 0, q = this->_bit_ceil;
        for(size_type k=q; k>0; k >>= 1) {
            if(p+k <= this->_n and f(this->_data[p+k-1] + fold_l_inv)) {
                fold_l_inv = fold_l_inv + this->_data[(p+=k)-1];
            }
        }
        return p;
    }

    template<class F> inline size_type min_left(size_type r, const F& f) const noexcept(NO_EXCEPT) {
        assert(0 <= r && r <= this->_n);
        assert(f(S{}));
        if(r == 0) return 0;
        S fold_r = this->fold(r);
        size_type p = 0, q = lib::bit_ceil<std::make_unsigned_t<size_type>>(r);
        for(size_type k=q; k>0; k >>= 1) {
            if(p+k < r and !f(fold_r + -this->_data[p+k-1])) {
                fold_r = fold_r + -this->_data[(p+=k)-1];
            }
        }
        if(p == 0 and f(fold_r)) return 0;
        return p + 1;
    }
};


template<class, class = std::void_t<>> struct core {};

template<class monoid>
struct core<monoid,std::void_t<typename algebraic::internal::is_monoid_t<monoid>>> : base<monoid> {
    static_assert(algebraic::internal::is_commutative_v<monoid>, "commutative property is required");

  private:
    using base = typename fenwick_tree_impl::base<monoid>;

  public:
    using value_type = monoid;
    using size_type = typename base::size_type;

  protected:
    inline size_type _positivize_index(const size_type p) const noexcept(NO_EXCEPT) {
        return p < 0 ? this->size() + p : p;
    }

  public:
    core() noexcept(NO_EXCEPT) : base() {}
    explicit core(const size_type n, const value_type& v = {}) noexcept(NO_EXCEPT) : base(n) { this->fill(v); }
    template<class T> core(const std::initializer_list<T>& init_list) noexcept(NO_EXCEPT) : core(ALL(init_list)) {}

    template<class I, std::void_t<typename std::iterator_traits<I>::value_type>* = nullptr>
    explicit core(const I first, const I last) noexcept(NO_EXCEPT) : core(static_cast<size_type>(std::distance(first, last))) { this->assign(first, last); }


    template<class T>
    inline auto& assign(const std::initializer_list<T>& init_list) noexcept(NO_EXCEPT){ return this->assign(ALL(init_list)); }

    template<class I, std::void_t<typename std::iterator_traits<I>::value_type>* = nullptr>
    inline auto& assign(const I first, const I last) noexcept(NO_EXCEPT) {
        assert(std::distance(first, last) == this->size());
        std::copy(first, last, this->data());
        this->initialize();
        return *this;
    }

    inline auto& fill(const value_type& v = {}) noexcept(NO_EXCEPT) {
        std::fill(this->data(), this->data() + this->size(), v);
        this->initialize();
        return *this;
    }

    inline size_type size() const noexcept(NO_EXCEPT) { return this->base::size(); }
    inline bool empty() const noexcept(NO_EXCEPT) { return this->base::size() == 0; }

    struct point_reference : internal::point_reference<core> {
        point_reference(core *const super, const size_type p) noexcept(NO_EXCEPT)
          : internal::point_reference<core>(super, super->_positivize_index(p))
        {
            assert(0 <= this->_pos && this->_pos < this->_super->size());
        }

        operator value_type() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }
        value_type val() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }

        inline point_reference& set(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }
        inline point_reference& operator=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }

        inline point_reference& apply(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
        inline point_reference& operator<<=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
    };

    struct range_reference : internal::range_reference<core> {
        range_reference(core *const super, const size_type l, const size_type r) noexcept(NO_EXCEPT)
          : internal::range_reference<core>(super, super->_positivize_index(l), super->_positivize_index(r))
        {
            assert(0 <= this->_begin && this->_begin <= this->_end && this->_end <= this->_super->size());
        }

        inline value_type fold() noexcept(NO_EXCEPT) {
            if(this->_begin == 0 and this->_end == this->_super->size()) return this->_super->fold();
            if(this->_begin == 0) return this->_super->fold(this->_end);
            return this->_super->fold(this->_begin, this->_end);
        }
        inline value_type operator*() noexcept(NO_EXCEPT) {
            if(this->_begin == 0 and this->_end == this->_super->size()) return this->_super->fold();
            if(this->_begin == 0) return this->_super->fold(this->_end);
            return this->_super->fold(this->_begin, this->_end);
        }
    };


    inline auto& apply(const size_type p, const value_type& x) noexcept(NO_EXCEPT) {
        assert(0 <= p && p < this->size());
        this->base::apply(p, x);
         return *this;
    }

    inline auto& set(const size_type p, const value_type& x) noexcept(NO_EXCEPT) {
        static_assert(algebraic::internal::is_invertible_v<value_type>, "point setting requires inverse element");
        assert(0 <= p && p < this->size());
        this->base::set(p, x);
         return *this;
    }

    inline value_type get(const size_type p) const noexcept(NO_EXCEPT) {
        static_assert(algebraic::internal::is_invertible_v<value_type>, "point getting requires inverse element");
        assert(0 <= p && p < this->size());
        return this->base::get(p);
    }

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }

    inline const range_reference operator()(const size_type l, const size_type r) const noexcept(NO_EXCEPT) { return range_reference(this, l, r); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline value_type fold(const size_type l, const size_type r) const noexcept(NO_EXCEPT) {
        static_assert(algebraic::internal::is_invertible_v<value_type>, "range folding requires an inverse element");
        assert(0 <= l && l <= r && r <= this->size());
        return this->base::fold(l, r);
    }
    inline value_type fold(const size_type r) const noexcept(NO_EXCEPT) {
        assert(0 <= r && r <= this->size());
        return this->base::fold(r);
    }
    inline value_type fold() const noexcept(NO_EXCEPT) {
        return this->base::fold(this->size());
    }


  protected:
    using iterator_interface = internal::container_iterator_interface<value_type,core>;

  public:
    struct iterator : virtual iterator_interface {
        iterator(const core *const ref, const size_type p) noexcept(NO_EXCEPT) : iterator_interface(ref, p) {}

        inline value_type operator*() const noexcept(NO_EXCEPT) { return this->ref()->get(this->pos()); }
        inline value_type operator[](const typename iterator_interface::difference_type count) const noexcept(NO_EXCEPT) { return *(*this + count); }
    };

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this, 0); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this, this->size()); }
};

template<class Action>
struct core<Action, std::void_t<typename internal::is_action_t<Action>>> : core<typename Action::operand> {
    using action = Action;
    using core<typename action::operand>::core;

    static_assert(action::tags.none() or action::tags.has(actions::flags::range_folding));
};


} // namespace fenwick_tree_impl

} // namespace internal


template<class action> struct fenwick_tree : internal::fenwick_tree_impl::core<action> {
    using internal::fenwick_tree_impl::core<action>::core;
};


} // namespace lib
/* [data_structure/fenwick_tree.hpp] */
#line 54 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/implicit_treap.hpp] */
#line 1 "data_structure/implicit_treap.hpp"







#include <random>





/* #expanded [internal/uncopyable.hpp] */
#line 1 "internal/uncopyable.hpp"






namespace lib {

namespace internal {


struct uncopyable {
    uncopyable() noexcept(NO_EXCEPT) {}
    uncopyable(const uncopyable&) = delete;
    uncopyable& operator=(const uncopyable&) = delete;
};


} // namespace internal

} // namespace lib
/* [internal/uncopyable.hpp] */
#line 15 "data_structure/implicit_treap.hpp"






/* #expanded [random/xorshift.hpp] */
#line 1 "random/xorshift.hpp"









namespace lib {

struct xorshift {
    using result_type = std::uint32_t;

    static constexpr result_type MIN = std::numeric_limits<result_type>::min();
    static constexpr result_type MAX = std::numeric_limits<result_type>::max();

    static constexpr result_type min() noexcept(NO_EXCEPT) { return MIN; }
    static constexpr result_type max() noexcept(NO_EXCEPT) { return MAX; }

    inline void seed(unsigned int seed) noexcept(NO_EXCEPT) { this->w = seed; }

    constexpr xorshift() {};
    constexpr xorshift(const std::uint32_t seed) noexcept(NO_EXCEPT) : w(seed) {};

    inline result_type gen() noexcept(NO_EXCEPT) {
        result_type t;
        t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
    inline result_type operator()() noexcept(NO_EXCEPT) { return this->gen(); }

  private:
    result_type x = 123456789;
    result_type y = 362436069;
    result_type z = 521288629;
    result_type w = 88675123;
};

struct xorshift64 {
    using result_type = std::uint64_t;

    static constexpr result_type MIN = std::numeric_limits<result_type>::min();
    static constexpr result_type MAX = std::numeric_limits<result_type>::max();

    static constexpr result_type min() noexcept(NO_EXCEPT) { return MIN; }
    static constexpr result_type max() noexcept(NO_EXCEPT) { return MAX; }

    inline void seed(unsigned int seed) noexcept(NO_EXCEPT) { this->x = seed; }

    constexpr xorshift64() noexcept(NO_EXCEPT) {};
    constexpr xorshift64(const std::uint64_t seed) noexcept(NO_EXCEPT) : x(seed) {};

    inline result_type gen() noexcept(NO_EXCEPT) {
        x = x ^ (x << 13), x = x ^ (x >> 7), x = x ^ (x << 17);
        return x;
    }
    inline result_type operator()() noexcept(NO_EXCEPT) { return this->gen(); }

  private:
    std::uint64_t x = 3141592653589793238UL;
};

xorshift rand;
xorshift64 rand64;


} // namespace lib
/* [random/xorshift.hpp] */
#line 22 "data_structure/implicit_treap.hpp"




namespace lib {

namespace internal {

namespace implicit_treap_impl {


// Thanks to: https://github.com/xuzijian629/library2/blob/master/treap/implicit_treap.cpp
template<class OperandMonoid, class OperatorMonoid, OperandMonoid (*_map)(const OperandMonoid&, const OperatorMonoid&), OperatorMonoid (*_fold)(const OperatorMonoid&, internal::size_t)>
struct base : private uncopyable {
    using operand = OperandMonoid;
    using operation = OperatorMonoid;

    using size_type = internal::size_t;

  private:
    struct node;
    using Tree = node*;

    static xorshift rand;

    struct node {
        operand v, acc;
        operation lazy;

        xorshift::result_type priority;

        size_type cnt = 1;

        bool rev = false;
        Tree left = nullptr, right = nullptr;

        node(const operand& v, const base* super) noexcept(NO_EXCEPT)
        : v(v), acc(operand{}), lazy(operation{}), priority(super->rand()) {}
        ~node() {
            if(this->left) delete this->left;
            if(this->right) delete this->right;
        }
    };

    Tree root = nullptr;

    inline size_type cnt(const Tree tree) const noexcept(NO_EXCEPT) { return tree ? tree->cnt : 0; }

    inline operand acc(const Tree tree) const noexcept(NO_EXCEPT) { return tree ? tree->acc : operand{}; }

    inline void update_cnt(const Tree tree) const noexcept(NO_EXCEPT) { if(tree) tree->cnt = 1 + this->cnt(tree->left) + this->cnt(tree->right); }

    inline void update_acc(const Tree tree) const noexcept(NO_EXCEPT) {
        if(tree) tree->acc = this->acc(tree->left) + tree->v + this->acc(tree->right);
    }

    inline void pushup(const Tree tree) const noexcept(NO_EXCEPT) { this->update_cnt(tree), update_acc(tree); }

    inline void pushdown(const Tree tree) const noexcept(NO_EXCEPT) {
        if(tree and tree->rev) {
            tree->rev = false;
            std::swap(tree->left, tree->right);
            if(tree->left) tree->left->rev ^= 1;
            if(tree->right) tree->right->rev ^= 1;
        }
        if(tree and tree->lazy != operation{}) {
            if(tree->left) {
                tree->left->lazy = tree->lazy + tree->left->lazy;
                tree->left->acc = _map(tree->left->acc, _fold(tree->lazy, this->cnt(tree->left)));
            }
            if(tree->right) {
                tree->right->lazy = tree->lazy + tree->right->lazy;
                tree->right->acc = _map(tree->right->acc, _fold(tree->lazy, this->cnt(tree->right)));
            }
            tree->v = _map(tree->v, _fold(tree->lazy, 1));
            tree->lazy = operation{};
        }
        // this->pushup(tree);
    }

    inline void split(const Tree tree, const size_type pos, Tree& left, Tree& right) const noexcept(NO_EXCEPT) {
        if(!tree) {
            left = right = nullptr;
            return;
        }
        this->pushdown(tree);
        const size_type implicit_key = this->cnt(tree->left) + 1;
        if(pos < implicit_key) {
            this->split(tree->left, pos, left, tree->left), right = std::move(tree);
            this->pushup(right);
        }
        else {
            this->split(tree->right, pos - implicit_key, tree->right, right), left = std::move(tree);
            this->pushup(left);
        }
    }

    inline void insert(Tree& tree, const size_type pos, const Tree item) const noexcept(NO_EXCEPT) {
        Tree t1, t2;
        this->split(tree, pos, t1, t2);
        this->merge(t1, t1, item);
        this->merge(tree, t1, t2);
    }

    inline void merge(Tree& tree, const Tree left, const Tree right) const noexcept(NO_EXCEPT) {
        this->pushdown(left);
        this->pushdown(right);
        if(!left || !right) {
            tree = left ? left : right;
        }
        else if(left->priority > right->priority) {
            this->merge(left->right, left->right, right), tree = std::move(left);
        }
        else {
            this->merge(right->left, left, right->left), tree = std::move(right);
        }
        this->pushup(tree);
    }

    inline void erase(Tree& tree, const size_type pos) const noexcept(NO_EXCEPT) {
        Tree t1, t2, t3;
        this->split(tree, pos + 1, t1, t2);
        this->split(t1, pos, t1, t3);
        this->merge(tree, t1, t2);
        if(t3) delete t3;
    }

    inline void apply(Tree tree, const size_type l, const size_type r, const operation& v) const noexcept(NO_EXCEPT) {
        if(l >= r) return;
        Tree t1, t2, t3;
        this->split(tree, l, t1, t2);
        this->split(t2, r - l, t2, t3);
        t2->lazy = v + t2->lazy;
        // t2->acc = _map(t2->acc, _fold(v, cnt(t2)));
        this->merge(t2, t2, t3);
        this->merge(tree, t1, t2);
    }

    inline operand fold(Tree tree, const size_type l, const size_type r) const noexcept(NO_EXCEPT) {
        if(l == r) return operand{};
        Tree t1, t2, t3;
        this->split(tree, l, t1, t2);
        this->split(t2, r - l, t2, t3);
        operand ret = t2->acc;
        this->merge(t2, t2, t3);
        this->merge(tree, t1, t2);
        return ret;
    }

    // rank of value v in [l, r)
    inline size_type find(const Tree tree, operand& v, const size_type offset, const bool dir_left = true) const noexcept(NO_EXCEPT) {
        if(tree->acc + v == v) {
            return -1;
        } else {
            if(dir_left) {
                if(tree->left and tree->left->acc + v != v) {
                    return this->find(tree->left, v, offset, dir_left);
                } else {
                    return tree->v + v != v ? offset + this->cnt(tree->left) : this->find(tree->right, v, offset + this->cnt(tree->left) + 1, dir_left);
                }
            } else {
                if(tree->right and tree->right->acc + v != v) {
                    return this->find(tree->right, v, offset + this->cnt(tree->left) + 1, dir_left);
                } else {
                    return tree->v + v != v ? offset + this->cnt(tree->left) : this->find(tree->left, v, offset, dir_left);
                }
            }
        }
    }

    inline void reverse(Tree tree, const size_type l, const size_type r) const noexcept(NO_EXCEPT) {
        if(l >= r) return;
        Tree t1, t2, t3;
        this->split(tree, l, t1, t2);
        this->split(t2, r - l, t2, t3);
        t2->rev ^= 1;
        this->merge(t2, t2, t3);
        this->merge(tree, t1, t2);
    }

    // Same usage as: std::rotate(l, m, r)
    inline void rotate(Tree tree, const size_type l, const size_type m, const size_type r) const noexcept(NO_EXCEPT) {
        this->reverse(tree, l, r);
        this->reverse(tree, l, l + r - m);
        this->reverse(tree, l + r - m, r);
    }

  public:
    inline size_type size() const noexcept(NO_EXCEPT) { return this->cnt(this->root); }

  protected:
    virtual ~base() { delete this->root; }

  public:
    // void insert(const size_type p, const operand& v) { this->insert(this->root, p, std::make_shared<node>(v, this)); }
    void insert(const size_type p, const operand& v) noexcept(NO_EXCEPT) { this->insert(this->root, p, new node(v, this)); }

    inline void apply(const size_type l, const size_type r, const operation& v) noexcept(NO_EXCEPT) { this->apply(this->root, l, r, v); }

    inline operand fold(const size_type l, const size_type r) const noexcept(NO_EXCEPT) { return this->fold(this->root, l, r); }

    inline void erase(const size_type p) noexcept(NO_EXCEPT) { this->erase(this->root, p); }

    inline void reverse(const size_type l, const size_type r) const noexcept(NO_EXCEPT) { this->reverse(this->root, l, r); }

    inline void rotate(const size_type l, const size_type m, const size_type r) const noexcept(NO_EXCEPT) { this->rotate(this->root, l, m, r); }

    // 莠悟・謗｢邏｢縲・l, r)蜀・・k縺ｧf0(tr[k], v) != x縺ｨ縺ｪ繧区怙蟾ｦ/譛蜿ｳ縺ｮ繧ゅ・縲ょｭ伜惠縺励↑縺・ｴ蜷医・-1
    // 縺溘→縺医・MinMonoid縺ｮ蝣ｴ蜷医』譛ｪ貅縺ｮ譛蟾ｦ/譛蜿ｳ縺ｮ隕∫ｴ縺ｮ菴咲ｽｮ繧定ｿ斐☆
    inline size_type find(const size_type l, const size_type r, const operand& v, const bool dir_left) const noexcept(NO_EXCEPT) {
        if(l >= r) return -1;
        Tree t1, t2, t3;
        this->split(this->root, l, t1, t2);
        this->split(t2, r - l, t2, t3);
        const size_type ret = this->find(t2, v, l, dir_left);
        this->merge(t2, t2, t3);
        this->merge(this->root, t1, t2);
        return ret;
    }
};

template<class OperandMonoid, class OperatorMonoid, OperandMonoid (*_map)(const OperandMonoid&, const OperatorMonoid&), OperatorMonoid (*_fold)(const OperatorMonoid&, internal::size_t)>
xorshift base<OperandMonoid,OperatorMonoid,_map,_fold>::rand(std::random_device{}());


template<class Action>
struct core : base<typename Action::operand,typename Action::operation,Action::map,Action::fold> {
    static_assert(
        Action::tags.none() or
        Action::tags.has(actions::flags::range_folding, actions::flags::range_operation)
    );

  public:
    using action = Action;

    using operand = typename action::operand;
    using operation = typename action::operation;

    using value_type = operand;
    using action_type = typename operation::value_type;

  private:
    using base = implicit_treap_impl::base<operand,operation,Action::map,Action::fold>;

  public:
    using size_type = typename base::size_type;

  protected:
    inline size_type _positivize_index(const size_type p) const noexcept(NO_EXCEPT) {
        return p < 0 ? this->size() + p : p;
    }

  public:
    template<class... Args>
    explicit core(Args... args) noexcept(NO_EXCEPT) : core() { this->assign(std::forward<Args>(args)...); }
    template<class T> core(const std::initializer_list<T>& values) noexcept(NO_EXCEPT) : core(std::begin(values), std::end(values)) {}
    core() {}

    template<class I, std::void_t<typename std::iterator_traits<I>::value_type>* = nullptr>
    inline void insert(size_type p, const I first, const I last) noexcept(NO_EXCEPT) {
        for(auto itr=first; itr != last; ++itr, ++p) {
            this->insert(p, *itr);
        }
    }

    bool empty() const noexcept(NO_EXCEPT) { return this->size() == 0; }

    struct point_reference : internal::point_reference<core> {
        point_reference(core *const super, const size_type p) noexcept(NO_EXCEPT)
          : internal::point_reference<core>(super, super->_positivize_index(p))
        {
            assert(0 <= this->_pos && this->_pos < this->_super->size());
        }

        operator value_type() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }
        value_type val() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }

        inline point_reference& set(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }
        inline point_reference& operator=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }

        inline point_reference& apply(const action_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
        inline point_reference& operator<<=(const action_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
    };

    struct range_reference : internal::range_reference<core> {
        range_reference(core *const super, const size_type l, const size_type r) noexcept(NO_EXCEPT)
          : internal::range_reference<core>(super, super->_positivize_index(l), super->_positivize_index(r))
        {
            assert(0 <= this->_begin && this->_begin <= this->_end && this->_end <= this->_super->size());
        }

        inline value_type fold() noexcept(NO_EXCEPT) {
            if(this->_begin == 0 and this->_end == this->_super->size()) return this->_super->fold();
            return this->_super->fold(this->_begin, this->_end);
        }

        inline range_reference& fill(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->fill(this->_begin, this->_end, v);
            return *this;
        }

        inline range_reference& apply(const action_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_begin, this->_end, v);
            return *this;
        }
        inline range_reference& operator<<=(const action_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_begin, this->_end, v);
            return *this;
        }

        inline size_type find(const value_type& v, const bool dir_left = true) const noexcept(NO_EXCEPT) {
            return this->_super->base::find(this->_begin, this->_end, v, dir_left);
        }
    };


    inline void insert(size_type p, const value_type& v) noexcept(NO_EXCEPT) {
        p = this->_positivize_index(p), assert(0 <= p && p <= this->size());
        this->base::insert(p, v);
    }

    inline void insert(const size_type p, const value_type& v, const size_type count) noexcept(NO_EXCEPT) {
        REP(k, count) this->insert(p + k, v);
    }

    inline void push_front(const value_type& v, const size_type count = 1) noexcept(NO_EXCEPT) { this->insert(0, v, count); }
    inline void push_back(const value_type& v, const size_type count = 1) noexcept(NO_EXCEPT) { this->insert(this->size(), v, count); }

    inline void resize(const size_type size, const value_type& v = value_type{}) noexcept(NO_EXCEPT) {
        REP(this->size() - size) this->erase(-1);
        REP(i, this->size(), size) this->push_back(v);
    }

    inline void assign(const size_type size, const value_type& v = value_type{}) noexcept(NO_EXCEPT) {
        this->clear(), this->insert(0, v, size);
    }

    template<class T> inline void assign(const std::initializer_list<T>& values) noexcept(NO_EXCEPT) { this->assign(std::begin(values), std::end(values)); }

    template<class I, std::void_t<typename std::iterator_traits<I>::value_type>* = nullptr>
    inline void assign(const I first, const I last) noexcept(NO_EXCEPT) { this->clear(), this->insert(0, first, last); }

    inline void fill(const value_type& v) noexcept(NO_EXCEPT) {
        const size_type count = this->size();
        this->clear(), this->insert(0, v, count);
    }
    inline void fill(const size_type l, const size_type r, const value_type& v) noexcept(NO_EXCEPT) {
        REP(p, l, r) this->erase(p), this->insert(p, v);
    }

    inline void erase(size_type p) noexcept(NO_EXCEPT) {
        p = this->_positivize_index(p), assert(0 <= p && p < this->size());
        this->base::erase(p);
    }
    inline void erase(const size_type p, const size_type count) noexcept(NO_EXCEPT) { REP(count) this->erase(p); }
    inline void clear() noexcept(NO_EXCEPT) { this->erase(0, this->size()); }

    inline void pop_front(const size_type count = 1) noexcept(NO_EXCEPT) { this->erase(0, count); }
    inline void pop_back(const size_type count = 1) noexcept(NO_EXCEPT) { this->erase(this->size() - count, count); }


    inline void apply(size_type l, size_type r, const action_type& v) noexcept(NO_EXCEPT) {
        l = this->_positivize_index(l), r = this->_positivize_index(r);
        assert(0 <= l && l <= r && r <= this->size());
        this->base::apply(l, r, v);
    }
    inline void apply(const size_type p, const action_type& v) noexcept(NO_EXCEPT) { this->apply(p, p+1, v); }
    inline void apply(const action_type& v) noexcept(NO_EXCEPT) { this->apply(0, this->size(), v); }


    inline value_type get(size_type p) const noexcept(NO_EXCEPT) {
        p = this->_positivize_index(p), assert(0 <= p && p < this->size());
        return this->base::fold(p, p+1).val();
    }

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline value_type front() const noexcept(NO_EXCEPT) { return this->get(0); }
    inline value_type back() const noexcept(NO_EXCEPT) { return this->get(this->size()-1); }

    inline value_type fold(size_type l, size_type r) const noexcept(NO_EXCEPT) {
        l = this->_positivize_index(l), r = this->_positivize_index(r);
        assert(0 <= l && l <= r && r <= this->size());
        return this->base::fold(l, r).val();
    }
    inline value_type fold() const noexcept(NO_EXCEPT) { return this->fold(0, this->size()); }

    inline void reverse(size_type l, size_type r) const noexcept(NO_EXCEPT) {
        l = this->_positivize_index(l), r = this->_positivize_index(r);
        assert(0 <= l && l <= r && r <= this->size());
        this->base::reverse(l, r);
    }
    inline void reverse() const noexcept(NO_EXCEPT) { this->reverse(0, this->size()); }

    inline void rotate(size_type l, size_type m, size_type r) const noexcept(NO_EXCEPT) {
        l = this->_positivize_index(l), m = this->_positivize_index(m), r = this->_positivize_index(r);
        assert(0 <= l && l <= m && m < r && r <= this->size());
        this->base::rotate(l, m, r);
    }
    inline void rotate(const size_type m) const noexcept(NO_EXCEPT) { this->rotate(0, m, this->size()); }

    inline size_type find(size_type l, size_type r, const value_type& v, const bool dir_left = true) const noexcept(NO_EXCEPT) {
        l = this->_positivize_index(l), r = this->_positivize_index(r);
        assert(0 <= l && l <= r && r <= this->size());
        return this->base::find(l, r, v, dir_left);
    }
    inline size_type find(const value_type& v, const bool dir_left = true) const noexcept(NO_EXCEPT) {
        return this->find(0, this->size(), v, dir_left);
    }

  protected:
    using iterator_interface = internal::container_iterator_interface<value_type,core>;

  public:
    struct iterator : virtual iterator_interface {
        iterator(const core *const ref, const size_type p) noexcept(NO_EXCEPT) : iterator_interface(ref, p) {}

        inline value_type operator*() const noexcept(NO_EXCEPT) { return this->ref()->get(this->pos()); }
        inline value_type operator[](const typename iterator_interface::difference_type count) const noexcept(NO_EXCEPT) { return *(*this + count); }
    };

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this, 0); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this, this->size()); }
};


} // namespace implicit_treap_impl

} // namespace internal


template<class action> struct implicit_treap : internal::implicit_treap_impl::core<action> {
    using internal::implicit_treap_impl::core<action>::core;
};


} // namespace lib
/* [data_structure/implicit_treap.hpp] */
#line 55 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/kth_element.hpp] */
#line 1 "data_structure/kth_element.hpp"




#include <queue>




namespace lib {


template<class T, class container = std::vector<T>, class comparer = std::less<T>, class rev_comparer = std::greater<T>>
struct kth_element {
  protected:
    internal::size_t _k;
    std::priority_queue<T,container,comparer> small;
    std::priority_queue<T,container,rev_comparer> large;

  public:
    kth_element(internal::size_t k = 0) noexcept(NO_EXCEPT) : _k(k) {}

    inline T get() const noexcept(NO_EXCEPT) { return small.top(); }
    inline bool has() const noexcept(NO_EXCEPT) { return small.size() == _k; }

    inline void push(T v) noexcept(NO_EXCEPT) {
        if(small.size() < _k) {
            small.push(v);
            return;
        }
        T kth = small.top();
        if(v < kth) {
            small.pop(); small.push(v);
            large.push(kth);
        }
        else {
            large.push(v);
        }
    }

    inline void pop() noexcept(NO_EXCEPT) {
        small.pop();
        if(large.empty()) return;
        T v = large.top(); large.pop();
        small.push(v);
    }
};


} // namespace lib
/* [data_structure/kth_element.hpp] */
#line 56 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/lazy_segment_tree.hpp] */
#line 1 "data_structure/lazy_segment_tree.hpp"






















namespace lib {

namespace internal {

namespace lazy_segment_tree_impl {

// Thanks to: atcoder::lazy_segtree
template<class S, class F, S (*_map)(const S&, const F&), F (*_fold)(const F&, const internal::size_t)>
struct base {
    using size_type = internal::size_t;

  public:
    size_type _n = 0, _size = 0, _depth = 0;
    mutable size_type* _lengths = nullptr;
    mutable S* _values = nullptr;
    mutable F* _lazy = nullptr;

    inline void update(const size_type p) noexcept(NO_EXCEPT) {
        this->_values[p] = this->_values[p << 1] + this->_values[p << 1 | 1];
    }
    inline void all_apply(const size_type p, const F& f) const noexcept(NO_EXCEPT) {
        this->_values[p] = _map(this->_values[p], _fold(f, this->_lengths[p]));
        if(p < this->_size) this->_lazy[p] = f + this->_lazy[p];
    }
    inline void push(const size_type p) const noexcept(NO_EXCEPT) {
        this->all_apply(p << 1, this->_lazy[p]);
        this->all_apply(p << 1 | 1, this->_lazy[p]);
        this->_lazy[p] = {};
    }

  protected:
    base() noexcept(NO_EXCEPT) {}

    explicit base(const size_type n) noexcept(NO_EXCEPT) : _n(n), _depth(bit_width<std::make_unsigned_t<size_type>>(n - 1)) {
        this->_size = 1 << this->_depth;
        this->_lengths = new size_type[2*this->_size]();
        this->_values = new S[2*this->_size]();
        this->_lazy = new F[this->_size]();
    }
    ~base() {
        delete[] this->_lengths;
        delete[] this->_values;
        delete[] this->_lazy;
    }

    inline void initialize() noexcept(NO_EXCEPT) {
        REPD(p, 1, this->_size) {
            this->_lengths[p] = this->_lengths[p << 1] + this->_lengths[p << 1 | 1];
            this->update(p);
        }
    }

  public:
    inline size_type size() const noexcept(NO_EXCEPT) { return this->_n; }
    inline size_type allocated() const noexcept(NO_EXCEPT) { return this->_size; }
    inline size_type depth() const noexcept(NO_EXCEPT) { return this->_depth; }

    inline void set(size_type p, const S& x) noexcept(NO_EXCEPT) {
        p += this->_size;
        FORD(i, 1, this->_depth) this->push(p >> i);
        this->_values[p] = x;
        FOR(i, 1, this->_depth) this->update(p >> i);
    }

    inline S get(size_type p) const noexcept(NO_EXCEPT) {
        p += this->_size;
        FORD(i, 1, this->_depth) this->push(p >> i);
        return this->_values[p];
    }

    inline S fold(size_type l, size_type r) const noexcept(NO_EXCEPT) {
        if(l == r) return {};

        l += this->_size;
        r += this->_size;

        FORD(i, 1, this->_depth) {
            if(((l >> i) << i) != l) this->push(l >> i);
            if(((r >> i) << i) != r) this->push((r - 1) >> i);
        }

        S sml = S{}, smr = S{};
        while(l < r) {
            if(l & 1) sml = sml + this->_values[l++];
            if(r & 1) smr = this->_values[--r] + smr;
            l >>= 1;
            r >>= 1;
        }

        return sml + smr;
    }

    inline S fold_all() const noexcept(NO_EXCEPT) { return this->_values[1]; }

    inline void apply(size_type p, const F& f) noexcept(NO_EXCEPT) {
        p += this->_size;
        FORD(i, 1, this->_depth) this->push(p >> i);
        this->_values[p] = _map(this->_values[p], _fold(f, this->_lengths[p]));
        FOR(i, 1, this->_depth) this->update(p >> i);
    }
    inline void apply(size_type l, size_type r, const F& f) noexcept(NO_EXCEPT) {
        if(l == r) return;

        l += this->_size;
        r += this->_size;

        FORD(i, 1, this->_depth) {
            if(((l >> i) << i) != l) this->push(l >> i);
            if(((r >> i) << i) != r) this->push((r - 1) >> i);
        }

        {
            size_type l2 = l, r2 = r;
            while(l < r) {
                if(l & 1) this->all_apply(l++, f);
                if(r & 1) this->all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        FOR(i, 1, this->_depth) {
            if(((l >> i) << i) != l) this->update(l >> i);
            if(((r >> i) << i) != r) this->update((r - 1) >> i);
        }
    }

    template<bool (*g)(S)> inline size_type max_right(size_type l) const noexcept(NO_EXCEPT) {
        return this->max_right(l, [](S x) { return g(x); });
    }
    template<class G> inline size_type max_right(size_type l, G g) const noexcept(NO_EXCEPT) {
        assert(0 <= l && l <= _n);
        assert(g({}));
        if(l == _n) return _n;
        l += this->_size;
        FORD(i, 1, this->_depth) this->push(l >> i);
        S sm = S{};
        do {
            while(l % 2 == 0) l >>= 1;
            if(!g(sm + this->_values[l])) {
                while(l < this->_size) {
                    this->push(l);
                    l = (2 * l);
                    if(g(sm + this->_values[l])) {
                        sm = sm + this->_values[l];
                        l++;
                    }
                }
                return l - this->_size;
            }
            sm = sm + this->_values[l];
            l++;
        } while((l & -l) != l);
        return _n;
    }

    template<bool (*g)(S)> inline size_type min_left(size_type r) const noexcept(NO_EXCEPT) {
        return min_left(r, [](S x) { return g(x); });
    }
    template<class G> inline size_type min_left(size_type r, G g) const noexcept(NO_EXCEPT) {
        assert(0 <= r && r <= _n);
        assert(g({}));
        if(r == 0) return 0;
        r += this->_size;
        FORD(i, 1, this->_depth) this->push((r - 1) >> i);
        S sm = S{};
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!g(this->_values[r] + sm)) {
                while(r < this->_size) {
                    this->push(r);
                    r = (2 * r + 1);
                    if(g(this->_values[r] + sm)) {
                        sm = this->_values[r] + sm;
                        r--;
                    }
                }
                return r + 1 - this->_size;
            }
            sm = this->_values[r] + sm;
        } while((r & -r) != r);
        return 0;
    }
};


template<class Action>
struct core : base<typename Action::operand, typename Action::operation, Action::map, Action::fold> {
    static_assert(
        Action::tags.none() or
        Action::tags.has(actions::flags::range_folding, actions::flags::range_operation)
    );

  public:
    using action = Action;

    using operand = typename action::operand;
    using operation = typename action::operation;

  private:
    using base = lazy_segment_tree_impl::base<operand, operation, action::map, action::fold>;

  public:
    using value_type = operand;
    using action_type = typename operation::value_type;

    using size_type = typename base::size_type;

  protected:
    inline size_type _positivize_index(const size_type p) const noexcept(NO_EXCEPT) {
        return p < 0 ? this->size() + p : p;
    }

  public:
    core() : base() {}
    explicit core(const size_type n, const value_type& v = {}) noexcept(NO_EXCEPT) : base(n) { this->fill(v); }

    template<class T> core(const std::initializer_list<T>& init_list) noexcept(NO_EXCEPT) : core(ALL(init_list)) {}

    template<class I, std::void_t<typename std::iterator_traits<I>::value_type>* = nullptr>
    explicit core(const I first, const I last) noexcept(NO_EXCEPT) : base(static_cast<size_type>(std::distance(first, last))) { this->assign(first, last); }

    template<class T>
    inline auto& assign(const std::initializer_list<T>& init_list) noexcept(NO_EXCEPT) { return this->assign(ALL(init_list)); }

    template<class I, std::void_t<typename std::iterator_traits<I>::value_type>* = nullptr>
    inline auto& assign(const I first, const I last) noexcept(NO_EXCEPT) {
        assert(std::distance(first, last) == this->_n);
        size_type p = 0;
        for(auto itr=first; itr!=last; ++itr, ++p) {
            this->_lengths[this->_size + p] = 1, this->_values[this->_size + p] = value_type(*itr);
        }
        this->initialize();
        return *this;
    }

    inline auto& fill( const value_type& v = {}) noexcept(NO_EXCEPT) {
        REP(p, 0, this->_n) {
            this->_lengths[this->_size + p] = 1, this->_values[this->_size + p] = v;
        }
        this->initialize();
        return *this;
    }

    bool empty() const noexcept(NO_EXCEPT) { return this->size() == 0; }

    struct point_reference : internal::point_reference<core> {
        point_reference(core *const super, const size_type p) noexcept(NO_EXCEPT)
          : internal::point_reference<core>(super, super->_positivize_index(p))
        {
            assert(0 <= this->_pos && this->_pos < this->_super->size());
        }

        operator value_type() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }
        value_type val() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }

        inline point_reference& set(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }
        inline point_reference& operator=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }

        inline point_reference& apply(const action_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
        inline point_reference& operator<<=(const action_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
    };

    struct range_reference : internal::range_reference<core> {
        range_reference(core *const super, const size_type l, const size_type r) noexcept(NO_EXCEPT)
          : internal::range_reference<core>(super, super->_positivize_index(l), super->_positivize_index(r))
        {
            assert(0 <= this->_begin && this->_begin <= this->_end && this->_end <= this->_super->size());
        }

        inline range_reference& apply(const action_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_begin, this->_end, v);
            return *this;
        }
        inline range_reference& operator<<=(const action_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_begin, this->_end, v);
            return *this;
        }

        inline value_type fold() noexcept(NO_EXCEPT) {
            if(this->_begin == 0 and this->_end == this->_super->size()) return this->_super->fold();
            return this->_super->fold(this->_begin, this->_end);
        }
        inline value_type operator*() noexcept(NO_EXCEPT) {
            if(this->_begin == 0 and this->_end == this->_super->size()) return this->_super->fold();
            return this->_super->fold(this->_begin, this->_end);
        }
    };


    inline auto& set(size_type p, const value_type& v) noexcept(NO_EXCEPT) {
        p = this->_positivize_index(p), assert(0 <= p && p < this->size());
        this->base::set(p, v);
         return *this;
    }

    inline auto& apply(size_type l, size_type r, const action_type& v) noexcept(NO_EXCEPT) {
        l = this->_positivize_index(l), r = this->_positivize_index(r);
        assert(0 <= l && l <= r && r <= this->size());
        this->base::apply(l, r, v);
        return *this;
    }
    inline auto& apply(const size_type p, const action_type& v) noexcept(NO_EXCEPT) { this->apply(p, p+1, v); return *this; }
    inline auto& apply(const action_type& v) noexcept(NO_EXCEPT) { this->apply(0, this->size(), v);  return *this; }


    inline value_type get(size_type p) const noexcept(NO_EXCEPT) {
        p = this->_positivize_index(p), assert(0 <= p && p < this->size());
        return this->base::get(p).val();
    }

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline value_type fold(size_type l, size_type r) const noexcept(NO_EXCEPT) {
        l = this->_positivize_index(l), r = this->_positivize_index(r);
        assert(0 <= l && l <= r && r <= this->size());
        return this->base::fold(l, r).val();
    }
    inline value_type fold() const noexcept(NO_EXCEPT) { return this->fold_all(); }


  protected:
    using iterator_interface = internal::container_iterator_interface<value_type,core>;

  public:
    struct iterator : virtual iterator_interface {
        iterator(const core *const ref, const size_type p) noexcept(NO_EXCEPT) : iterator_interface(ref, p) {}

        inline value_type operator*() const noexcept(NO_EXCEPT) { return this->ref()->get(this->pos()); }
    };

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this, 0); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this, this->size()); }
};


} // namespace lazy_segment_tree_impl

} // namespace internal


template<class action> struct lazy_segment_tree : internal::lazy_segment_tree_impl::core<action> {
    using internal::lazy_segment_tree_impl::core<action>::core;
};


} // namespace lib
/* [data_structure/lazy_segment_tree.hpp] */
#line 57 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/restorable_stack.hpp] */
#line 1 "data_structure/restorable_stack.hpp"




#include <memory>




namespace lib {

template<class T, class ID = int, template<class,class> class storage = std::unordered_map>
struct restorable_stack {
  protected:
    struct node;
    using node_ptr = std::shared_ptr<node>;

    struct node {
        std::map<int,int> a;
        std::optional<T> val = std::nullopt;
        node_ptr parent;
    };

    node_ptr _current;
    storage<ID,node_ptr> _storage;

  public:
    restorable_stack() noexcept(NO_EXCEPT) { this->clear(); };

    inline bool empty() const noexcept(NO_EXCEPT) {
        return !this->_current->val.has_value();
    }
    inline bool stored(ID x) const noexcept(NO_EXCEPT) {
        return this->_storage.count(x);
    }

    inline T top() const noexcept(NO_EXCEPT) {
        return this->_current->val.value();
    }

    template<class U>
    inline auto top_or(const U &&v) const noexcept(NO_EXCEPT) {
        return this->_current->val.value_or(v);
    }

    inline void push(const T x) noexcept(NO_EXCEPT) {
        this->_current.reset(new node{ x, this->_current });
    }
    inline void pop() noexcept(NO_EXCEPT) {
        this->_current = this->_current->parent;
    }
    inline void save(const ID x) noexcept(NO_EXCEPT) {
        this->_storage[x] = this->_current;
    }
    inline void load(const ID x) noexcept(NO_EXCEPT) {
        this->_current = this->_storage[x];
    }
    inline void clear() noexcept(NO_EXCEPT) {
        this->_current.reset(new node{});
    }
};

} // namespace lib
/* [data_structure/restorable_stack.hpp] */
#line 58 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [data_structure/segment_tree.hpp] */
#line 1 "data_structure/segment_tree.hpp"
























namespace lib {

namespace internal {

namespace segment_tree_impl {


// Thanks to: atcoder::segtree
template<class S> struct base : private lib::internal::uncopyable {
    using size_type = internal::size_t;

  protected:
    size_type _n = 0, _size = 0, _depth = 0;
    S* _data = nullptr;

    inline void update(const size_type k) noexcept(NO_EXCEPT) { this->_data[k] = this->_data[k << 1] + this->_data[k << 1 | 1]; }

  protected:
    base() noexcept(NO_EXCEPT) {}
    explicit base(const size_type n) noexcept(NO_EXCEPT) : _n(n), _depth(bit_width<std::make_unsigned_t<size_type>>(n - 1)) {
        this->_size = 1 << this->_depth;
        this->_data = new S[this->_size << 1]();
    }
    ~base() { delete[] this->_data; }

  public:
    inline size_type size() const noexcept(NO_EXCEPT) { return this->_n; }
    inline size_type allocated() const noexcept(NO_EXCEPT) { return this->_size; }
    inline size_type depth() const noexcept(NO_EXCEPT) { return this->_depth; }

  protected:
    inline void apply(size_type p, const S& x) noexcept(NO_EXCEPT) {
        this->set(p, this->_data[p + this->_size] + x);
    }

    inline void set(size_type p, const S& x) noexcept(NO_EXCEPT) {
        p += this->_size;
        this->_data[p] = x;
        FOR(i, 1, this->_depth) this->update(p >> i);
    }

    inline S get(size_type p) const noexcept(NO_EXCEPT) {
        return this->_data[p + this->_size];
    }

    inline S fold(size_type l, size_type r) const noexcept(NO_EXCEPT) {
        S sml, smr;
        l += this->_size;
        r += this->_size;

        while(l < r) {
            if(l & 1) sml = sml + this->_data[l++];
            if(r & 1) smr = this->_data[--r] + smr;
            l >>= 1;
            r >>= 1;
        }
        return sml + smr;
    }

    inline S fold_all() const noexcept(NO_EXCEPT) { return this->_data[1]; }

  public:
    template<bool (*f)(S)> inline size_type max_right(const size_type l) const noexcept(NO_EXCEPT) {
        return this->max_right(l, [](S x) { return f(x); });
    }
    template<class F> inline size_type max_right(size_type l, const F& f) const noexcept(NO_EXCEPT) {
        assert(0 <= l && l <= this->_n);
        assert(f(S{}));
        if(l == this->_n) return this->_n;
        l += this->_size;
        S sm;
        do {
            while(l%2 == 0) l >>= 1;
            if(!f(sm + this->_data[l])) {
                while(l < this->_size) {
                    l <<= 1;
                    if(f(sm + this->_data[l])) {
                        sm = sm + this->_data[l];
                        ++l;
                    }
                }
                return l - this->_size;
            }
            sm = sm + this->_data[l];
            ++l;
        } while((l & -l) != l);
        return this->_n;
    }

    template<bool (*f)(S)> inline size_type min_left(const size_type r) const noexcept(NO_EXCEPT) {
        return this->min_left(r, [](S x) { return f(x); });
    }
    template<class F> inline size_type min_left(size_type r, const F& f) const noexcept(NO_EXCEPT) {
        assert(0 <= r && r <= this->_n);
        assert(f(S()));
        if (r == 0) return 0;
        r += this->_size;
        S sm;
        do {
            --r;
            while(r > 1 and (r%2)) r >>= 1;
            if(!f(this->_data[r] + sm)) {
                while(r < this->_size) {
                    r = (r << 1 | 1);
                    if(f(this->_data[r] + sm)) {
                        sm = this->_data[r] + sm;
                        --r;
                    }
                }
                return r + 1 - this->_size;
            }
            sm = this->_data[r] + sm;
        } while((r & -r) != r);
        return 0;
    }
};


template<class, class = std::void_t<>> struct core {};

template<class monoid>
struct core<monoid, std::void_t<typename algebraic::internal::is_monoid_t<monoid>>> : base<monoid> {
  private:
    using base = typename segment_tree_impl::base<monoid>;

  public:
    using value_type = monoid;
    using size_type = typename base::size_type;

  protected:
    inline size_type _positivize_index(const size_type p) const noexcept(NO_EXCEPT) {
        return p < 0 ? this->size() + p : p;
    }

  public:
    core() : base() {}
    explicit core(const size_type n, const value_type& v = {}) noexcept(NO_EXCEPT) : base(n) { this->fill(v); }

    template<class T>
    core(const std::initializer_list<T>& init_list) noexcept(NO_EXCEPT) : core(ALL(init_list)) {}

    template<class I, std::void_t<typename std::iterator_traits<I>::value_type>* = nullptr>
    explicit core(const I first, const I last) noexcept(NO_EXCEPT) : core(static_cast<size_type>(std::distance(first, last))) { this->assign(first, last); }

    template<class T>
    inline auto& assign(const std::initializer_list<T>& init_list) noexcept(NO_EXCEPT) { return this->assign(ALL(init_list)); }

    template<class I, std::void_t<typename std::iterator_traits<I>::value_type>* = nullptr>
    inline auto& assign(const I first, const I last) noexcept(NO_EXCEPT) {
        assert(std::distance(first, last) == this->size());
        size_type p = 0;
        for(auto itr=first; itr!=last; ++itr, ++p) this->_data[this->_size + p] = value_type(*itr);
        REPD(p, 1, this->_size) this->update(p);
        return *this;
    }

    inline auto& fill(const value_type& v = {}) noexcept(NO_EXCEPT) {
        REP(p, this->_n) this->_data[this->_size + p] = v;
        REPD(p, 1, this->_size) this->update(p);
        return *this;
    }

    bool empty() const noexcept(NO_EXCEPT) { return this->size() == 0; }

    struct point_reference : internal::point_reference<core> {
        point_reference(core *const super, const size_type p) noexcept(NO_EXCEPT)
          : internal::point_reference<core>(super, super->_positivize_index(p))
        {
            assert(0 <= this->_pos && this->_pos < this->_super->size());
        }

        operator value_type() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }
        value_type val() const noexcept(NO_EXCEPT) { return this->_super->get(this->_pos); }

        inline point_reference& set(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }
        inline point_reference& operator=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->set(this->_pos, v);
            return *this;
        }

        inline point_reference& apply(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
        inline point_reference& operator<<=(const value_type& v) noexcept(NO_EXCEPT) {
            this->_super->apply(this->_pos, v);
            return *this;
        }
    };

    struct range_reference : internal::range_reference<core> {
        range_reference(core *const super, const size_type l, const size_type r) noexcept(NO_EXCEPT)
          : internal::range_reference<core>(super, super->_positivize_index(l), super->_positivize_index(r))
        {
            assert(0 <= this->_begin && this->_begin <= this->_end && this->_end <= this->_super->size());
        }

        inline value_type fold() noexcept(NO_EXCEPT) {
            if(this->_begin == 0 and this->_end == this->_super->size()) return this->_super->fold();
            return this->_super->fold(this->_begin, this->_end);
        }
        inline value_type operator*() noexcept(NO_EXCEPT) {
            return this->_super->fold(this->_begin, this->_end);
        }
    };


    inline auto& apply(const size_type p, const value_type& x) noexcept(NO_EXCEPT) {
        assert(0 <= p && p < this->size());
        this->base::apply(p, x);
         return *this;
    }

    inline auto& set(const size_type p, const value_type& x) noexcept(NO_EXCEPT) {
        assert(0 <= p && p < this->size());
        this->base::set(p, x);
         return *this;
    }

    inline value_type get(const size_type p) const noexcept(NO_EXCEPT) {
        assert(0 <= p && p < this->size());
        return this->base::fold(p, p+1);
    }

    inline point_reference operator[](const size_type p) noexcept(NO_EXCEPT) { return point_reference(this, p); }
    inline range_reference operator()(const size_type l, const size_type r) noexcept(NO_EXCEPT) { return range_reference(this, l, r); }

    inline value_type fold(const size_type l, const size_type r) const noexcept(NO_EXCEPT) {
        assert(0 <= l && l <= r && r <= this->size());
        return this->base::fold(l, r);
    }
    inline value_type fold(const size_type r) const noexcept(NO_EXCEPT) {
        assert(0 <= r && r <= this->size());
        return this->base::fold(0, r);
    }
    inline value_type fold() const noexcept(NO_EXCEPT) {
        return this->base::fold_all();
    }


    struct iterator : virtual internal::container_iterator_interface<value_type,core> {
        iterator(const core *const ref, const size_type p) noexcept(NO_EXCEPT) : internal::container_iterator_interface<value_type,core>(ref, p) {}

        inline value_type operator*() const noexcept(NO_EXCEPT) { return this->ref()->get(this->pos()); }
    };

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this, 0); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this, this->size()); }
};

template<class Action>
struct core<Action, std::void_t<typename internal::is_action_t<Action>>> : core<typename Action::operand> {
    using action = Action;
    using core<typename action::operand>::core;

    static_assert(Action::tags.none() or Action::tags.has(actions::flags::range_folding));
};


} // namespace segment_tree_impl

} // namespace internal


template<class monoid> struct segment_tree : internal::segment_tree_impl::core<monoid> {
    using internal::segment_tree_impl::core<monoid>::core;
};


} // namespace lib
/* [data_structure/segment_tree.hpp] */
#line 59 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [graph/centroid_decomposition.hpp] */
#line 1 "graph/centroid_decomposition.hpp"







/* #expanded [graph.hpp] */
#line 1 "graph.hpp"
















/* #expanded [grid.hpp] */
#line 1 "grid.hpp"
























namespace lib {

namespace internal {

namespace grid_impl {

template<class T>
struct interface {
    // virtual void assign(const size_t, const size_t, const T&) noexcept(NO_EXCEPT) = 0;

    // virtual void resize(const size_t, const size_t) noexcept(NO_EXCEPT) = 0;

    // virtual size_t height() const noexcept(NO_EXCEPT) = 0;
    // virtual size_t width() const noexcept(NO_EXCEPT) = 0;

    // virtual size_t id(const size_t, const size_t) const noexcept(NO_EXCEPT) = 0;

    // virtual T& operator()(const size_t, const size_t) noexcept(NO_EXCEPT) = 0;
    // virtual const T& operator()(const size_t, const size_t) const noexcept(NO_EXCEPT) = 0;
};

template<class T> struct container_base : virtual interface<T> {
  private:
    size_t _h, _w;

  protected:
    inline void _validate_index(__attribute__ ((unused)) const size_t i, __attribute__ ((unused)) const size_t j) const noexcept(NO_EXCEPT) {
        assert(0 <= i and i < this->height());
        assert(0 <= j and j < this->width());
    }

    inline size_t _positivize_row_index(const size_t x) const noexcept(NO_EXCEPT) {
        return x < 0 ? this->height() + x : x;
    }
    inline size_t _positivize_col_index(const size_t x) const noexcept(NO_EXCEPT) {
        return x < 0 ? this->width() + x : x;
    }

  public:
    container_base() noexcept(NO_EXCEPT) = default;
    container_base(const size_t h, const size_t w) noexcept(NO_EXCEPT) : _h(h), _w(w) {}

    virtual void resize(const size_t h, const size_t w) noexcept(NO_EXCEPT) /*override*/ {
        this->_h = h, this->_w = w;
    }

    inline size_t height() const noexcept(NO_EXCEPT) /*override*/ { return this->_h; }
    inline size_t width() const noexcept(NO_EXCEPT) /*override*/ { return this->_w; }

    inline size_t id(const size_t i, const size_t j) const noexcept(NO_EXCEPT) /*override*/ {
        const size_t _i = this->_positivize_row_index(i);
        const size_t _j = this->_positivize_col_index(j);
        this->_validate_index(_i, _j);
        return _i * this->width() + _j;
    }
};

template<class T, class Row = std::vector<T>, class base = std::vector<Row>>
struct container : base, container_base<T>, virtual interface<T> {

    container(const size_t n = 0) noexcept(NO_EXCEPT) : container(n, n) {}
    container(const size_t h, const size_t w, const T &val = T{}) noexcept(NO_EXCEPT) : base(h, Row(w, val)), container_base<T>(h, w) {}

    container(const std::initializer_list<Row> init_list) noexcept(NO_EXCEPT) : base(init_list) {
        const size_t rows = std::distance(ALL(init_list));
        const size_t first_cols = init_list.begin()->size();

        if constexpr (DEV_ENV) { ITR(init_row, init_list) assert((size_t)init_row.size() == first_cols); }

        this->container_base<T>::resize(rows, first_cols);
    }

    inline void assign(const container &source) noexcept(NO_EXCEPT) {
        this->resize(source.height(), source.width());
        this->base::assign(ALL(source));
    }

    inline void assign(const size_t h, const size_t w, const T &val = T{}) noexcept(NO_EXCEPT) /*override*/ {
        this->container_base<T>::resize(h, w);
        this->base::resize(h);
        ITRR(row, *this) row.assign(w, val);
    }

    inline void resize(const size_t h, const size_t w) noexcept(NO_EXCEPT) /*override*/ {
        this->container_base<T>::resize(h, w);
        this->base::resize(h);
        ITRR(row, *this) row.resize(w);
    }

    inline T& operator()(const size_t i, const size_t j) noexcept(NO_EXCEPT) /*override*/ {
        const size_t _i = this->_positivize_row_index(i);
        const size_t _j = this->_positivize_col_index(j);
        this->_validate_index(_i, _j);
        return (*this)[_i][_j];
    }

    inline const T& operator()(const size_t i, const size_t j) const noexcept(NO_EXCEPT) /*override*/ {
        const size_t _i = this->_positivize_row_index(i);
        const size_t _j = this->_positivize_col_index(j);
        this->_validate_index(_i, _j);
        return (*this)[_i][_j];
    }
};

template<class T, class base = std::vector<T>>
struct unfolded_container : base, container_base<T>, virtual interface<T> {

    unfolded_container(size_t n = 0) noexcept(NO_EXCEPT) : unfolded_container(n, n) {}
    unfolded_container(const size_t h, const size_t w, const T &val = T{}) noexcept(NO_EXCEPT) : base(h*w, val), container_base<T>(h, w) {}

    unfolded_container(std::initializer_list<std::initializer_list<T>> init_list) noexcept(NO_EXCEPT) {
        const size_t rows = std::distance(init_list.begin(), init_list.end());
        const size_t first_cols = init_list.begin()->size();

        this->resize(rows, first_cols);

        for(auto index=0, itr=init_list.begin(), itr_end=init_list.end(); itr!=itr_end; ++itr) {
            assert((size_t)itr->size() == first_cols);
            for(auto v=itr->begin(), v_end=itr->end(); v!=v_end; ++v) (*this)[index++] = *v;
        }
    }

    inline void assign(const unfolded_container &source) noexcept(NO_EXCEPT) {
        this->resize(source.height(), source.width());
        this->base::assign(ALL(source));
    }

    inline void assign(const size_t h, const size_t w, const T &val = T{}) noexcept(NO_EXCEPT) /*override*/ {
        this->container_base<T>::resize(h, w);
        this->base::assign(h*w, val);
    }

    inline void resize(const size_t h, const size_t w) noexcept(NO_EXCEPT) /*override*/ {
        this->container_base<T>::resize(h, w);
        this->base::resize(h*w);
    }

    inline T& operator()(const size_t i, const size_t j) noexcept(NO_EXCEPT) /*override*/ {
        const size_t _i = this->_positivize_row_index(i);
        const size_t _j = this->_positivize_col_index(j);
        return (*this)[this->id(_i, _j)];
    }

    inline const T& operator()(const size_t i, const size_t j) const noexcept(NO_EXCEPT) /*override*/ {
        const size_t _i = this->_positivize_row_index(i);
        const size_t _j = this->_positivize_col_index(j);
        return (*this)[this->id(_i, _j)];
    }
};

}  // namespace grid_impl

template<class T, class container> struct grid_core : container, virtual grid_impl::interface<T> {
    using container::container;
    using size_type = internal::size_t;

    enum class invert_direction { vertical, horizontal };
    enum class rotate_direction { counter_clockwise, clockwise };

    template<class U = T, class Stream = std::istream>
    void inline read(Stream *const ist = &std::cin) noexcept(NO_EXCEPT) {
        REP(i, this->height()) REP(j, this->width()) {
            U val; *ist >> val;
            (*this)(i, j) = val;
        }
    }


    inline bool is_valid(const size_type i, const size_type j) const noexcept(NO_EXCEPT) {
        return 0 <= i and i < this->height() and 0 <= j and j < this->width();
    }


    template<class I>
    inline auto vicinities(const size_type i, const size_type j, const I dirs_first, const I dirs_last) const noexcept(NO_EXCEPT) {
        std::vector<std::pair<size_type,size_type>> res;
        REP(itr, dirs_first, dirs_last) {
            const size_type ii = i + itr->first, jj = j + itr->second;
            if(this->is_valid(ii, jj)) res.emplace_back(ii, jj);
        }
        return res;
    }

    template<class I, class C>
    inline auto vicinities(const std::pair<size_type,size_type>& p, const C dirs) const noexcept(NO_EXCEPT) {
        return this->vicinities(p.first, p.second, ALL(dirs));
    }

    inline auto vicinities4(const size_type i, const size_type j) const noexcept(NO_EXCEPT) { return this->vicinities(i, j, ALL(DIRS4)); }
    inline auto vicinities4(const std::pair<size_type,size_type>& p) const noexcept(NO_EXCEPT) { return this->vicinities(p.first, p.second, ALL(DIRS4)); }

    inline auto vicinities8(const size_type i, const size_type j) const noexcept(NO_EXCEPT) { return this->vicinities(i, j, ALL(DIRS8)); }
    inline auto vicinities8(const std::pair<size_type,size_type>& p) const noexcept(NO_EXCEPT) { return this->vicinities(p.first, p.second, ALL(DIRS8)); }


    template<invert_direction DIRECTION = invert_direction::vertical>
    inline grid_core& invert() noexcept(NO_EXCEPT) {
        grid_core res(this->height(), this->width());
        REP(i, this->height()) REP(j, this->width()) {
            if constexpr (DIRECTION == invert_direction::vertical) {
                res(i,j) = (*this)(this->height()-i-1,j);
            }
            else {
                res(i,j) = (*this)(i, this->width()-j-1);
            }
        }
        this->assign(res);
        return *this;
    }

    template<rotate_direction DIRECTION = rotate_direction::clockwise>
    inline grid_core& rotate(const size_t k) noexcept(NO_EXCEPT) {
        grid_core res = *this;
        REP(i, k) { res = res.rotate<DIRECTION>(); }
        this->assign(res);
        return *this;
    }

    template<rotate_direction DIRECTION = rotate_direction::clockwise>
    inline grid_core& rotate() noexcept(NO_EXCEPT) {
        grid_core res(this->width(), this->height());
        REP(i, this->width()) REP(j, this->height()) {
            if constexpr (DIRECTION == rotate_direction::clockwise) {
                res(i,j) = (*this)(this->height()-j-1,i);
            }
            else {
                res(i,j) = (*this)(j,this->width()-i-1);
            }
        }
        this->assign(res);
        return *this;
    }

    inline grid_core& transpose() noexcept(NO_EXCEPT) {
        grid_core res(this->width(), this->height());
        REP(i, this->width()) REP(j, this->height()) {
            res(i,j) = (*this)(j,i);
        }
        this->assign(res);
        return *this;
    }
};

} // namespace internal

template<class T, class Row = vector<T>, class base = vector<Row>>
using grid = internal::grid_core<T,internal::grid_impl::container<T,Row,base>>;

template<class T, class Row = valarray<T>, class base = valarray<Row>>
using valgrid = internal::grid_core<T,internal::grid_impl::container<T,Row,base>>;

template<class T, class base = vector<T>>
using unfolded_grid = internal::grid_core<T,internal::grid_impl::unfolded_container<T,base>>;

} // namespace lib
/* [grid.hpp] */
#line 18 "graph.hpp"

#line 19 "graph.hpp"


namespace lib {

namespace internal {

namespace graph_impl {


template<class cost_t, class size_type> struct edge {
  private:
    inline static internal::size_t unique() noexcept(NO_EXCEPT) { static internal::size_t id = 0; return id++; }

  public:
    using cost_type = cost_t;

    const internal::size_t id = unique();
    const size_type from, to; const cost_t cost;

    edge(const size_type u, const size_type v, const cost_t w) noexcept(NO_EXCEPT) : from(u), to(v), cost(w) {}

    operator size_type() const noexcept(NO_EXCEPT) { return this->to; }

    inline size_type opposite(const size_type v) const noexcept(NO_EXCEPT) {
        if(this->from == v) return this->to;
        if(this->to == v) return this->from;
        assert(false);
    }

    std::tuple<size_type,size_type,cost_t> _debug() const noexcept(NO_EXCEPT) { return { from, to, cost }; };

    friend bool operator==(const edge& lhs, const edge& rhs) noexcept(NO_EXCEPT) { return lhs.id == rhs.id; }
    friend bool operator!=(const edge& lhs, const edge& rhs) noexcept(NO_EXCEPT) { return lhs.id != rhs.id; }
};


} // namespace graph_impl

} // namespace internal

template<class C = ll>
struct graph : std::vector<std::vector<internal::graph_impl::edge<C,internal::size_t>>> {
    using size_type = internal::size_t;
    using cost_type = C;

    using edge_type = typename internal::graph_impl::edge<cost_type,size_type>;

    enum class edge_kind { undirected, directed };

  private:
    size_type _directed_edge_count = 0, _undirected_edge_count = 0;

    std::vector<edge_type> _edges;
    std::vector<size_type> _out_degs, _in_degs;

  protected:
    inline void _add_edge(const size_type u, const size_type v, const cost_type w) noexcept(NO_EXCEPT) {
        this->operator[](u).emplace_back(u, v, w);
        ++_out_degs[u], ++_in_degs[v];
        ++this->_directed_edge_count;
    }

  public:
    explicit graph(const size_type n = 0) noexcept(NO_EXCEPT)
      : std::vector<std::vector<edge_type>>(n), _out_degs(n), _in_degs(n)
    {}

    inline void clear() noexcept(NO_EXCEPT) { this->std::vector<std::vector<edge_type>>::clear(); }

    inline const auto& edges() const noexcept(NO_EXCEPT) { return this->_edges; }
    inline const auto& edge(const size_type k) const noexcept(NO_EXCEPT) { return this->_edges[k]; }

    inline const auto& degrees() const noexcept(NO_EXCEPT) { return this->_in_degs; }
    inline const auto& degree(const size_type k) const noexcept(NO_EXCEPT) { return this->_in_degs[k]; }

    inline const auto& in_degrees() const noexcept(NO_EXCEPT) { return this->_in_degs; }
    inline const auto& in_degree(const size_type k) const noexcept(NO_EXCEPT) { return this->_in_degs[k]; }

    inline const auto& out_degrees() const noexcept(NO_EXCEPT) { return this->_out_degs; }
    inline const auto& out_degree(const size_type k) const noexcept(NO_EXCEPT) { return this->_out_degs[k]; }

    inline size_type vertices() const noexcept(NO_EXCEPT) { return static_cast<size_type>(this->size()); }

    inline size_type directed_edges_count() const noexcept(NO_EXCEPT) { return this->_directed_edge_count; }

    template<class R = valgrid<bool>>
    inline auto make_has_edges() const noexcept(NO_EXCEPT) {
        R res(this->size(), this->size(), false);
        REP(i, this->size()) ITR(j, this->operator[](i)) res[i][j] = true;
        return res;
    }

    template<const bool SELF_ZERO = true, class T = cost_type, class R = valgrid<T>>
    inline auto make_initial_distance_matrix() const noexcept(NO_EXCEPT) {
        R res(this->size(), this->size(), numeric_limits<T>::arithmetic_infinity());
        if constexpr(SELF_ZERO) REP(i, this->size()) res[i][i] = 0;
        REP(i, this->size()) ITR(j, this->operator[](i)) res[i][j] = j.cost;
        return res;
    }

    template<const bool SELF_ZERO = true, class T = cost_type, class R = valgrid<T>>
    inline auto make_distance_matrix() const noexcept(NO_EXCEPT) {
        R res = this->make_initial_distance_matrix<SELF_ZERO,T,R>();
        REP(k, this->size()) REP(i, this->size()) REP(j, this->size()) {
            chmin(res[i][j], res[i][k] + res[k][j]);
        }
        return res;
    }

    template<const edge_kind EDGE_TYPE = edge_kind::directed>
    inline void add_edge(const size_type u, const size_type v, const cost_type w = 1) noexcept(NO_EXCEPT) {
        assert(0 <= u and u < this->vertices()), assert(0 <= v and v < this->vertices());
        this->_edges.emplace_back(u, v, w);
        this->_add_edge(u, v, w);
        if constexpr(EDGE_TYPE == edge_kind::undirected) this->_add_edge(v, u, w);
    }

    inline void add_edge_bidirectionally(const size_type u, const size_type v, const cost_type w = 1) noexcept(NO_EXCEPT) {
        this->add_edge<edge_kind::undirected>(u, v, w);
    }

    template<bool WEIGHTED = false, bool ONE_ORIGIN = true, const edge_kind EDGE_TYPE = edge_kind::directed, class Stream = std::istream>
    void inline read(const size_type edges, Stream *const ist = &std::cin) noexcept(NO_EXCEPT) {
        REP(edges) {
            size_type u, v; cost_type w = 1; *ist >> u >> v; if(ONE_ORIGIN) --u, --v;
            if(WEIGHTED) *ist >> w;
            this->add_edge<EDGE_TYPE>(u, v, w);
        }
    }
    template<bool WEIGHTED = false, bool ONE_ORIGIN = true, class Stream = std::istream>
    void inline read_bidirectionally(const size_type edges, Stream *const ist = &std::cin) noexcept(NO_EXCEPT) {
        REP(edges) {
            size_type u, v; cost_type w = 1; *ist >> u >> v; if(ONE_ORIGIN) --u, --v;
            if(WEIGHTED) *ist >> w;
            this->add_edge<edge_kind::undirected>(u, v, w);
        }
    }

    // graph/shortest_path.hpp
    template<class cost_t = cost_type> inline void distances_without_cost(const size_type, std::vector<cost_t> *const) const noexcept(NO_EXCEPT) ;
    template<class cost_t = cost_type> inline std::vector<cost_t> distances_without_cost(const size_type) const noexcept(NO_EXCEPT) ;

    // graph/dijkstra.hpp
    template<class cost_t = cost_type> inline void distances_with_01cost(const size_type, std::vector<cost_t> *const) const noexcept(NO_EXCEPT) ;
    template<class cost_t = cost_type> inline std::vector<cost_t> distances_with_01cost(const size_type) const noexcept(NO_EXCEPT) ;

    // graph/dijkstra.hpp
    template<class cost_t = cost_type> inline void distances(const size_type, std::vector<cost_t> *const) const noexcept(NO_EXCEPT) ;
    template<class cost_t = cost_type> inline std::vector<cost_t> distances(const size_type) const noexcept(NO_EXCEPT) ;

    // graph/topological_sort.hpp
    inline bool sort_topologically(std::vector<size_type> *const ) const noexcept(NO_EXCEPT) ;
    inline bool sort_topologically() const noexcept(NO_EXCEPT) ;

    // graph/topological_sort.hpp
    template<class> inline bool sort_topologically_with_priority(std::vector<size_type> *const) const noexcept(NO_EXCEPT) ;
    template<class> inline bool sort_topologically_with_priority() const noexcept(NO_EXCEPT) ;

    // graph/minimum_paph_cover.hpp
    inline size_type minimum_paph_cover_size_as_dag() const noexcept(NO_EXCEPT) ;

    // graph/spanning_tree_cost.hpp
    template<class cost_t = cost_type>
    inline cost_t minimum_spanning_tree(graph *const = nullptr) const noexcept(NO_EXCEPT) ;

    // graph/spanning_tree_cost.hpp
    template<class cost_t = cost_type>
    inline cost_t maximum_spanning_tree(graph *const = nullptr) const noexcept(NO_EXCEPT) ;

    // graph/connected_components.hpp
    inline dsu components() const noexcept(NO_EXCEPT) ;

    // graph/from_grid.hpp
    template<bool = false, class G, class U = char>
    inline void from_grid(const G&, U = '.') noexcept(NO_EXCEPT) ;

    // graph/manhattan_minimum_spanning_tree.hpp
    template<class I, class J = I, class distance_type = cost_type, class = internal::size_t>
    inline distance_type build_manhattan_mst(const I, const I, const J, const J) noexcept(NO_EXCEPT) ;
};

} // namespace lib
/* [graph.hpp] */
#line 9 "graph/centroid_decomposition.hpp"

namespace lib {


// Thanks to: https://qiita.com/drken/items/4b4c3f1824339b090202
template<class graph = graph<>>
struct centroid_decomposition {
    using size_type = internal::size_t;

    std::vector<size_type> centroids;

  private:
    const graph& G;
    std::vector<size_type> _size, _parent;
    std::vector<bool> _used;

  public:
    centroid_decomposition(const graph& G) noexcept(NO_EXCEPT)
      : G(G),
        _size(G.vertices()), _parent(G.vertices()), _used(G.vertices())
    {}

    inline const auto& sizes() const noexcept(NO_EXCEPT) { return this->_size; }
    inline const auto& parents() const noexcept(NO_EXCEPT) { return this->_parent; }
    inline const auto& used() const noexcept(NO_EXCEPT) { return this->_used; }

    inline size_type size(const size_type v) const noexcept(NO_EXCEPT) {
        assert(0 <= v && v < this->G.vertices());
        return this->_size[v];
    }
    inline size_type parent(const size_type v) const noexcept(NO_EXCEPT) {
        assert(0 <= v && v < this->G.vertices());
        return this->_parent[v];
    }
    inline bool used(const size_type v) const noexcept(NO_EXCEPT) {
        assert(0 <= v && v < this->G.vertices());
        return this->_used[v];
    }

    const std::vector<size_type>& find(const size_type v, const size_type sz, const size_type p = -1) noexcept(NO_EXCEPT) {
        assert(not this->_used[v]);

        this->_size[v] = 1, this->_parent[v] = p;
        bool found = true;
        ITR(e, this->G[v]) {
            if(e.to == p) continue;
            if(this->_used[e.to]) continue;

            this->find(e.to, sz, v);
            if(this->_size[e.to] > sz / 2) found = false;
            this->_size[v] += this->_size[e.to];
        }
        if(sz - this->_size[v] > sz / 2) found = false;
        if(found) this->centroids.push_back(v);

        return this->centroids;
    }

    auto decompose(const size_type root, const size_type sz) noexcept(NO_EXCEPT) {
    assert(not this->_used[root]);

        std::vector<std::pair<size_type,size_type>> subtrees;

        this->centroids.clear();
        this->find(root, sz);

        const size_type centroid = this->centroids[0];
        this->_used[centroid] = true;

        ITR(e, this->G[centroid]) {
            if(this->_used[e.to]) continue;
            if(e.to == this->_parent[centroid]) {
                subtrees.emplace_back(e.to, sz - this->_size[centroid]);
            }
            else {
                subtrees.emplace_back(e.to, this->_size[e.to]);
            }
        }

        return std::make_pair(centroid, subtrees);
    }

    auto decompose(const size_type root = 0) noexcept(NO_EXCEPT) {
        return this->decompose(root, this->G.vertices());
    }
};


} // namespace lib
/* [graph/centroid_decomposition.hpp] */
#line 61 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/centroid_path_decomposition.hpp] */
#line 1 "graph/centroid_path_decomposition.hpp"













namespace lib {

// Thanks to: https://kazuma8128.hatenablog.com/entry/2018/07/16/010500#fn-96e76557
class centroid_path_decomposition {
    using size_type = internal::size_t;

  private:
    std::vector<std::vector<size_type>> G;

  public:
    std::vector<size_type> in, out, size, head, parent;

  private:
    size_type _cur = 0;

    void _erase_parent(const size_type v, const size_type p) noexcept(NO_EXCEPT) {
        this->parent[v] = p;
        ITRR(nv, G[v]) {
            if(nv == this->G[v].back()) break;
            if(nv == p) std::swap(nv, this->G[v].back());
            this->_erase_parent(nv, v);
        }
        this->G[v].pop_back();
    }

    void _race_size(const size_type v) noexcept(NO_EXCEPT) {
        ITRR(nv, this->G[v]) {
            this->_race_size(nv);
            this->size[v] += this->size[nv];
            if(this->size[nv] > this->size[this->G[v].front()]) std::swap(nv, this->G[v].front());
        }
    }

    void _race_path(const size_type v) noexcept(NO_EXCEPT) {
        this->in[v] = this->_cur++;
        ITR(nv, this->G[v]) {
            this->head[nv] = (nv == this->G[v].front() ? this->head[v] : nv);
            this->_race_path(nv);
        }
        this->out[v] = this->_cur;
    }

  public:
    template<class graph>
    centroid_path_decomposition(const graph& G, const size_type root = 0) noexcept(NO_EXCEPT)
      : G(G.size()), in(G.size(), -1), out(G.size(), -1), size(G.size(), 1), head(G.size()), parent(G.size(), -1)
    {
        REP(v, G.size()) ITR(nv, G[v]) this->G[v].push_back(nv);
        this->build(root);
    }

    void build(const size_type root = 0) noexcept(NO_EXCEPT) {
        ITR(v, this->G[root]) this->_erase_parent(v, root);
        this->_race_size(root);
        this->head[root] = root;
        this->_race_path(root);
    }

    size_type id(const size_type v) noexcept(NO_EXCEPT) { return this->in[v]; }

    size_type lca(size_type u, size_type v) const noexcept(NO_EXCEPT) {
        while(true) {
            if(this->in[u] > this->in[v]) std::swap(u, v);
            if(this->head[u] == this->head[v]) return u;
            v = this->parent[this->head[v]];
        }
    }

    template<class F>
    void edges_on_path(size_type u, size_type v, const F&& f) noexcept(NO_EXCEPT) {
        while(true) {
            if(this->in[u] > this->in[v]) std::swap(u, v);
            if(this->head[u] != this->head[v]) {
                f(this->in[head[v]] - 1, this->in[v]);
                v = this->parent[this->head[v]];
            } else {
                if(u != v) f(this->in[u], this->in[v]);
                break;
            }
        }
    }

    template<class F>
    void nodes_on_path(int u, int v, const F&& f) noexcept(NO_EXCEPT) {
        while (true) {
            if (this->in[u] > this->in[v]) std::swap(u, v);
            f(std::max(this->in[this->head[v]] - 1, this->in[u]), this->in[v]);
            if (this->head[u] != this->head[v])
                v = this->parent[this->head[v]];
            else {
                break;
            }
        }
    }

    template<class F>
    void subtree(const size_type v, const F&& f) noexcept(NO_EXCEPT) { f(this->in[v], this->out[v]); }
};


} // namespace lib
/* [graph/centroid_path_decomposition.hpp] */
#line 62 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/connected_components.hpp] */
#line 1 "graph/connected_components.hpp"






// #include "snippet/internal/types.hpp"





template<class edge_cost>
lib::dsu lib::graph<edge_cost>::components() const noexcept(NO_EXCEPT) {
    lib::dsu dsu(this->vertices());
    ITR(edges, *this) ITR(_id, u, v, _w, edges) {
        dsu.merge(u, v);
    }
    return dsu;
}
/* [graph/connected_components.hpp] */
#line 63 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/directed_minimum_spanning_tree.hpp] */
#line 1 "graph/directed_minimum_spanning_tree.hpp"


// TODO
/* [graph/directed_minimum_spanning_tree.hpp] */
#line 64 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/from_grid.hpp] */
#line 1 "graph/from_grid.hpp"







template<class edge_cost>
template<bool REV, class G, class U>
void lib::graph<edge_cost>::from_grid(const G &grid, U available) noexcept(NO_EXCEPT) {
    this->clear();
    this->resize(grid.height() * grid.width());

    REP(i, grid.height()) REP(j, grid.width()) {
        if(REV ^ (grid(i, j) != available)) continue;
        if(i+1 < grid.height() and (REV ^ (grid(i+1, j) == available))) {
            this->template add_edge<graph<edge_cost>::edge_type::undirected>(grid.id(i, j), grid.id(i+1, j));
        }
        if(j+1 < grid.width() and (REV ^ (grid(i, j+1) == available))) {
            this->template add_edge<graph<edge_cost>::edge_type::undirected>(grid.id(i, j), grid.id(i, j+1));
        }
    }
}
/* [graph/from_grid.hpp] */
#line 65 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/lowest_common_ancestor.hpp] */
#line 1 "graph/lowest_common_ancestor.hpp"












namespace lib {


struct lowest_common_ancestor {
    using size_type = internal::size_t;
    std::vector<std::vector<size_type>> parent;
    std::vector<size_type> dists;

  private:
    template<class graph>
    void dfs(const graph &G, const size_type v, const size_type p, const size_type d) noexcept(NO_EXCEPT) {
        this->parent[0][v] = p;
        this->dists[v] = d;
        ITR(e, G[v]) {
            if(e.to != p) dfs(G, e.to, v, d+1);
        }
    }

  public:
    template<class graph>
    lowest_common_ancestor(const graph &G, const size_type root = 0) noexcept(NO_EXCEPT) { this->init(G, root); }

    template<class graph>
    void init(const graph &G, const size_type root = 0) noexcept(NO_EXCEPT) {
        const size_type V = static_cast<size_type>(G.size());
        const size_type K = lib::bit_width<std::make_unsigned_t<size_type>>(V);

        this->parent.assign(K, std::vector<size_type>(V, -1));
        this->dists.assign(V, -1);

        this->dfs(G, root, -1, 0);

        REP(k, K-1) REP(v, V) {
            if(this->parent[k][v] < 0) this->parent[k+1][v] = -1;
            else this->parent[k+1][v] = this->parent[k][this->parent[k][v]];
        }
    }

    size_type operator()(const size_type u, const size_type v) const noexcept(NO_EXCEPT) {
        return this->find(u, v);
    }

    size_type find(size_type u, size_type v) const noexcept(NO_EXCEPT) {
        if(this->dists[u] < this->dists[v]) std::swap(u, v);
        size_type K = static_cast<size_type>(this->parent.size());

        REP(k, K) {
            if((this->dists[u] - this->dists[v]) >> k & 1) u = this->parent[k][u];
        }

        if(u == v) return u;

        REPD(k, K) {
            if(this->parent[k][u] != this->parent[k][v]) {
                u = this->parent[k][u];
                v = this->parent[k][v];
            }
        }

        return this->parent[0][u];
    }

    size_type distance(const size_type u, const size_type v) const noexcept(NO_EXCEPT) {
        return this->dists[u] + this->dists[v] - 2 * this->dists[find(u, v)];
    }
};


} // namespace lib
/* [graph/lowest_common_ancestor.hpp] */
#line 66 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/manhattan_minimum_spanning_tree.hpp] */
#line 1 "graph/manhattan_minimum_spanning_tree.hpp"









#include <atcoder/dsu>








namespace lib {


// TODO: Vector View
template <class I, class J = I, class cost_type = typename std::iterator_traits<I>::value_type, class size_type = internal::size_t>
std::vector<std::tuple<size_type,size_type,cost_type>> manhattan_mst_candidate_edges(
    const I x_first, const I x_last, const J y_first, const J y_last
) noexcept(NO_EXCEPT) {
    std::vector<cost_type> xs(x_first, x_last), ys(y_first, y_last);
    assert(xs.size() == ys.size());

    std::vector<size_type> indices(xs.size());
    std::iota(ALL(indices), 0);

    std::vector<std::tuple<size_type,size_type,cost_type>> res;

    REP(2) {
        REP(2) {
            std::sort(ALL(indices), [&](const auto i, const auto j) { return xs[i] + ys[i] < xs[j] + ys[j]; });

            std::map<cost_type,size_type> scan;
            ITR(i, indices) {
                for(auto itr = scan.lower_bound(-ys[i]); itr!=scan.end(); itr=scan.erase(itr)) {
                    const auto j = itr->second;
                    if(xs[i] - xs[j] < ys[i] - ys[j]) break;
                    res.emplace_back(i, j, std::abs(xs[i] - xs[j]) + std::abs(ys[i] - ys[j]));
                }
                scan[-ys[i]] = i;
            }

            std::swap(xs, ys);
        }
        ITRR(x, xs) x *= -1;
    }

    std::sort(ALL(res), [&](const auto& p, const auto& q) { return std::get<2>(p) < std::get<2>(q); });

    return res;
}


template<class I, class J = I, class cost_type = typename std::iterator_traits<I>::value_type, class size_type = internal::size_t>
std::vector<std::tuple<size_type,size_type,cost_type>> manhattan_mst_edges(
    const I x_first, const I x_last, const J y_first, const J y_last,
    cost_type *const cost_sum = nullptr
) noexcept(NO_EXCEPT) {
    assert(std::distance(x_first, x_last) == std::distance(y_first, y_last));

    if(cost_sum) *cost_sum = 0;

    std::vector<std::tuple<size_type,size_type,cost_type>> res;
    atcoder::dsu uf(static_cast<int>(std::distance(x_first, x_last)));

    ITR(u, v, w, (manhattan_mst_candidate_edges<I,J,cost_type,size_type>(x_first, x_last, y_first, y_last))) {
        if(not uf.same(u, v)) {
            uf.merge(u, v);
            res.emplace_back(u, v, w);
            if(cost_sum) *cost_sum += w;
        }
    }

    return res;
}


template<class edge_cost>
template <class I, class J, class cost_type, class size_type>
cost_type graph<edge_cost>::build_manhattan_mst(const I x_first, const I x_last, const J y_first, const J y_last) noexcept(NO_EXCEPT) {
    assert(std::distance(x_first, x_last) == std::distance(y_first, y_last));

    cost_type res = 0;

    ITR(u, v, w, (manhattan_mst_edges<I,J,cost_type,size_type>(x_first, x_last, y_first, y_last))) {
        this->add_edge_bidirectionally(u, v, w);
    }

    return res;
}


} // namespace lib
/* [graph/manhattan_minimum_spanning_tree.hpp] */
#line 67 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/maximum_bipartite_matching.hpp] */
#line 1 "graph/maximum_bipartite_matching.hpp"


#include <atcoder/maxflow>






namespace lib {

struct maximum_bipartite_matching {
    using size_type = internal::size_t;

  protected:
    using MF = atcoder::mf_graph<size_type>;

    size_type _n;
    MF mf;

  public:
    maximum_bipartite_matching(size_type n = 0) noexcept(NO_EXCEPT) : _n(n), mf(2*n+2) {
        REP(i, n) {
            this->mf.add_edge(2*n, i, 1);
            this->mf.add_edge(n+i, 2*n+1, 1);
        }
    }

    void add(size_type i, size_type j) {
        this->mf.add_edge(i, this->_n+j, 1);
    }

    size_type solve() {
        return this->mf.flow(2*this->_n, 2*this->_n+1);
    }
};

} // namespace lib
/* [graph/maximum_bipartite_matching.hpp] */
#line 68 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/minimum_paph_cover.hpp] */
#line 1 "graph/minimum_paph_cover.hpp"









#line 10 "graph/minimum_paph_cover.hpp"

template<class edge_cost>
typename lib::graph<edge_cost>::size_type lib::graph<edge_cost>::minimum_paph_cover_size_as_dag() const noexcept(NO_EXCEPT) {
    lib::maximum_bipartite_matching bm(this->size());

    REP(i, this->size()) ITR(j, (*this)[i]) {
        bm.add(i, j.to);
    }

    return this->size() - bm.solve();
}
/* [graph/minimum_paph_cover.hpp] */
#line 69 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/shortest_path.hpp] */
#line 1 "graph/shortest_path.hpp"


/* #expanded [graph/internal/bfs.hpp] */
#line 1 "graph/internal/bfs.hpp"















template<class edge_cost>
template<class cost_t>
void lib::graph<edge_cost>::distances_without_cost(const size_type s, std::vector<cost_t> *dists) const noexcept(NO_EXCEPT) {
    dists->assign(this->size(), lib::numeric_limits<cost_t>::arithmetic_infinity());

    std::queue<size_type> que;
    que.push(s), (*dists)[s] = 0;

    while(not que.empty()) {
        const size_type v = que.front(); que.pop();
        ITR(nv, (*this)[v]) {
            if((*dists)[nv.to] < lib::numeric_limits<cost_t>::arithmetic_infinity()) continue;
            (*dists)[nv.to] = (*dists)[v] + 1;
            que.push(nv.to);
        }
    }
}

template<class edge_cost>
template<class cost_t>
std::vector<cost_t> lib::graph<edge_cost>::distances_without_cost(const size_type s) const noexcept(NO_EXCEPT) {
    std::vector<cost_t> dists;
    this->distances_without_cost<cost_t>(s, &dists);
    return dists;
}
/* [graph/internal/bfs.hpp] */
#line 4 "graph/shortest_path.hpp"
/* #expanded [graph/internal/01bfs.hpp] */
#line 1 "graph/internal/01bfs.hpp"




#include <deque>











template<class edge_cost>
template<class cost_t>
void lib::graph<edge_cost>::distances_with_01cost(const size_type s, std::vector<cost_t> *const dists) const noexcept(NO_EXCEPT) {
    std::deque<size_type> que;

    dists->assign(this->size(), lib::numeric_limits<cost_t>::arithmetic_infinity());
    que.push_back(s), (*dists)[s] = 0;

    while(not que.empty()) {
        const auto u = que.front(); que.pop_front();
        const cost_t d = (*dists)[u];

        ITR(e, (*this)[u]) {
            const size_type v = e.to; const auto cost = e.cost;

            if((*dists)[v] <= d + cost) continue;

            (*dists)[v] = d + cost;

            if(cost) que.push_back(v);
            else que.push_front(v);
        }
    }
}

template<class edge_cost>
template<class cost_t>
std::vector<cost_t> lib::graph<edge_cost>::distances_with_01cost(const size_type s) const noexcept(NO_EXCEPT) {
    std::vector<cost_t> dists;
    this->distances_with_01cost<cost_t>(s, &dists);
    return dists;
}
/* [graph/internal/01bfs.hpp] */
#line 5 "graph/shortest_path.hpp"
/* #expanded [graph/internal/dijkstra.hpp] */
#line 1 "graph/internal/dijkstra.hpp"
















template<class edge_cost>
template<class cost_t>
void lib::graph<edge_cost>::distances(const size_type s, std::vector<cost_t> *const dists) const noexcept(NO_EXCEPT) {
    using state = std::pair<cost_t,size_type>;
    std::priority_queue<state,std::vector<state>,std::greater<state>> que;

    dists->assign(this->size(), lib::numeric_limits<cost_t>::arithmetic_infinity());

    que.emplace(0, s), (*dists)[s] = 0;

    while(not que.empty()) {
        const auto [d, u] = que.top(); que.pop();

        if((*dists)[u] < d) continue;

        ITR(e, (*this)[u]) {
            const size_type v = e.to; const auto cost = e.cost;

            if((*dists)[v] <= d + cost) continue;

            (*dists)[v] = d + cost;
            que.emplace((*dists)[v], v);
        }
    }
}

template<class edge_cost>
template<class cost_t>
std::vector<cost_t> lib::graph<edge_cost>::distances(const size_type s) const noexcept(NO_EXCEPT) {
    std::vector<cost_t> dists;
    this->distances<cost_t>(s, &dists);
    return dists;
}
/* [graph/internal/dijkstra.hpp] */
#line 6 "graph/shortest_path.hpp"
/* [graph/shortest_path.hpp] */
#line 70 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/spanning_tree.hpp] */
#line 1 "graph/spanning_tree.hpp"







namespace lib {

namespace internal {

namespace graph_impl {


template<class G, class cost_type, class Compare>
cost_type kruskal(const G& graph, const Compare compare, G *const mst = nullptr) noexcept(NO_EXCEPT) {
    atcoder::dsu ds(graph.size());

    std::vector<std::tuple<typename G::edge_type::cost_type,size_t,size_t>> edges;

    REP(u, graph.size()) ITR(e, graph[u]) {
        edges.emplace_back(e.cost, u, e.to);
    }

    std::sort(ALL(edges), compare);

    if(mst) mst->clear(), mst->resize(graph.size());

    cost_type res = cost_type{};
    ITR(w, u, v, edges) {
        if(not ds.same(u, v)) {
            ds.merge(u, v);
            if(mst) mst->add_edge_bidirectionally(u, v, w);
            res += w;
        }
    }

    return res;
}


} // namespace graph_impl

} // namespace internal


template<class edge_cost>
template<class cost_type>
cost_type graph<edge_cost>::minimum_spanning_tree(graph<edge_cost> *const mst) const noexcept(NO_EXCEPT) {
    return internal::graph_impl::kruskal<graph<edge_cost>,cost_type,std::less<std::tuple<cost_type,size_t,size_t>>>(*this, {}, mst);
}

template<class edge_cost>
template<class cost_type>
inline cost_type graph<edge_cost>::maximum_spanning_tree(graph<edge_cost> *const mst) const noexcept(NO_EXCEPT) {
    return internal::graph_impl::kruskal<graph<edge_cost>,cost_type,std::greater<std::tuple<cost_type,size_t,size_t>>>(*this, {}, mst);
}


} // namespace lib
/* [graph/spanning_tree.hpp] */
#line 71 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [graph/topological_sort.hpp] */
#line 1 "graph/topological_sort.hpp"











template<class edge_cost>
template<class comparer>
bool lib::graph<edge_cost>::sort_topologically_with_priority(std::vector<size_type> *const sorted) const noexcept(NO_EXCEPT) {
    sorted->clear();

    std::vector<size_type> in_degs(this->size());
    ITR(v, *this) ITR(e, v)  ++in_degs[e.to];

    std::priority_queue<size_type,std::vector<size_type>,comparer> que;
    REP(i, this->size()) if(in_degs[i] == 0) que.push(i);

    while(not que.empty()) {
        const size_type v = que.top(); que.pop();
        ITR(u, (*this)[v]) if(!(--in_degs[u.to])) que.push(u.to);
        sorted->push_back(v);
    }

    return sorted->size() == this->size();
}

template<class edge_cost>
template<class comparer>
bool lib::graph<edge_cost>::sort_topologically_with_priority() const noexcept(NO_EXCEPT) {
    std::vector<size_type> vs;
    return this->sort_topologically_with_priority<comparer>(&vs);
}


template<class edge_cost>
bool lib::graph<edge_cost>::sort_topologically(std::vector<size_type> *const sorted) const noexcept(NO_EXCEPT) {
    sorted->clear();

    std::vector<size_type> in_degs(this->size());
    ITR(v, *this) ITR(e, v)  ++in_degs[e.to];

    std::queue<size_type> que;
    REP(i, this->size()) if(in_degs[i] == 0) que.push(i);

    while(not que.empty()) {
        const size_type v = que.front(); que.pop();
        ITR(u, (*this)[v]) if(!(--in_degs[u.to])) que.push(u.to);
        sorted->push_back(v);
    }

    return sorted->size() == this->size();
}

template<class edge_cost>
bool lib::graph<edge_cost>::sort_topologically() const noexcept(NO_EXCEPT) {
    std::vector<size_type> vs;
    return this->sort_topologically(&vs);
}
/* [graph/topological_sort.hpp] */
#line 72 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [hash/multiset_hasher.hpp] */
#line 1 "hash/multiset_hasher.hpp"














namespace lib {


template<
    class T,
    std::uint64_t MOD = 0x1fffffffffffffff,
    int hasher_id = -1,
    class random_engine = std::mt19937_64,
    template<class...> class map = std::unordered_map
>
struct multiset_hasher {
  private:
    using uint128_t = internal::uint128_t;

  public:
    using hash_type = std::uint64_t;
    using size_type = std::uint64_t;

    static constexpr hash_type mod = MOD;

  protected:
    static random_engine rand;
    static map<T,hash_type> _ids;

    static inline hash_type _id(const T& v) noexcept(NO_EXCEPT) {
        if(multiset_hasher::_ids.count(v)) return multiset_hasher::_ids[v];
        return multiset_hasher::_ids[v] = multiset_hasher::rand() % mod;
    }

    static constexpr hash_type mask(const size_type a) noexcept(NO_EXCEPT) { return (1ULL << a) - 1; }

    static constexpr hash_type mul(hash_type a, hash_type b) noexcept(NO_EXCEPT) {
        #ifdef __SIZEOF_INT128__

        uint128_t res = static_cast<uint128_t>(a) * b;

        #else

        hash_type a31 = a >> 31, b31 = b >> 31;
        a &= multiset_hasher::mask(31);
        b &= multiset_hasher::mask(31);
        hash_type x = a * b31 + b * a31;
        hash_type res = (a31 * b31 << 1) + (x >> 30) + ((x & multiset_hasher::mask(30)) << 31) + a * b;

        #endif

        res = (res >> 61) + (res & multiset_hasher::mod);
        if(res >= multiset_hasher::mod) res -= multiset_hasher::mod;

        return res;
    }

    hash_type _hash = 0;

    inline void _add_hash(const hash_type h, const hash_type count) noexcept(NO_EXCEPT) {
        this->_hash += multiset_hasher::mul(h, count);
        if(this->_hash >= multiset_hasher::mod) this->_hash -= multiset_hasher::mod;
    }
    inline void _remove_hash(const hash_type h, const hash_type count) noexcept(NO_EXCEPT) {
        auto hash = static_cast<std::make_signed_t<hash_type>>(this->_hash);
        hash -= multiset_hasher::mul(h, count);
        if(hash < 0) hash += multiset_hasher::mod;
        this->_hash = hash;
    }

  public:
    multiset_hasher() noexcept(NO_EXCEPT) {
        static_assert(mod < std::numeric_limits<std::make_signed_t<hash_type>>::max());
    }

    template<class I> multiset_hasher(const I first, const I last) noexcept(NO_EXCEPT) : multiset_hasher() {
        for(auto itr=first; itr != last; ++itr) this->insert(*itr);
    }

    template<class U>
    multiset_hasher(const std::initializer_list<U>& init_list) noexcept(NO_EXCEPT) : multiset_hasher(std::begin(init_list), std::end(init_list)) {}

    inline size_type empty() const noexcept(NO_EXCEPT) { return this->get() == 0; }
    inline void clear() const noexcept(NO_EXCEPT) { this->_hash = 0; }

    // return: whether inserted newly
    inline void insert(const T& v, size_type count = 1) noexcept(NO_EXCEPT) {
        this->_add_hash(multiset_hasher::_id(v), count);
    }

    // return: iterator of next element erased
    inline void erase(const T& v, const size_type count = 1) noexcept(NO_EXCEPT) {
        this->_remove_hash(multiset_hasher::_id(v), count);
    }

    inline hash_type get() const noexcept(NO_EXCEPT) { return this->_hash; }
    inline hash_type operator()() const noexcept(NO_EXCEPT) { return this->_hash; }

    inline bool operator==(const multiset_hasher& other) const noexcept(NO_EXCEPT) { return this->_hash == other._hash; }
    inline bool operator!=(const multiset_hasher& other) const noexcept(NO_EXCEPT) { return this->_hash != other._hash; }
};

template<class T, std::uint64_t mod, int id, class E, template<class...> class M>
E multiset_hasher<T,mod,id,E,M>::rand(std::random_device{}());

template<class T, std::uint64_t mod, int id, class E, template<class...> class M>
M<T,typename multiset_hasher<T,mod,id,E,M>::hash_type> multiset_hasher<T,mod,id,E,M>::_ids;


} // namespace lib
/* [hash/multiset_hasher.hpp] */
#line 74 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [hash/sequence_hasher.hpp] */
#line 1 "hash/sequence_hasher.hpp"





#include <chrono>














namespace lib {


// Thanks to: https://github.com/tatyam-prime/kyopro_library/blob/master/RollingHash.cpp
template<std::uint64_t MOD = 0x1fffffffffffffff, std::uint64_t BASE = 0>
struct sequence_hasher {
  private:
    using uint64_t = std::uint64_t;
    using uint128_t = internal::uint128_t;

  public:
    using size_type = internal::size_t;
    using hash_type = uint64_t;

    static constexpr hash_type mod = MOD;
    static hash_type base;

  private:
    size_type _n = 0, _front = 0;
    std::vector<hash_type> _hashed;
    static std::vector<hash_type> _powers;

  protected:
    static inline hash_type power(const size_type p) noexcept(NO_EXCEPT) {
        if(static_cast<size_type>(sequence_hasher::_powers.size()) <= p) {
            size_type n = static_cast<size_type>(sequence_hasher::_powers.size());
            sequence_hasher::_powers.resize(p+1);
            if(n == 0) sequence_hasher::_powers[0] = 1;
            REP(i, std::max(0, n-1), p) sequence_hasher::_powers[i+1] = sequence_hasher::mul(sequence_hasher::_powers[i], sequence_hasher::base);
        }
        return sequence_hasher::_powers[p];
    }

    inline hash_type& hashed(const size_type p) noexcept(NO_EXCEPT) {
        if(static_cast<size_type>(this->_hashed.size()) <= p) this->_hashed.resize(p+1);
        return this->_hashed[p];
    }
    inline const hash_type& hashed(const size_type p) const noexcept(NO_EXCEPT) { return this->_hashed[p]; }

    static constexpr hash_type mask(const size_type a) noexcept(NO_EXCEPT) { return (1ULL << a) - 1; }

    static constexpr hash_type mul(hash_type a, hash_type b) noexcept(NO_EXCEPT) {
        #ifdef __SIZEOF_INT128__

        uint128_t res = static_cast<uint128_t>(a) * b;

        #else

        hash_type a31 = a >> 31, b31 = b >> 31;
        a &= sequence_hasher::mask(31);
        b &= sequence_hasher::mask(31);
        hash_type x = a * b31 + b * a31;
        hash_type res = (a31 * b31 << 1) + (x >> 30) + ((x & sequence_hasher::mask(30)) << 31) + a * b;

        #endif

        if constexpr(sequence_hasher::mod == 0x1fffffffffffffff) {
            res = (res >> 61) + (res & sequence_hasher::mod);
            if(res >= sequence_hasher::mod) res -= sequence_hasher::mod;
        }
        else {
            res %= sequence_hasher::mod;
        }

        return static_cast<hash_type>(res);
    }

    size_type index(size_type k) const noexcept(NO_EXCEPT) { return this->_front + k; }

  public:
    struct hash {
      private:
        const hash_type _val;
        const size_type _len;

      public:
        hash(const hash_type _val, const size_type _len) noexcept(NO_EXCEPT) : _val(_val), _len(_len) {}

        inline hash_type val() const noexcept(NO_EXCEPT) { return this->_val; }
        inline operator hash_type() const noexcept(NO_EXCEPT) { return this->_val; }

        inline size_type size() const noexcept(NO_EXCEPT) { return this->_len; }

        inline bool operator==(const hash& other) const noexcept(NO_EXCEPT) { return this->_val == other._val and this->_len == other._len; }
        inline bool operator!=(const hash& other) const noexcept(NO_EXCEPT) { return this->_val != other._val or this->_len != other._len; }

        inline hash concat(const hash& other) const noexcept(NO_EXCEPT) { return sequence_hasher::concat(*this, other); }
        inline hash operator+(const hash& other) const noexcept(NO_EXCEPT) { return sequence_hasher::concat(*this, other); }
    };

    sequence_hasher(const size_type n = 0) noexcept(NO_EXCEPT) : _n(n) {
        if(sequence_hasher::base <= 0) {
            xorshift64 rand64(std::random_device{}());
            sequence_hasher::base = static_cast<hash_type>(rand64() % sequence_hasher::mod);
        }
    }

    template<class I>
    sequence_hasher(const I first, const I last) noexcept(NO_EXCEPT) : sequence_hasher(static_cast<size_type>(std::distance(first, last))) {
        this->_hashed.resize(this->_n);
        this->_hashed.assign(this->_n+1, 0);

        size_type i = 0;
        for(auto itr=first; itr!=last; ++i, ++itr) {
            this->hashed(i+1) = sequence_hasher::mul(this->hashed(i), sequence_hasher::base) + std::hash<typename std::iterator_traits<I>::value_type>{}(*itr);
            if(this->hashed(i+1) >= sequence_hasher::mod) this->hashed(i+1) -= sequence_hasher::mod;
        }
    }

    inline size_type size() const noexcept(NO_EXCEPT) { return this->_n - this->_front; }

    inline hash get(size_type l, size_type r) const noexcept(NO_EXCEPT) {
        assert(0 <= l and l <= r and r <= this->size());
        l = this->index(l), r = this->index(r);
        hash_type res = this->hashed(r) + sequence_hasher::mod - sequence_hasher::mul(this->hashed(l), sequence_hasher::power(r-l));
        if(res >= sequence_hasher::mod) res -= sequence_hasher::mod;

        return { res, r - l };
    }
    inline hash get() const noexcept(NO_EXCEPT) { return this->get(0, this->size()); }
    inline hash operator()(const size_type l, const size_type r) const noexcept(NO_EXCEPT) { return this->get(l, r); }

    inline hash subseq(const size_type p, const size_type c) const noexcept(NO_EXCEPT) { return this->get(p, p+c); }
    inline hash subseq(const size_type p) const noexcept(NO_EXCEPT) {  return this->get(p, this->size()); }


    static constexpr hash_type concat(const hash_type h0, const hash_type h1, const size_type len1) noexcept(NO_EXCEPT) {
        hash_type res = sequence_hasher::mul(h0, sequence_hasher::power(len1)) + h1;
        if(res >= sequence_hasher::mod) res -= sequence_hasher::mod;

        return res;
    }
    static constexpr hash concat(const hash& h0, const hash& h1) noexcept(NO_EXCEPT) {
        return { sequence_hasher::concat(h0.val(), h1.val(), h1.size()), h0.size() + h1.size() };
    }


    template<class T> inline sequence_hasher& push_back(const T& v) noexcept(NO_EXCEPT) {
        this->_n++;

        this->hashed(this->_n) = sequence_hasher::mul(this->hashed(this->_n-1), sequence_hasher::base) + std::hash<T>{}(v);
        if(this->hashed(this->_n) >= sequence_hasher::mod) this->hashed(this->_n-1) -= sequence_hasher::mod;

        return *this;
    }

    inline sequence_hasher& pop_back() noexcept(NO_EXCEPT) {
        assert(this->_n > 0);
        this->_n--;
        return *this;
    }

    inline sequence_hasher& pop_front() noexcept(NO_EXCEPT) {
        this->_front++;
        assert(this->_front <= this->_n);
        return *this;
    }


    template<class I> inline sequence_hasher& concat(const I first, const I last) noexcept(NO_EXCEPT) {
        size_type n = this->_n;
        this->_n += std::distance(first, last);

        size_type i = n;
        for(auto itr=first; itr!=last; ++i, ++itr) {
            this->hashed(i+1) = sequence_hasher::mul(this->hashed(i), sequence_hasher::base) + std::hash<typename std::iterator_traits<I>::value_type>{}(*itr);
            if(this->hashed(i+1) >= sequence_hasher::mod) this->hashed(i+1) -= sequence_hasher::mod;
        }

        return *this;
    }

    template<class T>inline sequence_hasher& concat(const T& v) noexcept(NO_EXCEPT) { return this->concat(ALL(v)); }

    inline size_type lcp(size_type l0, size_type r0, size_type l1, size_type r1) noexcept(NO_EXCEPT) {
        size_type size = std::min(r0 - l0, r1 - l1);
        size_type low = -1, high = size + 1;

        while(high - low > 1) {
            size_type mid = (low + high) / 2;
            if(this->get(l0, l0 + mid) == this->get(l1, l1 + mid)) low = mid;
            else high = mid;
        }

        return low;
    }
};

template<std::uint64_t mod, std::uint64_t Base> std::uint64_t sequence_hasher<mod,Base>::base = Base;
template<std::uint64_t mod, std::uint64_t base> std::vector<std::uint64_t> sequence_hasher<mod,base>::_powers;


} // namespace lib
/* [hash/sequence_hasher.hpp] */
#line 75 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [hash/set_hasher.hpp] */
#line 1 "hash/set_hasher.hpp"











namespace lib {


template<
    class T,
    int hasher_id = -1,
    class random_engine = std::mt19937_64,
    template<class...> class set = std::unordered_set,
    template<class...> class map = std::unordered_map
>
struct set_hasher : protected set<T> {
  private:
    using base = set<T>;

  public:
    using hash_type = typename random_engine::result_type;
    using size_type = typename base::size_type;

  protected:
    static random_engine rand;
    static map<T,hash_type> _ids;

    hash_type _hash = 0;

    static inline hash_type id(const T& v) noexcept(NO_EXCEPT) {
        auto itr = set_hasher::_ids.find(v);
        if(itr == std::end(set_hasher::_ids)) return set_hasher::_ids[v] = set_hasher::rand();
        return itr->second;
    }

  public:
    set_hasher() {}

    template<class I> set_hasher(const I first, const I last) noexcept(NO_EXCEPT) {
        for(auto itr=first; itr != last; ++itr) this->_insert(*itr);
    }

    template<class U>
    set_hasher(const std::initializer_list<U>& init_list) noexcept(NO_EXCEPT) : set_hasher(std::begin(init_list), std::end(init_list)) {}

    inline size_type empty() const noexcept(NO_EXCEPT) { return this->base::empty(); }
    inline size_type size() const noexcept(NO_EXCEPT) { return this->base::size(); }
    inline size_type max_size() const noexcept(NO_EXCEPT) { return this->base::max_size(); }

    inline void clear() const noexcept(NO_EXCEPT) { this->_hash = 0, this->base::clear(); }

    using base::count;
    using base::find;
    using base::equal_range;

    inline auto begin() const noexcept(NO_EXCEPT) { return this->base::begin(); }
    inline auto end() const noexcept(NO_EXCEPT) { return this->base::end(); }

    template<class... Args> auto lower_bound(const Args&... args) const noexcept(NO_EXCEPT) { return this->base::lower_bound(args...); }
    template<class... Args> auto upper_bound(const Args&... args) const noexcept(NO_EXCEPT) { return this->base::upper_bound(args...); }

    // return: whether inserted newly
    inline bool insert(const T& v) noexcept(NO_EXCEPT) {
        if(this->base::count(v)) return false;
        this->base::insert(v);
        this->_hash ^= set_hasher::id(v);
        return true;
    }

    // return: number of erased elements (0 or 1)
    inline size_type erase(const T& v) noexcept(NO_EXCEPT) {
        if(not this->base::count(v)) return 0;
        this->base::erase(v);
        this->_hash ^= set_hasher::id(v);
        return 1;
    }

    inline hash_type get() const noexcept(NO_EXCEPT) { return this->_hash; }
    inline hash_type operator()() const noexcept(NO_EXCEPT) { return this->_hash; }

    inline bool operator==(const set_hasher& other) const noexcept(NO_EXCEPT) { return this->_hash == other._hash; }
    inline bool operator!=(const set_hasher& other) const noexcept(NO_EXCEPT) { return this->_hash != other._hash; }
};

template<class T, int id, class E, template<class...> class S, template<class...> class M>
E set_hasher<T,id,E,S,M>::rand(std::random_device{}());

template<class T, int id, class E, template<class...> class S, template<class...> class M>
M<T,typename set_hasher<T,id,E,S,M>::hash_type> set_hasher<T,id,E,S,M>::_ids;


} // namespace lib
/* [hash/set_hasher.hpp] */
#line 76 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [iterable/accumulation.hpp] */
#line 1 "iterable/accumulation.hpp"
















namespace lib {


template<class T, class container = valarray<T>>
struct accumulation : container {
    using size_type = internal::size_t;

  protected:
    inline size_type _positivize_index(const size_type x) const noexcept(NO_EXCEPT) {
        return x < 0 ? std::size(*this) + x : x;
    }

  public:
    accumulation() noexcept(NO_EXCEPT) {}

    template<class I, class Operator = std::plus<T>>
    accumulation(const I first, const I last, const T head = T{}, const Operator op = std::plus<T>{}) noexcept(NO_EXCEPT) {
        this->resize(std::distance(first, last) + 1);
        std::exclusive_scan(first, last, std::begin(*this), head, op);
        const auto back = std::prev(std::end(*this));
        *back = op(*std::prev(back), *std::prev(last));
    }

    template<class Operaotr = std::minus<T>>
    inline T operator()(size_type left, size_type right, Operaotr op = std::minus<T>{}) const noexcept(NO_EXCEPT) {
        left = _positivize_index(left), right = _positivize_index(right);
        assert(0 <= left and left <= right and right < (size_type)std::size(*this));
        return op((*this)[right], (*this)[left]);
    }
};

template<class I>
explicit accumulation(const I, const I) -> accumulation<typename std::iterator_traits<I>::value_type>;


template<class T, class container = valarray<valarray<T>>, class Operator = std::plus<T>>
struct accumulation_2d : container {
    using size_type = internal::size_t;

  protected:
    inline size_type _positivize_index(const size_type x) const noexcept(NO_EXCEPT) {
        return x < 0 ? std::size(*this) + x : x;
    }

    Operator _op;

  public:
    explicit accumulation_2d() noexcept(NO_EXCEPT) {}

    template<class I>
    explicit accumulation_2d(const I first, const I last, const T head = T{}, const Operator op = std::plus<T>{}) noexcept(NO_EXCEPT) : _op(op) {
        const size_type h = static_cast<size_type>(std::distance(first, last));
        const size_type w = static_cast<size_type>(std::distance(std::begin(*first), std::end(*first)));
        {
            auto row = first;
            this->assign(h+1, head);
            (*this)[0].assign(w+1, head);
            REP(i, h) {
                assert(w == std::distance(std::begin(*row), std::end(*row)));
                (*this)[i+1].assign(w+1, head);
                REP(j, w) (*this)[i+1][j+1] = first[i][j];
                ++row;
            }
        }
        FOR(i, 1, h) FOR(j, w) (*this)[i][j] = op((*this)[i][j], (*this)[i-1][j]);
        FOR(i, h) FOR(j, 1, w) (*this)[i][j] = op((*this)[i][j], (*this)[i][j-1]);
    }

    template<class Rev = std::minus<T>>
    inline T operator()(size_type a, size_type b, size_type c, size_type d, const Rev rev = std::minus<T>{}) const noexcept(NO_EXCEPT) {
        a = _positivize_index(a), b = _positivize_index(b);
        c = _positivize_index(c), d = _positivize_index(d);
        assert(0 <= a and a <= b and b < (size_type)std::size(*this));
        assert(0 <= c and c <= d and d < (size_type)std::size((*this)[0]));
        return this->_op(rev((*this)[b][d], this->_op((*this)[a][d], (*this)[b][c])), (*this)[a][c]);
    }

    template<class Rev = std::minus<T>>
    inline T operator()(const std::pair<size_type,size_type> p, const std::pair<size_type,size_type> q, const Rev rev = std::minus<T>{}) const noexcept(NO_EXCEPT) {
        return this->operator()(p.first, p.second, q.first, q.second, rev);
    }
};

template<class I>
explicit accumulation_2d(const I, const I) ->
    accumulation_2d<
        typename std::iterator_traits<typename lib::internal::iterator_t<typename std::iterator_traits<I>::value_type>>::value_type
    >;


} // namespace lib
/* [iterable/accumulation.hpp] */
#line 78 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [iterable/adjacent_difference.hpp] */
#line 1 "iterable/adjacent_difference.hpp"













namespace lib {


template<class T, class container = vector<T>>
struct adjacent_difference : container {
  public:
    explicit adjacent_difference() noexcept(NO_EXCEPT) {}

    template<class I, class Operator = std::minus<T>>
    explicit adjacent_difference(const I first, const I last, const bool remove_first = true, const Operator op = std::minus<T>{}) noexcept(NO_EXCEPT) {
        this->resize(std::distance(first, last));
        std::adjacent_difference(first, last, begin(*this), op);
        if(remove_first) this->erase(begin(*this));
    }
};

template<class I>
explicit adjacent_difference(const I, const I) -> adjacent_difference<typename std::iterator_traits<I>::value_type>;


} // namespace lib
/* [iterable/adjacent_difference.hpp] */
#line 79 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [iterable/applied.hpp] */
#line 1 "iterable/applied.hpp"











namespace lib {


template<class I, class F, class C = valarray<typename std::iterator_traits<I>::value_type>>
inline auto applied(const I first, const I last, F&& func) noexcept(NO_EXCEPT) {
    C res(first, last);
    func(std::begin(res), std::end(res));
    return res;
}

template<class V, class F, class C = V>
inline auto applied(V v, F&& func) noexcept(NO_EXCEPT) {
    return applied<typename V::iterator,F,C>(std::begin(v), std::end(v), func);
}


template<class I>
inline auto sorted(const I first, const I last) noexcept(NO_EXCEPT) {
    return applied(first, last, std::sort<I>);
}

template<class V>
inline auto sorted(V v) noexcept(NO_EXCEPT) {
    return applied(v, std::sort<typename V::iterator>);
}


template<class I>
inline auto reversed(const I first, const I last) noexcept(NO_EXCEPT) {
    return applied(first, last, std::reverse<I>);
}

template<class V>
inline auto reversed(V v) noexcept(NO_EXCEPT) {
    return applied(v, std::reverse<typename V::iterator>);
}

template<class V>
inline auto unique(V v) noexcept(NO_EXCEPT) {
    std::sort(std::begin(v), std::end(v));
    v.erase(std::unique(std::begin(v), std::end(v)), std::end(v));
    return v;
}


} // namespace lib
/* [iterable/applied.hpp] */
#line 80 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [iterable/compressed.hpp] */
#line 1 "iterable/compressed.hpp"















namespace lib {

template<class T, class container = valarray<internal::size_t>>
struct compressed : container {
    using size_type = internal::size_t;

    std::vector<T> values;

  public:
    explicit compressed() noexcept(NO_EXCEPT) {}
    template<class I> compressed(const I first, const I last) noexcept(NO_EXCEPT) {
        this->values.assign(first, last);
        std::sort(this->values.begin(), this->values.end());
        this->values.erase(std::unique(this->values.begin(), this->values.end()), this->values.end());
        this->resize(std::distance(first, last));
        {
            auto itr = std::begin(*this);
            auto e = first;
            for(; e!=last; ++itr, ++e) {
                *itr = this->rank(*e);
            }
        }
    }

    inline size_type rank_sup() const { return static_cast<size_type>(this->values.size()); }

    inline size_type rank(const T& val) const noexcept(NO_EXCEPT) {
        return static_cast<size_type>(std::distance(this->values.begin(), std::lower_bound(this->values.begin(), this->values.end(), val)));
    }
    inline size_type rank2(const T& val) const noexcept(NO_EXCEPT) {
        return static_cast<size_type>(std::distance(this->values.begin(), std::upper_bound(this->values.begin(), this->values.end(), val))) - 1;
    }

    inline T value(const size_type rank) const noexcept(NO_EXCEPT) { return this->values[rank]; }
    inline T operator()(const internal::size_t val) const noexcept(NO_EXCEPT) { return this->values[val]; }
};

template<class I>
explicit compressed(const I, const I) -> compressed<typename std::iterator_traits<I>::value_type>;


} // namespace lib
/* [iterable/compressed.hpp] */
#line 81 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [iterable/counter.hpp] */
#line 1 "iterable/counter.hpp"










namespace lib {


template<class T, class container = std::map<T,internal::size_t>>
struct counter : container {
    explicit counter() noexcept(NO_EXCEPT) {}
    template<class I> counter(const I first, const I last) noexcept(NO_EXCEPT) {
        for(auto itr=first; itr!=last; ++itr) ++(*this)[*itr];
    }
};

template<class I>
explicit counter(const I, const I) -> counter<typename std::iterator_traits<I>::value_type>;


} // namespace lib
/* [iterable/counter.hpp] */
#line 82 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [iterable/count_inversion.hpp] */
#line 1 "iterable/count_inversion.hpp"








#line 9 "iterable/count_inversion.hpp"






#line 15 "iterable/count_inversion.hpp"




namespace lib {

template<const bool STRICT = true, class T = std::int64_t>
struct inversion {
    template<class I>
    static inline T count(const I first, const I last) noexcept(NO_EXCEPT) {
        const internal::size_t n = std::distance(first, last);
        const auto [ min, max ] = std::minmax_element(first, last);
        const auto m = *max - *min + 1;
        fenwick_tree<actions::range_sum<T>> cnt(m);
        T res = 0;
        {
            internal::size_t i = 0;
            I itr = first;
            for(; i < n; ++i, ++itr) {
                res += cnt.sum(*itr - *min + STRICT, m);
                cnt[*itr - *min]++;
            }
        }
        return res;
    }

    template<class I>
    static inline T count_with_compression(const I first, const I last) noexcept(NO_EXCEPT) {
        compressed<typename std::iterator_traits<I>::value_type> comp(first, last);
        return inversion::count(std::begin(comp), std::end(comp));
    }
};


} // namespace lib
/* [iterable/count_inversion.hpp] */
#line 83 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [iterable/inverse.hpp] */
#line 1 "iterable/inverse.hpp"










namespace lib {

template<class T, class V = std::vector<internal::size_t>, class container = std::map<T,V>>
struct inverse : container {
    explicit inverse() noexcept(NO_EXCEPT) {}
    template<class I> inverse(const I first, const I last) noexcept(NO_EXCEPT) {
        for(auto itr=first; itr!=last; ++itr) (*this)[*itr].push_back(static_cast<typename container::mapped_type::value_type>(std::distance(first,itr)));
    }
};

template<class I>
explicit inverse(const I, const I) -> inverse<typename std::iterator_traits<I>::value_type>;


} // namespace lib
/* [iterable/inverse.hpp] */
#line 84 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [iterable/longest_common_subsequence.hpp] */
#line 1 "iterable/longest_common_subsequence.hpp"















namespace lib {


template<class container = valgrid<internal::size_t>>
struct lcs_sizes : container {
    explicit lcs_sizes() noexcept(NO_EXCEPT) {}

    template<class I>
    explicit lcs_sizes(const I first0, const I last0, const I first1, const I last1) noexcept(NO_EXCEPT)
      : container(static_cast<internal::size_t>(std::distance(first0, last0))+1, static_cast<internal::size_t>(std::distance(first1, last1))+1) {
        internal::size_t pos0 = 0;
        for(auto itr0=first0; itr0!=last0; ++pos0, ++itr0) {
            internal::size_t pos1 = 0;
            for(auto itr1=first1; itr1!=last1; ++pos1, ++itr1) {
                if(*itr0 == *itr1) (*this)(pos0+1, pos1+1) = (*this)(pos0, pos1) + 1;
                else (*this)(pos0+1, pos1+1) = std::max((*this)(pos0+1, pos1), (*this)(pos0, pos1+1));
            }
        }
    }
};


} // namespace lib
/* [iterable/longest_common_subsequence.hpp] */
#line 85 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [iterable/longest_increasing_subsequence.hpp] */
#line 1 "iterable/longest_increasing_subsequence.hpp"















namespace lib {


template<bool STRICT, class T = i64, class container = vector<T>>
struct lis : container {
    using size_type = typename internal::size_t;

    std::vector<size_type> indices;

    explicit lis() noexcept(NO_EXCEPT) {}

    template<class I>
    explicit lis(const I first, const I last) noexcept(NO_EXCEPT) {
        std::vector<size_type> positions(std::distance(first, last), -1);

        size_type pos = 0;
        for(auto itr=first; itr!=last; ++pos, ++itr) {
            typename container::iterator bound;

            if constexpr(STRICT) bound = std::lower_bound(std::begin(*this), std::end(*this), *itr);
            else bound = std::upper_bound(std::begin(*this), std::end(*this), *itr);

            positions[pos] = static_cast<size_type>(std::distance(std::begin(*this), bound));

            if(std::end(*this) == bound) this->emplace_back(*itr);
            else *bound = *itr;
        }

        size_type target = *std::max_element(positions.begin(), positions.end());

        for(size_type i = static_cast<size_type>(positions.size()); --i >= 0;){
            if(positions[i] == target){
                this->operator[](target) = *(first + i);
                this->indices.emplace_back(i);
                --target;
            }
        }

        std::reverse(this->indices.begin(), this->indices.end());
    }
};


} // namespace lib
/* [iterable/longest_increasing_subsequence.hpp] */
#line 86 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 87 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [iterable/run_length_encoding.hpp] */
#line 1 "iterable/run_length_encoding.hpp"













namespace lib {

template<class T, class container = vector<std::pair<T,internal::size_t>>>
struct run_length : container {
    explicit run_length() noexcept(NO_EXCEPT) {}

    template<class I>
    explicit run_length(const I first, const I last) noexcept(NO_EXCEPT) {
        this->clear();
        typename container::value_type::second_type cnt = 0;
        for(I itr=first, prev=itr; itr!=last; ++itr) {
            if(*prev != *itr) this->emplace_back(*prev, cnt), cnt = 0;
            ++cnt;
            prev = itr;
        }
        this->emplace_back(*prev(last), cnt);
    }
};

template<class I>
explicit run_length(const I, const I) -> run_length<typename std::iterator_traits<I>::value_type>;


} // namespace lib
/* [iterable/run_length_encoding.hpp] */
#line 88 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 89 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"


#line 91 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 92 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/boundary_seeker.hpp] */
#line 1 "numeric/boundary_seeker.hpp"













namespace lib {

namespace internal {

namespace boundary_seeker_impl {


template<class T>
struct integal {
  protected:
    std::function<bool(T)> validate;

  public:
    integal(std::function<bool(T)> validate) noexcept(NO_EXCEPT) : validate(validate) {}

    template<const bool REVERSE = false>
    T bound(const T _ok, const T _ng) const noexcept(NO_EXCEPT) {
        T ok = _ok, ng = _ng;
        if constexpr(REVERSE) std::swap(ng, ok);
        while(std::abs(ok-ng) > 1) {
            T mid = ng + (ok - ng) / 2;
            (this->validate(mid) ? ok : ng) = mid;
        }
        return ok;
    }

    template<const bool REVERSE = false>
    T bound(const T ok) const noexcept(NO_EXCEPT) {
        T ng = ok + REVERSE ? -1 : 1;
        while(this->validate(ng)) ng += REVERSE ? -ng : ng;
        return this->bound(ok, ng);
    }

    template<const bool REVERSE = false>
    T bound() const noexcept(NO_EXCEPT) {
        return this->bound<REVERSE>(
            REVERSE ?
            numeric_limits<T>::arithmetic_infinity():
            numeric_limits<T>::arithmetic_negative_infinity()
        );
    }

    template<const bool REVERSE = false>
    T bound_or(const T ok, const T ng, const T proxy) const noexcept(NO_EXCEPT) {
        const T res = this->bound<REVERSE>(ok, ng);
        return this->validate(res) ? res : proxy;
    }

    template<const bool REVERSE = false>
    T bound_or(const T ok, const T proxy) const noexcept(NO_EXCEPT) {
        const T res = this->bound<REVERSE>(ok);
        return this->validate(res) ? res : proxy;
    }

    template<const bool REVERSE = false>
    T bound_or(const T proxy) const noexcept(NO_EXCEPT) {
        const T res = this->bound<REVERSE>();
        return this->validate(res) ? res : proxy;
    }
};

template<class T>
struct floating_point {
  protected:
    std::function<bool(T)> validate;

  public:
    floating_point(std::function<bool(T)> validate) noexcept(NO_EXCEPT) : validate(validate) {}

    template<const bool REVERSE = false, const internal::size_t ITERATIONS = 100'000>
    T bound(const T _ok, const T _ng) const noexcept(NO_EXCEPT) {
        T ok = _ok, ng = _ng;
        if constexpr(REVERSE) std::swap(ng, ok);
        REP(ITERATIONS) {
            T mid = ng + (ok - ng) / 2;
            (this->validate(mid) ? ok : ng) = mid;
        }
        return ok;
    }

    template<const bool REVERSE = false, const internal::size_t ITERATIONS = 100'000>
    T bound(const T ok) const noexcept(NO_EXCEPT) {
        T ng = ok + REVERSE ? -1 : 1;
        while(this->validate(ng)) ng += REVERSE ? -ng : ng;
        return this->bound<false,ITERATIONS>(ok, ng);
    }

    template<const bool REVERSE = false, const internal::size_t ITERATIONS = 100'000>
    T bound() const noexcept(NO_EXCEPT) {
        return this->bound<REVERSE,ITERATIONS>(
            REVERSE ?
            numeric_limits<T>::arithmetic_infinity() :
            numeric_limits<T>::arithmetic_negative_infinity()
        );
    }

    template<const bool REVERSE = false, const internal::size_t ITERATIONS = 100'000>
    T bound_or(const T ok, const T ng, const T proxy) const noexcept(NO_EXCEPT) {
        const T res = this->bound<REVERSE,ITERATIONS>(ok, ng);
        return this->validate(res) ? res : proxy;
    }

    template<const bool REVERSE = false, const internal::size_t ITERATIONS = 100'000>
    T bound_or(const T ok, const T proxy) const noexcept(NO_EXCEPT) {
        const T res = this->bound<REVERSE,ITERATIONS>(ok);
        return this->validate(res) ? res : proxy;
    }

    template<const bool REVERSE = false, const internal::size_t ITERATIONS = 100'000>
    T bound_or(const T proxy) const noexcept(NO_EXCEPT) {
        const T res = this->bound<REVERSE,ITERATIONS>();
        return this->validate(res) ? res : proxy;
    }
};

template<class, bool>
struct seeker {};

template<class T>
struct seeker<T,true> : integal<T> {
    using integal<T>::integal;
};

template<class T>
struct seeker<T,false> : floating_point<T> {
    using floating_point<T>::floating_point;
};


} // namespace boundary_seeker_impl

} // namespace internal


template<class T>
using boundary_seeker = internal::boundary_seeker_impl::seeker<T,std::is_integral_v<T>>;


} // namespace lib
/* [numeric/boundary_seeker.hpp] */
#line 93 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/divisors.hpp] */
#line 1 "numeric/divisors.hpp"








namespace lib {


template<class T> std::vector<T> divisors(const T k) noexcept(NO_EXCEPT) {
    std::vector<T> res;

    for(T i=1; i*i<=k; ++i) {
        if(k%i == 0) {
            res.emplace_back(i);
            if(i*i < k) res.emplace_back(k/i);
        }
    }

    return res;
}


} // namespace lib
/* [numeric/divisors.hpp] */
#line 94 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 95 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/extremum_seeker.hpp] */
#line 1 "numeric/extremum_seeker.hpp"












namespace lib {


template<class Res, class Arg>
struct extremum_seeker {
  protected:
    std::function<Res(Arg)> func;

  public:
    extremum_seeker(std::function<Res(Arg)> func) noexcept(NO_EXCEPT) : func(func) {}

    template<const internal::size_t ITERATIONS = 100'000>
    std::pair<Arg,Arg> arg_min(
        const Arg _low = (std::numeric_limits<Arg>::lowest() / 2) + 1,
        const Arg _high = (std::numeric_limits<Arg>::max() / 2) - 1
    ) const noexcept(NO_EXCEPT) {
        Arg low = _low, high = _high;
        REP(ITERATIONS) {
            const Arg p = low + (high - low) / 3;
            const Arg q = high - (high - low) / 3;
            if(this->func(p) < this->func(q)) {
                high = q;
            }
            else {
                low = p;
            }
        }

        return { low, high };
    }

    template<const internal::size_t ITERATIONS = 100'000>
    std::pair<Arg,Arg> arg_max(
        const Arg _low = (std::numeric_limits<Arg>::lowest() / 2) + 1,
        const Arg _high = (std::numeric_limits<Arg>::max() / 2) - 1
    ) const noexcept(NO_EXCEPT) {
        Arg low = _low, high = _high;
        REP(ITERATIONS) {
            const Arg p = low + (high - low) / 3;
            const Arg q = high - (high - low) / 3;
            if(this->func(p) > this->func(q)) {
                high = q;
            }
            else {
                low = p;
            }
        }

        return { low, high };
    }


    template<const internal::size_t ITERATIONS = 100'000>
    Res min(
        const Arg _low = (std::numeric_limits<Arg>::lowest() / 2) + 1,
        const Arg _high = (std::numeric_limits<Arg>::max() / 2) - 1
    ) const noexcept(NO_EXCEPT) {
        auto [ low, high ] = this->arg_min<ITERATIONS>(_low, _high);
        Res res = std::min(this->func(low), this->func(high));
        FOR(x, low, high) chmin(res, this->func(x));
        return res;
    }

    template<const internal::size_t ITERATIONS = 100'000>
    Res max(
        const Arg _low = (std::numeric_limits<Arg>::lowest() / 2) + 1,
        const Arg _high = (std::numeric_limits<Arg>::max() / 2) - 1
    ) const noexcept(NO_EXCEPT) {
        auto [ low, high ] = this->arg_max<ITERATIONS>(_low, _high);
        Res res = std::max(this->func(low), this->func(high));
        FOR(x, low, high) chmax(res, this->func(x));
        return res;
    }
};


} // namespace lib
/* [numeric/extremum_seeker.hpp] */
#line 96 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/fast_prime.hpp] */
#line 1 "numeric/fast_prime.hpp"


// #include "../inner/inner_math.hpp"
// #include "../misc/rng.hpp"


















namespace lib {

namespace internal {

//Thanks to: https://github.com/NyaanNyaan/library/blob/master/prime/fast-factorize.hpp
namespace fast_factorize_impl {


using value_type = uint64_t;


namespace internal {


// Miller-Rabin primality test
template<typename mint> bool primality_test(const value_type n, const std::initializer_list<value_type> as) noexcept(NO_EXCEPT) {
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wconversion"
    if(static_cast<value_type>(mint::mod()) != n) mint::set_mod(n);
  #pragma GCC diagnostic pop

    value_type d = n-1;

    while(~d & 1) d >>= 1;

    mint e(1), rev(n - 1);
    for(value_type a : as) {
        if(n <= a) break;
        value_type t = d;
        mint y = mint(a).pow(t);
        while(t != n - 1 && y != e && y != rev) y *= y, t *= 2;
        if(y != rev && t % 2 == 0) return false;
    }

    return true;
}


} // namespace internal


bool is_prime(const value_type n) noexcept(NO_EXCEPT) {
    if(~n & 1) return n == 2;
    if(n <= 1) return false;

    if(n < (1UL << 31)) return internal::primality_test<modint>(n, { 2, 7, 61 });
    else return internal::primality_test<modint64>(n, { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 });
}

using int64_t = std::int64_t;

namespace internal {


// Pollard's rho algorithm
template <typename mint, typename T> T find_factor(const T n) noexcept(NO_EXCEPT) {
    if(~n & 1) return 2;
    if(is_prime(n)) return n;

    if(static_cast<value_type>(mint::mod()) != n) mint::set_mod(n);

    mint R, one = 1;

    auto f = [&](mint x) noexcept(NO_EXCEPT) { return x * x + R; };

    static xorshift64 rand(std::random_device{}());
    auto rand_ = [&]() noexcept(NO_EXCEPT) { return rand() % (n - 2) + 2; };

    while(true) {

        mint x, y, ys, q = one;
        R = rand_(), y = rand_();
        T g = 1;
        constexpr int m = 128;

        for(int r = 1; g == 1; r <<= 1) {
            x = y;
            for(int i = 0; i < r; ++i)
                y = f(y);
            for(int k = 0; g == 1 && k < r; k += m) {
                ys = y;
                for(int i = 0; i < m && i < r - k; ++i)
                    q *= x - (y = f(y));
                g = std::gcd(q.val(), n);
            }
        }

        if(g == n) {
            do {
                g = std::gcd((x - (ys = f(ys))).val(), n);
            } while(g == 1);
        }
        if(g != n) return g;
    }

    assert(false);
}


vector<int64_t> factorize(const value_type n) noexcept(NO_EXCEPT) {
    if(n <= 1) return {};

    value_type p;
    if(n <= (1UL << 31)) p = find_factor<modint>(static_cast<std::uint32_t>(n));
    else p = find_factor<modint64,std::uint64_t>(n);

    if(p == n) return { int64_t(p) };

    auto l = internal::factorize(p);
    auto r = internal::factorize(n / p);

    std::copy(std::begin(r), std::end(r), std::back_inserter(l));

    return l;
}


} // namespace internal


vector<int64_t> factorize(const value_type n) noexcept(NO_EXCEPT) {
    auto res = internal::factorize(n);
    std::sort(std::begin(res), std::end(res));
    return res;
}

set<int64_t> prime_factors(const value_type n) noexcept(NO_EXCEPT) {
    auto factors = factorize(n);
    set<int64_t> res(std::begin(factors), std::end(factors));
    return res;
}

std::map<int64_t,int64_t> count_factors(const value_type n) noexcept(NO_EXCEPT) {
    std::map<int64_t,int64_t> mp;
    for(auto &x : internal::factorize(n)) mp[x]++;
    return mp;
}

vector<int64_t> divisors(const value_type n) noexcept(NO_EXCEPT) {
    if(n == 0) return {};

    std::vector<std::pair<int64_t, int64_t>> v;
    for(auto &p : factorize(n)) {
        if(v.empty() || v.back().first != p) {
            v.emplace_back(p, 1);
        } else {
            v.back().second++;
        }
    }

    vector<int64_t> res;
    auto f = [&](auto rc, int i, int64_t x) noexcept(NO_EXCEPT) -> void {
        if(i == static_cast<int>(v.size())) {
            res.push_back(x);
            return;
        }
        for(int j = static_cast<int>(v[i].second);; --j) {
            rc(rc, i + 1, x);
            if(j == 0)
                break;
            x *= v[i].first;
        }
    };

    f(f, 0, 1);
    std::sort(std::begin(res), std::end(res));

    return res;
}


} // namespace fast_factorize_impl

} // namespace internal


using internal::fast_factorize_impl::divisors;
using internal::fast_factorize_impl::factorize;
using internal::fast_factorize_impl::count_factors;
using internal::fast_factorize_impl::prime_factors;
using internal::fast_factorize_impl::is_prime;


} // namespace lib
/* [numeric/fast_prime.hpp] */
#line 97 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/int128.hpp] */
#line 1 "numeric/int128.hpp"



#include <cctype>











template<class C, class S>
std::basic_istream<C,S>& operator>>(std::basic_istream<C,S>& in, lib::i128& v) noexcept(NO_EXCEPT) {
    std::string str; in >> str;
    v = 0;
    bool negative = (str[0] == '-');
    REP(d, std::next(str.begin(), negative), str.end()) {
        assert(std::isdigit(*d));
        v = v * 10 + *d - '0';
    }
    if(negative) v *= -1;
    return in;
}

template<class C, class S>
std::basic_ostream<C,S>& operator<<(std::basic_ostream<C,S>& out, lib::i128 v) noexcept(NO_EXCEPT) {
    if(v == 0) return out << 0;
    if(v < 0) out << '-', v *= -1;
    std::string str;
    while(v > 0) str += static_cast<char>(v%10) + '0', v /= 10;
    std::reverse(str.begin(), str.end());
    return out << str;
}
/* [numeric/int128.hpp] */
#line 98 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/interval_scanner.hpp] */
#line 1 "numeric/interval_scanner.hpp"


/* #expanded [numeric/internal/two-pointer-technique.hpp] */
#line 1 "numeric/internal/two-pointer-technique.hpp"
















namespace lib {

namespace internal {

namespace interval_scanner_impl {


template<class T> using interval = std::pair<T, T>;
template<class T> using intervals = std::vector<std::pair<T, T>>;


template<class T> struct base {
  protected:
    std::function<bool(T)> validate;

  public:
    base(std::function<bool(T)> validate) : validate(validate) {}

    void scan(T,T,T) {
        static_assert(internal::EXCEPTION<T>, "not implemented: scan()");
    }

    void split(const T first, const T last, intervals<T> *intervals) const {
        std::valarray<bool> valid(false, last - first);
        for(auto itr=first,index=0; itr!=last; ++itr, ++index) valid[index] = validate(itr);

        auto can_begin = [&](const T itr) {
            const auto index = itr - first;
            if(itr == first) return valid[index];
            if(itr == last) return false;
            if(not valid[index-1] and valid[index]) return true;
            return false;
        };

        auto is_end = [&](const T itr) {
            const  auto index = itr - first;
            if(itr == first) return false;
            if(itr == last) return valid[index-1];
            if(valid[index-1] and not valid[index]) return true;
            return false;
        };

        {
            intervals->clear();
            T start = first;
            for(auto itr=first; ; ++itr) {
                if(can_begin(itr)) start = itr;
                if(is_end(itr)) intervals->emplace_back(start, itr);
                if(itr == last) break;
            }
        }
    }

    void scan_all(const T first, const T last) const {
        intervals<T> targets;
        this->split(first, last, &targets);
        ITR(start, end, targets) this->scan(first, start, end);
    }
};


} // namespace interval_scanner_impl

} // namespace internal


template<class T>
struct exclusive_interval_scanner : internal::interval_scanner_impl::base<T> {
  protected:
    std::function<void(T)> init;
    std::function<bool(T)> can_expand;
    std::function<void(T)> expand, contract;
    std::function<void(T, T)> apply;

  public:
    using interval = internal::interval_scanner_impl::interval<T>;
    using intervals = internal::interval_scanner_impl::intervals<T>;

    exclusive_interval_scanner(
        std::function<bool(T)> validate,
        std::function<void(T)> init,
        std::function<bool(T)> can_expand,
        std::function<void(T)> expand,
        std::function<void(T)> contract,
        std::function<void(T, T)> apply
    ) : internal::interval_scanner_impl::base<T>(validate), init(init), can_expand(can_expand), expand(expand), contract(contract), apply(apply) {}

    template<const bool FOLLOWING = true>
    void scan(const T start, const T end) const {
        T l_itr=start, r_itr=start;
        while(l_itr < end) {
            if (FOLLOWING and r_itr <= l_itr) {
                r_itr = l_itr+1;
                init(l_itr);
            }
            while(r_itr < end && can_expand(r_itr)) {
                expand(r_itr++);
            }
            apply(l_itr, r_itr);
            contract(l_itr++);
        }
    };

    template<const bool FOLLOWING = true>
    void scan_all(const T first, const T last) const {
        intervals targets;
        this->split(first, last, &targets);
        ITR(start, end, targets) this->scan<FOLLOWING>(start, end);
    }
};


template<class T>
struct inclusive_interval_scanner : internal::interval_scanner_impl::base<T> {
  protected:
    std::function<void()> init;
    std::function<bool()> valid;
    std::function<void(T)> expand, contract;
    std::function<void(T, T)> apply;

  public:
    using interval = internal::interval_scanner_impl::interval<T>;
    using intervals = internal::interval_scanner_impl::intervals<T>;

    inclusive_interval_scanner(
        std::function<bool(T)> validate,
        std::function<void()> init,
        std::function<bool()> valid,
        std::function<void(T)> expand,
        std::function<void(T)> contract,
        std::function<void(T, T)> apply
    ) : internal::interval_scanner_impl::base<T>(validate), init(init), valid(valid), expand(expand), contract(contract), apply(apply) {}

    template<const bool INVERSE = false, const bool FOLLOWING = true, const bool CONFIRMATION = true>
    void scan(const T start, const T end) const {
        T l_itr = start, r_itr = start;
        init();
        while(l_itr < end) {
            if(FOLLOWING and r_itr < l_itr) {
                r_itr = l_itr;
                init();
            }
            if(r_itr < end and (INVERSE ^ valid())) {
                expand(r_itr++);
            }
            else {
                contract(l_itr++);
            }
            if(!CONFIRMATION or valid()) apply(l_itr, r_itr);
        }
    }

    template<const bool INVERSE = false, const bool FOLLOWING = true, const bool CONFIRMATION = true>
    void scan_all(const T first, const T last) const {
        intervals targets;
        this->split(first, last, &targets);
        ITR(start, end, targets) this->scan<INVERSE,FOLLOWING,CONFIRMATION>(start, end);
    }
};


} // namespace lib
/* [numeric/internal/two-pointer-technique.hpp] */
#line 4 "numeric/interval_scanner.hpp"
/* #expanded [numeric/internal/mo.hpp] */
#line 1 "numeric/internal/mo.hpp"

















/* #expanded [utility/hilbert_order.hpp] */
#line 1 "utility/hilbert_order.hpp"




template<class T> T hilbert_order(const T n, T i, T j) {
    T p, q, d = 0;
    for(T t=n>>1; t>0; t>>=1) {
        p = (i&t) > 0, q = (j&t) > 0;
        d += t * t * ((p * 3) ^ q);
        if(q > 0) continue;
        if(p > 0) {
            i = n - i - 1;
            j = n - j - 1;
        }
        std::swap(i, j);
    }
    return d;
}

template<class T> T hilbert_order(const T n,const std::pair<T,T> p) {
    return hilbert_order(n, p.first, p.second);
}
/* [utility/hilbert_order.hpp] */
#line 19 "numeric/internal/mo.hpp"


namespace lib {

template<class R, class EF, class PF, class EB = EF, class PB = PF>
class interval_plannner {
  private:
    using size_t = internal::size_t;

  public:
    const EF& expand_front; const EB& expand_back;
    const PF& contract_front; const PB& contract_back;
    const R& evaluate;

    interval_plannner(
        const EF& expand_front, const EB& expand_back,
        const PF& contract_front, const PB& contract_back,
        const R& evaluate
    ) noexcept(NO_EXCEPT)
      : expand_front(expand_front), expand_back(expand_back),
        contract_front(contract_front), contract_back(contract_back),
        evaluate(evaluate)
    {}

    interval_plannner(const EF& expand, const PF& contract, const R& evaluate) noexcept(NO_EXCEPT)
      : interval_plannner(expand, expand, contract, contract, evaluate)
    {}


    template<class QI, class RI>
    void scan(const QI query_first, const QI query_last, const RI res_first) noexcept(NO_EXCEPT) {
        const size_t q = std::distance(query_first, query_last);

        size_t n = 0;
        for(auto query=query_first; query!=query_last; ++query) {
            chmax(n, std::max(query->first, query->second));
        }
        n = 1 << bit_width<std::make_unsigned_t<size_t>>(n);

        std::vector<i64> orders(q);
        {
            auto query = query_first;
            auto order = orders.begin();
            for(; query!=query_last; ++query, ++order) {
                *order = hilbert_order<i64>(n, *query);
            }
        }

        std::vector<size_t> indices(q); std::iota(ALL(indices), 0);
        std::sort(ALL(indices), [&orders](const size_t i, const size_t j) { return orders[i] < orders[j]; });

        size_t l = 0, r = 0;
        ITR(i, indices) {
            while(l > query_first[i].first) expand_front(--l);
            while(r < query_first[i].second) expand_back(r++);
            while(l < query_first[i].first) contract_front(l++);
            while(r > query_first[i].second) contract_back(--r);
            res_first[i] = evaluate();
        }
    }

    template<class QI>
    auto scan(const QI query_first, const QI query_last) noexcept(NO_EXCEPT) {
        std::vector<std::invoke_result_t<R>> res(std::distance(query_first, query_last));
        this->scan(query_first, query_last, res.begin());
        return res;
    }

    template<class Q>
    auto scan(const Q queries) noexcept(NO_EXCEPT) {
        std::vector<std::invoke_result_t<R>> res(std::distance(std::begin(queries), std::end(queries)));
        this->interval_scan(std::begin(queries), std::end(queries), res.begin());
        return res;
    }
};


} // namespace lib
/* [numeric/internal/mo.hpp] */
#line 5 "numeric/interval_scanner.hpp"
/* [numeric/interval_scanner.hpp] */
#line 99 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/math.hpp] */
#line 1 "numeric/math.hpp"













namespace lib {


namespace binomial_impl {


template<class T>
struct small_binomial {
    using size_type = internal::size_t;
    using value_type = T;

  private:
    std::vector<lib::valarray<T>> _nPr, _nCr;

  public:
    constexpr small_binomial(const size_type max_n) noexcept(NO_EXCEPT) : small_binomial(max_n, max_n) {};
    constexpr small_binomial(const size_type max_n, const size_type max_r) noexcept(NO_EXCEPT) : _nPr(max_n+1, max_r+1), _nCr(max_n+1, max_r/2+1) {
        this->_nPr[0][0] = this->_nCr[0][0] = 1;
        FOR(i, 1, max_n) {
            this->_nPr[i][0] = this->_nCr[i][0] = 1;
            FOR(j, 1, max_r) {
                this->_nPr[i][j] = i * this->_nPr[i-1][j-1];
            }
            FOR(j, 1, max_r/2) {
                this->_nCr[i][j] = this->_nCr[i-1][j-1] + this->_nCr[i-1][j];
            }
        }
    }

    inline constexpr T nPr(const size_type n, size_type r) const noexcept(NO_EXCEPT) {
        assert(0 <= n);
        assert(0 <= r);
        if(n < r) return 0;
        return this->_nPr[n][r];
    }

    inline constexpr T nCr(const size_type n, size_type r) const noexcept(NO_EXCEPT) {
        assert(0 <= n);
        assert(0 <= r);
        if(n < r) return 0;
        if(n < r*2) r = n - r;
        return this->_nCr[n][r];
    }
};

template<class T>
struct small_binomial_prime_mod {
    static_assert(atcoder::internal::is_modint<T>::value);

    using size_type = internal::size_t;
    using value_type = T;

  private:
    lib::valarray<T> _inv, _fact, _fact_inv;

  public:
    small_binomial_prime_mod(const size_type max_n) noexcept(NO_EXCEPT) : _inv(max_n+1), _fact(max_n+1), _fact_inv(max_n+1) {
        this->_fact[0] = this->_fact[1] = 1;
        this->_fact_inv[0] = this->_fact_inv[1] = 1;
        this->_inv[1] = 1;
        const auto mod = T::mod();
        FOR(i, 2, max_n) {
            this->_fact[i] = this->_fact[i-1] * i;
            this->_inv[i] =  -this->_inv[mod%i] * (mod/i);
            this->_fact_inv[i] = this->_fact_inv[i-1] * this->_inv[i];
        }
    }

    T nPr(size_type n, size_type r) const noexcept(NO_EXCEPT) {
        assert(0 <= n);
        assert(0 <= r);
        if(n < r) return 0;
        return this->_fact[n] * this->_fact_inv[n-r];
    }

    T nCr(size_type n, size_type r) const noexcept(NO_EXCEPT) {
        assert(0 <= n);
        assert(0 <= r);
        if(n < r) return 0;
        return this->_fact[n] * this->_fact_inv[r] * this->_fact_inv[n-r];
    }
};

template<class T, class N = std::int64_t>
struct large_binomial_prime_mod {
    static_assert(atcoder::internal::is_modint<T>::value);

    using size_type = internal::size_t;
    using value_type = T;

  private:
    lib::valarray<T> _inv, _fact_inv;

  public:
    large_binomial_prime_mod(const size_type max_r) noexcept(NO_EXCEPT) : _inv(max_r/2+1), _fact_inv(max_r/2+1) {
        this->_fact_inv[0] = this->_fact_inv[1] = 1;
        this->_inv[1] = 1;
        const auto mod = T::mod();
        FOR(i, 2, max_r/2) {
            this->_inv[i] = -this->_inv[mod%i] * (mod/i);
            this->_fact_inv[i] = this->_fact_inv[i-1] * this->_inv[i];
        }
    }

    T nPr(size_type n, size_type r) const noexcept(NO_EXCEPT) {
        assert(0 <= n);
        assert(0 <= r);
        if(n < r) return 0;
        T res = 1;
        FORD(i, n-r+1, n) res *= i;
        return res;
    }

    T nCr(const N n, size_type r) {
        if(n < r*2) r = n-r;
        return this->nPr(n, r) * this->_fact_inv[r];
    }
};

template<class T, class N = std::int64_t>
struct large_binomial_fixed_power_prime_mod {
    static_assert(atcoder::internal::is_modint<T>::value);

    using size_type = internal::size_t;
    using value_type = T;

  private:
    const N _n;
    lib::valarray<T> _nCr, _inv, _fact;

  public:
    inline N n() const noexcept(NO_EXCEPT) { return this->_n; }


    large_binomial_fixed_power_prime_mod(const N n) noexcept(NO_EXCEPT) : large_binomial_fixed_power_prime_mod(n, n) {}
    large_binomial_fixed_power_prime_mod(const N n, const size_type max_r) noexcept(NO_EXCEPT)
      : _n(n), _nCr(max_r/2+1), _inv(max_r/2+1), _fact(max_r+1)
    {
        assert(0 <= n);

        this->_fact[0] = this->_fact[1] = 1;
        this->_inv[1] = 1;
        const auto mod = T::mod();
        FOR(i, 2, max_r/2) {
            this->_inv[i] = -this->_inv[mod%i] * (mod/i);
        }
        FOR(i, 2, max_r) {
            this->_fact[i] = i * this->_fact[i-1];
        }
        this->_nCr[0] = 1;
        FOR(i, 1, max_r/2) {
            this->_nCr[i] = this->_nCr[i-1] * (n-i+1) * this->_inv[i];
        }
    }

    T nPr(size_type r) noexcept(NO_EXCEPT) {
        return this->nCr(r) * this->_fact[r];
    }

    T nCr(size_type r) noexcept(NO_EXCEPT) {
        assert(0 <= r);
        if(this->_n < r) return 0;
        if(this->_n < r*2) r = this->_n-r;
        return this->_nCr[r];
    }

};


} // binomial_impl


using binomial_impl::small_binomial;
using binomial_impl::small_binomial_prime_mod;
using binomial_impl::large_binomial_prime_mod;
using binomial_impl::large_binomial_fixed_power_prime_mod;


} // namespace lib
/* [numeric/math.hpp] */
#line 100 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/matrix.hpp] */
#line 1 "numeric/matrix.hpp"














namespace lib {

namespace internal {

namespace matrix_impl {

template<class T> struct interface : virtual grid_impl::interface<T> {
    // virtual size_t rows() const noexcept(NO_EXCEPT)= 0;
    // virtual size_t cols() const noexcept(NO_EXCEPT)= 0;

    // virtual size_t square() const noexcept(NO_EXCEPT)= 0;
};

}

template<class T, class base>
struct matrix_core : base, virtual matrix_impl::interface<T> {
    using base::base;

    static inline matrix_core identity(const size_t n, const T &&val = { 1 }) noexcept(NO_EXCEPT) {
        matrix_core res(n);
        REP(i, n) res(i, i) = val;
        return res;
    }

    inline size_t rows() const noexcept(NO_EXCEPT) /*override*/ { return this->height(); }
    inline size_t cols() const noexcept(NO_EXCEPT) /*override*/ { return this->width(); }

    inline size_t square() const noexcept(NO_EXCEPT) /*override*/ { return this->rows() == this->cols(); }

    template<class U> inline matrix_core& operator+=(const U rhs) noexcept(NO_EXCEPT) {
        REP(i, this->rows()) REP(j, this->cols()) (*this)(i, j) += rhs;
        return *this;
    }
    template<class ...U> inline matrix_core& operator+=(const matrix_core<U...> rhs) noexcept(NO_EXCEPT) {
        REP(i, this->rows()) REP(j, this->cols()) (*this)(i, j) += rhs(i, j);
        return *this;
    }
    template<class U> inline matrix_core operator+(const U rhs) const noexcept(NO_EXCEPT) {
        return matrix_core(*this) += rhs;
    }

    template<class U> inline matrix_core& operator-=(const U rhs) noexcept(NO_EXCEPT) {
        REP(i, this->rows()) REP(j, this->cols()) (*this)(i, j) -= rhs;
        return *this;
    }
    template<class ...U> inline matrix_core& operator-=(const matrix_core<U...> rhs) noexcept(NO_EXCEPT) {
        REP(i, this->rows()) REP(j, this->cols()) (*this)(i, j) -= rhs(i, j);
        return *this;
    }
    template<class U> inline matrix_core operator-(const U rhs) const noexcept(NO_EXCEPT) {
        return matrix_core(*this) -= rhs;
    }

    template<class ...U> inline matrix_core operator*(const matrix_core<U...> rhs) noexcept(NO_EXCEPT) {
        assert(this->cols() == rhs.rows());
        matrix_core res(this->rows(), rhs.cols());
        REP(i, this->rows()) REP(j, rhs.cols()) REP(k, this->cols()) {
            res(i, j) += (*this)(i, k) * rhs(k, j);
        }
        return res;
    }
    template<class U> inline matrix_core operator*(const U rhs) noexcept(NO_EXCEPT) {
        matrix_core res(*this);
        REP(i, res.rows()) REP(j, res.cols()) res(i, j) *= rhs;
        return res;
    }
    template<class U> inline matrix_core& operator*=(const U rhs) noexcept(NO_EXCEPT) {
        matrix_core res = *this * rhs;
        this->assign(res);
        return *this;
    }

    template<class U> inline matrix_core& operator/=(const U rhs) noexcept(NO_EXCEPT) {
        REP(i, this->rows()) REP(j, this->cols()) (*this)(i, j) /= rhs;
        return *this;
    }
    template<class U> inline matrix_core operator/(const U rhs) const noexcept(NO_EXCEPT) {
        return matrix_core(*this) /= rhs;
    }

    template<class U> inline matrix_core& operator%=(const U rhs) noexcept(NO_EXCEPT) {
        REP(i, this->rows()) REP(j, this->cols()) (*this)(i, j) %= rhs;
        return *this;
    }
    template<class U> inline matrix_core operator%(const U rhs) const noexcept(NO_EXCEPT) {
        return matrix_core(*this) %= rhs;
    }

    inline matrix_core pow(ll p) noexcept(NO_EXCEPT) {
        assert(this->square());
        matrix_core x = *this, res = matrix_core::Identity(this->rows());
        while(p > 0) {
            if(p & 1) res *= x;
            x *= x;
            p >>= 1;
        }
        return res;
    }
};

} // namespace internal

template<class T, class base = grid<T>>
using matrix = internal::matrix_core<T,base>;

template<class T>
using valmatrix = internal::matrix_core<T,unfolded_grid<T,valarray<T>>>;

template<class T>
using unfolded_matrix = internal::matrix_core<T,unfolded_grid<T>>;

} // namespace lib
/* [numeric/matrix.hpp] */
#line 101 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 102 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 103 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/prime_sieve.hpp] */
#line 1 "numeric/prime_sieve.hpp"









namespace lib {


template<class container = std::vector<bool>> struct prime_flags : container {
    prime_flags(const internal::size_t max) noexcept(NO_EXCEPT) : container(max+1, true) {
        (*this)[0] = (*this)[1] = false;
        for(internal::size_t p=2; p*p<=max; p++) if((*this)[p]) {
            for(internal::size_t i=p*p; i<=max; i+=p) (*this)[i] = false;
        }
    }
};

template<class T, class container = std::vector<T>> struct prime_sieve : container {
  protected:
    std::vector<bool> is_prime;

  public:
    prime_sieve() noexcept(NO_EXCEPT) {}
    prime_sieve(const T max) noexcept(NO_EXCEPT) : is_prime(max+1, true) {
        is_prime[0] = is_prime[1] = false;
        FOR(p, T{2}, max) {
            if(is_prime[p]) {
                for(T i = mul_overflow(p,p).value_or(max+1); i<=max; i+=p) is_prime[i] = false;
                this->emplace_back(p);
            }
        }
    }
    inline bool operator()(const T index) const noexcept(NO_EXCEPT) {
        return is_prime[index];
    }
};


} // namespace lib
/* [numeric/prime_sieve.hpp] */
#line 104 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/quotient_enumerator.hpp] */
#line 1 "numeric/quotient_enumerator.hpp"













namespace lib {


template<class T, bool CEIL = false>
struct quotient_enumerator {
    using value_type = std::tuple<T,T,T>; // (q, l, r)
    using size_type = T;

    T n = 0;

  private:
    T _n = 0;
    mutable size_type _size = -1;

  protected:
    using iterator_interface = internal::bidirectional_iterator_interface<const value_type>;

  public:
    // Enumerate tuple of (q, l, r), which means (floor/ceil)(n/k) == q (l <= k <= r).
    quotient_enumerator(const T n) noexcept(NO_EXCEPT) : n(n), _n(n - CEIL) { assert(n > 0); }

    struct iterator;
    using const_iterator = iterator;

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this->_n, 1); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this->_n, this->n + 1); }

    inline auto rbegin() noexcept(NO_EXCEPT) { return std::make_reverse_iterator(this->end()); }
    inline auto rend() noexcept(NO_EXCEPT) { return std::make_reverse_iterator(this->begin()); }

    inline size_type size() const noexcept(NO_EXCEPT) {
        if(this->_size < 0) {
            size_type r = lib::sqrt_floor(this->_n);
            this->_size = 2 * r - (this->_n < r * (r + 1)) + CEIL;
        }
        return this->_size;
    }

    struct iterator : virtual iterator_interface {
        using reference = value_type;

      protected:
        T _n = 0;
        T _q = 0, _l = 0, _r = 0;

        void _set_l(const T l) noexcept(NO_EXCEPT) {
            this->_l = l, this->_q = this->_n / l;
            if(this->_q == 0) {
                if(CEIL) {
                    if(l == this->_n + 1) this->_r = l;
                }
                return;
            }
            this->_r = this->_n / this->_q;
        }
        void _set_r(const T r) noexcept(NO_EXCEPT) {
            this->_r = r, this->_q = this->_n / r;
            this->_l = this->_n / (this->_q + 1) + 1;
        }

      public:
        iterator() noexcept(NO_EXCEPT) {}
        iterator(const T n, const T l) noexcept(NO_EXCEPT) : _n(n) { this->_set_l(l); }


        friend inline bool operator==(const iterator& lhs, const iterator& rhs) noexcept(NO_EXCEPT) { return lhs._l == rhs._l; };
        friend inline bool operator!=(const iterator& lhs, const iterator& rhs) noexcept(NO_EXCEPT) { return lhs._l != rhs._l; };

        inline value_type operator*() const noexcept(NO_EXCEPT) { return { this->_q + CEIL, this->_l, this->_r }; }

        inline iterator& operator++() noexcept(NO_EXCEPT) { this->_set_l(this->_r + 1); return *this; }
        inline iterator operator++(int) noexcept(NO_EXCEPT) { const auto res = *this; this->_set_l(this->_r + 1); return res; }

        inline iterator& operator--() noexcept(NO_EXCEPT) { this->_set_r(this->_l - 1); return *this; }
        inline iterator operator--(int) noexcept(NO_EXCEPT) { const auto res = *this; this->_set_r(this->_l - 1); return res; }
    };

};


} // namespace lib
/* [numeric/quotient_enumerator.hpp] */
#line 105 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [numeric/rational.hpp] */
#line 1 "numeric/rational.hpp"


// #include <boost/rational.hpp>
/* [numeric/rational.hpp] */
#line 106 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [random/generator.hpp] */
#line 1 "random/generator.hpp"








namespace lib {


template<class Engine> struct random_engine {
    using result_type = typename Engine::result_type;
    using signed_result_type = typename std::make_signed_t<result_type>;

  private:
    mutable Engine engine;

  public:
    static constexpr result_type MIN = Engine::min();
    static constexpr result_type MAX = Engine::max();

    static constexpr result_type min() noexcept(NO_EXCEPT) { return MIN; }
    static constexpr result_type max() noexcept(NO_EXCEPT) { return MAX; }

    constexpr random_engine(unsigned long seed = 3141592653UL) noexcept(NO_EXCEPT) { this->engine.seed(seed); };

    inline result_type operator()() const noexcept(NO_EXCEPT) {
        return this->engine();
    }

    inline result_type operator()(result_type max) const noexcept(NO_EXCEPT) {
        if(max == 0) return 0;
        return (*this)() % max;
    }
    inline signed_result_type operator()(signed_result_type min, signed_result_type max) const noexcept(NO_EXCEPT) {
        assert(min <= max);
        return min + (*this)(max - min);
    };

    template<class T = double> inline T real() const noexcept(NO_EXCEPT) {
        const T v = static_cast<T>((this->engine() + 0.5) / (1.0 + this->max()));
        return static_cast<T>((this->random() + v) / (1.0 + this->max()));
    }
};


} // namespace lib
/* [random/generator.hpp] */
#line 108 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 109 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"


#line 111 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [snippet/fast_io.hpp] */
#line 1 "snippet/fast_io.hpp"








#ifdef __GNUC__

__attribute__((constructor)) inline void fast_io() noexcept(NO_EXCEPT) { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }

#else

inline void fast_io() noexcept(NO_EXCEPT) { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }

#endif
/* [snippet/fast_io.hpp] */
#line 112 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 113 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [snippet/using.hpp] */
#line 1 "snippet/using.hpp"









#include <bitset>

#include <stack>

// #include <boost/dynamic_bitset.hpp>

/* #expanded [utilities.hpp] */
#line 1 "utilities.hpp"


/* #expanded [adapter/io.hpp] */
#line 1 "adapter/io.hpp"



#line 4 "adapter/io.hpp"

#line 5 "adapter/io.hpp"

lib::input_adapter _input;
lib::output_adapter _print;

#define input _input
#define print _print
/* [adapter/io.hpp] */
#line 4 "utilities.hpp"


#line 6 "utilities.hpp"


#line 8 "utilities.hpp"



#line 11 "utilities.hpp"


#line 13 "utilities.hpp"

/* #expanded [geometry/basic.hpp] */
#line 1 "geometry/basic.hpp"


/* #expanded [geometry/point.hpp] */
#line 1 "geometry/point.hpp"



#include <complex>







namespace lib {

template <class T> struct point : protected std::pair<T,T> {
  public:
    constexpr point() {}
    constexpr point(const T& x, const T& y) noexcept(NO_EXCEPT) : std::pair<T,T>(x, y) {}
    template<class U> constexpr point(const point<U>& p) noexcept(NO_EXCEPT) : point(p.x(), p.y()) {};
    template<class U> constexpr point(point<U>&& p) noexcept(NO_EXCEPT) : point(p.x(), p.y()) {};

    template<class U>
    constexpr point& operator=(const point<U>& p) & noexcept(NO_EXCEPT) { this->x() = p.x(),this->y() = p.y(); return *this; };
    template<class U>
    constexpr point& operator=(point<U>&& p) && noexcept(NO_EXCEPT) { this->x() = p.x(), this->y() = p.y(); return *this; };


    inline T& x() noexcept(NO_EXCEPT) { return this->first; }
    inline T& y() noexcept(NO_EXCEPT) { return this->second; }
    inline const T& x() const noexcept(NO_EXCEPT) { return this->first; }
    inline const T& y() const noexcept(NO_EXCEPT) { return this->second; }

    inline constexpr point& operator+=(const point& v) noexcept(NO_EXCEPT) { this->x() += v.x(), this->y() += v.y(); return *this; }
    inline constexpr point& operator-=(const point& v) noexcept(NO_EXCEPT) { this->x() -= v.x(), this->y() -= v.y(); return *this; }

    friend inline constexpr point operator+(point a, const point& b) noexcept(NO_EXCEPT) { return a += b; }
    friend inline constexpr point operator-(point a, const point& b) noexcept(NO_EXCEPT) { return a -= b; }
    friend inline constexpr point operator*(const point& a, const point& b) noexcept(NO_EXCEPT) { return a.x() * b.x() + a.y() * b.y(); }

    friend inline constexpr bool operator==(const point& a, const point& b) noexcept(NO_EXCEPT) { return a.x() == b.x() && a.y() == b.y(); }
    friend inline constexpr bool operator!=(const point& a, const point& b) noexcept(NO_EXCEPT) { return a.x() != b.x() or a.y() != b.y(); }

    friend inline constexpr bool operator<(const point& a, const point& b) noexcept(NO_EXCEPT) { return a.x() != b.x() ? a.x() < b.x() : a.y() < b.y(); }
    friend inline constexpr bool operator>(const point& a, const point& b) noexcept(NO_EXCEPT) { return a.x() != b.x() ? a.x() > b.x() : a.y() > b.y(); }
    friend inline constexpr bool operator<=(const point& a, const point& b) noexcept(NO_EXCEPT) { return !(a > b); }
    friend inline constexpr bool operator>=(const point& a, const point& b) noexcept(NO_EXCEPT) { return !(a < b); }

    std::pair<T,T> _debug() const noexcept(NO_EXCEPT) { return { this->x(), this->y() }; }
};


} // namespace lib


template<class T>
inline constexpr T std::abs(const lib::point<T>& v) {
    T x = v.x(), y = v.y(), n = std::max(std::abs(x), std::abs(y));
    if(0 <= n and n <= 0) return 0;
    x /= n, y /= n;
    return n * std::sqrt(x * x + y * y);
}

namespace lib {


template<class U, class T>
inline constexpr U distance(const point<T>& a, const point<T>& b) {
    return std::abs(point<U>(a - b));
}

template<class T>
inline constexpr T cross(point<T> a, point<T> b, const point<T>& o = {}) {
    a -= o, b -= o;
    return a.x() * b.y() - a.y() * b.x();
}


} // namespace lib


template<class T, class C, class S>
std::basic_istream<C,S>& operator>>(std::basic_istream<C,S>& in, lib::point<T>& v) {
    T x, y; in >> x >> y;
    v = { x, y };
    return in;
}
/* [geometry/point.hpp] */
#line 4 "geometry/basic.hpp"
/* [geometry/basic.hpp] */
#line 15 "utilities.hpp"


/* #expanded [multi_container.hpp] */
#line 1 "multi_container.hpp"














namespace lib {

namespace internal {

namespace multi_container_impl {


template<class container> struct base : container {
    using container::container;

    protected:
    inline void _validate_index(__attribute__ ((unused)) const internal::size_t index) const noexcept(NO_EXCEPT) {
        assert(0 <= index and index < (internal::size_t)this->size());
    }
    inline internal::size_t _positivize_index(const internal::size_t x) const noexcept(NO_EXCEPT) {
        return x < 0 ? this->size() + x : x;
    }
};


} // namespace multi_contatiner_impl

} // namespace internal


template<class T, const unsigned int RANK, template<class...> class container = valarray>
struct multi_container : internal::multi_container_impl::base<container<multi_container<T,RANK-1,container>>> {
    using internal::multi_container_impl::base<container<multi_container<T,RANK-1,container>>>::base;

    template<class Head, class... Tail>
    multi_container(const Head head, const Tail... tail) noexcept(NO_EXCEPT)
    : internal::multi_container_impl::base<container<multi_container<T,RANK-1,container>>>(head, multi_container<T,RANK-1,container>(tail...)) {
        static_assert(std::is_integral_v<Head>, "size must be integral");
    }

    template<class Head, class... Tail> T& operator()(const Head _head, const Tail... tail) noexcept(NO_EXCEPT) {
        static_assert(std::is_integral_v<Head>, "index must be integral");

        const internal::size_t head = this->_positivize_index(_head);
        this->_validate_index(head);
        return (*this)[head](tail...);
    }

    template<class Head, class... Tail> const T& operator()(const Head _head, const Tail... tail) const noexcept(NO_EXCEPT) {
        static_assert(std::is_integral_v<Head>, "index must be integral");

        const internal::size_t head = this->_positivize_index(_head);
        this->_validate_index(head);
        return (*this)[head](tail...);
    }
};

template<class T, template<class...> class container>
struct multi_container<T,1,container> : internal::multi_container_impl::base<container<T>> {
    using internal::multi_container_impl::base<container<T>>::base;

    template<class... Args> multi_container(const Args&... args) noexcept(NO_EXCEPT) : internal::multi_container_impl::base<container<T>>(args...) {}

    T& operator()(const internal::size_t _index) noexcept(NO_EXCEPT) {
        const internal::size_t index = this->_positivize_index(_index);
        this->_validate_index(index);
        return (*this)[index];
    }
    const T& operator()(const internal::size_t _index) const noexcept(NO_EXCEPT) {
        const internal::size_t index = this->_positivize_index(_index);
        this->_validate_index(index);
        return (*this)[index];
    }
};


// template<class T, const unsigned int RANK, class base = std::vector<T>>
// struct UnfoldedMultiContainer : base {
//   protected:
//     std::array<size_t,RANK> size_list;

//   public:
//     using base::base;

//     template<class... Args>
//     UnfoldedMultiContainer(const Args... _args) {
//         const std::initializer_list<size_t> args { _args... };

//         dev_debug(args.size() == RANK or args.size() == RANK + 1);

//         size_t length = 0;
//         REP(r, RANK) length += size_list[r] = args[r];

//         if(args.size() == RANK+1) this->assign(length, args.back());
//         else this->assign(length, T{});
//     }

//     template<class... Args> T& operator()(Args... args) {
//         const std::initializer_list<size_t> args { _args... };
//         reverse(ALL(args));

//         assert(args.size() == RANK);

//         size_t curr = 0;
//         ITR(r, RANK) {
//             curr += arg[r];
//             curr += arg[r] * size_list[];
//         }
//     }

//     template<class Head, class... Tail> const T& operator()(Head head, Tail... tail) const noexcept(NO_EXCEPT) {
//     }
// };


template<class T, template<class...> class container>
struct multi_container<T,0,container> {
    static_assert(internal::EXCEPTION<T>, "invalid rank: 0, should be 1 or more");
};

// template<class T, class container>
// struct UnfoldedMultiContainer<T,0,container> {
//     static_assert(internal::EXCEPTION<T>, "invalid rank: 0, should be 1 or more");
// };

} // namespace lib
/* [multi_container.hpp] */
#line 18 "utilities.hpp"


/* #expanded [string.hpp] */
#line 1 "string.hpp"









namespace lib {


template<class I, class Res = std::string>
Res to_lower(const I first, const I last) noexcept(NO_EXCEPT) {
    Res res;
    res.reserve(std::distance(first, last));
    std::transform(first, last, std::back_inserter(res), ::tolower);
    return res;
}

template<class I, class Res = std::string>
Res to_uppwer(const I first, const I last) noexcept(NO_EXCEPT) {
    Res res;
    res.reserve(std::distance(first, last));
    std::transform(first, last, std::back_inserter(res), ::toupper);
    return res;
}


template<class Res = std::string>
Res to_lower(const std::string str) noexcept(NO_EXCEPT) {
    return to_lower<std::string::const_iterator,Res>(std::begin(str), std::end(str));
}

template<class Res = std::string>
Res to_uppwer(const std::string str) noexcept(NO_EXCEPT) {
    return to_uppwer<std::string::const_iterator,Res>(std::begin(str), std::end(str));
}


} // namespace lib
/* [string.hpp] */
#line 21 "utilities.hpp"
/* #expanded [views.hpp] */
#line 1 "views.hpp"


/* #expanded [view/sequence.hpp] */
#line 1 "view/sequence.hpp"













namespace lib {


template<class Ref>
struct view : internal::view_impl::base {
    using size_type = internal::size_t;
    using value_type = typename Ref::value_type;

    using transposer = std::function<size_type(const size_type)>;

  protected:
    transposer _transposer = [&](const size_type pos) { return pos; };

    Ref* _ref;
    size_type _pos = 0, _taken = 0;

  private:
    __attribute__((always_inline)) inline void _validate() const noexcept(NO_EXCEPT) {
        assert(0 <= this->_pos && this->_pos < static_cast<size_type>(this->_ref->size()));
        assert(0 <= this->_taken);
        assert(this->_pos + this->_taken <= static_cast<size_type>(this->_ref->size()));
    }

  public:
    view(Ref *const ref) noexcept(NO_EXCEPT) : _ref(ref) {}

    inline view& reset(Ref *const ref) noexcept(NO_EXCEPT) { this->_ref = ref; return *this; }

    inline Ref* operator->() const noexcept { return this->_ref; }
    inline Ref& operator*() const noexcept { return *this->_ref; }

    inline size_type size() const noexcept(NO_EXCEPT) { return this->_taken; }

    // inline auto begin() const noexcept(NO_EXCEPT) { return std::next(std::begin(*this->_ref), this->_pos); }
    // inline auto end() const noexcept(NO_EXCEPT) { return std::next(this->begin(), this->_taken); }

    inline view& drop(const size_type pos = 0) noexcept(NO_EXCEPT) { this->_pos = pos; this->_validate(); return *this; }
    inline view& shift(const size_type count = 1) noexcept(NO_EXCEPT) { this->_pos += count; this->_validate(); return *this; };

    inline view& take(const size_type count) noexcept(NO_EXCEPT) { this->_taken = count; this->_validate(); return *this; }
    inline view& take() noexcept(NO_EXCEPT) { this->_taken = std::size(*this->_ref); return *this; }

    inline view& transpose(const transposer& f) noexcept { this->_transposer = f; return *this; }


    inline value_type& operator[](const size_type count) noexcept {
        this->_validate();
        return std::next(std::begin(*this->_ref), this->_pos)[this->_transposer(count)];
    }
    inline const value_type& operator[](const size_type count) const noexcept {
        this->_validate();
        return std::next(std::begin(*this->_ref), this->_pos)[this->_transposer(count)];
    }


  protected:
    using iterator_interface = internal::container_iterator_interface<value_type,view>;

  public:
    struct iterator : virtual iterator_interface {
        iterator(const view *const ref, const size_type pos) noexcept(NO_EXCEPT) : iterator_interface(ref, pos) {}

        inline value_type operator*() const noexcept(NO_EXCEPT) { return this->ref()->operator[](this->pos()); }
        inline value_type operator[](const typename iterator_interface::difference_type count) const noexcept(NO_EXCEPT) { return *(*this + count); }
    };

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this, 0); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this, this->size()); }
};


} // namespace lib
/* [view/sequence.hpp] */
#line 4 "views.hpp"
/* #expanded [view/cyclic.hpp] */
#line 1 "view/cyclic.hpp"













namespace lib {


template<class Ref, class Size = std::make_signed_t<std::size_t>>
struct cyclic_view : internal::view_impl::base {
    using size_type = Size;
    using value_type = typename Ref::value_type;

    using transposer = std::function<size_type(const size_type)>;

  protected:
    transposer _transposer = [&](const size_type pos) { return pos; };

    Ref* _ref;
    size_type _pos = 0, _taken;

  private:
    template<class T> __attribute__((always_inline)) inline T _mod(const T v) const noexcept(NO_EXCEPT) {
        return (v + this->size()) % this->size();
    }

  public:
    cyclic_view(Ref *const ref) noexcept(NO_EXCEPT) : _ref(ref), _taken(std::size(*ref)) {}

    inline cyclic_view& reset(Ref *const ref) noexcept(NO_EXCEPT) { this->_ref = ref, this->_taken = std::size(*ref); return *this; }

    inline Ref* operator->() const noexcept { return this->_ref; }
    inline Ref& operator*() const noexcept { return *this->_ref; }

    inline size_type size() const noexcept(NO_EXCEPT) { return this->_taken; }

    inline cyclic_view& drop(const size_type pos = 0) noexcept(NO_EXCEPT) { this->_pos = pos; return *this; }
    inline cyclic_view& shift(const size_type count = 1) noexcept(NO_EXCEPT) { this->_pos += count; return *this; };

    inline cyclic_view& take(const size_type count) noexcept(NO_EXCEPT) { this->_taken = count; return *this; }
    inline cyclic_view& take() noexcept(NO_EXCEPT) { this->_taken = std::size(*this->_ref); return *this; }

    inline cyclic_view& transpose(const transposer& f) noexcept { this->_transposer = f; return *this; }


    inline value_type& operator[](const size_type count) noexcept {
        return this->_ref->operator[](this->_mod(this->_pos + this->_transposer(count)));
    }
    inline const value_type& operator[](const size_type count) const noexcept {
        return this->_ref->operator[](this->_mod(this->_pos + this->_transposer(count)));
    }


  protected:
    using iterator_interface = internal::container_iterator_interface<value_type,cyclic_view>;

  public:
    struct iterator : virtual iterator_interface {
        iterator(const cyclic_view *const ref, const size_type pos) noexcept(NO_EXCEPT) : iterator_interface(ref, pos) {}

        inline value_type operator*() const noexcept(NO_EXCEPT) { return this->ref()->operator[](this->pos()); }
        inline value_type operator[](const typename iterator_interface::difference_type count) const noexcept(NO_EXCEPT) { return *(*this + count); }
    };

    inline iterator begin() const noexcept(NO_EXCEPT) { return iterator(this, 0); }
    inline iterator end() const noexcept(NO_EXCEPT) { return iterator(this, this->size()); }
};


} // namespace lib
/* [view/cyclic.hpp] */
#line 5 "views.hpp"
/* #expanded [view/multi.hpp] */
#line 1 "view/multi.hpp"














namespace lib {



template<class Ref, internal::size_t D>
struct multi_view : internal::view_impl::base {
    using size_type = internal::size_t;

    using transposer = std::function<std::vector<size_type>(const std::initializer_list<size_type>&)>;

  protected:
    transposer _transposer = [&](const std::initializer_list<size_type>& pos) { return std::vector<size_type>(pos.begin(), pos.end()); };

    Ref* _ref;
    size_type _pos[D] = {};

    template<class R, class I, size_type d = 0> inline auto& _access(
        R *const r,
        const I p
    ) noexcept(NO_EXCEPT) {
        if constexpr(d == D) {
            return *r;
        }
        else {
            size_type index = this->_pos[d] + *std::next(p, d);

            assert(0 <= index && index < static_cast<size_type>(std::size(*r)));

            using nR = std::remove_reference_t<decltype(r->operator[](0))>;
            return multi_view::_access<nR,I,d+1>(&r->operator[](index), p);
        }
    }

  public:
    multi_view(Ref *const ref) noexcept(NO_EXCEPT) : _ref(ref) {}

    inline multi_view& reset(Ref *const ref) noexcept(NO_EXCEPT) { this->_ref = ref; return *this; }

    inline Ref* operator->() const noexcept(NO_EXCEPT) { return this->_ref; }
    inline Ref& operator*() const noexcept(NO_EXCEPT) { return *this->_ref; }

    inline size_type size() const noexcept(NO_EXCEPT) { return std::size(*this->_ref); }

    inline multi_view& drop(const std::initializer_list<size_type> pos) noexcept(NO_EXCEPT) {
        assert(pos.size() == std::size(this->_pos));
        for(auto a=pos.begin(),b=std::begin(this->_pos); a != pos.end(); ++a, ++b) *b = *a;
        return *this;
    }
    template<class... Pos> inline multi_view& drop(const Pos... pos) noexcept(NO_EXCEPT) { return this->drop({ pos... }); }
    inline multi_view& drop() noexcept(NO_EXCEPT) { std::memset(this->_pos, 0, sizeof(this->_pos)); return *this; }

    inline const multi_view& transpose(const transposer& f) noexcept(NO_EXCEPT) { this->_transposer = f; return *this; }


    inline auto& operator[](const std::initializer_list<size_type> pos_) noexcept(NO_EXCEPT) {
        const auto pos = this->_transposer(pos_);
        return this->_access(this->_ref, pos.begin());
    }
    inline const auto& operator[](std::initializer_list<size_type> pos_) const noexcept(NO_EXCEPT) {
        const auto pos = this->_transposer(pos_);
        return this->_access(this->_ref, pos.begin());
    }

    template<class... Pos> inline auto& operator()(const Pos... pos) noexcept(NO_EXCEPT) { return this->operator[]({ pos... }); }
    template<class... Pos> inline const auto& operator()(const Pos... pos) const noexcept(NO_EXCEPT) { return this->operator[]({ pos... }); }
};

} // namespace lib
/* [view/multi.hpp] */
#line 6 "views.hpp"
/* #expanded [view/2d.hpp] */
#line 1 "view/2d.hpp"














namespace lib {


template<class Ref> struct view_2d : internal::view_impl::base {
    using size_type = internal::size_t;

    using transposer = std::function<std::pair<size_type,size_type>(const size_type, const size_type)>;

  protected:
    transposer _transposer = [&](const size_type i, const size_type j) { return { i, j }; };

    Ref* _ref;
    size_type _pos0, _pos1;

  public:
    view_2d(Ref *const ref) noexcept(NO_EXCEPT) : _ref(ref) {}

    inline view_2d& reset(Ref *const ref) { this->_ref = ref; return *this; }

    inline Ref* operator->() const noexcept(NO_EXCEPT) { return this->_ref; }
    inline Ref& operator*() const noexcept(NO_EXCEPT) { return *this->_ref; }

    inline size_type size() const noexcept(NO_EXCEPT) { return std::size(*this->_ref); }
    inline size_type height() const noexcept(NO_EXCEPT) { return std::size(*this->_ref); }
    inline size_type width() const noexcept(NO_EXCEPT) { return std::size(*this->_ref->begin()); }

    inline view_2d& drop(const std::initializer_list<size_type> pos) noexcept(NO_EXCEPT) {
        assert(pos.size() == std::size(this->_pos));
        for(auto a=pos.begin(),b=std::begin(this->_pos); a != pos.end(); ++a, ++b) *b = *a;
        return *this;
    }
    template<class... Pos> inline view_2d& drop(const Pos... pos) noexcept(NO_EXCEPT) { return this->drop({ pos... }); }
    inline view_2d& drop() noexcept(NO_EXCEPT) { std::memset(this->_pos, 0, sizeof(this->_pos)); return *this; }

    inline const view_2d& transpose(const transposer& f) noexcept(NO_EXCEPT) { this->_transposer = f; return *this; }

    inline auto& operator()(const size_type i, const size_type j) noexcept(NO_EXCEPT) { return this->operator[]({ i, j }); }
    inline const auto& operator()(const size_type i, const size_type j) const noexcept(NO_EXCEPT) { return this->operator[]({ i, j }); }

    inline auto& operator[](std::pair<size_type,size_type> pos) noexcept(NO_EXCEPT) {
        pos = this->_transposer(pos);
        return this->_ref->operator[](pos.first)[pos.second];
    }
    inline const auto& operator[](std::pair<size_type,size_type> pos) const noexcept(NO_EXCEPT) {
        pos = this->_transposer(pos);
        return this->_ref->operator[](pos.first)[pos.second];
    }
};


} // namespace lib
/* [view/2d.hpp] */
#line 7 "views.hpp"
/* #expanded [view/zip.hpp] */
#line 1 "view/zip.hpp"


















namespace lib {


template<class...> struct zip_view;

namespace internal {

namespace view_impl {


template<class,class...> struct zip_iterator;

template<class View, class... Iterators>
struct zip_iterator : iterator_interface<std::tuple<typename std::iterator_traits<Iterators>::value_type...>>, iterator_base {
    using difference_type = size_t;
    using iterator_category = most_primitive_iterator_tag<typename std::iterator_traits<Iterators>::iterator_category...>;

    friend View;

  protected:
    using indices = std::make_index_sequence<sizeof...(Iterators)>;
    using iterator_collection = std::tuple<Iterators...>;

    iterator_collection _iterators;

    auto as_const() const noexcept(NO_EXCEPT) {
        return typename View::const_iterator(this->_iterators);
    }

  public:
    explicit zip_iterator() {}
    explicit zip_iterator(const Iterators... iterators) noexcept(NO_EXCEPT) : _iterators({ iterators... }) {}
    template<class... Is> zip_iterator(const std::tuple<Is...> coll) noexcept(NO_EXCEPT) : _iterators(coll) {}

    inline auto& operator++() noexcept(NO_EXCEPT) {
        std::apply([this](auto&... args) { (++args, ...); }, this->_iterators);
        return *this;
    }
    inline auto operator++(int) noexcept(NO_EXCEPT) {
        const auto res = *this;
        std::apply([this](auto&... args) { (++args, ...); }, this->_iterators);
        return res;
    }

    inline auto& operator--() noexcept(NO_EXCEPT) {
        std::apply([this](auto&... args) { (--args, ...); }, this->_iterators);
        return *this;
    }
    inline auto operator--(int) noexcept(NO_EXCEPT) {
        const auto res = *this;
        std::apply([this](auto&... args) { (--args, ...); }, this->_iterators);
        return res;
    }

    inline auto& operator+=(const difference_type diff) noexcept(NO_EXCEPT) {
        std::apply([this,diff](auto&&... args) { ((args += diff), ...); }, this->_iterators);
        return *this;
    }

    inline auto& operator-=(const difference_type diff) noexcept(NO_EXCEPT) {
        std::apply([this,diff](auto&... args) { ((args -= diff), ...); }, this->_iterators);
        return *this;
    }

    friend inline zip_iterator operator+(zip_iterator lhs, const difference_type rhs) noexcept(NO_EXCEPT) { return lhs += rhs; }
    friend inline zip_iterator operator-(zip_iterator lhs, const difference_type rhs) noexcept(NO_EXCEPT) { return lhs -= rhs; }

    protected:
    template<std::size_t... I>
    const auto dereference_elements_impl(std::index_sequence<I...>) noexcept(NO_EXCEPT) { return std::tie(*std::get<I>(this->_iterators)...); }
    template<std::size_t... I>
    const auto dereference_elements_impl(std::index_sequence<I...>) const noexcept(NO_EXCEPT) { return std::tie(*std::get<I>(this->_iterators)...); }

    const auto dereference_elements() noexcept(NO_EXCEPT) { return dereference_elements_impl(indices()); }
    const auto dereference_elements() const noexcept(NO_EXCEPT) { return dereference_elements_impl(indices()); }

    public:
    const auto operator*() noexcept(NO_EXCEPT) { return dereference_elements(); }
    const auto operator*() const noexcept(NO_EXCEPT) { return dereference_elements(); }

    // For range base for.
    friend inline bool operator==(const zip_iterator &lhs, const zip_iterator &rhs) noexcept(NO_EXCEPT) { return lhs._iterators == rhs._iterators; }
    friend inline bool operator!=(const zip_iterator &lhs, const zip_iterator &rhs) noexcept(NO_EXCEPT) { return lhs._iterators != rhs._iterators; }
    friend inline bool operator<=(const zip_iterator &lhs, const zip_iterator &rhs) noexcept(NO_EXCEPT) { return lhs._iterators <= rhs._iterators; }
    friend inline bool operator>=(const zip_iterator &lhs, const zip_iterator &rhs) noexcept(NO_EXCEPT) { return lhs._iterators >= rhs._iterators; }
    friend inline bool operator<(const zip_iterator &lhs, const zip_iterator &rhs) noexcept(NO_EXCEPT) { return lhs._iterators < rhs._iterators; }
    friend inline bool operator>(const zip_iterator &lhs, const zip_iterator &rhs) noexcept(NO_EXCEPT) { return lhs._iterators > rhs._iterators; }
};

} // namespace view_impl

} // namespace internal



// Thanks to: https://qiita.com/pshiko/items/aee2641149b0cc97e287
template<class... Views>
struct zip_view : internal::view_impl::base {
  public:
    using iterator = internal::view_impl::zip_iterator<zip_view, internal::iterator_t<Views>...>;
    using const_iterator = internal::view_impl::zip_iterator<zip_view, internal::iterator_t<const Views>...>;

  protected:
    std::tuple<Views...> _bases;
    iterator _begin, _end;

  public:
    explicit zip_view(const Views... views) noexcept(NO_EXCEPT) : _bases({ views... }) {
        std::apply(
            [this](const auto&... args) {
                this->_begin = iterator{ std::begin(args)... };
                this->_end = iterator{ std::end(args)... };
            },
            _bases
        );
    };

    iterator begin() noexcept(NO_EXCEPT) { return this->_begin; }
    iterator end() noexcept(NO_EXCEPT) { return this->_end; }

    const_iterator begin() const noexcept(NO_EXCEPT) { return this->_begin.as_const(); }
    const_iterator end() const noexcept(NO_EXCEPT) { return this->_end.as_const(); }

    const_iterator cbegin() const noexcept(NO_EXCEPT) { return this->_begin.as_const(); }
    const_iterator cend() const noexcept(NO_EXCEPT) { return this->_end.as_const(); }
};


namespace views {


template<class... Views>
inline auto zip(Views&&... views) noexcept(NO_EXCEPT) { return zip_view(range(views)...); };


} // namespace views


} // namespace lib
/* [view/zip.hpp] */
#line 8 "views.hpp"

/* [views.hpp] */
#line 22 "utilities.hpp"



#line 25 "utilities.hpp"

#line 26 "utilities.hpp"



#line 29 "utilities.hpp"

#line 30 "utilities.hpp"

/* #expanded [utility/applier.hpp] */
#line 1 "utility/applier.hpp"





namespace lib {

namespace internal {
    template<class T> T max(T a, T b) { return std::max(a, b); }
    template<class T> T max(T x) { return x; }
    template<class T> T max() { return  -std::numeric_limits<T>::min(); }

    template<class T> T min(T a, T b) { return std::min(a, b); }
    template<class T> T min(T x) { return x; }
    template<class T> T min() { return  std::numeric_limits<T>::max(); }
}

template<class T, T (*op)(T,T)> struct applier {
    using value_type = T;

  protected:
    T _v;

  public:
    applier(const T& v = T{}) : _v(v) {}
    template<class U> applier& operator<<=(U&& val) & noexcept {
        _v = op(_v, std::forward<U>(val));
        return *this;
    }
    inline T val() const { return _v; }
    inline operator T() const { return _v; }
};

template<class T> using maximum = applier<T,internal::max<T>>;
template<class T> using minimum = applier<T,internal::min<T>>;

}
/* [utility/applier.hpp] */
#line 32 "utilities.hpp"

/* #expanded [utility/restrictor.hpp] */
#line 1 "utility/restrictor.hpp"







namespace lib {


template<class T, T INF, T SUP> struct static_restrictor {
    using restrictor = static_restrictor;

  protected:
    T _v;

    inline void _clamp() { this->_v = std::clamp(this->_v, INF, SUP); }
    inline restrictor& _assign(T v) {
        this->_v = std::clamp(v, INF, SUP);
        return *this;
    }

  public:
    static_restrictor(T v = T{}) : _v(v) {}
    inline T val() const { return this->_v; }

    restrictor& operator++() { return this->_assign(this->_v + 1); }
    restrictor& operator--() { return this->_assign(this->_v - 1); }
    restrictor operator++(int) {
        restrictor res = *this;
        *this++;
        return res;
    }
    restrictor operator--(int) {
        restrictor res = *this;
        *this--;
        return res;
    }

    restrictor& operator+=(const restrictor& rhs) { return this->_assign(this->_v + rhs.val()); }
    restrictor& operator-=(const restrictor& rhs) { return this->_assign(this->_v - rhs.val()); }
    restrictor& operator*=(const restrictor& rhs) {
        if(mul_over(this->_v, rhs.val(), SUP)) return this->_assign(SUP);
        if(mul_under(this->_v, rhs.val(), INF)) return this->_assign(INF);
        return this->_assign(this->_v * rhs.val());
    }
    restrictor& operator/=(const restrictor& rhs) { return this->_assign(this->_v / rhs.val()); }

    restrictor operator+() const { return *this; }
    restrictor operator-() const { return restrictor() - *this; }

    friend restrictor operator+(const restrictor& lhs, const restrictor& rhs) {
        return restrictor(lhs) += rhs;
    }
    friend restrictor operator-(const restrictor& lhs, const restrictor& rhs) {
        return restrictor(lhs) -= rhs;
    }
    friend restrictor operator*(const restrictor& lhs, const restrictor& rhs) {
        return restrictor(lhs) *= rhs;
    }
    friend restrictor operator/(const restrictor& lhs, const restrictor& rhs) {
        return restrictor(lhs) /= rhs;
    }
    friend bool operator==(const restrictor& lhs, const restrictor& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const restrictor& lhs, const restrictor& rhs) {
        return lhs._v != rhs._v;
    }
    friend bool operator<(const restrictor& lhs, const restrictor& rhs) {
        return lhs._v < rhs._v;
    }
    friend bool operator>(const restrictor& lhs, const restrictor& rhs) {
        return lhs._v > rhs._v;
    }
    friend bool operator<=(const restrictor& lhs, const restrictor& rhs) {
        return lhs._v <= rhs._v;
    }
    friend bool operator>=(const restrictor& lhs, const restrictor& rhs) {
        return lhs._v >= rhs._v;
    }
};


} // namespace lib


namespace std {
    template<class T, T INF, T SUP>
    T std::abs(const lib::static_restrictor<T,INF,SUP>& v) { return std::abs(v.val()); }
}
/* [utility/restrictor.hpp] */
#line 34 "utilities.hpp"


#line 36 "utilities.hpp"

#line 37 "utilities.hpp"

#line 38 "utilities.hpp"


#line 40 "utilities.hpp"

#line 41 "utilities.hpp"

#line 42 "utilities.hpp"

/* [utilities.hpp] */
#line 17 "snippet/using.hpp"


using std::cin;
using std::cout;

using std::pair;
using std::tuple;

using std::queue;
using std::stack;
using std::priority_queue;

using std::bitset;

using std::sort;
using std::reverse;

using std::min_element;
using std::max_element;

// using boost::dynamic_bitset

using lib::i32;
using lib::u32;
using lib::i64;
using lib::u64;

#ifdef __GNUC__
using lib::i128;
using lib::u128;
#endif

using lib::uint;
using lib::ll;
using lib::ull;
using lib::ld;

using lib::INF32;
using lib::INF64;
using lib::INF;

using lib::INV;

using lib::LN;
using lib::SPC;

using lib::DIRS4;
using lib::DIRS8;

using lib::input_adapter;
using lib::output_adapter;

using lib::nPr;
using lib::nCr;

using lib::pow;
using lib::pow_mod;
using lib::inv_mod;

using lib::spair;

using lib::multi_container;

using lib::minimum;
using lib::maximum;

using lib::modint998244353;
using lib::modint1000000007;
using lib::modint;
using lib::modint64;

using lib::sorted;
using lib::reversed;

using lib::join;

using lib::chmin;
using lib::chmax;

using lib::grid;
using lib::graph;

using lib::matrix;
using lib::unordered_multiset;

using lib::set;
using lib::unordered_set;
using lib::multiset;
using lib::unordered_multiset;

using lib::map;
using lib::unordered_map;
using lib::multimap;
using lib::unordered_multimap;

using lib::valarray;
using lib::vector;
using lib::string;
using lib::array;
/* [snippet/using.hpp] */
#line 114 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"


#line 116 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 117 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 118 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 119 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

/* #expanded [geometries.hpp] */
#line 1 "geometries.hpp"




/* #expanded [geometry/convex_full.hpp] */
#line 1 "geometry/convex_full.hpp"










namespace lib {


template<class I, class P = typename std::iterator_traits<I>::value_type>
std::vector<P> convex_hull(const I first, const I last, const bool margin = false) noexcept(NO_EXCEPT) {
    using size_t = internal::size_t;

    std::vector<P> points(first, last);

    const auto n = static_cast<size_t>(points.size());
    std::sort(points.begin(), points.end());

    std::vector<P> res;

    for(const auto& p : points) {
        while(res.size() >= 2UL and cross(p, res.end()[-2], res.end()[-1]) <= 0) {
            res.pop_back();
        }
        res.emplace_back(p);
    }

    const auto t = static_cast<size_t>(res.size());
    for(auto i=n-2; i>=0; --i) {
        const auto p = points[i];
        while(static_cast<size_t>(res.size()) > t and cross(p, res.end()[-2], res.end()[-1]) <= 0) {
            res.pop_back();
        }
        if(not margin and i == 0) break;
        res.emplace_back(p);
    }

    return res;
}


} // namespace lib
/* [geometry/convex_full.hpp] */
#line 6 "geometries.hpp"
/* [geometries.hpp] */
#line 121 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 122 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"


#line 124 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 125 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 126 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 127 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [template.hpp] */
#line 1 "template.hpp"


#ifdef LOCAL_JUDGE
    #include<debug>
    #define debug(...) debugger::debug(debugger::split(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
    #define DEBUG(...) do { debugger::DEBUG(nullptr, "\033[3;35m#" + std::to_string(__LINE__) + "\033[m  "); debugger::DEBUG(__VA_ARGS__); debugger::DEBUG(nullptr, "\033[m\n"); } while(0);
#else
    #define debug(...) ({ ; })
    #define DEBUG(...) ({ ; })
#endif




#line 15 "template.hpp"

#line 16 "template.hpp"



/* [template.hpp] */
#line 128 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"

#line 129 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
/* #expanded [timer.hpp] */
#line 1 "timer.hpp"








namespace lib {


struct timer {
    using time = std::int32_t;
    using progress_type = long double;

  protected:
    const time time_limit = 0;
    const progress_type progress_duration = 0;

    std::chrono::system_clock::time_point clock_start, clock_end;

  public:

    timer(const time time_limit = 0) noexcept : time_limit(time_limit),
        progress_duration(
            static_cast<progress_type>(
                std::chrono::duration_cast<std::chrono::system_clock::duration>(
                    std::chrono::milliseconds(time_limit)
                ).count()
            )
        )
    {
        this->reset();
    }

    inline time limit() noexcept { return this->time_limit; }

    inline timer* reset() noexcept {
        this->clock_start = std::chrono::system_clock::now();
        this->clock_end = clock_start + std::chrono::milliseconds(this->time_limit);
        return this;
    }

    inline time elapsed() const noexcept {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - this->clock_start).count();
    }
    inline time remaining() const noexcept {
        return time_limit - this->elapsed();
    }

    inline bool expired() const noexcept { return this->elapsed() >= time_limit; }
    inline progress_type progress() const noexcept {
        return std::clamp<progress_type>((std::chrono::system_clock::now() - this->clock_start).count() / this->progress_duration, 0, 1);
    }
};


} // namespace lib
/* [timer.hpp] */
#line 130 "/home/uni_kakurenbo/CompetitiveProgramming/sources/libraries/original/all.hpp"
