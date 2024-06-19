#include<bits/stdc++.h>
using namespace std;

template<class T>
class MaxHeap{
public:
    vector<T> node;

    MaxHeap()
    {

    }

    void up_heapify(int idx)
    {
        while(idx>0 && node[(idx-1)/2]<node[idx])
        {
            swap(node[(idx-1)/2], node[idx]);
            idx = (idx-1)/2;
        }

    }

    //O(logn)
    void Insert(T x)
    {
        node.push_back(x);
        up_heapify(node.size()-1);  //last index = a.size()-1
    }

    void down_heapify(int idx)
    {
        while(1)
        {
            T large = idx;
            T left = 2*idx+1;
            T right = 2*idx+2;
            if(left<node.size() && node[left]>node[large])
            {
                large = left;
            }
            if(right<node.size() && node[right]>node[large])
            {
                large = right;
            }
            if(idx == large)
            {
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

    T getMax()
    {
        if(node.empty())
        {
           cout << "Heap is empty\n";
           T a;
           return a;
        }
        return node[0];
    }
};

int main()
{

    MaxHeap<char> h;

    h.Insert('a');
    h.Insert('c');
    h.Insert('u');
    h.Insert('y');
    h.Insert('l');

    h.print();

    h.Delete('l');
    h.print();

    cout << "max: " << h.getMax() << "\n";
    //cout << "extract " << h.extractMax() << "\n";
    h.print();

    /*
    MaxHeap h;
    vector<int> arr = {1,2,3,4,10,9,8,7};
    h.build_from_array(arr);
    h.print();
    vector<int> sorted_arr = h.heapSort(arr);
    for(int i=0 ; i<sorted_arr.size() ; i++){
        cout << sorted_arr[i] << " ";
    }
    cout << "\n";
*/

}


