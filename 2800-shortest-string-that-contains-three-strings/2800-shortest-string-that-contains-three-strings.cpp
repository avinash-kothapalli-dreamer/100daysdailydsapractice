class Solution {
public:

    string getMin(string c,string d){
        return (c.size()<d.size() || (c.size()==d.size() && c <d))? c:d;
    }
    string addTwoStrings(string &a,string &b){
        if(b.find(a) != string::npos) return b;

        else if(a.find(b) != string::npos) return a;

        for(int i=0;i<a.size();i++){
          string one = a.substr(i);
          string two = b.substr(0,one.size());

          if(one == two) return a+b.substr(one.size());
        }

        return a+b;
    }
    string solve(string &a,string &b,string &c){
        string t1 = addTwoStrings(a,b);
        string t2 = addTwoStrings(b,a);

        string res1 = getMin(addTwoStrings(t1,c),addTwoStrings(c,t1));
        string res2 = getMin(addTwoStrings(t2,c),addTwoStrings(c,t2));

        return getMin(res1,res2);
    }
    string minimumString(string a, string b, string c) {
        string res = getMin(solve(a,b,c),min(solve(b,c,a),solve(c,a,b)));

        return res;
    }
};