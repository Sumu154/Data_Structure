#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
public:
    T data;
    node *next;
};


template<class T>
class LinkedList{
public:
    node<T> *head;
    int size;

    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    int getsize()
    {
        return size;
    }

    node<T>* new_node(int data)
    {
        size++;
        node<T> *newnode = new node<T>;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }

    void Insert_head(int data)
    {
        node<T> *newnode = new_node(data);
        if(head == NULL)
        {
            head = newnode;
            return ;
        }
        newnode->next = head;
        head = newnode;
    }

    void remove_head()
    {
        if(head == NULL)
            return;

        size--;
        node<T> *current = head;
        head = current->next;
        delete current;
    }
};

template<class T>
class Stack{
public:
    LinkedList<T> l;

    Stack()
    {

    }

    void top()
    {
        if(l.getsize() == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << l.head->data << "\n";
    }

    void push(T value)
    {
        l.Insert_head(value);
    }

    void pop()
    {
        if(l.getsize() == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        l.remove_head();
    }
};

int main()
{
    Stack<int> a;

    for(int i=0 ; i<10 ; i++){
        a.push(i*10+10);
    }

    for(int i=0 ; i<10 ; i++){
        a.top();
        a.pop();
    }
    a.top();
}

