#include<bits/stdc++.h>
using namespace std;

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

    BinarySearchTree()
    {
        root = NULL;
    }

    int Search(vector<int> inordr, int st, int en, int curr)
    {
        for(int i=st ; i<=en ; i++){
            if(inordr[i]==curr){
                return i;
            }
        }
        return -1;
    }

    node* build_tree(vector<int> preordr, vector<int> inordr, int st, int en)
    {
        static int idx = 0;
        if(st>en){
            return NULL;
        }
        int curr = preordr[idx];
        idx++;
        node* a = new node(curr);

        if(st==en){
            return a;
        }
        int pos = Search(inordr, st, en, curr);
        a->left = build_tree(preordr, inordr, st, pos-1);
        a->right = build_tree(preordr, inordr, pos+1, en);
        return a;

    }

    void Preorder(node *root)     //root+left+right
    {
        if(root == NULL){
            return;
        }
        cout << root->val << " ";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Inorder(node *root)     //left+root+right
    {
        if(root == NULL){
            return;
        }
        Inorder(root->left);
        cout << root->val << " ";
        Inorder(root->right);
    }
};

int main()
{
    vector<int> preordr = {1, 2, 4, 3, 5};
    vector<int> inordr = {4, 2, 1, 5, 3};

    BinarySearchTree b;
    node* root = b.build_tree(preordr, inordr, 0, 4);
    b.Preorder(root);
    cout << "\n";
    b.Inorder(root);

}

