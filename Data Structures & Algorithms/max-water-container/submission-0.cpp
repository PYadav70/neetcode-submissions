class Solution {
public:
    int maxArea(vector<int>& heights) {
      int n = heights.size();
      int i = 0;
      int j = n-1;
      int mostWater = 0;

      while(i<j){
        int w = j-i;
        int h = min(heights[i], heights[j]);
        int area = h*w;
        mostWater = max(mostWater, area);

        if(heights[i] > heights[j]){
            j--;
        }else{
            i++;
        }
      }
      return mostWater;  
    }
};
