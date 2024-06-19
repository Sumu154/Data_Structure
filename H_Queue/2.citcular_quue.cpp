#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 100;

class Queue{
public:
    int a[MAX_SIZE];
    int l,r;
    int size;

    Queue()
    {
        l= 0;
        r= -1;
        size = 0;
    }

    void enqueue(int data)
    {
        if(size == MAX_SIZE)
        {
            cout << "Queue is full\n";
            return;
        }
        size++;
        r++;
        if(r == MAX_SIZE)
        {
            r=0;
        }
        a[r] = data;
    }

    void dequeue()
    {
        if(size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }
        size--;
        l++;
        if(l == MAX_SIZE)
        {
            l = 0;
        }
    }

    int front()
    {
        if(size == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return a[l];
    }

    int getsize()
    {
        return size;
    }
};

int main()
{
    Queue q;

    for(int i=0 ; i<5 ; i++){
       q.enqueue(i*10);
    }

    for(int i=0 ; i<5 ; i++){
        cout << q.front() << "\n";
        q.dequeue();
    }
    q.dequeue();
}

