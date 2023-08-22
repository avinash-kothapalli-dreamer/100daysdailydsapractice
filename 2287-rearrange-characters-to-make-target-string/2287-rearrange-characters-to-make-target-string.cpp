class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int>mpp,mpp1;
        
        for(auto it:s){
            mpp[it]++;
        }
        int ans = 1e9;
        for(auto it:target){
            mpp1[it]++;
        }
        
        for(auto it:target){
           ans = min(ans,mpp[it]/mpp1[it]);
        }
        
        
        return ans;
    }
};