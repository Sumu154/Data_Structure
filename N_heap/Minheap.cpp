#include<bits/stdc++.h>
using namespace std;

class MinHeap{
public:
    vector<int> node;

    MinHeap()
    {

    }

    void up_heapify(int idx)
    {
        while(idx>0 and node[(idx-1)/2]>node[idx]){
            swap(node[(idx-1)/2], node[idx]);
            idx = (idx-1)/2;
        }
    }


    void Insert(int x)
    {
        node.push_back(x);
        up_heapify(node.size()-1);
    }


    void down_heapify(int idx)
    {
        while(1){
            int least = idx;
            int left = 2*idx+1;
            int right = 2*idx+2;
            if(left<node.size() and node[left]<node[least]){
                least = left;
            }
            if(right<node.size() and node[right]<node[least]){
                least = right;
            }
            if(least == idx){
                break;
            }
            swap(node[least], node[idx]);
            idx = least;
        }
    }


    void Delete(int idx)
    {
        swap(node[node.size()-1], node[idx]);
        node.pop_back();

        if(node[idx]<node[(idx-1)/2]){
            up_heapify(idx);
        }
        else{
            down_heapify(idx);
        }
    }

    void print()
    {
        for(int i=0 ; i<node.size() ; i++){
            cout << node[i] << " ";
        }
        cout << "\n";
    }

    int getMin()
    {
        if(node.empty()){
           cout << "Heap is empty\n";
           return -1;
        }
        return node[0];
    }

    int extractMin()
    {
        if(node.empty()){
            cout << "heap is empty\n";
            return -1;
        }

        int mini = node[0];
        Delete(0);
        return mini;
    }

    void build_from_array(vector<int> &a)
    {
        node = a;
        int n = node.size();
        int last_non_leaf = (n/2)-1;
        for(int i=last_non_leaf; i>=0 ; i--){
            down_heapify(i);
        }
    }

    vector<int>  heapSort(vector<int> a)
    {
        build_from_array(a);    //array theke age heap e convert kora lagbe
        vector<int>sorted_a;
        for(int i=0 ; i<a.size() ; i++){
            sorted_a.push_back(extractMin());
        }
        return sorted_a;
    }
};

int main()
{

    MinHeap h;

    h.Insert(2);
    h.Insert(6);
    h.Insert(3);
    h.Insert(8);
    h.Insert(9);
    h.Insert(4);
//    h.Insert(8);
//    h.Insert(0);
//    h.Insert(3);


    h.print();

    h.Delete(3);
    h.print();

    cout << "min: " << h.getMin() << "\n";
    cout << "extract " << h.extractMin() << "\n";
    h.print();

    MinHeap h1;
    vector<int> a = {1,2,3,4,10,9,8,7};
    h1.build_from_array(a);
    h1.print();
    vector<int> sorted_a = h1.heapSort(a);
    for(int i=0 ; i<sorted_a.size() ; i++){
        cout << sorted_a[i] << " ";
    }
    cout << "\n";

}
