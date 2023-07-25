class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int>visited(n,0);
        
        int res = 0;
        
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int count = 0,start = nums[i];
                do{
                    count++;
                    start = nums[start];
                    visited[start] = true;
                }while(nums[i] !=start);
                
                res = max(res,count);
            }
        }
        
        return res;
    }
};