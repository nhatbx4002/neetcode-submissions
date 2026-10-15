class Solution {
private:
    bool check(const string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false; 
            left++;
            right--;
        }

        return true;
    }

    void backtracking(const string& s, int start, vector<string>& path, vector<vector<string>>& res){

       if(start == s.size()){
            res.push_back(path);
            return;
       } 

       for(int end = start; end < s.size(); end++){
            if(!check(s,start,end)) continue;

            path.push_back(s.substr(start,end-start+1));
            backtracking(s, end + 1, path, res); 
            path.pop_back(); 
       }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtracking(s, 0, path, res);
        return res;
    }
};
