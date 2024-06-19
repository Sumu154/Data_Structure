#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node *prev;
    node *next;

    node(int val)
    {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList{
public:
    node *head;
    int size;

    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    //creates new node with the given data
//    node* new_node(int data)
//    {
//        size++;
//        node *newnode = new node;
//        newnode->data = data;
//        newnode->prev = NULL;
//        newnode->next = NULL;
//
//        return newnode;
//    }


    void traverse()
    {
        node *a = head;
        while(a){
            cout << a->val << " ";
            a = a->next;
        }
        cout << "\n";
    }

    //print size of list
    int getsize()
    {
        cout << "size: " << size << "\n";
    }

    void hasDuplicate()
    {
        if(!head){
            return;
        }

        node *a = head;
        while(a->next->next){
            node *b = head->next;
            while(b->next){
                if(a->val == b->val){
                    cout << "True\n";
                    return;
                }
                b = b->next;
            }
            a = a->next;
        }
        cout << "False\n";
    }

    void getOddIndexSum()
    {
        int sum=0, pos=0;
        node *a = head;
        while(a){
            if(pos%2 != 0){
                sum += a->val;
            }
            a = a->next;
            pos++;
        }
        cout << sum << "\n";
    }


    void Insert_head(int val)
    {
       node *newnode = new node(val);
       if(head == NULL){
           head = newnode;
           size++;
           return;
       }
       node *temp = head;
       newnode->next = temp;
       temp->prev = newnode;
       head = newnode;
       size++;
       /*
       newnode->next = head;
       head->prev = newnode;
       head = head->prev;
        */
    }

    void Insert_pos(int pos, int val)
    {
        if(pos>size || pos<0){
            return;
        }
        if(pos == 0){
            Insert_head(val);
            return ;
        }

        node *newnode = new node(val);
        int ind = 0;
        node *a = head;
        while(ind != pos-1){
            a = a->next;
            ind++;
        }

        newnode->next = a->next;
        newnode->prev = a;
        a->next->prev = newnode;
        a->next = newnode;
        size++;

    }

    //specific value er pore data add korbe
    void insert_after_value(int value, int val)
    {
        node *a = head;
        while(a){
            if(a->val == value){
                break;
            }
            a = a->next;
        }
        if(!a)
        {
            cout << "value doesn't exist\n";
            return;
        }
        node *newnode = new node(val);
        newnode->next = a->next;
        newnode->prev = a;
        if(a->next){ //value jodi last indexe na thake
            a->next->prev = newnode;
        }
        a->next = newnode;
        size++;
    }

    void Insert_end(int val)
    {
        node *newnode = new node(val);
        if(head == NULL){
            head = newnode;
            size++;
            return ;
        }

        node *a = head;
        while(a->next){
            a = a->next;
        }
        newnode->prev = a;
        a->next = newnode;
        size++;
    }

    void remove_head()
    {
        if(head == NULL){
            return;
        }

        size--;
        node *a = head;
        node *temp = head->next;
        delete a;
        if(temp){
            temp->prev = NULL;
        }
        head = temp;

    }

    void remove_pos(int pos)
    {
        if(pos>size or pos<0){
            return;
        }

        size--;
        node *a = head;
        int index = 0;
        while(index != pos){
            a = a->next;
            index++;
        }

        node* temp1 = a->prev;
        node* temp2 = a->next;
        if(temp1 != NULL){   //a jodi first element hoye tahole temp1 NULL hbe
            temp1->next = temp2;
        }
        if(temp2 != NULL){
            temp2->prev = temp1;
        }
        delete a;

        if(index == 0){
            head = temp2;
        }
    }

    void remove_last()
    {
        if(!head){
            return;
        }
        size--;
        if(!head->next){
            head = NULL;
            delete head;
            return;
        }

        node *a = head;
        while(a->next){
            a = a->next;
        }
        a->prev->next = NULL;
        delete a;

    }

     void remove_zero()
    {
        node *a = head;
        while(a){
            if(a->val == 0){
                if(a == head){
                    head = a->next;
                }
                if(a->prev){
                    a->prev->next = a->next;
                }
                if(a->next){
                    a->next->prev = a->prev;
                }
                node *temp =a;
                a = a->next;
                delete temp;
                size--;
            }

            else{
                a = a->next;
            }
        }
    }


    int getValue(int pos)
    {
        if(pos>size){
            cout << "This value doesn't exist\n";
        }

        node *a = head;
        for(int i=0 ; i<pos ; i++){
            a = a->next;
        }
        cout << "index= " << a->val << "\n";

    }

    void find_element(int val)
    {
        if(!head){
            cout << "Flase" << "\n";
            return;
        }
        node *a= head;
        while(a)
        {
            if(a->val == val){
                cout << "True" << "\n";
                return;
            }
            a = a->next;
        }
        cout << "Flase" << "\n";
        return;
    }

    void search_index(int val)
    {
        int index = 0;
        node *a = head;
        while(a){
            if(a->val == val){
                cout << "index= " << index << "\n";
                return;
            }
            a = a->next;
            index++;
        }
        cout << "Not found\n";
    }

    void search_all_index(int val)
    {
        int index = 0;
        bool found = false;

        node *a = head;
        while(a){
            if(a->val == val){
                cout << index << " ";
                found = true;
            }
            a = a->next;
            index++;
        }
        if(!found){
            cout << "Not found\n";
        }
    }


    void reverse_print()
    {
        node* last = head;
        int index = 0;
        while(index != size-1){
            last = last->next;
            index++;
        }   //last index is in *node last

        node* a = head;
        while(a)
        {
            swap(a->next, a->prev);
            a = a->prev;
        }
        head = last;
    }
};

int main()
{
    LinkedList l;

    cout << "Before enter val size \n" ;
    l.getsize();

    //user input dea
    int n;
    cin >> n;
    int val;
    for(int i=0 ; i<n ; i++){
        cin >> val;
        l.Insert_end(val);
    }
    cout << "After insert data: \n";
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "is duplicate present \n";
    l.hasDuplicate();
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "sum of all odd index ";
    l.getOddIndexSum();
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "the index of value 5 is: ";
    l.search_index(5);
    cout << "All index of value 5 is: ";
    l.search_all_index(5);
    cout << "\n\n";

    cout << "Insert 0 at head \n";
    l.Insert_head(0);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "insert 100 at index 2 \n";
    l.Insert_pos(2,100);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Insert 50 after 2 \n";
    l.insert_after_value(2,50);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Insert at end 50 \n";
    l.Insert_end(50);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Delete from head \n";
    l.remove_head();
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "remove at index 2\n";
    l.remove_pos(2);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "remove last element\n";
    l.remove_last();
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Delete alla zero \n";
    l.remove_zero();
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Get value in index 3 \n";
    l.getValue(3);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "the value 5 present in the list: ";
    l.find_element(5);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Reversed list\n";
    l.reverse_print();
    l.traverse();
    l.getsize();
    cout << "\n";


}
