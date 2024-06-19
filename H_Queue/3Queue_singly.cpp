#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
};

class Queue{
public:
    node *head;
    node *tail;
    int size;

    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    node* new_node(int data)
    {
        size++;
        node *newnode = new node;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }

    void enqueue(int data)
    {
        node *newnode = new_node(data);
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
        node *current = head;
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
