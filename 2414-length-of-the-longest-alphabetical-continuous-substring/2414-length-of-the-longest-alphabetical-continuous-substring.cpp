class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i=0;
        int j=1;
        int n =s.length();
        if(n==1) return 1;
        int ans = 0;
        while(i<n && j<n){
            while(j<n && s[j] == s[j-1]+ 1){
                
                j++;
            }
            
            ans = max(ans,j-i);
            
           i = j;
           j++;
        }
        
        return ans;
    }
};