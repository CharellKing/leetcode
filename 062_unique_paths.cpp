class Solution {
public:
    void get_max_min(long long int n, long long int m_n, long long int& max, long long int& min) {
        if (n > m_n) {
            max = n;
            min = m_n;
        } else {
            max = m_n;
            min = n;
        }    
    }
    
    long long int combine(long long int m, long long int n) {
        long long int max = n, min = m -n;
        get_max_min(n, m - n, max, min);
        
        int i = max + 1;
        int j = 1;
        long long int ret = 1;
        while (i <= m && j <= min) {
            ret = ret * i / j;
            i ++;
            j ++;
        }
        return ret;
    }
    
    int uniquePaths(int m, int n) {
        long long int total_steps = m + n - 2;
        long long horizon_steps = m - 1;
        if (m <= 0 || n <= 0) {
            return 0;
        }
        
        if (total_steps <= 0 || horizon_steps <= 0) {
            return 1;
        }
        return combine(total_steps, horizon_steps);
    }
};
