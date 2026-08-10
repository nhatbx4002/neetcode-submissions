class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = n - 1;
            int target = -nums[i];
            int cur_sum = 0;
            while (l < r) {
                cur_sum = nums[l] + nums[r];

                if (cur_sum < target) {
                    l++;
                } else if (cur_sum > target) {
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;

                    l++;
                    r--;
                }
            }
        }

        return res;
    }
};
