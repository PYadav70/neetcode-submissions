class Solution {
public:
    string minWindow(string s, string t) {
          if(s.size() < t.size()) return "";

          vector<int>requiredCount(128,0);
          for(char c : t){
            requiredCount[c]++;
          }

          int left = 0;
          int count = t.size();
          int minLen = INT_MAX;
          int start = 0;

          for(int right=0; right < s.size(); right++){
            if(requiredCount[s[right]] > 0){
                count--;
            }
            requiredCount[s[right]]--;

            while(count == 0){
                if(right-left + 1 < minLen){
                    minLen = right-left + 1;
                    start = left;
                }
                requiredCount[s[left]]++;

                if(requiredCount[s[left]] > 0){
                    count++;
                }
                left++;
            }
          }
          if(minLen == INT_MAX) return "";
          return s.substr(start, minLen);
    }
};

