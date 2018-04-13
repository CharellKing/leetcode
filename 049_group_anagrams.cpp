class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> rets;
        unordered_map<string, int> anagrams;
        for(int i = 0; i < strs.size(); i ++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            unordered_map<string, int>::iterator iter = anagrams.find(tmp);
            if (anagrams.end() == iter) {
                rets.push_back(vector<string>());
                rets.back().push_back(strs[i]);
                anagrams.insert(make_pair(tmp, rets.size() - 1));
            } else {
                rets[iter->second].push_back(strs[i]);
            }
        }
        return rets;
    }
};