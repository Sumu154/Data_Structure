#include<bits/stdc++.h>
using namespace std;

//all function in O(1)
int main()
{
    queue<int> q;

for(int i=0 ; i<5 ; i++){
       q.push(i*10);
    }

    for(int i=0 ; i<5 ; i++){
        cout << "size=" << q.size() << " ";
        cout << q.front() << "\n";
        q.pop();
    }
    cout << q.empty();   //q ta ki empty kina..empty hole true return
}
