#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    vector<int> tree;

    SegmentTree(int n)
    {
        tree.resize(4*n);
    }

    void build(vector<int> &a, int idx, int st, int en){
        if(st == en){
            tree[idx] = a[st];
            return;
        }
        int mid = (st+en)/2;
        int left = 2*idx+1;
        int right = 2*idx+2;

        build(a, left, st, mid);
        build(a, right, mid+1, en);

        tree[idx] = tree[left] + tree[right];
    }

    int query(int idx, int st, int en, int l, int r){
        if(st>r or en<l){       //no overlap
            return 0;
        }
        if(st>=l and en<=r){        //full overlap
            return tree[idx];
        }

        int mid = (en+st)/2;
        int left  = idx*2+1;
        int right = idx*2+2;

        int lsum = query(left, st, mid, l, r);
        int rsum = query(right, mid+1, en, l, r);
        return lsum + rsum;

    }

    void Update(vector<int>&a, int idx, int st, int en, int pos, int val){
        if(st==en){
            tree[idx] = val;    //segment tree update
            a[pos] = val;       //given array update
            return;
        }

        int mid = (en+st)/2;
        int left  = idx*2+1;
        int right = idx*2+2;
        if(pos<=mid){
            Update(a, left, st, mid, pos, val);
        }
        else{
            Update(a, right, mid+1, en, pos, val);
        }
        tree[idx] = tree[left] + tree[right];
    }

    void printTree()
    {
        for (int i=0 ; i<15 ; i++){
            cout << tree[i] << " ";
        }
    }


};

int main()
{
    vector<int> a = {5, 3, 2, 4, 1, 8, 6, 10}; // Example array
    int n = a.size();

    SegmentTree s(n);

    s.build(a, 0, 0, n-1);
    s.printTree();

    cout << "\n" << s.query(0,0,n-1,1,5) << "\n";

    s.Update(a,0, 0, n-1, 2, 6);
    s.printTree();
    cout << "\n" << s.query(0,0,n-1,1,5) << "\n";

    return 0;

}


