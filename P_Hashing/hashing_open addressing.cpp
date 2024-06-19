#include <bits/stdc++.h>
using namespace std;

class Hashing{
public:
    vector<int> hashtable;
    int bucket;
    int emptyMark;

    Hashing(int size)
    {
        bucket = size;
        emptyMark = numeric_limits<int>::min();
        hashtable.resize(size, emptyMark);
    }


    int hashFunction(int val)
    {
        return val%bucket; // Simple modulo hash function
    }

    void Insert(int val)
    {
        int idx = hashFunction(val);
        if(hashtable[idx]==emptyMark or hashtable[idx]==val){
            hashtable[idx] = val;
            return;
        }

 /*       //linear probing
        int i=1;
        int linIdx = (idx+i)%bucket; // Linear probing
        while(linIdx != idx) {
            if(hashtable[linIdx]==emptyMark or hashtable[linIdx] == val){
                hashtable[linIdx] = val;
                return;
            }
            i++;
            linIdx = (idx+i)%bucket;
        }
*/
        //quadratic probing
        int i = 1;
        int quadIdx = (idx+i*i)%bucket;
        while(quadIdx != idx) {
            if (hashtable[quadIdx]==emptyMark or hashtable[quadIdx]==val){
                hashtable[quadIdx] = val;
                return;
            }
            i++;
            quadIdx = (idx+i*i)%bucket;
        }

    }

    bool Search(int val)
    {
        int idx = hashFunction(val);

        if(hashtable[idx] == val) {
            return true;
        }

        int i = (idx+1)%bucket; // Linear probing
        while(i != idx) {
            if(hashtable[i] == val) {
                return true;
            }
            i = (i + 1) % bucket;
        }

        return false; // Key not found
    }

    bool Delete(int val)
    {
        int idx = hashFunction(val);

        if(hashtable[idx] == val) {
            hashtable[idx] = emptyMark; // Delete by marking as empty
            return true;
        }
/*
        int i = (idx + 1) % bucket; // Linear probing
        while (i != idx) {
            if (hashtable[i] == val) {
                hashtable[i] = emptyMark; // Delete by marking as empty
                return true;
            }
            i = (i+1)%bucket;
        }
*/
        //quadratic probing
        int i = 1;
        int quadIdx = (idx + i * i) % bucket;
        while (quadIdx != idx) {
            if (hashtable[quadIdx] == val) {
                hashtable[quadIdx] = emptyMark; // Delete by marking as empty
                return true;
            }
            i++;
            quadIdx = (idx + i * i) % bucket;
        }

        return false; // Key not found, unable to delete
    }

    void printTable()
    {
        for (int i = 0; i < bucket; ++i) {
            if (hashtable[i] != emptyMark) {
                cout << i << " --> " << hashtable[i] << endl;
            }
            else {
                cout << i << " --> " << endl;
            }
        }
    }

};

int main() {
    Hashing h(10);

    h.Insert(5);
    h.Insert(15);
    h.Insert(25);
    h.Insert(35);
    h.Insert(10);
    h.Insert(20);
    h.Insert(30);
    h.Insert(40);
    h.printTable();
    cout << "\n";

    h.Delete(15);
    h.printTable();
    cout << "\n";

    cout << "Search 25: " << (h.Search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 15: " << (h.Search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
