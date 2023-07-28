class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>ans;
        int sum = 0;
        
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
                int n = ans.size();
                sum+=ans[n-1]+ans[n-2];
                ans.push_back(ans[n-1]+ans[n-2]);
                
            }else if(operations[i]=="C"){
                sum -= ans.back();
                
                ans.erase(ans.end()-1);
               
                
            }else if(operations[i]=="D"){
                sum+=2*ans.back();
                ans.push_back(2*ans.back());
                
            }else{
                
                
                
                sum+=stoi(operations[i]);
                ans.push_back(stoi(operations[i]));
            }
            
            //cout<<sum<<" ";
        }
        for(auto it:ans) cout<<it<<" ";
        return sum;
    }
};