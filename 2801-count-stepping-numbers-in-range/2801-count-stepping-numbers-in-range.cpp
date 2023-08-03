class Solution {
     typedef long long   ll;
     ll mod = 1000000007;
public:
    ll dp[101][11][2][2];
    ll helper(int currindex,bool tight,bool zero,int prevdigit,string high){
        
        if(currindex == high.length()){
            if(zero) return 0;
            return 1;
        }
        
        ll res = 0;
        
        if(dp[currindex][prevdigit+1][tight][zero] != -1) return dp[currindex][prevdigit+1][tight][zero];
        
        int limit = high[currindex]-'0';
        
        if(!tight) limit = 9;
        for(int i=0;i<=limit;i++){
            bool istight = tight && i == limit;
            bool iszero = zero && i == 0;
            
            if(zero || abs(prevdigit-i)==1){
                res+=helper(currindex+1,istight,iszero,i,high);
                res%=mod;
            }
        }
        


        dp[currindex][prevdigit + 1][tight][zero] = res;
        return res;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        ll l = helper(0, true, true, -1, low);
        
        memset(dp, -1, sizeof(dp));
        ll r = helper(0, true, true, -1, high);
        
        ll res = r - l;
        res %= mod;
        res += mod;
        res %= mod;
        
        ll add = true;
        for (ll i = 1; i < (ll) low.size(); i++)
            if (abs(low[i] - low[i - 1]) != 1) add = false;
        if (add) res++;
        
        res %= mod;
        return res;
    }
};