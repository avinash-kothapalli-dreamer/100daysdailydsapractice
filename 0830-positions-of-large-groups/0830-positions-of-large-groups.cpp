class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
      int prev = 0;
      char prevchar = s[0];
      int cnt = 1;
      vector<vector<int>> ans;
        int n = s.length();
        
        for(int i=1;i<s.length();i++){
            if(s[i]==prevchar){
                cnt++;
            }else{
                if(cnt>=3){
                    ans.push_back({prev,i-1});
                }
                prev = i;
                cnt = 1;
                prevchar = s[i];
            }
        }
        
        if(cnt>=3) ans.push_back({prev,n-1});
        
    return ans;
    }
};