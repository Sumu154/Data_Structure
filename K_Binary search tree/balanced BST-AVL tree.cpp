#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node *left;
    node *right;
    int height;

    node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
        height = 0;
    }
};

class AvlTree{
public:
    node *root;

    AvlTree()
    {
        root = NULL;
    }

    int height(node *a)
    {
        if (a == NULL){
            return 0;
        }
        return a->height;
    }

    node *rightRotate(node *a)
    {
        node *x = a->left;
        node *y = x->right;
        x->right = a;
        a->left = y;

        a->height = 1 + max(height(a->left), height(a->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    node *leftRotate(node *a)
    {
        node *x = a->right;
        node *y = x->left;
        x->left = a;
        a->right = y;

        a->height = 1 + max(height(a->left), height(a->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    int getBf(node *a)
    {
        if (a == NULL) {
            return 0;
        }
        int lh = height(a->left);
        int rh = height(a->right);
        return lh - rh;
    }

    node *Insert(node *root, int val)
    {
        if (root==NULL){
            node *newnode = new node(val);
            return newnode;
        }

        node *a = root;
        if (val < a->val) {
            a->left = Insert(a->left, val);
        }
        else if (val > a->val) {
            a->right = Insert(a->right, val);
        }
        else {
            return a;
        }

        a->height = 1 + max(height(a->left), height(a->right));
        int bf = getBf(a);
        if (bf > 1) {
            if(val < a->left->val){
                return rightRotate(a);
            }
            else if(val > a->left->val){
                a->left = leftRotate(a->left);
                return rightRotate(a);
            }
        }

        if (bf < -1){
            if(val > a->right->val){
                return leftRotate(a);
            }
            else if (val < a->right->val){
                a->right = rightRotate(a->right);
                return leftRotate(a);
            }
        }
        return a;
    }

    node *Delete(node *a, int val)
    {
        if (a == NULL){
            return a;
        }
        if (val < a->val){
            a->left = Delete(a->left, val);
        }
        else if (val > a->val){
            a->right = Delete(a->right, val);
        }
        else {
            if (a->left == NULL or a->right == NULL){
                node *temp;
                if (a->left){
                    temp = a->left;
                }
                else {
                    temp = a->right;
                }

                if (temp == NULL){
                    temp = a;
                    a = NULL;
                }
                else{
                    *a = *temp;
                }
                delete temp;
            }
            else {
                node *temp = findMin(a->right);
                a->val = temp->val;
                a->right = Delete(a->right, temp->val);
            }
        }

        if(a == NULL){
            return a;
        }

        a->height = 1 + max(height(a->left), height(a->right));
        int bf = getBf(a);

        if (bf > 1){
            if (getBf(a->left) >= 0){
                return rightRotate(a);
            }
            else {
                a->left = leftRotate(a->left);
                return rightRotate(a);
            }
        }

        if (bf < -1) {
            if (getBf(a->right) <= 0){
                return leftRotate(a);
            }
            else {
                a->right = rightRotate(a->right);
                return leftRotate(a);
            }
        }

        return a;
    }

    node *findMin(node *root)
    {
        node *a = root;
        while (a->left != NULL) {
            a = a->left;
        }
        return a;
    }

  // In-order traversal
    void Inorder(node *root)
    {
        if (root == NULL) {
            return;
        }
        Inorder(root->left);
        cout << root->val << " ";
        Inorder(root->right);

    }

  // Pre-order traversal
    void Preorder(node *root)
    {
        if (root == NULL) {
            return;
        }
        Preorder(root->left);
        cout << root->val << " ";
        Preorder(root->right);

    }
  // Post-order traversal
    void postorder(node *root)
    {
        if (root == NULL) {
            return;
        }
        postorder(root->left);
        cout << root->val << " ";
        postorder(root->right);

    }
  // Breadth-first traversal
    void BFS(node *root)
    {
        if (root == NULL) return;

        queue<node *> q;
        q.push(root);

        while (!q.empty()) {
            node *current = q.front();
            q.pop();

            cout << current->val << " ";

            if (current->left != NULL) {
                q.push(current->left);
            }

            if (current->right != NULL) {
                q.push(current->right);
            }
        }
    }
};

int main() {
  AvlTree b;
    b.root = b.Insert(b.root, 12);
    b.root = b.Insert(b.root, 8);
    b.root = b.Insert(b.root, 18);
    b.root = b.Insert(b.root, 5);
    b.root = b.Insert(b.root, 11);
    b.root = b.Insert(b.root, 17);
    b.root = b.Insert(b.root, 4);
    //tree.root = tree.Insert(tree.root, 1);
    //tree.root = tree.Insert(tree.root, 2);

  cout << "In-order Traversal: ";
  b.Inorder(b.root);
  cout << endl;

  cout << "Pre-order Traversal: ";
  b.Preorder(b.root);
  cout << endl;

  cout << "Post-order Traversal: ";
  b.postorder(b.root);
  cout << endl;

  cout << "Breadth-first Traversal: ";
  b.BFS(b.root);
  cout << endl;

  b.root = b.Delete(b.root, 5);
  cout << "After deleting 10:" << endl;
  cout << "In-order Traversal: ";
  b.Inorder(b.root);
  cout << endl;
}
