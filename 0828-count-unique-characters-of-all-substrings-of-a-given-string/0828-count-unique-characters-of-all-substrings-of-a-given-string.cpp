class Solution {
public:
    int uniqueLetterString(string s) {
        int ans =0;
        int N = s.length();

        int index[26][2];

        int mod = pow(10,9) + 7;

        memset(index,-1,sizeof(index));

        for(int i=0;i<N;i++){
            int ch = s[i]-'A';
            ans= (ans + ((i - index[ch][1])*(index[ch][1] - index[ch][0])));

            ans%=mod;

            index[ch][0] = index[ch][1];
            index[ch][1] = i;
        }


        for(int c =0;c<26;c++){
            ans = ans +(N-index[c][1])*(index[c][1]-index[c][0]);

            ans%=mod;
        }
        
        return ans;
    }
};