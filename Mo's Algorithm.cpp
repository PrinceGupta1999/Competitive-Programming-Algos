#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> using indexed_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
ll block;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, i, k, j, m;
    cin>>n;
    ll a[n];
    for(i = 0; i < n; i++)
    {
        a[i] = rand() % n;
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    cin>>m;
    block = (ll)sqrt(n);
    pair<ll, ll> q[m];
    for(i = 0; i < m; i++)
        cin>>q[i].first>>q[i].second;
    sort(q, q + m, [](pair<ll, ll> a, pair<ll, ll> b)
    {
        if(a.first / block != b.first / block)
            return a.first < b.first;
        return a.second < b.second;
    });
    ll s = 0, l = 0, r = 0;
    for(i = 0; i < m; i++)
    {

        while(l < q[i].first)
            s -= a[l++];

        while(l > q[i].first)
            s += a[--l];
        while(r <= q[i].second)
            s += a[r++];

        while(r > q[i].second + 1)
            s -= a[--r];

        cout<<q[i].first<<" "<<q[i].second<<" "<<s<<"\n";
    }
    return 0;
}