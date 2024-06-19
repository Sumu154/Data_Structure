#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    st.push(4);
    st.push(2);
    st.push(5);


    stack<int>temp;

    while(!st.empty()){
        int now = st.top();
        st.pop();

        while(!temp.empty()){
            if(temp.top() < now){
                break;
            }
            st.push(temp.top());
            temp.pop();
        }
        temp.push(now);
    }

    swap(temp, st);

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }



    return 0;
}


