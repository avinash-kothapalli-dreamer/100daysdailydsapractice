class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int>mpp;
        int n  = nums.size();
        
        for(auto it:nums) mpp[it]++;
        
        int help = mpp.size();
        if(help == 1) return n*(n+1)/2;
        
        mpp.clear();
        
       // cout<<mpp.size()<<endl;
        
        int i=0,j=0;
        bool flag = true;
        
        while(i<n && j<n){
            if(flag)
            mpp[nums[j]]++;
            
            if(mpp.size()==help){
               cout<<j<<" "<<i<<endl;
                ans+=(n-j);
                mpp[nums[i]]--;
                flag = false;
                
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                 i++;
            }
            
            else {
                flag = true;
                j++; 
            }
        }
        
       return ans;
    }
};