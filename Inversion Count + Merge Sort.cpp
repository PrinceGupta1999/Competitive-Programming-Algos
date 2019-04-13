#include<bits/stdc++.h>
using namespace std;
#define size_ar 10 // size of array
int temp[size_ar]; // sorted array
unordered_map<int, int> inversion;
void merge(int l, int m, int r)
{
    int i = l, j = m, ar[size_ar], k = 0; // initialize pointer to indexes
    vector<int> indexes; 
    while(i < m && j < r)
    {
        if(temp[i] < temp[j]) // right is smaller => inversion
        {
            inversion[temp[i]] += (j - m); // inversion = (no. of elements already in new array)
            ar[k++] = temp[i++]; // Put element in order
        }
        else // No inversion
            ar[k++] = temp[j++]; // Put element in order
    }
    // Handling cases when one of the arrays is finished
    while(i < m)
    {
        inversion[temp[i]] += (r - m);
        ar[k++] = temp[i++];
    }
    while(j < r)
        ar[k++] = temp[j++];
    for(i = l, k = 0; i < r; i++, k++) // Putting back to sorted array
        temp[i] = ar[k];
}
void count_inversions(int l, int r)
{
    if(l < r - 1) // array contains at least 2 elements
    {
        int m = (l + r) / 2; 
        count_inversions(l, m); // Recurse
        count_inversions(m, r);
        merge(l, m, r);
    }
}
int main()
{
    int ar[size_ar], i, n;
    cin>>n;
    for(i = 0; i < n; i++) // initializations
    {
        cin>>ar[i]; 
        temp[i] = ar[i];
        inversion[ar[i]] = 0;
    }
    count_inversions(0, n);
    for(auto item : inversion) // printing details
        cout<<item.first<<" : "<<item.second<<"\n";
    for(i = 0; i < n; i++)
        cout<<temp[i]<<" ";
    return 0;
}
