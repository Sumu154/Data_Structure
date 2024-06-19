#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 100;

class Queue{
public:
    int a[MAX_SIZE];
    int l, r;

    Queue()
    {
        l= 0;
        r= -1;
    }

    void enqueue(int data)
    {
        if(r >= MAX_SIZE)
        {
            cout << "Queue is full\n";
            return;
        }
        r++;
        a[r] = data;
    }

    void dequeue()
    {
        if(l > r)
        {
            cout << "Queue is empty\n";
            return;
        }
        l++;
    }

    int front()
    {
        if(l > r)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return a[l];
    }

    int getsize()
    {
        return r-l+1;
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
