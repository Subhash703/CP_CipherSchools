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
    Node *getMiddleNode(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    Node *reverseList(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }
        Node *curr = head, *next = NULL, *prev = NULL;
        while (curr != NULL)
        {
            // 4 most important steps to follow
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node *reverseLastHalf(Node *currentHead)
    {
        if (currentHead == NULL)
        {
            return currentHead;
        }
        Node *curr = currentHead->next, *next = NULL, *prev = NULL;
        currentHead->next = NULL;
        while (curr != NULL)
        {
            // 4 most important steps to follow
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isListPalindrome(Node *root)
    {
        // Get the middle node
        Node *mid = getMiddleNode(root);
        cout << mid->data << " " << endl;
        // Reverse 2nd half of the list
        Node *lastHalfHead = reverseLastHalf(mid);
        // Compare both parts of the list
        // printList(lastHalfHead);
        Node *ptr1 = root, *ptr2 = lastHalfHead;
        while (ptr1 && ptr2)
        {
            if (ptr1->data != ptr2->data)
            {
                cout << "Not Palindrome!" << endl;
                return false;
            }
        }
        // Reverse 2nd half again
        cout << "Palindrome List!" << endl;
        return true;
    }
};

int main()
{
    SingliLinkedList list;
    for (int i = 5; i > 0; i--)
    {
        list.insertBiginning(i);
    }
    list.printList(list.head);
    list.isListPalindrome(list.head);
    cout << endl;

    SingliLinkedList list2;
    list2.insertBiginning(2);
    list2.insertBiginning(1);
    list2.insertInEnd(3);
    list2.insertInEnd(2);
    list2.insertInEnd(1);
    list2.printList(list2.head);
    list2.isListPalindrome(list2.head);
    return 0;
}