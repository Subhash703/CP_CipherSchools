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

Node *reverseLinkedListInGroupsHelper(Node *head, int K)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head, *prev = NULL, *next = NULL;
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
        head->next = reverseLinkedListInGroupsHelper(next, K);
    return prev;
}

Node *ReverseInGroups(Node *head, int k)
{
    return reverseLinkedListInGroupsHelper(head, k);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head = ReverseInGroups(head, 3);
    Node *curr = head;

    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}