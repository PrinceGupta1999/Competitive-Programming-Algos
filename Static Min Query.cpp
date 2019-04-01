#include <bits/stdc++.h>
using namespace std;
void preprocess_min(unsigned int ar[], int size, vector<vector<unsigned int>>& min_values)
{
    int i = 0, j, factor;
    vector<unsigned int> minimum;
    for(i = 0; i < size; i++)
        minimum.push_back(ar[i]);
    min_values.push_back(minimum);
    minimum.clear();
    i = 1;
    factor = 2;
    while(factor <= size)
    {
        for(j = 0; j < size + 1 - factor; j++)
            minimum.push_back(min(min_values[i - 1][j], min_values[i - 1][j + (1 << (i - 1))]));
        min_values.push_back(minimum);
        minimum.clear();
        factor *= 2;
        i += 1;
    }
}
unsigned int previousPowerOf2(unsigned int n)
{
    unsigned int temp = n;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    if(n == temp)
        return n;
    return n / 2;
}
int min_query(unsigned int l, unsigned int r, vector<vector<unsigned int>> & min_values)
{
    int size = previousPowerOf2(r - l + 1);
    int temp = size, log_size = -1;
    while(temp)
    {
        temp /= 2;
        log_size++;
    }
    return min(min_values[log_size][l], min_values[log_size][l + size]);
}
int main()
{
    vector<vector<unsigned int>> min_values;
    unsigned int i, ar[100], n, q, l, r;
    cin>>n;
    for(i = 0; i < n; i++)
        cin>>ar[i];
    preprocess_min(ar, n, min_values);
    cin>>q;
    for(i = 0; i < q; i++)
    {
        cin>>l>>r;
        cout<<min_query(l - 1, r - 1, min_values)<<"\n";
    }
    return 0;
}