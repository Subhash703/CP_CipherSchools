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
    bool DetectLoop(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return false;

        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }

    // 1->2->3->4->5->6->3->4
    void removeTheLoop(Node *root)
    {
        bool isLoop = false;
        Node *slow = root, *fast = root;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isLoop = true;
                break;
            }
        }
        cout << slow->data << " " << fast->data << endl;
        if (isLoop)
        {
            if (slow == fast)
            {
                while (fast->next != slow)
                {
                    fast = fast->next;
                }
            }
            else
            {
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            // Line removing the loop
            fast->next = NULL;
        }
    }
};

int main()
{
    SingliLinkedList list;
    for (int i = 8; i > 0; i--)
    {
        list.insertBiginning(i);
    }
    list.head->next->next->next->next->next->next->next = list.head->next->next;
    // list.printList(list.head);
    cout << list.DetectLoop(list.head) << " ";
    cout << endl;
    list.removeTheLoop(list.head);
    cout << list.DetectLoop(list.head) << " " << endl;
    list.printList(list.head);
    return 0;
}