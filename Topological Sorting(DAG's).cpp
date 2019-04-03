#include<bits/stdc++.h>
using namespace std;
unordered_set<int> unvisited;
void topological_sort(map<int, vector<int>>& adjacency_list, int e, vector<int>& sorted)
{

    for(auto u : adjacency_list[e])
        if(unvisited.find(u) != unvisited.end())
            topological_sort(adjacency_list, u, sorted);
    sorted.push_back(e);
    unvisited.erase(e);
}
int main()
{
    map<int, vector<int>> adjacency_list;
    vector<int> sorted;
    int i, n, k, node, a, b;
    cin>>n>>k;
    for(i = 0; i < n; i++)
    {
        cin>>node;
        adjacency_list[node] = vector<int>();
        unvisited.insert(node);
    }
    for(i = 0; i < k; i++)
    {
        cin>>a>>b;
        adjacency_list[a].push_back(b);
    }
    while(!unvisited.empty())
        topological_sort(adjacency_list, *unvisited.begin(), sorted);
    reverse(sorted.begin(), sorted.end());
    for(auto item : sorted)
        cout<<item<<"\n";
    return 0;
}