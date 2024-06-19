#include <bits/stdc++.h>
using namespace std;

/*
4 2
apple app sumaiya sum
app sum

output:
2
2

*/

class node{
public:
    node *child[26];
    bool endmark;
    int count;

    node()
    {
        for (int i=0; i<26; i++) {
            child[i] = NULL;
        }
        endmark = false;
        count = 0;
    }
};

class Trie{
public:
    node *root;

    Trie()
    {
        root = new node();
    }

    void Insert(string word)
    {
        node *a = root;
        for (char i: word) {
            int idx = i-'a';
            if (!a->child[idx]) {
                a->child[idx] = new node();
            }
            a = a->child[idx];
            a->count++;
        }
    }

    int CountPre(string pre) {
        node *a = root;
        for (char i: pre) {
            int idx = i-'a';
            if (!a->child[idx]) {
                return 0; // No words with this prefix
            }
            a = a->child[idx];
        }
        return a->count;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    Trie t;

    for (int i=0; i<n; i++) {
        string word;
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower); // Convert to lowercase
        t.Insert(word);
    }

    for (int i = 0; i < q; i++) {
        string pre;
        cin >> pre;
        transform(pre.begin(), pre.end(), pre.begin(), ::tolower); // Convert to lowercase
        int count = t.CountPre(pre);
        cout << count << endl;
    }

}

