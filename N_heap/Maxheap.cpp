#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
    vector<int> node;

    MaxHeap()
    {

    }

    void up_heapify(int idx)
    {
        while(idx>0 and node[(idx-1)/2]<node[idx])  //parenter sathe check
        {
            swap(node[(idx-1)/2], node[idx]);
            idx = (idx-1)/2;
        }

    }

    //O(logn)
    void Insert(int x)
    {
        node.push_back(x);
        up_heapify(node.size()-1);  //last index = a.size()-1
    }

    void down_heapify(int idx)
    {
        while(1){
            int large = idx;
            int left = 2*idx+1;
            int right = 2*idx+2;
            if(left<node.size() and node[left]>node[large]){
                large = left;
            }
            if(right<node.size() and node[right]>node[large]){
                large = right;
            }
            if(idx == large){
                break;
            }
            swap(node[idx], node[large]);
            idx = large;

        }
    }

    //O(logn)
    void Delete(int idx)
    {
        swap(node[idx], node[node.size()-1]);
        node.pop_back();
        down_heapify(idx);
    }

    void print()
    {
        for(int i=0 ; i<node.size() ; i++){
            cout << node[i] << " ";
        }
        cout << "\n";
    }

    int getMax()
    {
        if(node.empty())
        {
           cout << "Heap is empty\n";
           return -1;
        }
        return node[0];
    }

    int extractMax()
    {
        if(node.empty())
        {
           cout << "Heap is empty\n";
           return -1;
        }
        int maxi = node[0];
        Delete(0);
        return maxi;
    }

    //ekta given array theke kivabe head build korte pari
    void build_from_array(vector<int> &a)
    {
        node = a;
        int n = node.size();
        int last_nonleaf = n/2-1;
        for(int i=last_nonleaf ; i>=0 ; i--){
            down_heapify(i);
        }
    }

    //heapsort
    vector<int>  heapSort(vector<int> a)
    {
        build_from_array(a);    //array theke age heap e convert kora lagbe
        vector<int>sorted_a;
        for(int i=0 ; i<a.size() ; i++){
            sorted_a.push_back(extractMax());
        }
        reverse(sorted_a.begin(), sorted_a.end());
        return sorted_a;
    }
};



int main()
{

    MaxHeap h;

    h.Insert(4);
    h.Insert(7);
    h.Insert(9);
    h.Insert(1);
    h.Insert(10);

    h.print();

    h.Delete(2);
    h.print();

    cout << "max: " << h.getMax() << "\n";
    cout << "extract " << h.extractMax() << "\n";
    h.print();



    MaxHeap h1;
    vector<int> a = {1,2,3,4,10,9,8,7};
    h1.build_from_array(a);
    h1.print();
    vector<int> sorted_a = h1.heapSort(a);
    for(int i=0 ; i<sorted_a.size() ; i++){
        cout << sorted_a[i] << " ";
    }
    cout << "\n";


}


