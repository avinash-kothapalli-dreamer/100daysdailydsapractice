class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st = 0;
        int curr =0;
        int j = 0;
        int n = gas.size();
        int totalgas= 0;
        int totalcost = 0;
        while(j<gas.size()){
            totalgas+=gas[j];
            totalcost+=cost[j];
            curr -= cost[j];
            curr+=gas[j];
            if(curr<0){
                st = j+1;
                curr = 0;
            }
            j++;
        }
        
        return (totalgas<totalcost)?-1:st;
    }
};