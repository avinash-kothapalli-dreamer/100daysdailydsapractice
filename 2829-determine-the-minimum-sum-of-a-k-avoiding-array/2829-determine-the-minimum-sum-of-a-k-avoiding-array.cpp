class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int>st;
        st.insert(1);
        int j = 2;
        while(st.size()<n){
            if(st.find(k-j) == st.end()){
                st.insert(j);
               
            }
            j++;
        }
        int sum = 0;
        
        for(auto it:st) sum+=it;
        
        return sum;
    }
};