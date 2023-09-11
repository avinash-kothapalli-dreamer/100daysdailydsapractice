struct Job{
    int Start,End,Profit;
};
bool static cmp(Job a,Job b){
    return a.End<b.End;
}
class Solution {
public:
    int dp[100000];
    int help(vector<Job> &vec,int n){
        int ind = -1;
        for(int i=n-1;i>=0;i--){
            if(vec[n].Start>=vec[i].End){
                ind = i;
                break;
            }
        }
        
        return ind;
    }
    
    int f(vector<Job> & vec,int n){
        
        if(n==0) return vec[0].Profit;
        
        if(dp[n] != -1) return dp[n];
        
        int pick = vec[n].Profit;
        int ind = help(vec,n);
        if(ind != -1){
            pick += f(vec,ind);
        }
        int nonpick = f(vec,n-1);
        
        return dp[n] = max(pick,nonpick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job>vec;
        for(int i=0;i<startTime.size();i++){
            vec.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(vec.begin(),vec.end(),cmp);
        
        memset(dp,-1,sizeof(dp));
        
        return f(vec,vec.size()-1);
    }
};