#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

void traverseList(Node *head)
{
    // Node h hi nhi
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    // 1 -> 2 -> 3 -> 4 ->5 -> NULL
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " "; //
        // if(curr->data == 5){
        //     return true;     //Agr search krna hota to
        // }
        curr = curr->next;
    }
}

// Insert => head | index  | tail
Node *InsertStart(Node *head, int x)
{
    Node *newNode = new Node(x); // Node create ho gya h
    // Agar list empty h
    if (head == NULL)
    { // head = NULL
        head = newNode;
        return head;
    }
    // 15 -> 10 -> NULL           | newNode(-1)->null        => -1 -> 15 -> 10->NULL
    newNode->next = head; // -1 -> 15 -> 10
    head = newNode;       // 15 -> 10 -> NULL;

    return head;
}

int getLenght(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

Node *DeleteNode(Node *head, int k)
{
    // 5 | 3
    int n = getLenght(head);
    if (k > n)
    {
        cout << "Itne element h hi nhi" << endl;
        return head;
    }
    // -1 -> 15 -> 10 -> NULL
    if (k == 1)
    {
        Node *tmp = head;
        head = head->next; // 15->10->NULL
        delete tmp;
        return head;
    }
    else if (k == n)
    {
        // phle last node tk traverse krte h
        // -1 -> 15 -> 10  -> NULL
        Node *curr = head, *prev = NULL;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        // prev = 15, curr = 10
        prev->next = NULL;
        delete curr;
    }
    else
    {
        // -1 -> 8 -> 5 -> 15 -> 10  -> NULL , k = 3
        Node *curr = head, *prev = NULL;
        int count = 1;
        while (count < k)
        {
            count++; // 1 -> 2 -> 3
            prev = curr;
            curr = curr->next;
        }
        // prev = 8, curr = 5;
        prev->next = curr->next;
        delete curr;
    }
    return head;
}
Node *reverseListHelper(Node *head)
{
    if (head == NULL)
        return head;
    Node *curr = head, *next = NULL, *prev = NULL;
    next = curr->next;
    curr->next = prev;
    prev = curr;
    return reverseListHelper(next);
}
Node *reverseList(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    // 1 -> 2 -> 3 -> 4
    return reverseListHelper(head);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(26);
    head->next->next = new Node(334);           // 1 -> 2 -> 3 -> NULL
    head->next->next->next = new Node(42);      //1 -> 2 -> 3 -> 4 -> NULL
    head->next->next->next->next = new Node(5); //1 -> 2 -> 3 -> 4 -> 5 ->NULL
    // Traverse List
    traverseList(head);
    cout << endl;
    Node *newList = NULL; // newList=NULL;
    newList = InsertStart(newList, 10);
    cout << "Value1 : " << newList->data << "\n"; // newList = 10->NULL
    newList = InsertStart(newList, 15);
    cout << "Value2 : " << newList->data << "\n"; // 15 -> 10 -> NULL
    newList = InsertStart(newList, -1);
    cout << "Value3 : " << newList->data << "\n";
    traverseList(newList); // -1 -> 10 -> NULL
    cout << endl;
    // Deletion at 2nd position
    newList = DeleteNode(newList, 2);
    traverseList(newList); // -1 -> 10 -> NULL
    return 0;
}
