#include<bits/stdc++.h>
using namespace std;

int p = 31;
const int N = 1e5+3;
const int MOD = 1e9+7;
vector<long long> power(N);

long long calHash(string s)
{
    long long Hash = 0;
    for(int i=0 ; i<s.size() ; i++){
        Hash = (Hash + (s[i]-'a'+1)*power[i])%MOD;
    }
    return Hash;
}

int main()
{
    vector<string> a = {"aa", "ab", "aa", "b", "cc", "cc"};

    //
    power[0] = 1;
    for(int i=1 ; i<N ; i++){
        power[i] = (power[i-1]*p)%MOD;
    }

    vector<long long> hashes;
    for(auto i: a){
        hashes.push_back((calHash(i)));
    }
    sort(hashes.begin(), hashes.end());
//    for(auto i: hashes){
//        cout << i << " ";
//    }
    int count=0;
    for(int i=0 ; i<a.size() ; i++){
        if(i==0 or hashes[i]!=hashes[i-1]){
            count++;
        }
    }
    cout << count << "\n";

}
