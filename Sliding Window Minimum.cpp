#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[100], i, n, k;
    deque<pair<int, int>> sliding_window;
    cin>>n>>k;
    for(i = 0; i < n; i++)
        cin>>ar[i];
    for(i = 0; i < k; i++)
    {
        while(!sliding_window.empty() && sliding_window.back().first > ar[i])
            sliding_window.pop_back();
        sliding_window.emplace_back(ar[i], i);
    }
    cout<<sliding_window.front().first<<"\n";
    for(i = k; i < n; i++)
    {
        if(sliding_window.front().second + k == i)
            sliding_window.pop_front();
        while(!sliding_window.empty() && sliding_window.back().first > ar[i])
            sliding_window.pop_back();
        sliding_window.emplace_back(ar[i], i);
        cout<<sliding_window.front().first<<"\n";
    }
    return 0;
}