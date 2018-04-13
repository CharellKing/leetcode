class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() <= 0) {
            return -1;
        }
        
        if (gas.size() == 1) {
            if (gas[0] >= cost[0]) {
                return 0;
            } else {
                return -1;
            }
        }
        vector<pair<int, int>> nums;
        for(int i = 0; i < gas.size(); i ++) {
            if (gas[i] - cost[i] != 0) {
                nums.push_back(make_pair(i, gas[i] - cost[i]));
            }
        }
        
        for(int i = 0; i < nums.size();) {
            if (nums[i].second >= 0) {
                int prev = i - 1;
                prev = (prev < 0 ? nums.size() - 1 : prev);
                if (nums[prev].second < 0) {
                    int j = i;
                    int sum = 0;
                     do {
                        sum += nums[j].second;
                        j ++;
                        if (j >= nums.size()) {
                            j = 0;
                        }
                    } while (sum >= 0 && j != i);
                    
                    if (i == j) {
                        if (sum >= 0) {
                            return nums[i].first;   
                        } 
                        return -1;
                    } else if (j > i) {
                        i = j;
                    } else {
                        i ++;
                    }
                } else {
                    i ++;
                }
            } else {
                i ++;
            }
        }
        return -1;
    }
};


