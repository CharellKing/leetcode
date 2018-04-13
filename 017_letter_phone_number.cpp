class Solution {
private:
    const string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    void to_letter(const string& digits, int index, vector<string>& words, string& word) {
        if (index >= digits.size()) {
            words.push_back(word);
        } else {
            const string& chs = mapping[digits[index] - '0'];
            for(int i = 0; i < chs.size(); i ++) {
                word.push_back(chs[i]);
                to_letter(digits, index + 1, words, word);
                word.pop_back();
            }
        }
    }
    vector<string> letterCombinations(const string& digits) {
        if (digits.size() <= 0) {
            return vector<string>();
        }
        vector<string> words;
        string word;
        to_letter(digits, 0, words, word);
        return words;
    }
};
