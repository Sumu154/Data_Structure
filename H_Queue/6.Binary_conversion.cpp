#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");

    cout << "Binary representation of 1-" << n << "\n";
    for(int i=0 ; i<n ; i++){
        cout << q.front();
        string temp = q.front();
        q.pop();
        q.push(temp+"0");
        q.push(temp+"1");
        cout << "\n";
    }
}
