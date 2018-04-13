class Solution {
public:
    void split_words(const string& str, vector<string>& words) {
        string word;
        for(int i = 0; i < str.size(); i ++) {
            if (' ' == str[i]) {
                if (word.size() > 0) {
                    words.push_back(word);
                }
                word.clear();
            } else {
                word.push_back(str[i]);
            }
        }
        if (word.size() > 0) {
            words.push_back(word);
        }
    }
    
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        split_words(str, words);
        
        if (pattern.size() != words.size()) {
            return false;
        }
        
        string combinations[256];
        unordered_map<string, char> reverse_combinations;
        for(int i = 0; i < pattern.size(); i ++) {
            if (combinations[pattern[i]] == "" and reverse_combinations.find(words[i]) == reverse_combinations.end()) {
                combinations[pattern[i]] = words[i];
                reverse_combinations.insert(make_pair(words[i], pattern[i]));
            } else if (!(combinations[pattern[i]] == words[i] and reverse_combinations[words[i]] == pattern[i])) {
                return false;
            }
        }
        return true;
    }
};
