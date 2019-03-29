#include <bits/stdc++.h>
#define maxint 2147483647
using namespace std;
int link[128], size_tree[128];
int find(int x)
{
    while (x != link[x]) x = link[x];
    return x;
}
bool same(int a, int b) {
    return find(a) == find(b);
}
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (size_tree[a] < size_tree[b])
    {
        int temp = a;
        a = b;
        b = temp;
    }
    -   size_tree[a] += size_tree[b];
    link[b] = a;
}
void max_spanning_tree(int n, int k, int mat[128][128], int final_mat[128][128], priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>& edges, priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>& unused_edges)
{
    int i, num_edges = 0, j;
    for(i = 0; i < n; i++)
    {
        link[i] = i;
        size_tree[i] = 1;
    }
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            final_mat[i][j] = maxint;
    while(!edges.empty())
    {
        int w, a, b;
        tie(w, a, b) = edges.top();
        edges.pop();
        if (!same(a,b))
            unite(a,b);
        else
        {
            unused_edges.push({w, a, b});
            num_edges++;
        }
    }
    for(i = 0; i < n; i++)
        final_mat[i][link[i]] = mat[i][link[i]];
    while(num_edges > k)
    {
        int w, a, b;
        tie(w, a, b) = unused_edges.top();
        unused_edges.pop();
        final_mat[a][b] = mat[a][b];
        final_mat[b][a] = mat[b][a];
        num_edges--;
    }
}
float floyd_warshall(int mat[128][128], int n)
{
    float sum = 0;
    int i, j, k, distances[128][128];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            distances[i][j] = mat[i][j];
            if(i == j)
                distances[i][j] = 0;
        }
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0; k < n; k++)
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
    for(i = 0; i < n; i++)
        for(j = 0; j < i; j++)
            if(distances[i][j] != maxint)
                sum += distances[i][j];
    return sum;
}
int main()
{
    float w_g, w_gdash;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> edges;
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> unused_edges;
    int n, k, mat[128][128], i, j, final_mat[128][128];
    cin>>n>>k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            cin>>mat[i][j];
            if(j < i)
                edges.push({mat[i][j], i, j});
        }
    w_g = floyd_warshall(mat, n);
    max_spanning_tree(n, k, mat, final_mat, edges, unused_edges);
    w_gdash = floyd_warshall(final_mat, n);
    cout<<std::fixed<<unused_edges.size()<<" "<<w_gdash / w_g<<"\n";
    while(!unused_edges.empty())
    {
        int w, a, b;
        tie(w, a, b) = unused_edges.top();
        unused_edges.pop();
        cout<<min(a, b) + 1<<" "<<max(a, b) + 1<<"\n";
    }
    return 0;
}