class FindSumPairs {
public:
    vector<int>arr1,arr2;
    unordered_map<int,int>freq2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(int num : arr2){
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        int oldVal = arr2[index];
        freq2[oldVal]--;
        arr2[index] += val;
        freq2[arr2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int x : arr1){
            ans += freq2[tot-x];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */