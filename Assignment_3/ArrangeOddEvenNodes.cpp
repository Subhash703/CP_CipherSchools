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

class SingliLinkedList
{
public:
    Node *head;
    SingliLinkedList()
    {
        this->head = NULL;
    }
    void insertBiginning(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertInEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
            head = newNode;
        else
        {
            Node *curr = head;
            while (curr->next)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    int getSize(Node *head)
    {
        Node *curr = head;
        int count = 0;
        while (curr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
    void printList(Node *head)
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    Node *ArrangeOddEvenNodes(Node *head)
    {
        int n = getSize(head);
        Node *tmp = head;
        Node *prev = NULL;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
            }
            else
            {
            }
        }
    }
};

int main()
{

    // Rearrange a linked list such that all even and odd positioned nodes are together

    SingliLinkedList list;
    vector<int> arr = {1, 3, 3, 3, 4, 5, 6, 7, 6, 6, 6};
    for (int i = 0; i < arr.size(); i++)
    {
        list.insertInEnd(arr[i]);
    }
    list.printList(list.head);

    Node *root = list.ArrangeOddEvenNodes(list.head);
    list.printList(root);
    return 0;
}