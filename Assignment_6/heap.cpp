#include <bits/stdc++.h>

using namespace std;

class MinHeap
{
    int *harr;
    int count;
    int capacity;

    int parent(int index)
    {
        return (index - 1) / 2;
    }
    int leftChild(int index)
    {
        return (2 * index + 1);
    }
    int rightChilde(int index)
    {
        return (2 * index + 1);
    }

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        this->count = 0;
        this->harr = new int[this->capacity];
    }
};

int main()
{

    return 0;
}