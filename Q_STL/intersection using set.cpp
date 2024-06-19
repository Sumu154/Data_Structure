#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a;
    cin >> n;
    set<int> s1;
    for(int i=0 ; i<n ; i++){
        cin >> a;
        s1.insert(a);
    }

    cin >> m;
    set<int> s2;
    for(int i=0 ; i<m ; i++){
        cin >> a;
        s2.insert(a);
    }

    set<int> intersect;
    for(int i:s1){
        if(s2.find(i) != s2.end())
        {
            intersect.insert(i);
        }
    }

    for(int i:intersect){
        cout << i << " ";
    }
}
