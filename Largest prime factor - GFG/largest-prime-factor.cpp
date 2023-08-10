//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
bool isprime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    
    return true;
}
    long long int largestPrimeFactor(int N){
        // code here
        int ans = 0;
        for(int i=1;i<=sqrt(N);i++){
            if(N%i==0 ){
                if(isprime(i) && isprime(N/i)){
                  int help = max(i,N/i);
                  ans = max(ans,help);
                }else if(isprime(i)){
                    ans = max(ans,i);
                }else if(isprime(N/i)){
                    ans = max(ans,N/i);
                }
                
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends