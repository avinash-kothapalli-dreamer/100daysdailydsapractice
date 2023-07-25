class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int>visited(n,0);
        
        int res = 0;
        
        
        for(int i=0;i<n;i++){
            if(nums[i] != INT_MAX){
                int count = 0,start = nums[i];
                do{
                    int temp = start;
                    start = nums[start];
                    nums[temp] = INT_MAX;
                    
                    count++;
                    
                }while(nums[start] != INT_MAX);
                
                res = max(res,count);
            }
        }
        
        return res;
    }
};