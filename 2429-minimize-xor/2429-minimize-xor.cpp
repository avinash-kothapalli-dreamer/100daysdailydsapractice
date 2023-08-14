class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        for(int i = num2;i;i/=2){
            if(i%2) cnt++;
        }
        //cout<<cnt<<endl;
        int i = 31;
        int x = 0;
        
        while(i>=0 && cnt){
            if(1<<i & num1){
                x|=1<<i;
                cnt--;
            }
            i--;
        }
        
        //cout<<cnt<<endl;
        //cout<<x<<endl;
       
        i=0;
        // bool flag = i<=31;
        // bool flag1 = cnt>=0;
        // cout<<flag << flag1<<endl;
        while(i<=31 && cnt){
            if((x & 1<<i) == 0){
                cnt--;
                x|=1<<i;
                // cout<<i<<cnt<<endl;
            }
            
            i++;
            // cout<<i<<endl;
        }
        
        return x;
        
    }
};