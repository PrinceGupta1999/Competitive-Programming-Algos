// Prerequisite => Disjoint Set Union(DSU)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int p[100001], r[100001];
// Functions for implementing DSU
int findSet(int x)
{
    if(p[x] != x)
        p[x] = findSet(p[x]);
    return p[x];
}
int linkSet(int x, int y)
{
    if(x != y)
    {
        if(r[x] > r[y])
        {
            p[y] = x;
            return x;
        }
        else
        {
            p[x] = y;
            if(r[x] == r[y])
                r[y]++;
            return y;
        }
    }
    return x;
}
int unionSet(int x, int y)
{
    return linkSet(findSet(x), findSet(y));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, i, x, y, c, totalCost = 0;
    cin>>n>>m;
    for(i = 0; i <= n; i++) // Initialization of sets
    {
        r[i] = 0;
        p[i] = i;
    }
    for(i = 0; i < m; i++) // Union of Sets
    {
        cin>>x>>y;
        unionSet(x, y);
    }
    set<int> components;
    for(i = 1; i <= n; i++)
    {
        cin>>c;
        x = findSet(i);
        if(components.find(x) == components.end()) // Representative x not currently in components => new component
        {
            components.insert(x);
            cout<<"Component "<<x<<": ";
            for(int j = 0; j < n; j++)
                if(findSet(j) == x)
                    cout<<j<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
