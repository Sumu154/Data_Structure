#include<bits/stdc++.h>
using namespace std;

int PostfixEvaluation(string s)
{
    stack<int> st;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]>='0' and s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            if(s[i]=='+'){
                st.push(op1+op2);
            }
            else if(s[i]=='-'){
                st.push(op1-op2);
            }
            else if(s[i]=='*'){
                st.push(op1*op2);
            }
            else if(s[i]=='/'){
                st.push(op1/op2);
            }
            else if(s[i]=='^'){
                st.push(pow(op1,op2));
            }
        }
    }
    return st.top();
}

/*
input
46+2/5*7+

output
32

*/

int main()
{
    string s;
    cin >> s;
    cout << PostfixEvaluation(s);
}
