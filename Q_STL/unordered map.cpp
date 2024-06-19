#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> m;  // <key, value>

    m.insert({"sumaiya",210041154});
    m["rohan"] = 210041151;

    for(pair<string,int> i:m){
        cout << i.first << "," << i.second << "\n";
    }
    for(auto i=m.begin() ; i!=m.end() ; i++){
        cout << (*i).first << "," << (*i).second << "\n";
    }

    cout << m.bucket_count() << "\n";

    cout << m.bucket("sumiaya") << "\n"; //sumiya key ta koto no buckete ace

    cout << m.bucket_size(2) << "\n";     //5 bucketer vitor koto ace

    cout << m.count("sumaiya") << "\n"; //sumaiya key ta koibar gece
}
