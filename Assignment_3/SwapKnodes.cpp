#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node()
    {
        Node(0);
    }
};
int getSize(Node *head)
{
    Node *curr = head;
    int size = 0;
    while (curr != NULL)
    {
        size++;
        curr = curr->next;
    }
    return size;
}

Node *SwapKthNode(Node *head, int K)
{
    if (head == NULL)
        return NULL;

    Node *curr = head, *prev = NULL, *next = NULL, *currLast = head, *prevLast = NULL, *nextLast = NULL;
    int n = getSize(head);
    if (K > n)
    {
        return head;
    }
    for (int i = 1; i < K; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    next = curr->next;
    // Kth node from the end will be (n-k+1)th node from the start
    for (int i = 1; i < (n - K + 1); i++)
    {
        prevLast = currLast;
        currLast = currLast->next;
    }
    nextLast = currLast->next;

    //
    cout << curr->data << " " << currLast->data << endl;

    prev->next = currLast;
    currLast->next = next;
    prevLast->next = curr;
    curr->next = nextLast;
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    Node *curr = SwapKthNode(head, 2);
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}