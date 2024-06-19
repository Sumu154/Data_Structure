#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
    vector<int> a;

    MaxHeap()
    {

    }

    void up_heapify(int idx)
    {
        while(idx>0 && a[(idx-1)/2]<a[idx])
        {
            swap(a[(idx-1)/2], a[idx]);
            idx = (idx-1)/2;
        }

    }

    void Insert(int x)
    {
        a.push_back(x);
        up_heapify(a.size()-1);  //last index = a.size()-1
    }

    void down_heapify(int idx)
    {
        while(1)
        {
            int large = idx;
            int left = 2*idx+1;
            int right = 2*idx+2;
            if(left<a.size() && a[left]>a[large])
            {
                large = left;
            }
            if(right<a.size() && a[right]>a[large])
            {
                large = right;
            }
            if(idx == large)
            {
                break;
            }
            swap(a[idx], a[large]);
            idx = large;

        }
    }

    void Delete(int idx)
    {
        swap(a[idx], a[a.size()-1]);
        a.pop_back();
        down_heapify(idx);
    }

    void print()
    {
        for(int i=0 ; i<a.size() ; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    int getMax()
    {
        if(a.empty())
        {
           cout << "Heap is empty\n";
           return -1;
        }
        return a[0];
    }

    int extractMax()
    {
        if(a.empty())
        {
           cout << "Heap is empty\n";
           return -1;
        }
        int maxi = a[0];
        Delete(0);
        return maxi;
    }

    int getsize()
    {
        return a.size();
    }

    //ekta given array theke kivabe head build korte pari
    void build_from_array(vector<int> &arr)
    {
        a = arr;
        int n = a.size();
        int last_nonleaf = n/2-1;
        for(int i=last_nonleaf ; i>=0 ; i--)
        {
            down_heapify(i);
        }
    }

};

class Priority_queue{
public:
    MaxHeap h;

    Priority_queue()
    {

    }

    void push(int x)
    {
        h.Insert(x);
    }

    void pop()
    {
        h.Delete(0);
    }

    int top()
    {
        return h.getMax();
    }

    int getsize()
    {
        return h.getsize();
    }
};



int main()
{
    Priority_queue p;

    p.push(5);
    p.push(7);
    p.push(10);
    p.push(1);
    p.push(2);

    while(p.getsize() != 0)
    {
        cout << p.top() << " ";
        p.pop();
    }
    cout << "\n";

}



