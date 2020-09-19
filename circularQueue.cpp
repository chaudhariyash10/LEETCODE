#include <stdc++.h>

using namespace std;

class MyCircularQueue
{
private:
    vector<int> v;
    int head, tail, size, maxsize;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
    {
        v.resize(k);
        head = -1;
        tail = -1;
        size = 0;
        maxsize = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (head == -1)
        {
            v[0] = value;
            head++;
            tail++;
            size++;
            return true;
        }
        else if (size == maxsize)
        {
            return false;
        }
        else
        {
            v[(tail + 1) % maxsize] = value;
            tail = (tail + 1) % maxsize;
            size++;
            return true;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (head == -1)
            return false;

        else if (head == tail)
        {
            head = -1;
            tail = -1;
            size = 0;
            return true;
        }
        else
        {
            head = (head + 1) % maxsize;
            size--;
            return true;
        }
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (head != -1)
            return v[head];
        return -1;
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (tail != -1)
            return v[tail];
        return -1;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        if (head == -1)
            return true;
        else
        {
            return false;
        }
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
       if(size == maxsize)
       {
           return true;
       }
       return false;

    }
};

int main()
{
    MyCircularQueue *que = new MyCircularQueue(5);

    cout << que->isEmpty();

    cout << que->enQueue(5);
    cout << que->enQueue(4);
    cout << que->deQueue();
    cout << que->enQueue(3);
    cout << que->enQueue(2);
    cout << que->deQueue();
    cout << que->enQueue(1);
    cout << que->enQueue(8);
    cout << que->enQueue(9);
    cout << que->Front();
    cout << que->Rear();
    cout << que->isFull();
    cout << que->deQueue();

    cout << que->isFull();
}