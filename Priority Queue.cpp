#include <bits/stdc++.h>
using namespace std;
#define max_size 100
class priorityQueue
{
    int queueSize, q[max_size];
    int left(int index);
    int right(int index);
    int parent(int index);
    void maxHeapify(int index);
public:
    void insert(int item);
    int maximumItem();
    int extractMax();
    void increaseKey(int item, int pos);
};
int priorityQueue :: left(int index)
{
    return 2 * index + 1;
}
int priorityQueue :: right(int index)
{
    return 2 * index + 2;
}
int priorityQueue :: parent(int index)
{
    return (index - 1) / 2;
}
void priorityQueue :: maxHeapify(int index)
{
    int l = left(index), r = right(index), greatest = index;
    if(l < queueSize)
    {
        if(l < queueSize && q[l] > q[greatest])
            greatest = l;
        if(r < queueSize && q[r] > q[greatest])
            greatest = r;
    }
    if(greatest != index)
    {
        int temp = q[index];
        q[index] = q[greatest];
        q[greatest] = temp;
        maxHeapify(greatest);
    }
}
void priorityQueue :: insert(int item)
{
    q[queueSize] = INT_MIN;
    increaseKey(queueSize++, item);
    queueSize++;
}
int priorityQueue :: maximumItem()
{
    if(queueSize <= 0)
    {
        cout<<"Empty Queue\n";
        return -1;
    }
    return q[0];
}
void priorityQueue :: increaseKey(int index, int newKey)
{
    if(queueSize <= 0)
    {
        cout<<"Empty Queue\n";
        return;
    }
    if(newKey < q[index])
    {
        cout<<"New Value smaller than earlier\n";
        return;
    }
    q[index] = newKey;
    while(index > 0 && q[parent(index)] < q[index])
    {
        int temp = q[index];
        q[index] = q[parent(index)];
        q[parent(index)] = temp;
        index = parent(index);
    }
}
int priorityQueue :: extractMax()
{
    if(queueSize <= 0)
    {
        cout<<"Empty Queue\n";
        return -1;
    }
    int temp = q[0];
    q[0] = q[queueSize - 1];
    q[queueSize - 1] = temp;
    queueSize--;
    maxHeapify(0);

}

int main()
{

    return 0;
}