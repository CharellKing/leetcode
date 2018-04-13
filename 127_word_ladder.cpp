#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	unordered_map<int, vector<int> > word_map;
	unordered_set<int> used_words;
public:
	bool is_neighbour(const string& a, const string& b) {
		if (a.size() != b.size()) {
			return false;
		}

		int diff_count = 0;
		for(int i = 0; i < a.size(); i ++) {
			if (a[i] != b[i]) {
				diff_count ++;
			}
		}
		return diff_count == 1;
	}

	void initialize(const string& beginWord, const string& endWord, unordered_set<string>& wordList, vector<int>& layer, vector<int>& reverse_layer) {
		wordList.insert(beginWord);
		wordList.insert(endWord);
		vector<string> words = vector<string>(wordList.begin(), wordList.end());

		int begin = 0, end = 0;
		for(int i = 0; i < words.size(); i ++) {
			if (words[i] == beginWord) {
				begin = i;
			} else if (words[i] == endWord) {
				end = i;
			}
			for(int j = i + 1; j < words.size(); j ++) {
				if (is_neighbour(words[i], words[j])) {
					unordered_map<int, vector<int> >::iterator iter = word_map.insert(make_pair(i, vector<int>())).first;
					iter->second.push_back(j);

					iter = word_map.insert(make_pair(j, vector<int>())).first;
					iter->second.push_back(i);
				}
			}
		}

		layer.push_back(begin);
		used_words.insert(begin);
		reverse_layer.push_back(end);
		used_words.insert(end);
	}

	bool is_find(const vector<int>& layer, int target) {
		for(int i = 0; i < layer.size(); i ++) {
			if (layer[i] == target) {
				return true;
			}
		}
		return false;
	}

	bool get_next_layer(const vector<int>& cur_layer, const vector<int>& reverse_layer, vector<int>& next_layer) {
		for(vector<int>::const_iterator iter = cur_layer.begin(); cur_layer.end() != iter; iter ++) {
			unordered_map<int, vector<int> >::iterator word_iter = word_map.find(*iter);
			if (word_map.end() != word_iter) {
				for(vector<int>::iterator next_iter = word_iter->second.begin(); word_iter->second.end() != next_iter; next_iter ++) {
					if (is_find(reverse_layer, *next_iter)) {
						return true;
					} else {
						if (used_words.end() == used_words.find(*next_iter)) {
							next_layer.push_back(*next_iter);
							used_words.insert(*next_iter);
						}
					}
				}
			}
		}
		return false;
	}

	int ladderLength(const string& beginWord, const string& endWord, unordered_set<string>& wordList) {
		if (beginWord == endWord) {
			return 1;
		}

		vector<int> one_layer, two_layer, reverse_one_layer, reverse_two_layer;
		vector<int> &cur_layer = one_layer, &next_layer = two_layer, &cur_reverse_layer = reverse_one_layer, &next_reverse_layer = reverse_two_layer;

		initialize(beginWord, endWord, wordList, cur_layer, cur_reverse_layer);
		int n_layer = 1;
		while (cur_layer.size() > 0 && cur_reverse_layer.size() > 0) {
			if (get_next_layer(cur_layer, cur_reverse_layer, next_layer)) {
				return 2 * n_layer;
			}

			swap(cur_layer, next_layer);
			next_layer.clear();

			if (get_next_layer(cur_reverse_layer, cur_layer, next_reverse_layer)) {
				return 2 * n_layer + 1;
			}
			swap(cur_reverse_layer, next_reverse_layer);
			next_reverse_layer.clear();

			n_layer ++;
		}
		return 0;
	}
};
