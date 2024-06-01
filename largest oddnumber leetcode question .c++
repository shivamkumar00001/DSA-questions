class Solution {
public:
    string largestOddNumber(string num) {
        
        string str="";

        for(int i=num.size();i>=0;--i){
            int digit=num[i]+'0';
            if(digit%2!=0){
                str=num.substr(0,i+1);
                break;
            }
        }
        return str;
    }
};
