#include<bits/stdc++.h>
using namespace std;

/*
arr te loop jehetu n bar cholbe tai
time complexity= O(n + 1 + n +1)  =O(2*n+2) = O(2*n) = O(n)
space complsxity= O(n+1)= O(n)
*/

int main()
{
    int n;
    cin >> n;  //memory nici O(1)
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){  //ei loope O(n)
        cin >> arr[i];
    }

    int maxi= arr[0];   // ei linegular jonno O(1)
    int mini= arr[0];
    int sum= 0;

    for(int i=0 ; i<n ; i++){      //ei loope O(n)
        maxi= max(maxi,arr[i]);
        mini= min(mini,arr[i]);
        sum= sum+arr[i];
    }

     cout << maxi << " " << mini << " " << sum << "\n"; // ekhane O(1)

}
