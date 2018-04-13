#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    struct DictNode {
        DictNode(char ch, bool is_word = false):ch(ch), is_word(is_word) {

        }
        char ch;
        unordered_map<char, DictNode*> childs;
        bool is_word;
    };
public:
    DictNode* build_tree(unordered_set<string>& word_dict) {
        DictNode* root = new DictNode('\n', false);
        for(unordered_set<string>::iterator iter = word_dict.begin(); word_dict.end() != iter; iter ++) {
            const string& str = *iter;
            DictNode* node = root;
            for(int i = 0; i < str.size(); i ++) {
                unordered_map<char, DictNode *>::iterator ret = node->childs.find(str[i]);
                if (ret == node->childs.end()) {
                    DictNode* new_node = new DictNode(str[i], false);
                    node->childs.insert(make_pair(str[i], new_node));
                    node = new_node;
                } else {
                    node = ret->second;
                }
            }

            if (node != root) {
                node->is_word = true;
            }
        }
        return root;
    }


    bool search_word(const string& s, const DictNode* root, const unordered_set<int>& cur, unordered_set<int>& next) {
        for(unordered_set<int>::const_iterator iter = cur.begin(); cur.end() != iter; iter ++) {
            const DictNode* node = root;
            for(int i = *iter; i < s.size(); i ++) {
                unordered_map<char, DictNode*>::const_iterator iter = node->childs.find(s[i]);
                if (iter == node->childs.end()) {
                    break;
                } else {
                    node = iter->second;
                    if (node->is_word) {
                        if (i + 1 == s.size()) {
                            return true;
                        }
                        next.insert(i + 1);
                    }
                }
            }
        }
        return false;
    }


    bool wordBreak(string s, unordered_set<string>& wordDict) {
        DictNode* root = build_tree(wordDict);


        unordered_set<int> one, two;
        unordered_set<int> &cur = one, &next = two;
        cur.insert(0);
        while (cur.size() > 0) {
            if (true == search_word(s, root, cur, next)) {
                return true;
            }
            swap(cur, next);
            next.clear();
        }
        return false;
    }
};


