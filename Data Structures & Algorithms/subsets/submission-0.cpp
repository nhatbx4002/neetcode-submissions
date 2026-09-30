class Solution {
public:

    void backtracking(vector<int>& nums,int st, vector<int> path, vector<vector<int>>& res){
        res.push_back(path);
        for(int i = st; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1,path,res);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path = {}; 
        backtracking(nums,0,path,res);
        return res;
    }
};
