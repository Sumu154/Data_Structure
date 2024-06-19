#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    int maxi= max(a,b,c);
    int mini= min(a,b,c);
    int sum= a+b+c;
    int mul= a*b*c;

    cout << maxi << " " << mini << " " << sum << " " << mul << "\n";

    /*

    time complexity= O(1)  ...jehetu constant number of instruction
    space complexity= O(1)...constant..inputer opor dependant noy

   */
}
