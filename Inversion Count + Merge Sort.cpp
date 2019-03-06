#include<bits/stdc++.h>
using namespace std;
#define size_ar 10
int temp[size_ar];
unordered_map<int, int> inversion;
void merge(int l, int m, int r)
{
    int i = l, j = m, ar[size_ar], k = 0;
    vector<int> indexes;
    while(i < m && j < r)
    {
        if(temp[i] < temp[j])
        {
            inversion[temp[i]] += (j - m);
            ar[k++] = temp[i++];
        }
        else
            ar[k++] = temp[j++];
    }
    while(i < m)
    {
        inversion[temp[i]] += (r - m);
        ar[k++] = temp[i++];
    }
    while(j < r)
        ar[k++] = temp[j++];
    for(i = l, k = 0; i < r; i++, k++)
        temp[i] = ar[k];
}
void count_inversions(int l, int r)
{
    if(l < r - 1)
    {
        int m = (l + r) / 2;
        count_inversions(l, m);
        count_inversions(m, r);
        merge(l, m, r);
    }
}
int main()
{
    int ar[size_ar], i, n;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>ar[i];
        temp[i] = ar[i];
        inversion[ar[i]] = 0;
    }
    count_inversions(0, n);
    for(auto item : inversion)
        cout<<item.first<<" : "<<item.second<<"\n";
    for(i = 0; i < n; i++)
        cout<<temp[i]<<" ";
    return 0;
}