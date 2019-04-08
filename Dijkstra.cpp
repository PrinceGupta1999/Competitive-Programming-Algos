#include<bits/stdc++.h>
using namespace std;
#define maxint 2147483647
// General Case is taken here. When sequential nodes (1 : n) use arrays instead
void dijkstra(map<int, vector<pair<int, int>>>& adjacency_list, map<int, int>& distance, int source)
{
    distance[source] = 0; // Initializations
    priority_queue<pair<int, int>> q;
    unordered_set<int> processed;
    q.push({0, source});
    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if(processed.find(a) != processed.end()) // Check if visited
            continue;
        processed.insert(a);
        for(auto u : adjacency_list[a]) // Loop Through Neighbours
        {
            int b = u.first, w = u.second;
            if(distance[a] + w < distance[b]) // Check if relaxation possible
            {
                distance[b] = distance[a] + w;
                q.push({-distance[b], b}); // negated distance so as to not require a max heap
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
        adjacency_list[node] = vector<pair<int, int>>(); // Initializations of vertices with no neihbours and infinite distance
        distance[node] = maxint;
    }
    for(i = 0; i < k; i++)
    {
        cin>>a>>b>>w;
        adjacency_list[a].emplace_back(b, w); // Inserting Edges
        adjacency_list[b].emplace_back(a, w);
    }
    cin>>node;
    dijkstra(adjacency_list, distance, node);
    for(auto item : distance) // Output Distances
        cout<<item.first<<"\t"<<item.second<<"\n";
    return 0;
}
