#include<bits/stdc++.h>
using namespace std;



int main()
{
    unordered_map<int, int> mp;
    mp = {{1,3}, {2,1 }, {3,4 }};

    vector<pair<int, int>> a(mp.begin(), mp.end());
    sort(a.begin(), a.end(), [](const auto& b1, const auto& b2) {
        return b1.second > b2.second;
    });

    mp.clear();
    for(const auto& i : a) {
        mp[i.first] = i.second;
    }

    //arase
    mp.erase(1);

    for(auto i: mp){
        cout << i.first << " " << i.second << "\n";
    }

}
