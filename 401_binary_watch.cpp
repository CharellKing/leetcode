class Solution {
public:
    int count_bits(int number) {
        int count = 0;
        while (number) {
            number = number & (number - 1);
            count ++;
        }
        return count;
    }
    
    vector<string> readBinaryWatch(int num) {
        multimap<int, int> bits_num;
        for(int i = 0; i < 60; i ++) {
            bits_num.insert(make_pair(count_bits(i), i));
        }
        
        vector<string> ret;
        for(multimap<int, int>::iterator hour_iter = bits_num.begin(); bits_num.end() != hour_iter && hour_iter->first <= num; hour_iter ++) {
            if (hour_iter->second <= 11) {
                int minute_bits = num - hour_iter->first;
                pair<multimap<int, int>::iterator, multimap<int, int>::iterator> p = bits_num.equal_range(minute_bits);
                for(multimap<int, int>::iterator minute_iter = p.first; p.second != minute_iter; minute_iter ++) {
                    int minute = minute_iter->second;
                    int hour = hour_iter->second;
                    char c_time[32];
                    snprintf(c_time, 31, "%d:%02d", hour, minute);
                    ret.push_back(string(c_time));
                }
            }
        }
        return ret;
    }
};
