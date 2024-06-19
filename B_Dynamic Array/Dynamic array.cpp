#include<bits/stdc++.h>
using namespace std;

//memory comp= O(n)
class Array{
private:
    int *arr; //array pointer jeta last elemente point kore thakbe
    int cap;
    int size;

    //sz= cap hole capacity increase korte hbe
    void increase_size()
    {
        cap = cap*2;  //capacity double kore dilam
        //ekhn ager array theke value gula copy kore notun array te rakhbo..ager array delete korbo
        int *temp = new int [cap];  //notun arraye pointer nibo
        for(int i=0 ; i<size ; i++){
            temp[i] = arr[i];
        }
        delete [] arr; //ager pointer delete..
        arr = temp; //arr ke temp te point kore dilam..ekhn arr notun array te point kore thakbe
    }


    void Decrease_size()
    {
        cap = cap/2;
        int *temp = new int[cap];
        for(int i=0; i<size; i++){
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
    }

public:
    //array constructor
    Array()
    {
        arr = new int[1];  //shurute 1 sizer array nibo
        cap = 1;
        size = 0;
    }

    //arrayr laste value push korar jonno
    //t.c= O(1)
    void Push_back(int x)
    {
        if(cap == size)
        {
            increase_size();
        }
        arr[size]= x; //sz no positione x push korbo
        size++;     //sz 1 baraye dibo
    }

    //notun element insert korar jonno
    void Insert(int x, int pos)
    {
        if(cap == size)
        {
            increase_size();
        }
        for(int i=size-1 ; i>= pos ; i--){
            arr[i+1]= arr[i];
        }
        arr[pos] = x;
        size++;
    }


    //last element delete
    //t.c= O(1)
    void Pop_back()
    {
        if(size == 0)
        {
            cout << "Error" << "\n";
            return ;
        }
        size--;
    }

    //t.c= O(n)
    void Erase(int pos)
    {
        if(pos >= size)
        {
            cout << "Error" << "\n";
        }
        if(size == cap/2){
            Decrease_size();
        }

        for(int i=pos+1 ; i<size ; i++){
            swap(arr[i-1],arr[i]);
        }
        size--;
    }

    //t.c= O(n)
    void print_class()
    {
        for(int i=0 ; i<size ; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }


    //t.c= o(1)
    int getsize()
    {
        return size;
    }

    int getelement(int index)
    {
        if(index >= size)
        {
            cout << "Error";
            return -1;
        }
        return arr[index];
    }


};

int main()
{
    Array a; //a class nilam

    int data;
    for(int i=0 ; i<5 ; i++){
        cin >> data;
        a.Push_back(data);
    }
    a.print_class();
    a.Insert(3,1);
    a.print_class();

    cout << a.getsize() << "\n";
    for(int i=0 ; i<a.getsize() ; i++){
        cout << a.getelement(i) << " ";
    }
    cout << "\n";

    //erase kora
    a.Pop_back();
    a.print_class();
    a.Erase(2);
    a.print_class();

}
