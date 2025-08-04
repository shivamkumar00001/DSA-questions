class Solution {
public:
    int totalFruit(vector<int>& fruits) {
          
          int l=0;
          int r=0;
          int maxlen=0;
          int v=0;
          int x=-1;
          int n= fruits.size();
          int count=1;
          map<int,int> m;
        
        while(r<n){
            
                m[fruits[r]]+=1;
            
             if(m.size()>2){
                while(m.size()>2){
                    m[fruits[l]]--;
                    if( m[fruits[l]]==0){
                        m.erase(fruits[l]);
                    }
                    l++;
                }
            }
           else if(m.size()<=2){
                maxlen=max(maxlen,r-l+1);
                
            }
            r++;
        }
        return maxlen;
    }
};