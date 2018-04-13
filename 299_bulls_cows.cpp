class Solution {
public:
    string getHint(string secret, string guess) {
        int bull_count = 0;
        int cow_count = 0;
        int secret_ch_counts[256], guess_ch_counts[256];
        memset(secret_ch_counts, 0, 256 * sizeof(int));
        memset(guess_ch_counts, 0, 256 * sizeof(int));
        for(int i = 0; i < secret.size() && i < guess.size(); i ++) {
            if (secret[i] == guess[i]) {
                bull_count ++;
            } else {
                secret_ch_counts[secret[i]] ++;
                guess_ch_counts[guess[i]] ++;
            }
        }
        
        for(int i = 0; i < 256; i ++) {
            cow_count += (secret_ch_counts[i] > guess_ch_counts[i] ? guess_ch_counts[i] : secret_ch_counts[i]);
        }
        
        stringstream ss;
        ss << bull_count << "A" << cow_count << "B";
        return ss.str();
    }
};
