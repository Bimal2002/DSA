#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    vector<int>segTree;
    vector<int>arr;
    int n;
    public:
    SegmentTree(vector<int>input){
       arr = input;
       n = arr.size();
       segTree.resize(4*n);
       built(0,0,n-1);
    }
    void built(int ind, int low,int high){
        if(low == high){
            segTree[ind]= arr[low];
            return ;
        }

        int mid = (low + high)/2;
        built(2*ind+1,low,mid);
        built(2*ind+2,mid+1,high);

        segTree[ind]= segTree[2*ind+1]+ segTree[2*ind+2];

    }
    void update(int ind,int low,int high,int pos,int newVal){
        if(low == high){
            segTree[ind]= newVal;
            arr[pos] =newVal;
            return ;

        }

        int mid = (low + high)/2;
        if(pos <= mid){
            update(2*ind+1,low,mid,pos,newVal);
        }else{
            update(2*ind+2,mid+1,high,pos,newVal);
        }
        segTree[ind]= segTree[2*ind+1]+ segTree[2*ind+2];
    }
    void updateValue(int pos,int val){
        update(0,0,n-1,pos,val);
    }
    void printTree(){
        for(int i=0;i<2*n;i++){
            cout<<segTree[i]<<" ";
        }
    }

    int query(int ind ,int low ,int high, int l,int h ){
        if(h < low || l > high){
           return 0; // no overlap
        }
        if(l <= low && high <= h) return segTree[ind];
        int mid = (low + high)/2;
        int left = query(2*ind+1,low,mid,l,h);
        int right = query(2*ind+2, mid+1,high,l,h);
        return left + right;
    }
    int rangeSum(int l,int r){
        return query(0,0,n-1,l,r);
    }

};
int main() {
    vector<int> nums = {2, 5, 1, 4, 9, 3};
    SegmentTree st(nums);

    cout << "Initial sum [1,4] = " << st.rangeSum(1, 4) << endl;

    st.updateValue(3, 10);  // arr[3] = 10 instead of 4
    cout << "After update, sum [1,4] = " << st.rangeSum(1, 4) << endl;

    return 0;
}