#include<bits/stdc++.h>
using namespace std;

int p = 31;
const int N = 1e5+9l;
const int MOD = 1e9+7;
vector<int> power(N); //31 er power gula store rakhbo ekhane;

int calHash(string s)
{
    int Hash = 0;
    for(int i=0 ; i<s.size() ; i++){
        Hash = (Hash + (s[i]-'a'+1)*power[i])%MOD;
    }
    return Hash;
}

int main()
{
    vector<string> a = {"aa", "a", "bb"};

    //31 er power gula calculate
    power[0] = 1;
    for(int i=1 ; i<N ; i++){
        power[i] = (power[i-1]*p)%MOD;
    }

    vector<int> hashes;     //stringer hashgula strore korar jonno
    for(auto i: a){
        hashes.push_back(calHash(i));
    }

    cout << "string \t\t" << "hash\n";
    for(int i=0 ; i<a.size() ; i++){
        cout << a[i] << "\t\t" << hashes[i] << "\n";
    }


}
