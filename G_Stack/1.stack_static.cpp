 #include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;

class Stack{
public:
    int a[MAX_SIZE];
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

    //stacker tope data push kora
    void push(int value)
    {
        if(size == MAX_SIZE)
        {
            cout << "Stack is full\n";
            return;
        }
        size++;
        a[size-1] = value;
    }

    //stacker top theke value remove kora
    void pop()
    {
        if(size == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        a[size-1]=0;
        size--;
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
