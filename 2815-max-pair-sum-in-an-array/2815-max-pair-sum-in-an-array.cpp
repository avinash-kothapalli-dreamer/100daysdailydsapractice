class Solution {
public:
    int maxSum(vector<int>& nums) {
        int arr[10]= {};
        int n = nums.size();
        int ans = -1;
        for(auto n : nums){
            int max_d = 0;
            int k = n;
            while(k){
                max_d = max(max_d,k%10);
                k/=10;
            }
            
            if(arr[max_d]) ans = max(arr[max_d]+n,ans);
            
            arr[max_d] = max(arr[max_d],n);
        }
        
        return ans;
    }
};