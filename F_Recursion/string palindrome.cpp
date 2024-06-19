#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s)
{
    //base case
    if(s=="" || s.size()==1)
        return true;

    int n = s.size();
    string smaller = s.substr(1, n-2);
    return palindrome(smaller) &&   (s[0]== s.back());

}

int main()
{
    string s;
    cin >> s;
    int res = palindrome(s);
    if(res == 1)
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";
}
