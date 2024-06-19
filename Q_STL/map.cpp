#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> m;

    //m[key] = value
    //insert = O(logn)
    m["sumaiya"] = 210041154;
    m["rohan"] = 210041151;
    m["sumaiya"] = 210041151;

    //print
    for(auto i:m){
        cout << i.first << " " << i.second << "\n";
    }

    cout << m["sumaiya"] << "\n";
    cout << m.size() << "\n";
}
