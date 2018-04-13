class Solution {
public:
	vector<string> get_fields(const string& s, int i) {
		vector<string> fields;
		string val;
		if (i < s.size()) {
			val.append(1, s[i]);
			fields.push_back(val);
		}


		if (i + 1 < s.size() && s[i] != '0') {
			val.append(1, s[i + 1]);
			fields.push_back(val);
		}

		if (i + 2 < s.size() && s[i] != '0') {
			val.append(1, s[i + 2]);
			if (val >= "100" && val <= "255") {
				fields.push_back(val);
			}
		}
		return fields;
	}

    vector<string> restoreIpAddresses(const string& s) {
    	if (s.size() < 4) {
    		return vector<string>();
    	}

        int index = 0;
        vector<list<string>> list_rets;
        list<string> list_ret;
        vector<string> fields1 = get_fields(s, 0);
        for(int i = 0; i < fields1.size(); i ++) {
        	list_ret.push_back(fields1[i]);
        	index += i + 1;
        	vector<string> fields2 = get_fields(s, index);
        	for(int j = 0; j < fields2.size(); j ++) {
        		list_ret.push_back(fields2[j]);
        		index += j + 1;
        		vector<string> fields3 = get_fields(s, index);
        		for(int k = 0; k < fields3.size(); k ++) {
        			list_ret.push_back(fields3[k]);
        			index += k + 1;
        			if (index < s.size() && s.size() - index <= 3) {
        				vector<string> fields4 = get_fields(s, index);
        				int m = s.size() - index;
        				if (fields4.size() == m) {
        					list_ret.push_back(fields4[m - 1]);
        					list_rets.push_back(list_ret);
        					list_ret.pop_back();
        				}
        			}
        			index -= k + 1;
        			list_ret.pop_back();
        		}
        		index -= j + 1;
        		list_ret.pop_back();
        	}
        	index -= i + 1;
        	list_ret.pop_back();
        }

        vector<string> rets;
        for(int i = 0; i < list_rets.size(); i ++) {
        	string ret;
        	for(list<string>::iterator iter = list_rets[i].begin(); list_rets[i].end() != iter; iter ++) {
        		if (ret.size() == 0) {
        			ret += *iter;
        		} else {
        			ret += "." + *iter;
        		}
        	}
        	rets.push_back(ret);
        }
        return rets;
    }
};