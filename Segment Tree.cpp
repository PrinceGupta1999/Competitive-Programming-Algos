#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define default_val 1 // Default value for extra Nodes = Identity Val for nodeVal func.
#define default_ans_val 1 //Initial value for ans
ll nodeVal(ll lt, ll rt)
{
    //Fn. for calculating curNode given L. and R. Child
    return (lt * rt) / __gcd(lt, rt);
}
ll result(ll ans, ll val)
{
    //Fn. for calculating newAns given curAns. and valNode
    return (ans * val) / __gcd(ans, val);
}
void constructSegTree(ll tree[], ll size)
{
    ll temp = (ll)(pow(2, (ll)ceil(log2(size)))), i, j, factor;
    for(i = size; i < temp; i++)
        tree[i] = default_val;
    size = temp;
    temp = 2 * size - 1;
    for(i = size; i <= temp; i++)
        tree[i] = tree[i - size];
    for(i = size / 2; i >= 1; i /= 2)
    {
        factor = 2 * i;
        for(j = i; j < factor; j++)
            tree[j] = nodeVal(tree[2 * j], tree[2 * j + 1]);
    }
}
// Bottom To Top
ll query(ll l, ll r, const ll tree[], ll size)
{
    ll ans = default_ans_val;
    l += size;
    r += size;
    while(l <= r)
    {
        if(l % 2 == 1)
            ans = result(ans, tree[l++]);
        if(r % 2 == 0)
            ans = result(ans, tree[r--]);
        l /= 2;
        r /= 2;
    }
    return ans;
}
//Top to Bottom
ll query(ll l, ll r, ll tree[], ll p, ll q, ll k)
{
    if(l > q || r < p)
        return default_ans_val;
    if(l <= p && r >= q)
        return tree[k];
    ll mid = (p + q) / 2;
    ll lt = query(l, r, tree, p, mid, 2 * k), rt = query(l, r, tree, mid + 1, q, 2 * k + 1);
    return result(lt, rt);
}
void update(ll pos, ll value, ll tree[], ll size)
{
    pos += size;
    tree[pos] = value;
    pos /= 2;
    while(pos >= 1)
    {
        tree[pos] = nodeVal(tree[2 * pos], tree[2 * pos + 1]);
        pos /= 2;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll i, num_query, q[3], n;
    cin>>n;
    ll ar[n], tree[2LL * (ll)(pow(2, (ll)ceil(log2(n))))];
    for(i = 0; i < n; i++)
    {
        cin>>ar[i];
        tree[i] = ar[i];
    }
    cin>>num_query;
    constructSegTree(tree, n);
    // Don't forget to Update n
    n = (ll)(pow(2, (ll)ceil(log2(n))));
    while(num_query--)
    {
        // Update Op. - (q = {1, updIndex(1-based), updVal} Query Op. - (q = {2,lIndex, rIndex(1-Based)})
        cin>>q[0]>>q[1]>>q[2];
        if (q[0] == 1)
            update(q[1] - 1, q[2], tree, n);
        else
            cout<<query(q[1] - 1, q[2] - 1, tree, n)<<"\n";
        //  cout<<query(q[1] - 1, q[2] - 1, tree, 0, n - 1, 1)<<"\n";
    }
    return 0;
}