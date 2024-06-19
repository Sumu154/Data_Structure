#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> p;

    p.push(5);
    p.push(7);
    p.push(10);
    p.push(1);
    p.push(2);

    while(p.size() != 0)
    {
        cout << p.top() << " ";
        p.pop();
    }
    cout << "\n";

}

