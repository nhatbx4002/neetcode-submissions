class Solution {
public:
    int m,n;

    bool dfs(vector<vector<char>> b, const string& w, int r,int c,int k){
        if(k == (int)w.size()) return true;

        if(r < 0 || c < 0 || r >= m || c >= n || b[r][c] != w[k]) return false;

        char tmp = b[r][c];
        b[r][c] = '#';

        bool ok = dfs(b,w,r+1,c,k+1) ||
                    dfs(b,w,r-1,c,k+1) ||
                    dfs(b,w,r,c+1,k+1) ||
                    dfs(b,w,r,c-1,k+1);

        b[r][c] = tmp;

        return ok;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }

        return false;

    }
};
