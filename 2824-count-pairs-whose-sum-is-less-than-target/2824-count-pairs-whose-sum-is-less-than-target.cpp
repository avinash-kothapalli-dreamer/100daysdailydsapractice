class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans =0,n=nums.size();
        multiset<int>mq;
        mq.insert(nums[0]);
        //multiset<int>::iterator it;
        for(int i=1;i<n;i++){
        int tar = target - nums[i];
        multiset<int>::iterator it = mq.lower_bound(tar);
        // int ind = mq.find(val);
        if(it != mq.begin()){
            ans+=distance(mq.begin(),it);
        }
        mq.insert(nums[i]);
        }
        
        return ans;
    }
};