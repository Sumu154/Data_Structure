#include<bits/stdc++.h>
using namespace std;
/*
time= O(2^n)
space= O(n)
*/
int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int x= fib(n-1);
    int y= fib(n-2);
    return x+y;
}

/*for save
time= O(n)
space= O(1)
*/

int save[100];

int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(save != 0)
        return save[n];
    int x= fib(n-1);
    int y= fib(n-2);
    save[n]=x+y;
    return x+y;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
}
