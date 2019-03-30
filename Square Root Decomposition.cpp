#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, i, j, q, l, r, lBlk, rBlk, mini;
    cin>>n;
    ll ar[n], sizeBlk = (ll)sqrt(n), numBlk = (ll)ceil((ld)n / sizeBlk), blocks[numBlk + 1], k;
    for(i = 0; i < n; i++)
        cin>>ar[i];
    for(i = 0; i <= numBlk; i++)
        blocks[i] = INT64_MAX;
    k = -1;
    for(i = 0; i < n; i++)
    {
        if(k % sizeBlk == 0)
            k++;
        mini = blocks[k] < ar[i] ? blocks[k] : ar[i];
    }
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        l--; r--;
        mini = INT64_MAX;
        while (l < r and l % sizeBlk != 0 and l != 0)
        {
            mini = mini < ar[l] ? mini : ar[l];
            l++;
        }
        while (l + sizeBlk <= r)
        {
            // traversing completely overlapping blocks
            mini = mini < blocks[l / sizeBlk] ? mini : blocks[l / sizeBlk];
            l += sizeBlk;
        }
        while (l <= r)
        {
            // traversing last block in range
            mini = mini < ar[l] ? mini : ar[l];
            l++;
        }
        cout<<mini<<"\n";
    }
    return 0;
}