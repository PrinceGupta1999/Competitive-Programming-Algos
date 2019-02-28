#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007 // common value of MOD on codechef
typedef long long ll;
typedef long double ld;
template <typename T> using indexed_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>; // an improved RB Tree for getting node <---> order
int main()
{
    /* Reading from and Writing to Files 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    /* fast input and output
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);
     */
    ll t, n, i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<t<<" "<<n<<"\n";
    }
    /* Closing STDIN and STDOUT files
    fclose(stdin);
    fclose(stdout);
    */
    return 0;
}
