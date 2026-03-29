class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_set<int>storeRes(nums.begin(), nums.end());

        for(int num : nums){
            int streak = 0;
            int curr = num;
            while(storeRes.find(curr) != storeRes.end()){
                streak++;
                curr++;
            }
            res = max(res, streak);
        }
        return res;
    }
};
