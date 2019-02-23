#include <bits/stdc++.h>
#define infinity 2147483647
using namespace std;
int main()
{
    int i, j, n, m, query, x, y;
    char mat[1000][1000];
    int distance[1000][1000];
    bool visited[1000][1000];
    cin >> n >> m >> query;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            visited[i][j] = false;
            distance[i][j] = infinity;
        }
    cin>>x>>y;
    x--;y--;
    queue<pair<int, int>> q;
    distance[x][y] = 0;
    if(mat[x][y] == 'O')
        q.push({x, y});
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(visited[x][y])
            continue;
        visited[x][y] = true;
        if(y != 0)
            if(mat[x][y - 1] == 'O' && distance[x][y] + 1 < distance[x][y - 1])
            {
                distance[x][y - 1] = distance[x][y] + 1;
                q.push({x, y - 1});
            }
        if(y != m - 1)
            if(mat[x][y + 1] == 'O' && distance[x][y] + 1 < distance[x][y + 1])
            {
                distance[x][y + 1] = distance[x][y] + 1;
                q.push({x, y + 1});
            }
        if(x != 0)
            if(mat[x - 1][y] == 'O' && distance[x][y] + 1 < distance[x - 1][y])
            {
                distance[x - 1][y] = distance[x][y] + 1;
                q.push({x - 1, y});
            }
        if(x != n - 1)
            if(mat[x + 1][y] == 'O' && distance[x][y] + 1 < distance[x + 1][y])
            {
                distance[x + 1][y] = distance[x][y] + 1;
                q.push({x + 1, y});
            }
    }
    while(query--)
    {
        cin>>x>>y;
        x--;y--;
        if(distance[x][y] != infinity)
            cout<<distance[x][y]<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}