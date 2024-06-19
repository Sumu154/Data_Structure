#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
public:
    T data;
    node *next;
};

template<class T>
class Queue{
public:
    node<T> *head;
    node<T> *tail;
    int size;

    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    node<T>* new_node(int data)
    {
        size++;
        node<T> *newnode = new node<T>;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }

    void enqueue(T data)
    {
        node<T> *newnode = new_node(data);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void dequeue()
    {
        if(size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }
        if(size == 1)
        {
            size--;
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        size--;
        node<T> *current = head;
        head = current->next;
        delete current;
    }

    int front()
    {
        if(size == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return head->data;
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


