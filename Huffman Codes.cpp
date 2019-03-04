#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left, *right;
    int frequency;
    char character;
};
struct compareNodes
{
    bool operator()(Node *first, Node *other)
    {
        return first->frequency > other->frequency;
    }
};
int main()
{
    priority_queue<Node*, vector<Node*>, compareNodes> heap;
    int n, i;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        auto z = new Node;
        z->left = z->right = nullptr;
        cin>>z->character>>z->frequency;
        heap.push(z);
    }
    for(i = 0; i < n - 1; i++)
    {
        auto z = new Node;
        z->character = '*';
        z->frequency = 0;
        z->left = heap.top();
        z->frequency += heap.top()->frequency;
        heap.pop();
        z->right = heap.top();
        z->frequency += heap.top()->frequency;
        heap.pop();
        heap.push(z);
    }
    auto z = heap.top();
    heap.pop();
    cout<<z->frequency;
    return 0;
}