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
        m[a[i]]++;
        if(m.find(a[i]) != m.end())
        {
             cout << "First duplicate element is " << a[i]
                  << ", first occurring at index " << m[a[i]];
             break;
        }
        m[a[i]] = i;
    }
    if (m.empty()) {
        cout << "No duplicate element found." << "\n;
    }
}
