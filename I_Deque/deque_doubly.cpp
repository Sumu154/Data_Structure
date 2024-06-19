#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *prev;
    node *next;
};

class Deque{
public:
    node *head;
    node *tail;
    int size;

    Deque()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    node* new_node(int data)
    {
        size++;
        node *newnode = new node;            //size++ ei functione dile kaj kore na kno????
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        return newnode;
    }

    //pushback=insert at end --> O(1)
    void push_back(int data)
    {
        node *newnode = new_node(data);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }

    //pushfront=insert at head --> O(1)
    void push_front(int data)
    {
        node *newnode = new_node(data);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }

    //popback=remove at end --> O(1)
    void pop_back()
    {
        if(size == 0)
        {
            cout << "Deque is empty\n";
            return;
        }
        if(size == 1)
        {
            size--;
            delete tail;
            head = NULL;
            tail = NULL;
            return;
        }
        size--;
        node *temp = tail;
        tail = tail->prev;
        delete temp;
        tail->next = NULL;
    }

    void pop_front()
    {
        if(size == 0)
        {
            cout << "Deque is empty\n";
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
        node *temp = head;
        head = head->next;
        delete temp;
        head->prev = NULL;
    }

    int front()
    {
        if(size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }
        return head->data;
    }

    int back()
    {
        if(size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }
        return tail->data;
    }
};

int main()
{
    Deque d;

    d.push_back(30);
    d.push_back(40);
    d.push_back(50);

    d.push_front(20);
    d.push_front(10);

    d.pop_back();
    d.pop_front();

    cout << d.front() << "\n";
    cout << d.back() << "\n";
}
