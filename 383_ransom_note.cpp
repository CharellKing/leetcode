class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int note_chs[256], maga_chs[256];
        memset(note_chs, 0, 256 * sizeof(256));
        memset(maga_chs, 0, 256 * sizeof(256));
        
        for(int i = 0; i < ransomNote.size(); i ++) {
            note_chs[ransomNote[i]] ++;
        }
        
        for(int i = 0; i < magazine.size(); i ++) {
            maga_chs[magazine[i]] ++;
        }
        
        for(int i = 0; i < 256; i ++) {
            if (note_chs[i] > maga_chs[i]) {
                return false;
            }
        }
        return true;
    }
};
