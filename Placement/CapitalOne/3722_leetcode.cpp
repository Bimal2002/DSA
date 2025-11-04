class Solution {
public:
    string lexSmallest(string s) {
        string best = s;
        int n = s.length();
        for(int k=1;k<=n;k++){
            string temp = s;
            reverse(temp.begin(),temp.begin()+k);
            best = min(best,temp);

        }
        for(int k=1;k<= n;k++){
            string temp = s;
            reverse(temp.begin()+n-k,temp.end());
            best = min(temp,best);
        }
        return best;
    }
};
