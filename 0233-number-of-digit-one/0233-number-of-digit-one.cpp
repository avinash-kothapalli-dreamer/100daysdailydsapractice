class Solution {
public:
    int hell(int l,string s){
        int temp = 0;
        for(int i=l;i<s.length();i++){
            temp = temp*10+s[i]-'0';
        }
        
        return temp+1;
    }
    int f(int pos,bool tight,string help,vector<vector<int>> &dp){
        
        if(pos == help.size()) return 0;
        
        if(dp[pos][tight?1:0] != -1) return dp[pos][tight?1:0];
        
        int limit = 9;
        
        if(tight){
           limit = help[pos]-'0' ;
        }
        int ans = 0;
        for(int i = 0;i<=limit;i++){
           bool newtight = tight && (i==limit);
            
            if(i==1) ans=ans+ ((i==limit)?hell(pos+1,help):pow(10,help.size()-1-pos) )+ f(pos+1,newtight,help,dp);
            else ans+= f(pos+1,newtight,help,dp);
            
        }
        
      return dp[pos][tight?1:0]=ans;
    }
    int countDigitOne(int n) {
       string help = to_string(n);
        vector<vector<int>>dp(help.size()+1,vector<int>(2,-1));
       return f(0,true,help,dp);
        
    }
};   


