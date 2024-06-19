#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i].first;       //pairer 1st value
        a[i].second = i;         //pairer 2nd value
    }
    sort(a.begin(), a.end());  //1st value wise sort korece

    for(int i=0 ; i<n ; i++){
        cout << "Value " << a[i].first
             << ", Previous Index " << a[i].second << "\n";
    }
}
