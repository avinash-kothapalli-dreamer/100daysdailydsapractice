class Solution {
public:
    bool static cmp(vector<int>i1,vector<int>i2){
        return i1[0]<i2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int currstart = intervals[0][0];
        int currend  = intervals[0][1];
        vector<vector<int>>ans;
        
        for(int i=1;i<intervals.size();i++){
            int newstart = intervals[i][0];
            int newend = intervals[i][1];
           // cout<<newend<<endl;
            
            if(currend>=newstart){
                currend = max(newend,currend);
               // cout<<currend<<endl;
            }else{
                ans.push_back({currstart,currend});
                currstart = newstart;
                currend = newend;
            }
        }
        
        ans.push_back({currstart,currend});
        
        
        
        return ans;
    }
};