class Bitset {
    string x = "";
    int size ;
    int ones;
    int flips;
public:
    Bitset(int size) {
        this->size = size;
        for(int i=0;i<size;i++){
            x+='0';
        }
        ones = 0;
        flips=0;

    }
    
    void fix(int idx) {
        if(flips%2 == 0){
            //means i am thinking that '1' means '1' and '0' means '0';
            if(x[idx] == '0'){
                ones++;
                x[idx] = '1';
            }
        }
        else{
            //means now '0' means '1' and '1' means'0'
            if(x[idx] == '1'){
                ones++;
                x[idx] = '0';
            }
        }
    }
    
    void unfix(int idx) {
        if(flips%2 == 0){
            //means i am thinking that '1' means '1' and '0' means '0';
            if(x[idx] == '1'){
                ones--;
                x[idx] = '0';
            }
        }
        else{
            //means now '0' means '1' and '1' means'0'
            if(x[idx] == '0'){
                ones--;
                x[idx] = '1';
            }
        }
    }
    
    void flip() {
        flips++;
        ones = size - ones;
    }
    
    bool all() {
        if(ones == size)return true;
        return false;
    }
    
    bool one() {
        if(ones>=1)return true;
        return false;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string ans = x;
        if(flips%2 == 1){
            for(int i=0;i<size;i++){
                if(ans[i] == '1')ans[i] = '0';
                else if(ans[i] == '0')ans[i] = '1';
            }
        }
        return ans;
    }
};
