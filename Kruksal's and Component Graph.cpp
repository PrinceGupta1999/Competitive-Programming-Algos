#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int p[100001], r[100001];
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
    for(i = 0; i <= n; i++)
    {
        r[i] = 0;
        p[i] = i;
    }
    for(i = 0; i < m; i++)
    {
        cin>>x>>y;
        unionSet(x, y);
    }
    map<int, int> components;
    for(i = 1; i <= n; i++)
    {
        cin>>c;
        x = findSet(i);
        if(components.find(x) == components.end())
            components[x] = INT32_MAX;
        if(c >= 0)
            components[x] = min(components[x], c);
    }
    if(components.size() == 1)
    {
        cout<<0;
        return 0;
    }
    c = INT32_MAX;
    for(auto cost : components)
    {
        if(cost.second == INT32_MAX)
        {
            cout<<-1;
            return 0;
        }
        totalCost += cost.second;
        c = min(c, cost.second);
    }
    totalCost += (components.size() - 2) * c;
    cout<<totalCost;
    return 0;
}