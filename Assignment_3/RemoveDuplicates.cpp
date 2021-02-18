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
    Node *RemoveDuplicates(Node *root)
    {
        if (root == NULL || root->next == NULL)
        {
            return NULL;
        }
        Node *ptr = root;
        Node *nxt = NULL;
        while (ptr->next != NULL)
        {
            if (ptr->data == ptr->next->data)
            {
                nxt = ptr->next;
                ptr->next = nxt->next;
                delete nxt;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        return root;
    }
};

int main()
{
    SingliLinkedList list;
    vector<int> arr = {1, 3, 3, 3, 4, 5, 6, 7, 6, 6, 6};
    for (int i = 0; i < arr.size(); i++)
    {
        list.insertInEnd(arr[i]);
    }
    list.printList(list.head);

    Node *root = list.RemoveDuplicates(list.head);
    list.printList(root);
    return 0;
}