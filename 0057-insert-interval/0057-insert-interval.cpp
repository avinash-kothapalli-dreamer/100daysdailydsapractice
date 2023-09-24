class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval});
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>>ans;
        int currstart = intervals[0][0];
        int currend = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            int newend = intervals[i][1];
            int newstart = intervals[i][0];
            
            if(currend>=newstart){
                currend = max(currend,newend);
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