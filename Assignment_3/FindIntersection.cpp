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

    Node *findIntersectionNodeHelper(Node *larger, Node *smaller, int difference)
    {
        Node *ptr = larger, *qtr = smaller;
        for (int i = 0; i < difference; i++)
        {
            if (ptr == NULL)
            {
                return NULL;
            }
            ptr = ptr->next;
        }
        while (ptr != NULL && qtr != NULL)
        {
            if (ptr == qtr)
            {
                return ptr;
            }
            ptr = ptr->next;
            qtr = qtr->next;
        }
        return NULL;
    }

    Node *findIntersectionNode(Node *root1, Node *root2)
    {
        if (root1 == NULL || root2 == NULL)
        {
            return NULL;
        }
        int size1 = getSize(root1);
        int size2 = getSize(root2);
        int d = size1 - size2;
        if (d >= 0)
        {
            return findIntersectionNodeHelper(root1, root2, d);
        }
        else
        {
            return findIntersectionNodeHelper(root2, root1, -d);
        }
    }
};

int main()
{
    SingliLinkedList list1, list2;
    for (int i = 8; i > 0; i--)
    {
        list1.insertBiginning(i);
    }
    for (int i = 4; i > 0; i++)
    {
        list2.insertInEnd(i);
    }
    list1.head->next->next->next = list2.head;

    return 0;
}