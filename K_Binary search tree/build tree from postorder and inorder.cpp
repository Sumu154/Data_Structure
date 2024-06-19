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

    int Search(vector<int> inordr, int st, int en, int val)
    {
        for(int i=st ; i<=en ; i++){
            if(inordr[i]==val){
                return i;
            }
        }
        return -1;
    }

    node* build_tree(vector<int> postordr, vector<int> inordr, int st, int en)
    {
        static int idx = 4;
        if(st>en){
            return NULL;
        }
        int val = postordr[idx];
        idx--;
        node* a = new node(val);

        if(st==en){
            return a;
        }
        int pos = Search(inordr, st, en, val);
        a->right = build_tree(postordr, inordr, pos+1, en);
        a->left = build_tree(postordr, inordr, st, pos-1);
        return a;

    }

    void Postorder(node *root)     //root+left+right
    {
        if(root == NULL){
            return;
        }
        Postorder(root->left);
        Postorder(root->right);
        cout << root->val << " ";
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
    vector<int> postordr = {4, 2, 5, 3, 1};
    vector<int> inordr = {4, 2, 1, 5, 3};

    BinarySearchTree b;
    node* root = b.build_tree(postordr, inordr, 0, 4);
    b.Postorder(root);
    cout << "\n";
    b.Inorder(root);


}
