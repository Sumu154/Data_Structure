#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node *child[26];
    bool endmark;

    node()
    {
        for(int i=0 ; i<26 ; i++){
            child[i] = NULL;
        }
        endmark = false;
    }
};

class Trie{
public:
    node *root;

    Trie()
    {
        root = new node();
    }

    void Insert(string s)
    {
        node *a = root;
        for(int i=0 ; i<s.size() ; i++){
            int idx = s[i]- 'a';
            if(a->child[idx] == NULL){
                a->child[idx] = new node();
            }
            a = a->child[idx];
        }
        a->endmark = true;
    }

    void Delete(node *a, string s, int depth)
    {
        if(a==NULL){
            return;
        }
        if(depth == s.size()){
            if(a->endmark){
                a->endmark = false;
            }
            return;
        }

        int idx = s[depth]- 'a';
        Delete(a->child[idx], s, depth+1);

        if(!a->endmark){
            bool isEmpty = true;  //dhore nici endmarker por onno kono stringer part nai
            for(int i=0 ; i<26 ; i++){
                if(a->child[i]){
                    isEmpty = false;  //jodi thake
                    break;
                }
            }
            if(isEmpty){
                delete a;  //jodi asholei na thake delete a
                a = NULL;
            }
        }
    }

    bool Search(string s)
    {
        node *a = root;
        for(int i=0 ; i<s.size() ; i++){
            int idx = s[i]- 'a';
            if(a->child[idx] == NULL){
                return false;
            }
            a = a->child[idx];
        }
        return a and a->endmark;
    }

};

int main()
{
    Trie t;

    t.Insert("sumu");
    t.Insert("sumaiya");
    t.Insert("app");
    t.Insert("apple");

    if(t.Search("sumu")){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    t.Delete(t.root, "sumu", 0);
    if(t.Search("sumu")){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}
