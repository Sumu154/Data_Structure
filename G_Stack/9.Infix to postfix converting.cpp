#include<bits/stdc++.h>
using namespace std;

/*
input:  a+b
output: ab+

*/

int prec(char ch)
{
    if(ch=='+' or ch=='-'){
        return 0;
    }
    else{
        return 1;
    }
}


int main()
{
    string s;
    cin >> s;
    string ans;

    stack<char> st;
    for(int i=0 ; i<s.size() ; i++){
        char now = s[i];
        if(now>='a' and now<='z'){
            ans += now;
        }
        else{
            while(st.size() and prec(st.top()) >= prec(now)){
                ans += st.top();
                st.pop();
            }
            st.push(now);
        }
    }
    while(st.size()){
        ans += st.top();
        st.pop();
    }
    cout << ans;
}

