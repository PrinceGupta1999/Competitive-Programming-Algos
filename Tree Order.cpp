#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
typedef int ll;
typedef long double ld;
template <typename T> using indexed_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
struct Node
{
    ll id, left, right;
};
ll cnt;
ll constructTree(ll pre[], Node nd[], ll l, ll r)
{
    if(l > r)
        return -1;
    ll k;
    for(k = l; k <= r && nd[k].id != pre[cnt]; k++);
    cnt++;
    nd[k].left = constructTree(pre, nd, l, k - 1);
    nd[k].right = constructTree(pre, nd, k + 1, r);
    return k;
}
bool verifyPost(ll post[], Node nd[], ll root)
{
    if(root == -1)
        return true;
    if(!verifyPost(post, nd, nd[root].left))
        return false;
    if(!verifyPost(post, nd, nd[root].right))
        return false;
    if(nd[root].id != post[cnt])
        return false;
    cnt++;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, i, root = 0;
    cin>>n;
    ll pre[n], post[n];
    Node nd[n];
    for(i = 0; i < n; i++)
        cin>>pre[i];
    for(i = 0; i < n; i++)
        cin>>post[i];
    for(i = 0; i < n; i++)
        cin>>nd[i].id;
    cnt = 0;
    root = constructTree(pre, nd, 0, n - 1);
    cnt = 0;
    if(verifyPost(post, nd, root))
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
