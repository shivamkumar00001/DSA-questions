class Solution {
public:
    
    void generate(int ind,vector<string>& s, int n, string & ds){
        if((ind)>=n){
            s.push_back(ds);
            return;
        }
        if(ind==0){
        if(ds[ind]!= '0'){
            ds.push_back('0');
            generate(ind+1,s,n,ds);
            ds.pop_back();
        }}
        
         if(ind>0){
            if(ds[ind-1]!= '0'){
            ds.push_back('0');
            generate(ind+1,s,n,ds);
            ds.pop_back();
        }
         }     
        ds.push_back('1');
        generate(ind+1,s,n,ds); 
        ds.pop_back();


    }
    vector<string> validStrings(int n) {
        vector<string> s;
        string ds;
        generate(0,s,n,ds);
        return s;

    }
};
