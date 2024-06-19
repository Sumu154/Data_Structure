#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


class BinarySearchTree{
public:
    node *root;

    BinarySearchTree()
    {
        root = NULL;
    }

    node* sortedArrayToBST(int a[], int start, int end)
    {
        if(start > end){
            return NULL;
        }
        int mid = (start+end)/2;
        node *root = new node(a[mid]);

        root->left = sortedArrayToBST(a, start, mid-1);
        root->right = sortedArrayToBST(a, mid+1, end);

        return root;
    }

    void Inorder(node *root)
    {
        if(root == NULL){
            return;
        }
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
};

int main()
{
    BinarySearchTree b;
    int a[] = {1, 3, 4, 5, 6, 8, 9, 11, 12};
//    for(int i=0 ; i<=8 ; i++){
//        cout << a[i] << " ";
//    }
//    cout << "\n";

    node *root = b.sortedArrayToBST(a, 0, 8);
    b.Inorder(root);


}
