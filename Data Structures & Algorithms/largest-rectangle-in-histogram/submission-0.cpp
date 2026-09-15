class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;  
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int curHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && curHeight < heights[st.top()]) {
                int tp = st.top();
                st.pop();

                int height = heights[tp];

                int width = st.empty() ? i : i - st.top() - 1;

                res = max(res, height * width);
            }

            st.push(i);
        }

        return res;
    }
};
