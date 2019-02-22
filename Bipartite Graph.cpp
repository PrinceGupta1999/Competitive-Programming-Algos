#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mod 998244353
typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
ll result, odd, even;
unordered_set<int> unvisited;
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool isBipartite(vector<int> adj[], int u, bool color[])
{
    for (auto v : adj[u])
    {
        if (unvisited.find(v) != unvisited.end())
        {
            unvisited.erase(v);
            color[v] = !color[u];
            if(color[v])
                odd += 1;
            else
                even += 1;
            if (!isBipartite(adj, v, color))
                return false;
        }
        else if (color[u] == color[v])
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t, m, i, x, y;
    cin>>t;
    while(t--)
    {
        bool poss = true;
        result = 1;
        cin>>n>>m;
        vector<int> adj[n + 1];
        bool color[n + 1];
        for(i = 0; i < m; i++)
        {
            cin>>x>>y;
            addEdge(adj, x, y);
        }
        for(i = 1; i <= n; i++)
            unvisited.insert(i);
        while(!unvisited.empty())
        {
            int s = *unvisited.begin();
            unvisited.erase(s);
            odd = 1;
            even = 0;
            color[s] = true;
            if(!isBipartite(adj, s, color))
            {
                poss = false;
                unvisited.clear();
                break;
            }
            result = (result * (power(2, odd, mod) + power(2, even, mod)) % mod) % mod;
        }
        if(poss)
            cout<<result<<"\n";
        else
            cout<<0<<"\n";
        cout.flush();
    }
    return 0;
}