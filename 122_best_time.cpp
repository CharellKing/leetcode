class Solution {
public:
    void pass_descend(vector<int>& prices, int& begin) {
        while (begin + 1 < prices.size() && prices[begin] >= prices[begin + 1]) {
            begin ++;
        }    
    }
    
    int cal_ascend(vector<int>& prices, int& begin) {
        int trough = prices[begin];
        while (begin + 1 < prices.size() && prices[begin] <= prices[begin + 1]) {
            begin ++;
        }
        return prices[begin] - trough;
    }
    
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        
        int begin = 0, sum = 0;
        while(begin + 1 < prices.size()) {
            pass_descend(prices, begin);
            sum += cal_ascend(prices, begin);
        }
        return sum;
    }
};
