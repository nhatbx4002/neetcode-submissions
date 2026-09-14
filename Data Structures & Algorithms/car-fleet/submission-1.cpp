class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int, int>> ve;
        for (int i = 0; i < position.size(); i++) {
            ve.push_back({position[i], speed[i]});
        }

        sort(ve.begin(), ve.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; });

        for (int i = 0; i < ve.size(); i++) {
            double time = (double)(target - ve[i].first) / ve[i].second;

            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};
