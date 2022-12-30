#include <bits/stdc++.h>
#include "template.hpp"
#include "iterable/accumulation.hpp"

signed main() {
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n); REP(i, n) std::cin >> a[i];
    lib::accumulation<ll> sum(ALL(a));

    REP(q) {
        int l, r; std::cin >> l >> r;
        print(sum(l, r));
    }
}
