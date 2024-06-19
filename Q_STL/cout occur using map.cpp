#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    map<int, int> m;
    for(int i=0 ; i<n ; i++){
       m[a[i]]++;      //here, key=first = a[i] ..value=second = m[a[i]]
    }
    for(auto i:m){
        cout << i.first << ":" << i.second << "\n";
    }
}
