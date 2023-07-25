class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mpp;
        int n=list1.size(),m=list2.size();
        
        for(int i=0;i<n;i++){
            mpp[list1[i]]= i;
            
        }
        
        vector<string> ans;
        int mini = INT_MAX;
        
        for(int i=0;i<m;i++){
            if(mpp.find(list2[i]) != mpp.end()){
                if(i+mpp[list2[i]] == mini){
                    ans.push_back(list2[i]);
                }else if(i+mpp[list2[i]] < mini){
                    ans.clear();
                    ans.push_back(list2[i]);
                    mini = i+mpp[list2[i]];
                }
            }
        }
        
        return ans;
    }
};