class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();

        vector<int>freq1(26,0);
        for(char c : s1){
            freq1[c-'a']++;
        }
        vector<int>window(26,0);
        int left = 0;
        for(int right = 0 ; right < s2.size(); right++){
           window[s2[right]-'a']++;

           if(right - left + 1 > k ){
            window[s2[left]- 'a']--;
            left++;
           }
           if(right - left + 1 == k){
            if(window == freq1){
                return true;
            }
           }
        }
        return false;
    }
};
