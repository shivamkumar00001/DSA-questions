class Solution {
public:
    int largestInteger(int num) {
        vector<int> digit;
        int large =0;
        priority_queue<int>pe;
        priority_queue<int>po;
        while(num>0){
            int x = num%10;
            digit.push_back(x);
            if(x%2 == 0){
                pe.push(x);
            }
            else{
                po.push(x);
            }
            num = num/10;
        }
        reverse(digit.begin(),digit.end());
        int i =0;
        while(po.size()>0 || pe.size()>0){
            if(digit[i]%2 == 0){
                if(pe.size()>0){
                    large = large*10+pe.top();
                    pe.pop();
                }
                else if(pe.size()<0 && po.size()>0){
                    large = large*10 +po.top();
                    po.pop();
                }
            }
            else{
                if(po.size()>0){
                    large = large*10+po.top();
                    po.pop();
                }
                else if(po.size()<0 && pe.size()>0){
                    large = large*10 +pe.top();
                    pe.pop();
                }
            }
            i++;
        }

        return large;

    }
};