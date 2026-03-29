class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>count;

        for(int num : nums){
           count[num]++;
        }
        // store in vector
        vector<pair<int,int>>freq;
        for(auto &p : count){
          freq.push_back({p.second, p.first});
        }
        //descending order
        sort(freq.rbegin(), freq.rend());

        //take first k element
        vector<int>result;
        for(int i=0; i<k; i++){
           result.push_back(freq[i].second);
        }
        return result;
    }
};
