#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define LC(k) ((k) << 1)
#define RC(k) (((k) << 1) + 1)
#define default_val 0
#define default_lz_val 0
typedef long long ll;
template <typename T> using indexed_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
ll nodeVal(ll lc, ll rc, ll l, ll r, ll k)
{
    return lc + rc;
}
void applyLazy(ll tree[], ll lz[], ll l, ll r, ll k)
{
    tree[k] += (r - l + 1) * lz[k];
    if(l != r)
    {
        lz[LC(k)] += lz[k];
        lz[RC(k)] += lz[k];
    }
    lz[k] = 0;
}
void update(ll i, ll j, ll tree[], ll lz[], ll v, ll l, ll r, ll k)
{
    if(lz[k])
        applyLazy(tree, lz, l, r, k);
    if(i > r || j < l)
        return;
    if(i <= l && j >= r)
    {
        lz[k] += v;
        applyLazy(tree, lz, l, r, k);
        return;
    }
    ll mid = (l + r) / 2;
    update(i, j, tree, lz, v, l, mid, LC(k)); update(i, j, tree, lz, v, mid + 1, r, RC(k));
    tree[k] = nodeVal(tree[LC(k)], tree[RC(k)], l, r, k);
}
ll query(ll i, ll j, ll tree[], ll lz[], ll l, ll r, ll k)
{
    if(lz[k])
        applyLazy(tree, lz, l, r, k);
    if(i > r || j < l)
        return 0;
    if(i <= l && j >= r)
        return tree[k];
    ll mid = (l + r) / 2;
    return nodeVal(query(i, j, tree, lz, l, mid, LC(k)), query(i, j, tree, lz, mid + 1, r, RC(k)), l, r, k);
}
ll build(ll tree[], ll l, ll r, ll k)
{
    if(l == r)
        return tree[k];
    ll mid = (l + r) / 2;
    build(tree, l, mid, LC(k));
    build(tree, mid + 1, r, RC(k));
    tree[k] = nodeVal(tree[LC(k)], tree[RC(k)], l, r, k);
    return tree[k];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t, n, i, sz, q, l, r, v;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        sz = (ll)pow(2, ceil(log2(n)));
        ll tree[2 * sz], lz[2 * sz];
        memset(tree, default_val, sizeof(tree));
        memset(lz, default_lz_val, sizeof(lz));
        /*for(i = sz; i < sz + n; i++)
            cin>>tree[i];
        build(tree, 0, n - 1, 1);*/
        while(q--)
        {
            cin>>i>>l>>r;
            if(i)
            {
                v = query(l - 1, r - 1, tree, lz, 0, sz - 1, 1);
                cout<<v<<"\n";
            }
            else
            {
                cin>>v;
                update(l - 1, r - 1, tree, lz, v, 0, sz - 1, 1);
            }
        }
    }
    return 0;
}