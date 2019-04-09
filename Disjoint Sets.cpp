#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
ll findSet(ll x, ll p[]) // Finds representative of a set
{
    if(p[x] != x) // Check if x is not representative
        p[x] = findSet(p[x], p); // Perform Path Compression
    return p[x]; // Return parent
}
// Basic Version
ll linkSet(ll x, ll y, ll p[], ll r[]) // Merge the smaller set into larger set
{
    if(x != y) // Check if both sets are equal
    {
        if(r[x] > r[y]) // Use Principle of Ranks to approximate size of set
        {
            p[y] = x; // Representative of smaller set now points to larger set
            return x; // Return representative of new set
        }
        else
        {
            p[x] = y; // Representative of smaller set now points to larger set
            if(r[x] == r[y])
                r[y]++;
            return y; // Return representative of new set
        }
    }
    return x;
}
ll unionSet(ll x, ll y, ll p[], ll r[])
{
    return linkSet(findSet(x, p), findSet(y, p), p, r); // Link representatives of both sets
}
// Calculate Params including Size(sz), Min(mn)/Max(mx), Sum(s) 
ll linkSet(ll x, ll y, ll p[], ll r[], ll s[], ll m[], ll sz[])
{
    if(x != y)
    {
        if(r[x] > r[y])
        {
            p[y] = x;
            s[x] += s[y];
            m[x] = min(m[x], m[y]);
            sz[x] += sz[y];
            return x;
        }
        else
        {
            p[x] = y;
            if(r[x] == r[y])
                r[y]++;
            s[y] += s[x];
            m[y] = min(m[x], m[y]);
            sz[y] += sz[x];
            return y;
        }
    }
    return x;
}
ll unionSet(ll x, ll y, ll p[], ll r[], ll s[], ll m[], ll sz[])
{
    return linkSet(findSet(x, p), findSet(y, p), p, r, s, m, sz);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t, n, i, x, sm, T, mn;
    t = 1;
    while(true)
    {
        cin>>n;
        if(n == 0)
            break;
        sm = 0;
        mn = INT32_MAX;
        ll a[n], p[n], r[n], s[n], m[n], sz[n];
        pair<ll, ll> b[n];
        for(i = 0; i < n; i++) // Initialize all sets as separate of unit size and rank 0
        {
            cin>>a[i];
            mn = min(a[i], mn);
            b[i].first = s[i] = m[i] = a[i];
            b[i].second = p[i] = i;
            r[i] = 0;
            sz[i] = 1;
        }
        sort(b, b + n);
        for(i = 0; i < n; i++)
            if(a[i] != b[i].first)
                unionSet(i, b[i].second, p, r, s, m, sz);
        unordered_set<ll> processed;
        for(i = 0; i < n; i++)
        {
            x = findSet(i, p);
            if(processed.find(x) == processed.end())
            {
                processed.insert(x);
                if(sz[x] >= 2)
                    sm += (s[x] + min(m[x] * (sz[x] - 2), m[x] + mn * (sz[x] + 1)));
            }

        }
        cout<<"Case "<<t++<<": "<<sm<<"\n\n";
    }
    return 0;
}
