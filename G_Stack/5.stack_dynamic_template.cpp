#include<bits/stdc++.h>
using namespace std;

template<class T>
class Stack{
public:
    T *a;
    int cap;
    int size;

    Stack()
    {
        a = new T[1];
        cap = 1;
        size = 0;
    }

    void increase()
    {
        cap = cap*2;
        T *temp = new T [cap];
        for(int i=0 ; i<size ; i++){
            temp[i] = a[i];
        }
        swap(a,temp);
        delete []temp;
    }

    void top()
    {
        if(size == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << a[size-1] << "\n";
    }

    void push(T value)
    {
        if(size+1 > cap)
        {
             increase();
        }
        size++;
        a[size-1] = value;
    }

    void pop()
    {
        if(size == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        //a[size-1]=0;
        size--;
    }
};

int main()
{
    Stack<int> st;

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

    Stack<char> st2;
    st2.push('a');
    st2.top();
    st2.push('b');
    st2.top();
    st2.push('c');
    st2.top();

    st2.pop();
    st2.top();
    st2.pop();
    st2.top();
    st2.pop();
    st2.top();



}

