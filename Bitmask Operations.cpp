#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template <typename T> using indexed_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
struct Bitmask
{
    // Assume 0 based indexing for elements
    ull s, sz;
    explicit Bitmask(ull n)
    {
        s = 0;
        sz = n;
    }
    void insert(ull idx)
    {
        s |= (1 << idx);
    }
    void erase(ull idx)
    {
        s &= !(1 << idx);
    }
    void complement()
    {
        s = (ull)((1 << sz) - 1) & !(s);
    };
    void removeSmallestIdx()
    {
        s = s & (s - 1);
    }
    ull size()
    {
        return __builtin_popcountll(s);
    }
    ull capacity()
    {
        return sz;
    }
    bool find(ull idx)
    {
        return ((1 << idx) & s) != 0;
    }
};
ll union_bitmask(Bitmask a, Bitmask b)
{
    if(a.sz == b.sz)
        return a.s | b.s;
    return -1;
}
ll intersect_bitmask(Bitmask a, Bitmask b)
{
    if(a.sz == b.sz)
        return a.s & b.s;
    return -1;
}
ll subtract_bitmask(Bitmask a, Bitmask b)
{
    if(a.sz == b.sz)
        return a.s | !(b.s);
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t, n, i, p, m, w;
    return 0;
}