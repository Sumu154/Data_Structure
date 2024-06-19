#include<bits/stdc++.h>
using namespace std;

int calculate(char ch, int n1, int n2)
{
    if(ch == '+')
        return n1+n2;
    else if(ch == '-')
        return n1-n2;
    else if(ch == '*')
        return n1*n2;
    else if(ch == '/')
        return n1/n2;

        return -1;

}

int operation(string &s)
{
    stack<int>digit;
    stack<char>sign;

    for(int i=0; i<s.size(); i++)
    {
        char now = s[i];

        if(now>='1' && now<='9'){
            digit.push(now - '0');
        }
        else if(now == '('){
            sign.push(now);
        }
        else if(now == ')'){
            while(sign.top() != '(' ){
                int num2 = digit.top();
                digit.pop();

                int num1 = digit.top();
                digit.pop();

                char a = sign.top();
                sign.pop();

                int res = calculate(a, num1, num2);

                digit.push(res);
            }
            sign.pop();
        }
        else{
            while(sign.size() && sign.top() != '('){
                char ch = sign.top();

                if((now=='*' || now=='/') && (ch=='+' || ch=='-')){
                    break;
                }

                int num2 = digit.top();
                digit.pop();

                int num1 = digit.top();
                digit.pop();

                char a = sign.top();
                sign.pop();

                int res = calculate(a, num1, num2);

                digit.push(res);
            }

            sign.push(now);
        }
    }

    while(sign.size())
    {
        int num2 = digit.top();
        digit.pop();

        int num1 = digit.top();
        digit.pop();

        char a = sign.top();
        sign.pop();

        int res = calculate(a, num1, num2);

        digit.push(res);
    }

    return digit.top();
}

int main()
{
    string s;
    cin >> s;

    int result = operation(s);


    if(result == -1)
    {
        cout << "Error\n";
        return 0;
    }
    cout << result << "\n";

}

