class Solution {
public:

    void backtracking(vector<int>& nums, int st, vector<int>& currPath, vector<vector<int>>& ans){
        ans.push_back(currPath);

        for(int i = st; i < nums.size(); i++){
            if(i > st && nums[i] == nums[i-1]) continue; 
            currPath.push_back(nums[i]);
            backtracking(nums,i+1,currPath,ans);
            currPath.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> currPath;
        
        backtracking(nums,0,currPath,ans);
        return ans;
    }
};
