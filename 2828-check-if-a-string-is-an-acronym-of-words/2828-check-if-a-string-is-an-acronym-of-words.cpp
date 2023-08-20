class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
       int n  = s.length();
       if(n != words.size()) return false;
        
       for(int i=0;i<n;i++){
           if(s[i]!=words[i][0]) return false;
       }
        
        return true;
    }
};