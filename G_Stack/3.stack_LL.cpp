#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *prev;
    node *next;
};

class LinkedList{
public:

    node *head;
    int size;

    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    //creates new node with the given data
    node* new_node(int data)
    {
        size++;
        node *newnode = new node;
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;

        return newnode;
    }

    //print size of list
    int getsize()
    {
        return size;
    }

    void Insert_head(int data)
    {
       node *newnode = new_node(data);
       if(head == NULL)
       {
           head = newnode;
           return;
       }
       node *temp = head;
       newnode->next = temp;
       temp->prev = newnode;
       head = newnode;
    }


    void remove_head()
    {
        if(head == NULL)
        {
            return;
        }

        size--;
        node *current = head;
        node *temp = head->next;
        delete current;
        if(temp != NULL)
        {
            temp->prev = NULL;
        }
        head = temp;
    }
};

class Stack{
public:
    LinkedList l;

    Stack()
    {

    }

    void top()
    {
        if(l.getsize() == 0)
        {
            cout << "stack is empty\n";
            return;
        }
        cout <<  l.head->data << "\n";
    }

    void push(int value)
    {
        l.Insert_head(value);
    }

    void pop()
    {
        if(l.getsize() == 0)
        {
            cout << "stack is empty\n";
            return;
        }
        l.remove_head();
    }
};

int main()
{
    Stack st;

    st.push(1);
    st.top();
    st.push(2);
    st.top();
    st.push(3);
    st.top();

    st.pop();
    st.top();
    st.pop();
    st.top();
    st.pop();
    st.top();
}
