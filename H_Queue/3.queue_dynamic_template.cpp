#include<bits/stdc++.h>
using namespace std;

template<class T>
class Queue{
public:
    T *a;
    int l,r;
    int size;
    int cap;

    Queue()
    {
        a = new T[1];
        cap = 1;
        l= 0;
        r= -1;
        size = 0;
    }

    void remove_circle()
    {
        T *temp = new T[cap];
        int idx = 0;
        for(int i=l ; i<cap ; i++){
            temp[idx] = a[i];
            idx++;
        }
        for(int i=0 ; i<=r ; i++){
            temp[idx] = a[i];
            idx++;
        }
        swap(a,temp);
        delete []temp;
        l=0;
        r= cap-1;
    }


    void increase()
    {
        remove_circle();

        cap = cap*2;
        T *temp = new T[cap];
        for(int i=0 ; i<size ; i++){
            temp[i] = a[i];
        }
        swap(a,temp);
        delete []temp;
    }

    void enqueue(T data)
    {
        if(size == cap)
        {
            increase();
        }
        size++;
        r++;
        if(r == cap)
        {
            r = 0;
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
        if(l == cap)
        {
            l = 0;
        }
    }

    T front()
    {
        if(size == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return a[l];
    }
};

int main()
{
    Queue<int> q;

    for(int i=0 ; i<5 ; i++){
       q.enqueue(i*10);
    }

    for(int i=0 ; i<5 ; i++){
        cout << q.front() << "\n";
        q.dequeue();
    }
    q.dequeue();
}

