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
//
// Swap Kth node from beginning with Kth node from end in a Linked List
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

//
// Reverse alternate k nodes of a linkedlist
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 => 2->1->3->4->6->5;

Node *ReverseAlternateKnodes(Node *head, int K, bool flag)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head, *prev = NULL, *next = NULL;
    if (flag)
    {
        int k = 0;
        while (curr != NULL && k < K)
        {
            k++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (next != NULL)
            head->next = ReverseAlternateKnodes(next, K, !flag);
        return prev;
    }
    else
    {
        cout << curr->data << endl;
        int k = 0;
        while (curr != NULL && k < K)
        {
            k++;
            curr = curr->next;
        }
        if (curr != NULL)
            curr->next = ReverseAlternateKnodes(curr, K, !flag);
        return curr;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    Node *curr = ReverseAlternateKnodes(head, 2, true);
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}