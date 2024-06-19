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
    int rev;

    Deque()
    {
        head = NULL;
        tail = NULL;
        size = 0;
        rev = 0;
    }

    node* new_node(int data)
    {
        node *newnode = new node;            //size++ ei functione dile kaj kore na kno????
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        return newnode;
    }

    //insert at end --> O(1)
    void Insert_end(int data)
    {
        node *newnode = new_node(data);
        if(size == 0)
        {
            size++;
            head = newnode;
            tail = newnode;
            return;
        }
        size++;
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    void push_back(int data)
    {
        if(rev == 0)
            Insert_end(data);
        else
            Insert_head(data);
    }

    //insert at head --> O(1)
    void Insert_head(int data)
    {
        node *newnode = new_node(data);
        if(size == 0)
        {
            size++;
            head = newnode;
            tail = newnode;
            return;
        }
        size++;
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    void push_front(int data)
    {
        if(rev == 0)
            Insert_head(data);
        else
            Insert_end(data);
    }

    //popback=remove at end --> O(1)
    void remove_end()
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
    void pop_back()
    {
        if(rev == 0)
            remove_end();
        else
            remove_head();
    }

    void remove_head()
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

    void pop_front()
    {
        if(rev == 0)
            remove_head();
        else
            remove_end();
    }

    int front()
    {
        if(size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }
        if(rev == 0)
            return head->data;
        else
            return tail->data;
    }

    int back()
    {
        if(size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }
        if(rev == 0)
            return tail->data;
        else
            return head->data;
    }

    void reverse_deque()
    {
        if(rev == 0)
            rev = 1;
        else
            rev = 0;
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

    cout << "Before reverse\n";
    cout << d.front() << "\n";
    cout << d.back() << "\n";

    d.reverse_deque();
    cout << "After reverse\n";
    cout << d.front() << "\n";
    cout << d.back() << "\n";
}
