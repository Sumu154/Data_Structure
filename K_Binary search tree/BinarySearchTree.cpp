#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node *left;
    node *right;

    node(int val)
    {
        this->val = val;
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

    void Insertion(int val)
    {
        node *newnode = new node(val);
        if(root == NULL){
            root = newnode;
            return;
        }

        node *a = root;
        node *prev = NULL;
        while(a != NULL){
            if(newnode->val > a->val){
                prev = a;
                a = a->right;
            }
            else{
                prev = a;
                a = a->left;
            }
        }
        if(newnode->val > prev->val){
            prev->right = newnode;
        }
        else{
            prev->left = newnode;
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

    //DFS traversal- 3 types
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

    void Postorder(node *root)    //left+right+root
    {
        if(root == NULL){
            return;
        }
        Postorder(root->left);
        Postorder(root->right);
        cout << root->val << " ";
    }


    void Delete(int val)
    {
        node *a = root;
        node *prev = NULL;
        while(a){
            if(val > a->val){
                prev = a;
                a = a->right;
            }
            else if(val < a->val){
                prev = a;
                a = a->left;
            }
            else{
                break;
            }
        }

        if(a == NULL){
            cout << "Value doesn't exit\n";
            return;
        }

        // no child
        if(a->left==NULL and a->right==NULL){
            if(prev->left->val == a->val){
                prev->left = NULL;
            }
            else{
                prev->right = NULL;
            }
            delete a;
            return;
        }

        //one child
        if(!a->left and a ->right){
            if(a->left and a->val==prev->left->val){  //jake delete korbo she jodi left child hoy
                prev->left = a->right;
            }
            else{
                prev->right = a->right;
            }
            delete a;
            return;
        }
        if(a->left and !a->right){
            if(a->left and a->val==prev->left->val){
                prev->left = a->left;
            }
            else{
                prev->right = a->left;
            }
            delete a;
            return;
        }

        //two child
        node *temp = a->right;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        int saved = temp->val;  //inorder successor
        Delete(saved);
        a->val = saved;

    }

    int getMax()
    {
        node *a = root;
        node *prev = NULL;
        while(a){
            prev = a;
            a = a->right;
        }
        return prev->val;
    }

    int getMin()
    {
        node *a = root;
        node *prev = NULL;
        while(a){
            prev = a;
            a = a->left;
        }
        return prev->val;
    }

    bool Search(int val)
    {
        node *a = root;
        while(a){
            if(a->val > val){
                a = a->left;
            }
            else if(a->val < val){
                a = a->right;
            }
            else{
                return true;
            }
        }
        return false;
    }


    bool isBST(node *root, node *mini, node *maxi)
    {
        if(root==NULL){
            return true;
        }
        if(mini!=NULL and root->val<=mini->val){
            return false;
        }
        if(maxi!=NULL and root->val>=maxi->val){
            return false;
        }
        bool leftValid = isBST(root->left, mini, root);
        bool rightValid = isBST(root->right, root, maxi);
        return leftValid and rightValid;
    }

    int getSuc(node *root, node *suc, int val)
    {
        if(root == NULL){
            return 0;
        }
        if(root->val == val){
            if(root->right){
                node *a = root->right;
                while(a->left){
                    a = a->left;
                }
                return a->val;
            }

        }
        if(root->val > val){
            suc = root;
            getSuc(root->left, suc, val);
        }
        else{
            getSuc(root->right, suc, val);
        }
    }

    int getPre(node *root, node *pre, int val)
    {
        if(root == NULL){
            return 0;
        }
        if(root->val == val){
            if(root->left){
                node *a = root->left;
                while(a->right){
                    a = a->right;
                }
                return a->val;
            }
        }
        if(root->val < val){
            pre = root;
            getPre(root->right, pre, val);
        }
        else{
            getPre(root->left, pre, val);
        }
    }


    node* findLcaNode(node* root, int n1, int n2)
    {
        if(!root){
            return NULL;
        }
        if(root->val==n1 or root->val==n2){
            return root;
        }

        node* leftLca = findLcaNode(root->left, n1, n2);
        node* rightLca = findLcaNode(root->right, n1, n2);

        if(leftLca and rightLca){
            return root;
        }
        if(leftLca){
            return leftLca;
        }
        else{
            return rightLca;
        }
    }

    int findLca(int n1, int n2)
    {
        node* lca = findLcaNode(root, n1, n2);
        if(lca == NULL){
            return -1;
        }
        else{
            return lca->val;
        }
    }

};

int main()
{
    BinarySearchTree b;

    b.Insertion(6);
    b.Insertion(4);
    b.Insertion(3);
    b.Insertion(5);
    b.Insertion(7);
    b.Insertion(8);

    cout << "BFS: ";
    b.BFS();

    cout << "Inorder: ";
    b.Inorder(b.root);
    cout << "\n";

    cout << "Preorder: ";
    b.Preorder(b.root);
    cout << "\n";

    cout << "Postorder: ";
    b.Postorder(b.root);
    cout << "\n\n";


    cout << "after delete node 6\nBFS: ";
    b.Delete(6);
    b.BFS();
    cout << "\n";

    cout << "Max node: " << b.getMax() << "\n";
    cout << "Min node: " << b.getMin() << "\n\n";

    cout << "Search 4: " << b.Search(4) << "\n";

    cout << "is BST: " << b.isBST(b.root, NULL, NULL) << "\n\n";

    cout << "successor: " << b.getSuc(b.root, NULL, 4) << "\n";
    cout << "predecessor : " << b.getPre(b.root, NULL, 4) << "\n";

    cout << "\nLca of 3 and 5 is: ";
    int lca = b.findLca(3, 5);
    if(lca == -1){
        cout << "lca doesn't exist\n";
    }
    else{
        cout << lca << "\n";
    }


}
