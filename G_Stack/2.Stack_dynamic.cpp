#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    int *a;
    int cap;
    int size;

    Stack()
    {
        a = new int[1];
        cap = 1;
        size = 0;
    }

    void increase()
    {
        cap = cap*2;
        int *temp = new int [cap];
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

    void push(int value)
    {
        if(size >= cap)
        {
             increase();
        }
        size = size+1;
        a[size-1] = value;
    }

    void pop()
    {
        if(size == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        a[size-1]=0;
        size = size-1;
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

