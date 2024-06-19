#include<bits/stdc++.h>
using namespace std;

//  list constructor
list<int> l;             //a list with 0 element
//list<int> l(10);         //list of 10 element and initialized by garbage
//list<int> l(10, 0);      //list of 10 and initialized by 0
//list<int> l2(l);         //l er shb element copy hoye l2 te chole ashbe
//list<int> l2(l+1, l+5);  //perticular kicu element copy


void print()
{
    list<int>::iterator a = l.begin();  //node current head near moto
    while(a!=l.end()){
        cout << *a << " ";
        a++;
    }
    cout << "\n";
}

void Insert(int pos, int data)
{
    list<int>::iterator a = l.begin();
    advance(a, pos);
    l.insert(a, data);
}

int getValue(int pos)
{
    if(pos<0 || pos > l.size()){
        return -1;
    }
    list<int>::iterator a = l.begin();
    advance(a, pos);
    return *a;
}

bool Search(int data)
{
    list<int>::iterator a = l.begin();
    while(a != l.end())
    {
        if(*a == data)
        {
            return true;
        }
        a++;
    }
    return false;
}


void Delete(int pos)
{
    list<int>::iterator a = l.begin();
    advance(a, pos);
    l.erase(a);
}

void deleteZero()
{
    l.remove(0);
}


int main()
{
    /*
    //list capacity
    cout << l.size() << "\n";
    l.resize(10);
    cout << l.max_size() << "\n";
    l.clear();    //only value delete memory na,,so pore value insert abar kora jabe
    cout << l.empty() << "\n";
    */


    //list modifiers
    l.push_front(10);        //insert at head
    l.push_back(5);         //insert at end
    Insert(5,0);

    cout << "Insertion:\n";
    print();

    cout << "Size= " << l.size() << "\n";
    cout << "front ele: " << l.front() << "\n";
    cout << "back ele: " << l.back() << "\n";
    cout << "3rd element: " << *next(l.begin(), 3) << "\n";



    //Deletoin
    l.pop_front();
    l.pop_back();
    Delete(4);

    cout << "Deletion:\n";
    print();

    cout << "Size= " << l.size() << "\n";
    cout << "front ele: " << l.front() << "\n";
    cout << "back ele: " << l.back() << "\n";
    cout << "3th element: " << *next(l.begin(), 3) << "\n";

    cout << "Value of position 2: ";
    cout << getValue(2) << "\n";

    //search value
    cout << "Search 6: ";
    if(Search(6) == true){
        cout << "true\n";
    }
    else{
        cout << "false\n";
    }

    //all zero delete
    cout << "After deleting all zero: \n";
    deleteZero();
    print();
}
