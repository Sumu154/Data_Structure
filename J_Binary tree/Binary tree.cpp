#include<bits/stdc++.h>
using namespace std;

                                               /*    5
                                                    / \
                                                   /   \      height = 3
                                                  6     10  Diameter =
                                                /  \    / \
                                               /    \  /   \
                                              15   23 4
                                      */

class node{
public:
    int data;
    node *left;
    node *right;
};



class Binarytree{
public:
    node *root;

    Binarytree()
    {
        root = NULL;
    }

    node* new_node(int data)
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    void Insertion(int data)       //BFS traversal wise
    {
        node *newnode = new_node(data);
        if(root == NULL)
        {
            root = newnode;
            return;
        }
        queue<node*> q;
        q.push(root);  //root theke traverse shuru hbe
        while(!q.empty())
        {
            node *a = q.front();  //q er fronter value theke traverse shuru
            q.pop();                    //front value pop

            if(a->left == NULL)
            {
                a->left = newnode;
                return;
            }
            else                           //later ei node ta jate traverse hoy ejonno
            {                              //queue te push kora laglo
                q.push(a->left);
            }
            if(a->right == NULL)
            {
                a->right = newnode;
                return;
            }
            else
            {
                q.push(a->right);
            }
        }
    }

    void BFS()
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node *a = q.front();
            q.pop();
            if(a->left != NULL)
            {
                q.push(a->left);
            }
            if(a->right != NULL)
            {
                q.push(a->right);
            }
            cout << a->data << " ";
        }
    }

    //DFS traversal- 3 types
    void Preorder(node *root)     //root+left+right
    {
        node *a = root;
        if(a == NULL)  //base case
        {
            return;
        }
        cout << a->data << " ";
        Preorder(a->left);
        Preorder(a->right);
    }

    void Inorder(node *root)     //left+root+right
    {
        node *a = root;
        if(a == NULL)
        {
            return;
        }
        Inorder(a->left);
        cout << a->data << " ";
        Inorder(a->right);
    }

    void Postorder(node *root)    //left+right+root
    {
        node *a = root;
        if(a == NULL)
        {
            return;
        }
        Postorder(a->left);
        Postorder(a->right);
        cout << a->data << " ";
    }

    void Search(node *root, int data)
    {
        node *a = root;
        if(a == NULL)
        {
            return;
        }
        if(a->data == data)
        {
            cout << "YES Present";
            return;
        }
        Search(a->left, data);
        Search(a->right, data);
    }

    //height = total number of levels between root node and deepest node of the tree
    int cal_height(node *root)
    {
        node *a = root;
        if(a == NULL)
            return 0;

        int lh = cal_height(a->left);
        int rh = cal_height(a->right);
        return max(lh, rh)+1;
    }

    int isPerfect(node *root)
    {
        if(root == NULL)
            return 1;

        int level = 1;
        int flag = 1;           // 1 means it is still perfect

        queue<node*>  q;
        q.push(root);
        while(!q.empty())  // q empty hole loop off hbe
        {
            vector<int> levelValues;
            int size = q.size();
            while(size--)
            {
                node *a= q.front();
                q.pop();
                levelValues.push_back(a->data);

                if(a->left != NULL)
                {
                    q.push(a->left);
                }
                if(a->right != NULL)
                {
                    q.push(a->right);
                }
            }
            if(levelValues.size()!=0  && levelValues.size()!=level)
            {
                flag = 0;
            }
            level = level * 2;
        }
        return flag;
    }

    int  isComplete()
    {
        if(root == NULL)
            return 1;


        int flag = 0;
        queue<node *>q;
        q.push(root);
        while(q.size())
        {
            node* a = q.front();
            q.pop();

            if(a->left != NULL)
            {
                if(flag == 1)
                    return 0;

                q.push(a->left);
            }
            else
            {
                flag = 1;
            }

            if(a->right != NULL)
            {
                if(flag == 1)
                    return 0;

                q.push(a->right);
            }
            else
            {
                flag = 1;
            }
        }
        return 1;
    }


    bool isBST(node *root, node *mini, node *maxi)
    {
        node *a = root;
        if(a == NULL)
            return true;

        if(mini!=NULL && a->data<=mini->data)
        {
            return false;
        }
        if(maxi!=NULL && a->data>=maxi->data)
        {
            return false;
        }
        bool leftvalid =isBST(a->left, mini, a);
        bool rightvalid = isBST(a->right, a, maxi);
        return leftvalid and rightvalid;
    }

};

int main()
{
    Binarytree b;

    b.Insertion(20);
    b.Insertion(10);
    b.Insertion(22);
    b.Insertion(5);
    b.Insertion(12);
    b.Insertion(21);
    b.Insertion(25);
    b.Insertion(3);
    b.Insertion(15);

    cout << "BFS " << "\n";
    b.BFS();
    cout << "\nPreorser" << "\n";
    b.Preorder(b.root);
    cout << "\nInorder" << "\n";
    b.Inorder(b.root);
    cout << "\nPostorder" << "\n";
    b.Postorder(b.root);

    cout << "\nSearch ";
    b.Search(b.root, 15);

    cout << "\nheight " << b.cal_height(b.root) << "\n";

    cout << b.isPerfect(b.root) << "\n";
    cout << b.isComplete() << "\n";

    cout << "BST : " << b.isBST(b.root, NULL, NULL);
}
