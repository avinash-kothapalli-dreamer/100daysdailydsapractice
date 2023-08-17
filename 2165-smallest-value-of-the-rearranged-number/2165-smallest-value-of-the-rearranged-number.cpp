class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int>help(10,0);
        int neg = 0;
        
        if(num<0) {
            neg =1;
            num*=-1;
        }
         while(num>0){
            int rem = num%10;
            num/=10;
            help[rem]++;
         }
        long long ans = 0;
        
        //for(int i=0;i<10;i++) cout<<help[i]<<" ";
        if(neg){
           int j = 9;
            while(j>=0 ){
                if(help[j]>0){
                   ans = ans*10 + j;
                help[j]--; 
                }
                
                if(help[j]==0) j--;
                
                
                
            }
        }else{
            int j = 1;
            while(j<10 ){
                if(help[j]>0){
                ans=ans*10+j;
                help[j]--; 
                    break;
                }
                
                if(help[j]==0) j++;
            }
            
            j = 0;
            //cout<<ans<<endl;
            
            while(j<10 ){
                //cout<<help[j]<<j<<endl;
                if( help[j]>0){
               ans = ans*10 + j;
                help[j]--;
                }
                
                if(help[j]==0) j++;
            }
       }
        
        return (neg)?ans*-1:ans;
    }
};