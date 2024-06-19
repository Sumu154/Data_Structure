#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> s;

    //O(logn)
    s.insert(3);
    s.insert(4);
    s.insert(7);
    s.insert(5);
    s.insert(3);
    s.insert(5);

    //way 1 O(n)
    for(int i:s)
        cout << i << " ";
    cout << "\n";

    //way 2 O(n)
    for(auto it=s.begin() ; it!=s.end() ; it++){  // int dile kaj kore na
        cout << *it << " ";
    }
    cout << "\n";

    //size O(1)
    cout << s.size() << "\n";

    //erase O(logn)
    s.erase(3);  //all 3 delete hoye jabe
    for(int i:s)
        cout << i << " ";
    cout << "\n";

    //erase shudhu ekta delete koara jonno
    s.erase(s.find(5));
    for(int i:s)
        cout << i << " ";
    cout << "\n";


    cout << s.size() << "\n";

    //find O(logn)
    if(s.find(4) != s.end()) //4 seter kon memory te ace oi iterator ta return kore find function
        cout << "found\n";
    else
        cout << "Not found\n";



}

