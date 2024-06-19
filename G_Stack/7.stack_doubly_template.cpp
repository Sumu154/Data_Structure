#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
public:
    T data;
    node *prev;
    node *next;
};

template<class T>
class LinkedList{
public:

    node<T> *head;  //node ke already template kore felci..tai emn korte hbe
    int size;

    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    //creates new node with the given data
    node<T>* new_node(T data)
    {
        size++;
        node<T> *newnode = new node<T>;
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

    void Insert_head(T data)
    {
       node<T> *newnode = new_node(data);
       if(head == NULL)
       {
           head = newnode;
           return;
       }
       node<T> *temp = head;
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
        node<T> *current = head;
        node<T> *temp = head->next;
        delete current;
        if(temp != NULL)
        {
            temp->prev = NULL;
        }
        head = temp;
    }
};

template<class T>
class Stack{
public:
    LinkedList<T> l;

    Stack()
    {

    }

    T top()
    {
        if(l.getsize() == 0)
        {
            cout << "stack is empty\n";
            return -1;
        }
        return l.head->data;
    }

    void push(T value)
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

    int getsize()
    {
        return l.getsize();
    }
};

int main()
{
   /*

    stacke value push pop and view top value
    Stack<int> st;

    st.push(1);
    cout << st.top() << "\n";
    st.push(2);
    cout << st.top() << "\n";
    st.push(3);
    cout << st.top() << "\n";

    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";

    Stack<char> st2;
    st2.push('a');
    cout << st2.top() << "\n";
    st2.push('b');
    cout << st2.top() << "\n";
    st2.push('c');
    cout << st2.top() << "\n";

    st2.pop();
    cout << st2.top() << "\n";
    st2.pop();
    cout << st2.top() << "\n";
    st2.pop();
    cout << st2.top() << "\n";
    */

 /*
    //reverse the stack element
    Stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);

    Stack<int> temp;
    while(a.getsize() > 0)
    {
        temp.push(a.top());
        a.pop();
    }
    swap(a,temp);

    //check korar jonno kaj ta hocce naki
    while(a.getsize() > 0)
    {
        cout << a.top() << "\n";
        a.pop();
    }
  */
    //sort korbo
    Stack<int> a;
    a.push(1);
    a.push(2);
    a.push(6);
    a.push(4);

    Stack<int> temp;
    while(a.getsize() > 0)
    {
        int t = a.top();
        a.pop();
        while(temp.getsize() > 0)
        {
            if(temp.top() < t)
            {
                break;
            }
            a.push(temp.top());
            temp.pop();
        }
        temp.push(t);
    }
    swap(a,temp);

    //sort hoice kina check korar jonno
    while(a.getsize() > 0)
    {
        cout << a.top() << "\n";
        a.pop();
    }
}

