class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;

        for(int num : nums){
            mp[num]++;
        }
        vector<pair<int, int>>freq;
        for(auto &c : mp){
            freq.push_back({c.second, c.first});
        }
        sort(rbegin(freq), rend(freq));

        vector<int>result;

        for(int i = 0; i<k ; i++){
            result.push_back(freq[i].second);
        }
        return result;

    }
};
