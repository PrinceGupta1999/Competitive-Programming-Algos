#include<bits/stdc++.h>
#define size_ar 10
using namespace std;
void heapify(int ar[], int n, int index)
{
    int pos = 2 * index + 1;
    if(pos >= n)
        return;
    else if(pos + 1 < n)
        if(ar[pos] < ar[pos + 1])
            pos++;
    if(ar[pos] > ar[index])
    {
        swap(ar[pos], ar[index]);
        heapify(ar, n, pos);
    }
}
void heapsort(int ar[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(ar, n, i);
    for(int i = n - 1; i >= 0; i--)
    {
        swap(ar[0], ar[i]);
        heapify(ar, i, 0);
    }
}
int main()
{
    int ar[size_ar], i;
    for(i = 0; i < size_ar; i++)
        ar[i] = i + 1;
    random_shuffle(ar, ar + size_ar);
    heapsort(ar, size_ar);
    for(i = 0; i < size_ar; i++)
        cout<<ar[i]<<" ";
    return 0;
}