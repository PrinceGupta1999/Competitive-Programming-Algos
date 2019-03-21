#include <bits/stdc++.h>
using namespace std;

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int ar[], int low, int high)
{
    int pivot = ar[low];
    int i = low - 1, j = high + 1;

    while (true) {
        do {
            i++;
        } while (ar[i] < pivot);
        do {
            j--;
        } while (ar[j] > pivot);
        if (i >= j)
            return j;
        swap(ar[i], ar[j]);
    }
}

int partition_r(int ar[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(ar[random], ar[low]);
    return partition(ar, low, high);
}
void quickSort(int ar[], int low, int high)
{
    if (low < high) {
        int pi = partition_r(ar, low, high);
        quickSort(ar, low, pi);
        quickSort(ar, pi + 1, high);
    }
}

void printArray(int ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    printf("\n");
}

int main()
{
    int ar[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(ar) / sizeof(ar[0]);
    quickSort(ar, 0, n - 1);
    printf("Sorted array: \n");
    printArray(ar, n);
    return 0;
}
