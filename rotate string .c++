class Solution {
public:
    bool rotateString(string s, string goal) {
        
        for(int i=0;i<s.size();i++){
            if(s==goal){
                return true;
                break;
            }
            else{
                s+=s[0];
                s.erase(s.begin());
            }
        }
        return false;



    }
};
