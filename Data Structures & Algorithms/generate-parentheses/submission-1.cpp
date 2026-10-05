class Solution {
public:
    void backtracking(int n, vector<string>& ans, string& currentRes,int open, int close){
        if(currentRes.size() == 2*n){
            ans.push_back(currentRes);
            return;
        }

        if(open < n){
            currentRes.push_back('(');
            backtracking(n,ans,currentRes,open+1,close);
            currentRes.pop_back();
        }

        if(close < open){
            currentRes.push_back(')');
            backtracking(n,ans,currentRes,open,close+1);
            currentRes.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans; 
        string currentRes;
        backtracking(n,ans,currentRes,0,0);
        return ans;
    }
};
