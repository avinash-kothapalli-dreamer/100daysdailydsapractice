class Solution {
public:
    vector<int> left(vector<int>& maxHeights){
        vector<int>ans(maxHeights.size(),-1);
        
        stack<pair<int,int>>st;
        
        for(int i=0;i<maxHeights.size();i++){
            while(st.size()>0 && st.top().first>=maxHeights[i]) st.pop();
            
            if(st.size()>0) ans[i] = st.top().second;
            
            st.push({maxHeights[i],i});
             
        }
        
        return ans;
    }
    vector<int> right(vector<int>& maxHeights){
        vector<int>ans(maxHeights.size(),maxHeights.size());
        
        stack<pair<int,int>>st;
        
        for(int i=maxHeights.size()-1;i>=0;i--){
            while(st.size()>0 && st.top().first>=maxHeights[i]) st.pop();
            
            if(st.size()>0) ans[i] = st.top().second;
            
            st.push({maxHeights[i],i});
             
        }
        
        return ans;
    }
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        vector<int>leftsmaller = left(maxHeights);
        
        vector<long long int>leftsum(maxHeights.size(),0),rightsum(maxHeights.size(),0);
        
        for(int i=0;i<maxHeights.size();i++){
            int prev = leftsmaller[i];
            
            leftsum[i] = 1ll*(i - prev)*maxHeights[i];
            
            if(prev != -1) leftsum[i]+=leftsum[prev];
        }
        
        
        vector<int>rightsmaller = right(maxHeights);
        
        for(int i=maxHeights.size()-1;i>=0;i--){
            int prev1 = rightsmaller[i];
            
            rightsum[i] = 1ll*(prev1-i)*maxHeights[i];
            
            if(prev1 != maxHeights.size()) rightsum[i]+=rightsum[prev1];
        }
        
        long long maxi = -1e9;
        
        for(int i=0;i<maxHeights.size();i++){
            long long sum = leftsum[i]+rightsum[i] - maxHeights[i];
            if(sum>maxi) maxi = sum;
        }
        
        
        
        
        
        
        return maxi;
    }
};