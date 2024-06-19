#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;

    //push
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.size() << "\n";
    cout << st.top() << "\n";

    st.pop();
    cout << st.size() << "\n";
    cout << st.top() << "\n";

    st.pop();
    cout << st.size() << "\n";
    cout << st.top() << "\n";

    st.pop();
    cout << st.size() << "\n";
    cout << st.top() << "\n";

}
