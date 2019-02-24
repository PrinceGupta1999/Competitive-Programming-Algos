#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll f, s, g, u, d, c = 0;
    cin>>f>>s>>g>>u>>d;
    bool visited[f + 1];
    memset(visited, false, sizeof(visited));
    queue<pair<ll, ll>> q;
    q.emplace(s, c);
    visited[s] = true;
    while(!q.empty())
    {
        tie(s, c) = q.front();
        q.pop();
        if(s == g)
        {
            cout<<c;
            return 0;
        }
        c++;
        if(s > d && !visited[s - d])
            q.emplace(s - d, c), visited[s - d] = true;
        if(s + u <= f && !visited[s + u])
            q.emplace(s + u, c), visited[s + u] = true;
    }
    cout<<"use the stairs";
    return 0;
}