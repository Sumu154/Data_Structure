#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T> using pbds = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;


int main()
{
    int n;
    cin >> n;
    pbds<int> p;
    for(int i=0 ; i<n ; i++){        // 4 5 3 4 5
        int x;
        cin >> x;
        p.insert(x);
    }

    for(int i: p){
        cout << i << " ";
    }cout << "\n";


    // extra functionality
    cout << p.order_of_key(5) << "\n";           // 5 er cheye strickly koita value choto ace

    auto it = p.find_by_order(0);   //0 tomo index e je value ace tar iterator pabo  (pbds er)
    cout << *it << "\n";



    /* pair nibo for erase function */
    // int n;
    // cin >> n;
    // pbds<pair<int,int>> p;
    // for(int i=0 ; i<n ; i++){
    //     int x;
    //     cin >> x;
    //     p.insert({x,i});     //{val, index}
    // }

    // for(auto i: p){
    //     cout << i.first << " " << i.second << "\n";
    // } 

    // //erase function
    // p.erase({4,3});
    // for(auto i: p){
    //     cout << i.first << " " << i.second << "\n";
    // } 

    
}


