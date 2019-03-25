#include<bits/stdc++.h>
using namespace std;
#define maxint 2147483647
// General Case is taken here. When sequential nodes (1 : n) use arrays instead
// Similar to dijkstra use when negative edges in graph. This is basically dijkstra without processed thing.
void spfa(map<int, vector<pair<int, int>>>& adjacency_list, map<int, int>& distance, int source)
{
    distance[source] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, source});
    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();
        for(auto u : adjacency_list[a])
        {
            int b = u.first, w = u.second;
            if(distance[a] + w < distance[b])
            {
                distance[b] = distance[a] + w;
                q.push({distance[b], b});
            }
        }
    }
}
int main()
{
    map<int, vector<pair<int, int>>> adjacency_list;
    map<int, int> distance;
    int i, n, k, node, a, b, w;
    cin>>n>>k;
    for(i = 0; i < n; i++)
    {
        cin>>node;
        adjacency_list[node] = vector<pair<int, int>>();
        distance[node] = maxint;
    }
    for(i = 0; i < k; i++)
    {
        cin>>a>>b>>w;
        adjacency_list[a].emplace_back(b, w);
        adjacency_list[b].emplace_back(a, w);
    }
    cin>>node;
    spfa(adjacency_list, distance, node);
    for(auto item : distance)
        cout<<item.first<<"\t"<<item.second<<"\n";
    return 0;
}