#include <bits/stdc++.h>
using namespace std;

int p = 31;
const int N = 1e5+3;
int MOD = 1e9 + 9;
vector<long long> power(N);

void rabinKarpSearch(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();

    power[0] = 1;
    for(int i=1 ; i<=n1 ; i++){
        power[i] = (power[i-1]*p)%MOD;
    }

    // t er hashvalue ber kore rakhlam
    long long h = 0;
    for(int i=0 ; i<n2 ; i++){
        h = (h+(t[i]-'a'+1)*power[i])%MOD;
    }
    cout << "hash of t: " << h << "\n";

    //s er hasher array
    vector<long long> hashes(n1+1, 0);
    for(int i=0 ; i<n1 ; i++){
        hashes[i+1] =(hashes[i]+(s[i]-'a'+1)*power[i])%MOD;
    }

    //now calculate index
    for(int i=0 ; i+n2-1<n1 ; i++){
        long long curr_hash = (hashes[i+n2]+MOD-hashes[i])%MOD;
        if(curr_hash == h*power[i]%MOD){     //*
            cout<<"pattern occurs in the given string at "<<i<<endl;
        }
    }
}

//* ekhane %MOD use na korle only first index na ashbe,,ar use korle shb index pabo

int main()
{
    string s = "aaaaabaabaaaaabbb";
    string t = "aab";

    rabinKarpSearch(s,t);

    return 0;
}
