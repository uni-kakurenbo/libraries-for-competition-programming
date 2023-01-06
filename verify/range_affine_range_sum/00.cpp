#include <atcoder/modint>
#include "template.hpp"

#include "data_structure/lazy_segment_tree.hpp"
#include "data_structure/range_action/range_affine_range_sum.hpp"

#include <vector>

signed main() {
    int n, q; std::cin >> n >> q;
    std::vector<atcoder::modint998244353> a(n); input >> a;

    lib::lazy_segment_tree<lib::actions::range_affine_range_sum<atcoder::modint998244353>> data(ALL(a));
    debug(data);

    LOOP(q) {
        int t; std::cin >> t;
        if(t == 0) {
            ll l, r, b, c; std::cin >> l >> r >> b >> c;
            data.affine(l, r, b, c);
        }
        if(t == 1) {
            ll l, r; std::cin >> l >> r;
            print(data.sum(l, r));
        }
        debug(data);
    }
}
