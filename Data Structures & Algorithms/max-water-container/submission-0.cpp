class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int max_value = 0;
        int l = 0;
        int r = n - 1;

        while (l < r) {
            max_value = max(min(heights[l], heights[r]) * (r - l), max_value);

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max_value;
    }
};
