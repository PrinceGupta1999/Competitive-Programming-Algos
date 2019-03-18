#include<bits/stdc++.h>
#define e 0.000001
using namespace std;
int grid[201][201], temp_grid[201][201];
vector<int> links[201];
long double dist(complex<long long> temp)
{
    return (long double)((temp.real() * temp.real()) + (temp.imag() * temp.imag()));
}
bool bfs(int grid[201][201], int source, int destination, int parent[], int n)
{
    bool visited[n + 1], flag = true;
    for(int i = 0; i <= n; i++)
        visited[i] = false;
    queue <int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    while (!q.empty() && flag)
    {
        int u = q.front();
        q.pop();
        for (auto v : links[u])
        {
            if (!visited[v] && grid[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
        if(visited[destination])
            flag = false;
    }
    return visited[destination];
}
int fordFulkerson(int grid[201][201], int source, int destination, int n)
{
    int parent[n + 1];
    int max_flow = 0;
    while(bfs(grid, source, destination, parent, n))
    {
        int u, v;
        int path_flow = INT_MAX;
        for(v = destination; v != source; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, grid[u][v]);
        }
        for(v = destination; v != source; v = parent[v])
        {
            u = parent[v];
            grid[u][v] -= path_flow;
            grid[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    int n, i, j, destination = 0, flag, max_monkeys = 0, flag1, flag2 = 0;
    long long x, y;
    long double c;
    bool possible = false;
    cin>>n>>c;
    c *= c;
    int monkeys[n], capacity[n];
    complex<long long> coordinates[n];
    for(i = 0; i < n; i++)
    {
        cin>>x>>y>>monkeys[i]>>capacity[i];
        max_monkeys += monkeys[i];
        coordinates[i] = {x, y};
        if(monkeys[i] > capacity[i])
        {
            flag2++;
            destination = i;
        }
    }
    if(flag2 > 1)
    {
        cout<<"-1";
        return 0;
    }
    for(i = 0; i < n; i++)
    {
        flag = flag1 = 0;
        for(j = i + 1; j < n; j++)
        {
            flag1 = 1;
            if(dist(coordinates[i] - coordinates[j]) <= c || abs(dist(coordinates[i] - coordinates[j]) - c) <= e)
            {
                flag = 1;
                links[i].push_back(j);
                links[j].push_back(i);
                grid[i][j] = capacity[i];
                grid[j][i] = capacity[j];
            }
        }
        if(!flag && flag1 && monkeys[i])
        {
            cout<<"-1";
            return 0;
        }
        links[n].push_back(i);
        links[i].push_back(n);
        grid[n][i] = monkeys[i];
        grid[i][n] = grid[i][i] = 0;
    }
    if(flag2 == 1)
    {
        for(i = 0; i <= n; i++)
            for(j = 0; j <= n; j++)
                temp_grid[i][j] = grid[i][j];
        if(max_monkeys == fordFulkerson(temp_grid, n, destination, n))
        {
            cout<<destination<<"\n";
            for(i = 0; i <= n; i++)
            {
                for(j = 0; j <= n; j++)
                    cout<<temp_grid[i][j]<<" ";
                cout<<"\n";
            }

        }
        else
            cout<<"-1";
    }
    else
    {
        for(destination = 0; destination < n; destination++)
        {
            for(i = 0; i <= n; i++)
                for(j = 0; j <= n; j++)
                    temp_grid[i][j] = grid[i][j];
            if(max_monkeys == fordFulkerson(temp_grid, n, destination, n))
            {
                possible = true;
                cout<<destination<<"\n";
                for(i = 0; i <= n; i++)
                {
                    for(j = 0; j <= n; j++)
                        cout<<temp_grid[i][j]<<" ";
                    cout<<"\n";
                }

            }
        }
        if(!possible)
            cout<<"-1";
    }
    return 0;
}