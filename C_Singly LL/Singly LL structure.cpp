#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
};

class LinkedList{
public:
    node *head;
    int size;

    //constructor-->head ta jokhn kono data nai tokhn NULL point kore ace
    LinkedList()
    {
        head = NULL;
        size = 0; //size ta count rakhar jonno
    }

    //creates new node
    node* new_node(int data)
    {
        size++;
        node *newnode = new node;  //new noder pointer create korlam
        newnode->data = data;      //value set ar next
        newnode->next = NULL;

        return newnode;   // shei pointer return korbe means newnoder memory address
    }

    //traverse kore list print krobe
    void traverse()
    {
        node *a = head; //traverse korar jonno new pointer nite hbe
        while(a != NULL)
        {
            cout << a->data << " ";
            a= a->next;
        }
        cout << "\n";
    }

    //O(size of linked list)
    /*int getsize()
    {
        int size= 0;
        node* a = head; //list empty thakle a NULL point korbe..return zero korbe
        while(a != NULL)
        {
            size++;
            a = a->next;
        }

        return size;
    }*/

    //O(1) e getsize
    void getsize()
    {
        cout << "size: " << size << "\n";
        //return size;
    }

     void hasDuplicate()
    {
        node *a = head;

        while(a->next->next != NULL){
            node *b = a->next;
            while(b->next != NULL)
            {
                if(a->data == b->data)
                {
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
        while(a != NULL)
        {
            if(pos%2 != 0)
            {
                sum += a->data;
            }
            a = a->next;
            pos++;
        }
        cout <<  sum << "\n";
    }

    void Insert_head(int data)
    {
        node *newnode = new_node(data);
        if(head == NULL)     //mane kono data nai linked liste
        {
            head = newnode;
            return ;
        }

        //jodi head null na hoy
        newnode->next = head;
        head = newnode;
    }

    void Insert_pos(int pos, int data)
    {
       if(pos>size || pos<0)
       {
           return ;
       }
       if(pos == 0)
       {
           Insert_head(data);
           return;
       }

       node *a = head;  //traversing er jonno
       int index= 0;  //traversing er jonno nici
       while(index != pos-1)
       {
            a = a->next;   //loop theke ber hole a index-1 e point kore thakbe
            index++;
       }

       node *newnode = new_node(data);  //node create kore pointer ta return korbe oita newnode erakhci
       newnode->next = a->next;
       a->next = newnode;
    }

   //insert after specific value
    void insert_after_value(int value, int data)
    {
        node *a = head;
        while(a != NULL)
        {
            if(a->data == value)
            {
                break;
            }
            a = a->next;
        }
        if(a == NULL)  //oi value liste exist na korle a NULL porjonto traverse hbe
        {
            cout << "value does not exist\n";
            return;
        }

        node *newnode = new_node(data);
        newnode->next = a->next;
        a->next = newnode;
    }


    void Insert_end(int data)
    {
         node *newnode = new_node(data);
         if(head == NULL){
             head = newnode;
             return;
         }

         node *a = head;
         while(a->next != NULL){
             a = a->next;
         }
         a->next = newnode;

    }

   //heade je value thakbe oita delete
    void remove_head()
    {
        if(head == NULL)
        {
            return;
        }

        size--;
        node *a = head;
        head = a->next;

        delete a;
    }

   //delete at any position
    void remove_pos(int pos)
    {
        if(pos>=size || pos<0)
        {
            return ;
        }
        if(pos == 0)
        {
            remove_head();
            return;
        }
        size--;
        node *a = head;
        int index= 0;
        while(index != pos-1)
        {
            a = a->next;
            index++;
        }

        node *temp = a->next;   //temp jake delete korte chai take point kore ace
        a->next = temp->next;
        delete temp;

    }

    void remove_last()
    {
        if (head == NULL){
            return;
        }
        size--;
        if(head->next == NULL) {
            delete head;
            return;
        }

        node  *a = head;
        while(a->next->next != NULL)
        {
            a = a->next;
        }
        a->next = NULL;
        delete (a->next);

        // 2nd way
/*
        node  *a = head;
        int count = 0;
        while(count != size-2){
            a = a->next;
            count++;
        }
        a->next = NULL;
        delete (a->next);
*/
    }

    //je element gula 0 ogula delete kore dibo
    void remove_zero()
    {
        node *a = head;
        node *temp = NULL;

        while (a != NULL)
        {
            if(a->data == 0)
            {
                size--;
                if(temp == NULL)       //head e jodi 0 thake
                {
                    head = a->next;
                    delete a;
                    a = head;
                }
                else                       //head bade onno jaygay jodi 0 thake
                {
                    temp->next = a->next;
                    delete a;
                    a = temp->next;
                }
            }
            else
            {
                temp = a;
                a = a->next;
            }
        }
    }



    //kono ekta indexe ki data ace
    int getValue(int index)
    {
        if(index >= size)
        {
             cout << "This value doesn't exist\n";
        }

        node *a = head;
        for(int i=0 ; i<index ; i++){
            a = a->next;
        }
        cout << "index= " << a->data << "\n";
    }

    void find_element(int data)
    {
        if(head == NULL)
        {
            cout << "Flase" << "\n";
            return;
        }
        node *a = head;
        while(a != NULL)
        {
            if(a->data == data)
            {
                cout << "True" << "\n";
                return;
            }
            a = a->next;
        }
        cout << "Flase" << "\n";
        return;
    }


    //kono data kon indexe ace
    void serach_index(int data)
    {
       node *a = head;
       int index= 0;

       while(a != NULL)
       {
           if(a->data == data)
           {
               cout << index << "\n";
               break;

           }
           a = a->next;
           index++;
       }
    }


    void search_all_index(int data)
    {

       node *a = head;
       int index= 0;

       while(a != NULL)
       {
           if(a->data == data)
           {
               cout << index << " ";
           }
           a= a->next;
           index++;
       }
    }

/*   void sort_list()
   {
        if(head==NULL || head->next==NULL){
            return;
        }

        node* sorted = NULL;
        node* current = head;

        while(current != NULL)
        {
            node* nextNode = current->next;


            if(sorted==NULL || current->data < sorted->data)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                node* temp = sorted;
                while(temp->next != NULL   &&   current->data >= temp->next->data)
                {
                    temp = temp->next;
                }

                current->next = temp->next;
                temp->next = current;
            }

            current = nextNode;
        }
        head = sorted;
    }  */

    void sort_list()
    {
        node *a, *b;

        for(a=head ; a->next!=NULL ; a=a->next){
            for(b=a->next ; b!=NULL ; b=b->next)
            {
                if(a->data > b->data)
                {
                    swap(a->data, b->data);
                }
            }
        }
    }


   //reversely print korar jonno..linked listk reverse kore felbo na,,shudhu reversely print korbo
    void reverse_print2(node *a)
    {
        if(a == NULL)
        {
            return;
        }

        reverse_print2(a->next);
        cout << a->data << " ";
    }
    void reverse_print()
    {
        reverse_print2(head);
        cout << "\n";
    }

};

int main()
{
    LinkedList l;

    cout << "Before enter data \n" ;
    l.getsize();

    //user input dea
    int n;
    cin >> n;
    int data;
    for(int i=0 ; i<n ; i++){
        cin >> data;
        l.Insert_end(data);
    }
    cout << "After enter data \n";
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
    l.serach_index(5);
    cout << "All index of value 5 is: ";
    l.search_all_index(5);
    cout << "\n\n";

    cout << "Insert 0 at head \n";
    l.Insert_head(0);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Insert 100 in 1 position \n";
    l.Insert_pos(1,100);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Insert 50 after 2 \n";
    l.insert_after_value(2,50);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Insert 1 at end \n";
    l.Insert_end(1);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Delete from head \n";
    l.remove_head();
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Delete from position 2 \n";
    l.remove_pos(2);
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Delete from last \n";
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
    l.getsize();
    cout << "\n";

    cout << "the sorted list is \n";
    l.sort_list();
    l.traverse();
    l.getsize();
    cout << "\n";

    cout << "Reversed list\n";
    l.reverse_print();
    l.traverse();
    l.getsize();
    cout << "\n";
}
