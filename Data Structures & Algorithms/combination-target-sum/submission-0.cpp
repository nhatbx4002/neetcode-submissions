class Solution {
public:
    void backtracking(vector<int>& nums,int st, int target,vector<int> current, vector<vector<int>>& res,int sum){
        if(sum == target){
            res.push_back(current);
            return;
        }else if(sum < target){
            for(int i = st ; i < nums.size(); i++){
                current.push_back(nums[i]);
                backtracking(nums,i,target,current,res,sum+nums[i]);
                current.pop_back();
            }
        }

        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> current;

        backtracking(nums,0,target,current,res,0);

        return res;
    }
};
