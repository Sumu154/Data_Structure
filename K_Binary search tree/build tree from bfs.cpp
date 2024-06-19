#include<bits/stdc++.h>
using namespace std;

/*
10 20 60 30 50 70 -1 -1 40 -1 -1 -1 -1 80 -1 -1 -1

*/

class node{
public:
    int val;
    node* left;
    node* right;

    node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree{
public:
    node* root;

    BinarySearchTree(){
        root = NULL;
    }

    void build_tree( )
    {
        int val;
        cin >> val;
        if(val==-1){
            root=NULL;
        }
        else{
            root = new node(val);
        }
        queue<node*> q;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            node* a = q.front();
            q.pop();

            int l, r;
            cin >> l >> r;
            node* left;
            node* right;
            if(l==-1){
                left = NULL;
            }
            else{
                left = new node(l);
            }
            if(r==-1){
                right = NULL;
            }
            else{
                right = new node(r);
            }
            a->left = left;
            a->right = right;

            //3.children gula push
            if(a->left){
                q.push(a->left);
            }
            if(a->right){
                q.push(a->right);
            }
        }
    }

    void BFS()
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            node *a = q.front();
            q.pop();
            if(a->left){
                q.push(a->left);
            }
            if(a->right){
                q.push(a->right);
            }
            cout << a->val << " ";
        }
        cout << "\n";
    }

};

int main()
{
    BinarySearchTree b;
    b.build_tree();
    b.BFS();
}

