#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    int line = 1;
    stack<string> st;
    string s;

    for(int i=0 ; i<n; i++){
        string text;
        getline(cin, text);
        s += text + '\n';
    }

    for(int j = 0 ; j<s.length() ; j++){
        if(s[j] == '<'){
            int k = j+1;
            string tag;

            while(k<s.length() and s[k]!='>'){
                tag += s[k];
                k++;
            }

            if(!tag.empty() and tag[0] != '/'){
                st.push(tag);
            }
            else if(!tag.empty() and tag[0] == '/'){
                if (!st.empty() and st.top() == tag.substr(1)){
                    st.pop();
                }
                else{
                    cout << "Error at line " << line << "\n";
                    return 0;
                }
            }
        }

        if(s[j] == '\n'){
            line++;
        }
    }

    if(!st.empty()){
        cout << "Error at line " << line << endl;
    }
    else {
        cout << "No error" << endl;
    }
}

