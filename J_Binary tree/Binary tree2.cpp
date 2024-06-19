#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* parent;
    node* left;
    node* right;
};

class BinaryTree{
public:
    node* root;

    BinaryTree()
    {
        root = NULL;
    }

    node* new_node(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->parent = NULL;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    node* Insertion(int data, int parentData, int child)
    {
        node *newnode = new_node(data);

        if(!root){
            root = newnode;
        }
        else{
            node *parentNode = search(root, parentData);
            if (!parentNode){
                cout << "Not Found" << endl;
                delete newnode;
                return NULL;
            }

            newnode->parent = parentNode;
            if(child == 1){
                parentNode->left = newnode;
            }
            else if(child == 2){
                parentNode->right = newnode;
            }
        }
        return newnode;
    }

    node* search(node* a, int data)
    {
        if(!a){
            return NULL;
        }

        if(a->data == data){
            return a;
        }

        node* leftSearch = search(a->left, data);
        node *rightSearch = search(a->right, data);
        if(leftSearch){
            return leftSearch;
        }
        else{
            return rightSearch;
        }
    }



    void Remove(int data)
    {
        node* a = search(root, data);   //a = node to remove
        if(!a){
            cout << "Not Found" << endl;
            return;
        }

        if(a->left){
            removeSubtree(a->left);
        }
        if (a->right){
            removeSubtree(a->right);
        }

        if (a->parent){
            if (a->parent->left == a){
                a->parent->left = NULL;
            }
            else{
                a->parent->right = NULL;
            }
        }
        else{
            root = NULL;
        }

        delete a;
    }

    void removeSubtree(node* a)
    {
        if(a->left){
            removeSubtree(a->left);
        }
        if(a->right){
            removeSubtree(a->right);
        }
        delete a;
    }


    int height(node* a)
    {
        if (!a){
            return -1;
        }

        int lh = height(a->left);
        int rh = height(a->right);

        return max(lh, rh) + 1;
    }

    void preorder(node* a)
    {
        if (!a)
        {
            return;
        }

        cout << a->data << " ";
//        if (a->parent)
//        {
//            cout << a->parent->data;
//        }
//        else
//        {
//            cout << "N";
//        }
//        cout << ") ";

        preorder(a->left);
        preorder(a->right);
    }

};

int main()
{
    BinaryTree b;

    //Insertion
    b.Insertion(1, 0, 0);
    b.Insertion(2, 1, 1);
    b.Insertion(3, 1, 2);
    b.Insertion(5, 2, 2);
    b.Insertion(4, 2, 1);
    b.Insertion(6, 3, 1);
    b.Insertion(7, 3, 2);

    b.preorder(b.root);
    cout << "\n";

    //searching a node
    node *res = b.search(b.root, 3);
    if(res){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    //remove a node
    b.Remove(4);
    b.preorder(b.root);
    cout << "\n";

    //height of a tree
    cout << b.height(b.root);



}



