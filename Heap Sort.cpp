#include<bits/stdc++.h>
#define size_ar 10
using namespace std;
void heapify(int ar[], int n, int index) // Corrects a single anomally in the heap at the index = index
{
    int pos = 2 * index + 1; // Left Child
    if(pos >= n) // Out of Bounds => node[index] is a leaf
        return;
    else if(pos + 1 < n) 
        if(ar[pos] < ar[pos + 1]) // pos = index of greater child
            pos++;
    if(ar[pos] > ar[index]) // check if parent is smaller
    {
        swap(ar[pos], ar[index]); // Swap parent and greater child
        heapify(ar, n, pos); // Recurse
    }
}
void heapsort(int ar[], int n) // Sorts the array using Heap
{
    for(int i = n / 2 - 1; i >= 0; i--) // Build a max heap (leaf nodes are already max heaps) check anomally above
        heapify(ar, n, i);
    for(int i = n - 1; i >= 0; i--)
    {
        swap(ar[0], ar[i]); // top of heap => largest element => swapped to last element 
        heapify(ar, i, 0); // Reduce size of heap and correct the anomally that may have arose at index = 0
    }
}
int main()
{
    int ar[size_ar], i;
    for(i = 0; i < size_ar; i++) // Initialize array
        ar[i] = i + 1;
    random_shuffle(ar, ar + size_ar); // Random Shuffle
    heapsort(ar, size_ar); // Sort the array
    for(i = 0; i < size_ar; i++)
        cout<<ar[i]<<" ";
    return 0;
}
