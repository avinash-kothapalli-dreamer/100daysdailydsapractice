class Solution {
public:
    int dp[11][2][2];
    int f(vector<string>&digits,string s,int pos,bool tight,bool allzero){
        if(pos == s.size()) return 1;
        
        int limit= 9;
        if(tight){
            limit = s[pos]-'0';
        }
        
        if(dp[pos][tight?1:0][allzero?1:0] != -1) return dp[pos][tight?1:0][allzero?1:0];
        int ans=0;
        ans += allzero ? f(digits,s,pos+1,false,true):0;
        
        for(int i=0;i<digits.size();i++){
         bool newtight = tight && stoi(digits[i])==limit;
            if(stoi(digits[i]) <=limit){
                ans+=f(digits,s,pos+1,newtight,false);
            }
        }
        
        return dp[pos][tight?1:0][allzero?1:0] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
      string help = to_string(n);
        memset(dp,-1,sizeof(dp));
        //vector<vectorvector<int>>dp(help.size()+1,vector<int>(2,-1));
      return f(digits,help,0,true,true)-1;
    }
};