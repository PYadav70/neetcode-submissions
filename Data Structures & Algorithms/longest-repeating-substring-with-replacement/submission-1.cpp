class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int>mp;
        int length = 0;
        int left = 0;
        int maxfreq = 0;

        for(int right=0; right<n; right++){
            mp[s[right]]++;
            maxfreq = max(maxfreq, mp[s[right]]);

            if((right-left + 1)-maxfreq > k){
                mp[s[left]]--;
                left++;
            }
           length = max(length, right-left+1);
        }
        return length;
    }
};
