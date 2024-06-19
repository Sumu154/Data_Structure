#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    vector<int> tree;
    vector<int> lazy; // Array to store lazy updates

    SegmentTree(int n)
    {
        tree.resize(4*n);
        lazy.resize(4*n, 0);
    }

    void propagate(int idx, int st, int en)
    {
        if(lazy[idx] != 0){
            tree[idx] += (en-st+1)*lazy[idx];

            if(st!=en){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void build(vector<int>& a, int idx, int st, int en)
    {
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

    int query(int idx, int st, int en, int l, int r)
    {
        propagate(idx, st, en);

        if(st>r or en<l){ // No overlap
            return 0;
        }
        if(st>=l and en<=r){ // Full overlap
            return tree[idx];
        }

        int mid = (en+st)/2;
        int left = idx*2+1;
        int right = idx*2+2;

        int lsum = query(left, st, mid, l, r);
        int rsum = query(right, mid+1, en, l, r);
        return lsum+rsum;
    }

    void updateRange(int idx, int st, int en, int l, int r, int val)
    {
        propagate(idx, st, en);

        if(st>r or en<l) { // No overlap
            return;
        }
        if(st>=l and en<=r){ // total overlap
            tree[idx] += (en-st+1)*val;

            if(st != en){
                lazy[2*idx+1] += val;
                lazy[2*idx+2] += val;
            }
            return;
        }
        int mid = (en+st)/2;
        int left = idx*2+1;
        int right = idx*2+2;

        updateRange(left, st, mid, l, r, val);
        updateRange(right, mid+1, en, l, r, val);

        tree[idx] = tree[left] + tree[right];
    }

    void update(vector<int>& a, int idx, int st, int en, int pos, int val)
    {
        propagate(idx, st, en);

        if(st == en){
            tree[idx] = val; // Segment tree update
            a[pos] = val;    // Given array update
            return;
        }
        int mid = (en+st)/2;
        int left = idx*2+1;
        int right = idx*2+2;

        if(pos <= mid){
            update(a, left, st, mid, pos, val);
        }
        else{
            update(a, right, mid+1, en, pos, val);
        }

        tree[idx] = tree[left] + tree[right];
    }

    void printTree()
    {
        for(int i=0; i<tree.size(); i++){
            cout << tree[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    vector<int> a = {5, 3, 2, 4, 1, 8, 6, 10}; // Example array
    int n = a.size();

    SegmentTree s(n);

    s.build(a, 0, 0, n-1);
    s.printTree();

    cout << "\n" << s.query(0, 0, n-1, 1, 5) << "\n";

    s.updateRange(0, 0, n-1, 2, 5, 2);
    s.printTree();
    cout << "\n" << s.query(0, 0, n-1, 1, 5) << "\n";
}
