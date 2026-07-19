class Solution {
public:
    int hammingWeight(uint32_t n) {
    //   int n = nums.size();
      int count = 0;
      for(int i=31; i>=0; i--){
        if((n >> i)& 1 == 1){
            count++;
        }
      }
      return count;
    }
};
