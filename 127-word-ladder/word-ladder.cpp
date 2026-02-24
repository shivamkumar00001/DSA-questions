class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         
         unordered_set<string> s(wordList.begin(), wordList.end());
         s.erase(beginWord);
         queue<pair<string, int>>q;
         q.push({beginWord,1});
         
         while(q.size()>0){
            
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord) return step;
            for(int i =0; i< word.size();i++){
                char original = word[i];
                for(char j = 'a'; j<= 'z' ; j++){
                    word[i] = j;
                    if(s.find(word) != s.end()){
                        q.push({word, step+1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
         }

         return 0;
    }
};