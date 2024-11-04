class Solution {
public:
    string compressedString(string word) {
        string comp;
        long long count = 1;
        
        for (long long i = 0; i < word.size(); i++) {
            if (i < word.size() - 1 && word[i] == word[i + 1] && count < 9) {
                count++;
            } else {
                
                comp += to_string(count);
                comp += word[i];
                count = 1; 
            }
        }

        return comp;
    }
};
