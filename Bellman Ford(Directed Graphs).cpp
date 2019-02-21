#include<bits/stdc++.h>
using namespace std;
#define maxint 2147483647
// General Case is taken here. When sequential nodes (1 : n) use arrays instead
bool bellman_ford(vector<tuple<int, int, int>>& edge_list,map<int, int>& distance,int source)
{
    int count = 0;
    bool distance_reduced = true;
    distance[source] = 0;
    while(distance_reduced && count < distance.size())
    {
        distance_reduced = false;
        for (auto edge : edge_list)
        {
            int a, b, w;
            tie(a, b, w) = edge;
            if(distance[a] + w < distance[b] && distance[a] != maxint)
            {
                distance_reduced = true;
                distance[b] = distance[a] + w;
            }
        }
        count++;
    }
    return count != distance.size();
}
int main()
{
    vector<tuple<int, int, int>> edge_list;
    bool neg_cycle;
    map<int, int> distance;
    int i, n, k, node, a, b, w;
    cin>>n>>k;
    for(i = 0; i < n; i++)
    {
        cin>>node;
        distance[node] = maxint;
    }
    for(i = 0; i < k; i++)
    {
        cin>>a>>b>>w;
        edge_list.emplace_back(a, b, w);
    }
    cin>>node;
    neg_cycle = bellman_ford(edge_list, distance, node);
    if(neg_cycle)
        cout<<"Graph contains Negative Cycle";
    else
        for(auto item : distance)
            cout<<item.first<<"\t"<<item.second<<"\n";
    return 0;
}