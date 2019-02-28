#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key, degree;
    Node *left, *right, *parent, *child;
    bool marked;
};
class FibonacciHeap
{
private:
    void cut(Node *x, Node *y)
    {
        x->left->right = x->right;
        x->right->left = x->left;
        if(x == y->child)
        {
            if(x->right == x)
                y->child = nullptr;
            else
                y->child = x->right;
        }
        y->degree--;
        x->parent = nullptr;
        x->marked = false;
        x->right = rootList;
        x->left = rootList->left;
        rootList->left->right = x;
        rootList->left = x;
    }
    void cascadingCut(Node *y)
    {
        Node *z = y->parent;
        if(z)
        {
            if(y->marked)
            {
                cut(y, z);
                cascadingCut(z);
            }
            else
                y->marked = true;
        }
    }
    void consolidate()
    {
        int maxDegree = 0, d;
        Node *ar[maxDegree + 1];
        memset(ar, nullptr, sizeof(ar));
        Node *ptr = rootList, *x, *y;
        do
        {
            x = ptr;
            d = x->degree;
            while(ar[d])
            {
                y = ar[d];
                if(x->key > y->key)
                {
                    swap(x, y);
                    ptr = y;
                }
                link(y, x);
                ar[d] = nullptr;
                d++;
            }
            ar[d] = x;
            ptr = ptr->right;
        } while(ptr != rootList);
        min = nullptr;
        for(int i = 0; i <= maxDegree; i++)
            if(ar[i])
            {
                ptr = ar[i];
                if(!min)
                {
                    min = ptr;
                    rootList = ptr;
                    ptr->left = ptr->right = ptr;
                }
                else
                {
                    if(ptr->key < min->key)
                        min = ptr;
                    ptr->right = rootList;
                    ptr->left = rootList->left;
                    rootList->left->right = ptr;
                    rootList->left = ptr;
                }
            }
    }
    void link(Node *y, Node *x)
    {
        y->left->right = y->right;
        y->right->left = y->left;
        if(x->child)
        {
            y->left = x->child->left;
            y->right = x->child;
            x->child->left->right = y;
            x->child->left = y;
        }
        else
        {
            y = x->child;
            y->left = y->right = y;
        }
        y->marked = false;
        y->parent = x;
        x->degree++;
    }
public:
    int size;
    Node* min, *rootList;
    FibonacciHeap()
    {
        size = 0;
        min = rootList = nullptr;
    }
    void insert(int key)
    {
        auto *ptr = new Node;
        ptr->key = key;
        ptr->left = ptr->right = ptr->parent = ptr->child = nullptr;
        ptr->degree = 0;
        ptr->marked = false;
        if(!min)
        {
            min = ptr;
            rootList = ptr;
            ptr->left = ptr->right = ptr;
        }
        else
        {
            if(ptr->key < min->key)
                min = ptr;
            ptr->right = rootList;
            ptr->left = rootList->left;
            rootList->left->right = ptr;
            rootList->left = ptr;
        }
        size++;
    }
    void decreaseKey(int k, Node *x)
    {
        if(k > x->key)
        {
            cout<<"New Key Greater";
            return;
        }
        x->key = k;
        Node *y = x->parent;
        if(y && x->key < y->key)
        {
            cut(x, y);
            cascadingCut(y);
        }
        if(x->key < min->key)
            min = x;
    }
    Node* deleteNode(Node *x)
    {
        decreaseKey(INT32_MIN, x);
        return extractMin();
    }
    friend void unite(FibonacciHeap &h, FibonacciHeap &h1, FibonacciHeap &h2);
    Node* extractMin()
    {
        Node *z = min;
        if(z)
        {
            if(z->child)
            {
                Node *start = z->child, *ptr = z->child, *save;
                do
                {
                    save = ptr->right;
                    ptr->right = rootList;
                    ptr->left = rootList->left;
                    ptr->parent = nullptr;
                    rootList->left->right = ptr;
                    rootList->left = ptr;
                    ptr = save;
                } while(ptr != start);
            }
            z->right->left = z->left;
            z->left->right = z->right;
            if(z == z->right)
                min = nullptr;
            else
            {
                min = z->right;
                consolidate();
            }
            size--;
        }
        return z;
    }
};
friend void unite(FibonacciHeap &h, FibonacciHeap &h1, FibonacciHeap &h2)
{
    h.min = h1.min;
    h.rootList = h1.rootList;
    h2.rootList->right->left = h.rootList->left;
    h.rootList->left->right = h2.rootList->right;
    h2.rootList->right = h.rootList;
    h.rootList->left = h2.rootList;
    if(h.min == nullptr || (h2.min != nullptr && h2.min < h1.min))
        h.min = h2.min;
    h.size = h1.size + h2.size;
}
int main()
{
    ios::sync_with_stdio(false);
    return 0;
}