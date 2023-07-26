class Solution {
public:
    string maskPII(string s) {
       // string str="";
         vector<string>vec(4);
         vec[0] = "***-***-";
        vec[1] = "+*-***-***-";
        vec[2] = "+**-***-***-";
        vec[3] = "+***-***-***-";
            
        bool email=false,phone=false;
            
        char ch = s[0];
        //cout<<ch;
        if(ch>='A' && ch<='Z'||ch>='a' && ch<='z') email = true;
        else phone = true;
       string str="";
        
        if(phone)
        {
            //cout<<"phone";
            int cnt=0;
            for(int i=s.length()-1;i>=0;i--)
            {
                if(s[i]>='0' && s[i]-'0'<='9')
                {
                    cnt++;
                    str+=s[i];
                    
                    if(cnt==4) break;
                }
            }
            int help = 0;
            
            for(int i=0;i<s.length();i++) if(s[i]>='0' && s[i]-'0'<='9') help++;
            int countrycodelen = help-10;
            
            reverse(str.begin(),str.end());
            
          str = vec[countrycodelen] + str;
            
        
        }
        else
        {
            //cout<<"email";
           str+=tolower(s[0]);
        
          str+="*****";
           int i=0;
           for( i=0;i<s.length()-1;i++){
               if(s[i+1] == '@') break;
           }
        
           string s1 = s.substr(i);
           transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
          
        
          
        
           str+=s1;
           
        }
    
      return str;
    
    }
};