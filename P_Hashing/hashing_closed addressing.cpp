#include<bits/stdc++.h>
using namespace std;

class Hashing{
public:
    vector<list<int>> hashtable;
    int bucket;

    Hashing(int size)
    {
        bucket = size;
        hashtable.resize(size);
    }

    int hashFunction(int val)
    {
        return val%bucket;
    }

    void addval(int val)
    {
        int idx = hashFunction(val);
        hashtable[idx].push_back(val);
    }

    list<int>::iterator Search(int val)
    {
        int idx = hashFunction(val);
        list<int>:: iterator it = find(hashtable[idx].begin(), hashtable[idx].end(), val);
        return it;

    }

    void Delete(int val)
    {
        int idx = hashFunction(val);
        if(Search(val) == hashtable[idx].end()){
            cout << "key is not present\n";
            return;
        }
        hashtable[idx].erase(Search(val));
        cout << val << " is deleted\n";
    }

    void printTable() {
        for (int i = 0; i < bucket; ++i) {
            cout << i << " --> ";
            for (int val : hashtable[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Hashing h(10);

    h.addval(5);
    h.printTable();
    h.Delete(5);
    h.Delete(5);
}
