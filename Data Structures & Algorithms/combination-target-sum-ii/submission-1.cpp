class Solution {
public:
    void backtracking(vector<int>& candidates, int sum,int st,vector<int>& currPath,int target, vector<vector<int>>& res){   
        for(int i = st; i < candidates.size(); i++){            
            if(i > st && candidates[i] == candidates[i-1]) continue;               
            currPath.push_back(candidates[i]);
            if(sum + candidates[i] == target){
                res.push_back(currPath);
            }else if(sum + candidates[i] < target){
                backtracking(candidates,sum+candidates[i],i+1,currPath,target,res);
            }
            currPath.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currPath;
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,0,0,currPath,target,res);

        return res;      
    }
};
