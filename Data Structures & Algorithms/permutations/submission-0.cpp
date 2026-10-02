class Solution {
public:
    void backtracking(vector<int>& nums, map<int,int>& visited, vector<int>& currPath, vector<vector<int>>& res, int currNums){
        if(currNums == nums.size()){
            res.push_back(currPath);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[nums[i]]){
                visited[nums[i]]++;
                currPath.push_back(nums[i]);
                backtracking(nums, visited, currPath, res, currNums + 1);
                visited[nums[i]]--; 
                currPath.pop_back();
            }
        }

        return ;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currPath;
        vector<vector<int>> res;
        map<int,int> visited;

        backtracking(nums,visited,currPath,res,0);

        return res;
    }
};
