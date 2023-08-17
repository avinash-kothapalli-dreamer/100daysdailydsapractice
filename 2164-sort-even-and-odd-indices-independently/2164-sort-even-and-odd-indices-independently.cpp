class Solution {
public:
    static bool comp(int &a,int &b){
        return a>b;
    }
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>even,odd;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0)even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        
        sort(odd.begin(),odd.end(),comp);
        sort(even.begin(),even.end());
        
        nums.clear();
        
        int k = even.size();
        int j = odd.size();
        int i=0;
        int n = 0;
        while(i<k && n<j){
            nums.push_back(even[i]);
            nums.push_back(odd[n]);
            i++;
            n++;
        }
        
        while(i<k) {
            nums.push_back(even[i]);
            i++;
        }
        while(n<j) {
            nums.push_back(odd[n]);
            n++;
        }
        
        return nums;
    }
};