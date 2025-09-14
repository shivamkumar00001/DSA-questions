class Solution {
public:
    
    vector<int> solve(string s){

        vector<int> result;

        for(int i=0;i<s.size();i++){
            char c =s[i];

            if(c == '-' || c == '+' || c == '*'){

                vector<int> left = solve(s.substr(0,i));
                vector<int> right = solve(s.substr(i+1));

                for(int a: left){
                    for(int b : right){
                        if(c == '+'){
                            result.push_back(a+b);
                        }
                        else if( c == '-'){
                            result.push_back(a-b);
                        }
                        else if( c == '*'){
                            result.push_back(a*b);
                        }
                    }
                }
                
            }
            
        }
        if(result.empty()){
                    result.push_back(stoi(s));
                }
        return result;
    }
    vector<int> diffWaysToCompute(string s) {
        return solve(s);

    }
};