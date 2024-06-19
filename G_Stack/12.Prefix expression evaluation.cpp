#include<bits/stdc++.h>
using namespace std;

int PrefiEvaluation(string s)
{
    stack<int> st;
    for(int i=s.size()-1 ; i>=0 ; i--){
        if(s[i]>='0' and s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
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
-+7*45+20

output
25

*/

int main()
{
    string s;
    cin >> s;
    cout << PrefiEvaluation(s);
}
