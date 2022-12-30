/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ GCC */
/* #region template */
#include <bits/stdc++.h>
using namespace std;

namespace atcoder {}
using namespace atcoder;

namespace lib {}
using namespace lib;

#include "template.hpp"
/* #endregion */

#include "data_structure/range_operations.hpp"

signed main() {
    int n, q; cin >> n >> q;
    vector<int> a(n); input >> a;

    range_sum<ll> data(ALL(a));
    debug(data);

    REP(q) {
        int t; cin >> t;
        if(t == 0) {
            int p, x; cin >> p >> x;
            data.add(p, x);
        }
        if(t == 1) {
            int l, r; cin >> l >> r;
            print(data.sum(l, r));
        }
        debug(data);
    }

    return 0;
}
