#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left, *right;
    int frequency; // Frequency of Character(s)
    char character; // Character represented by leaf node otherwise '*'
};
struct compareNodes
{
    bool operator()(Node *first, Node *other) // Custom compare func. to use in heap
    {
        return first->frequency > other->frequency;
    }
};
int main()
{
    priority_queue<Node*, vector<Node*>, compareNodes> heap;
    int n, i;
    cin>>n;
    for(i = 0; i < n; i++) // Iniitalizations
    {
        auto z = new Node;
        z->left = z->right = nullptr;
        cin>>z->character>>z->frequency;
        heap.push(z);
    }
    for(i = 0; i < n - 1; i++)
    {
        auto z = new Node; // Create New Intermediate Node
        z->character = '*'; // Initialize to Default Values
        z->frequency = 0;
        z->left = heap.top();
        z->frequency += heap.top()->frequency; // Get Smallest Nodes 
        heap.pop();
        z->right = heap.top(); 
        z->frequency += heap.top()->frequency;
        heap.pop();
        heap.push(z); // Push the new Intermediate Node
    }
    auto z = heap.top();
    heap.pop();
    cout<<z->frequency; // Just O/P to verify result. Can fetch all codes for characters.
    return 0;
}
