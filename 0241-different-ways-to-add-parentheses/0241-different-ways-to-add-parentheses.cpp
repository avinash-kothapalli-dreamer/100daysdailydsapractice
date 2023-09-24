class Solution {
public:
    bool isoperator(char ch){
        return ch=='*' || ch=='+' || ch=='-';
    }
    vector<int> f(int i,int j,string& expression){
        int len = j-i+1;
        
        if(len<=2){
            return {stoi(expression.substr(i,len))};
        }
        vector<int>ans;
        for(int k=i;k<=j;k++){
            if(isoperator(expression[k])){
                char ch = expression[k];
                vector<int>left = f(i,k-1,expression);
                vector<int>right = f(k+1,j,expression);
                
                for(auto l:left){
                    for(auto r:right){
                        if(ch=='+'){
                            ans.push_back(l+r);
                        }else if(ch == '-'){
                            ans.push_back(l-r);
                        }else if(ch=='*'){
                            ans.push_back(l*r);
                        }
                    }
                }
                
            }
        }
        
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
       int n = expression.size();
        
        return f(0,n-1,expression);
    }
};