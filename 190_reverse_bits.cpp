class Solution {
private:
    unordered_map<uint32_t, uint32_t> reverse_nums;
public:
    uint32_t reverseBits(uint32_t n) {
        if (0 == n) {
            return 0;
        }

        if (reverse_nums.find(n) != reverse_nums.end()) {
            return reverse_nums[n];
        }

        int reverse_num = 0, num = 0, i = 0, origin_num = n;
        while (n > 0) {
            int bit = n & 1;
            num |= (bit << i);
            reverse_num |= (bit << (31 - i));
            n >>= 1;
            i ++;
            reverse_nums.insert(make_pair(num, reverse_num));
            reverse_nums.insert(make_pair(reverse_num, num));
        }
        return reverse_nums[origin_num];
    }
};