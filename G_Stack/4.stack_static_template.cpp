#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 100;

template<class T>
class Stack{
public:
    T a[MAX_SIZE];
    int size;

    Stack()
    {
        size = 0;
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
        if(size == MAX_SIZE)
        {
            cout << "Stack is full\n";
            return;
        }
        size++;
        a[size-1]= value;
    }

    void pop()
    {
        if(size == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        size--;
    }
};

int main()
{
    Stack<int> st;
    for(int i=0 ; i<10 ; i++){
        st.push(i*10);
    }
    for(int i=0 ; i<10 ; i++){
        st.top();
        st.pop();
    }
    st.pop();
}
