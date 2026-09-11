class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        stack<int> st; 
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && temps[i] > temps[st.top()]){
                int prev_index = st.top();
                st.pop();
                ans[prev_index] = i - prev_index;
            }

            st.push(i);
        }

        return ans;
    }
};
