class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> cnt;

        for(const auto& num : nums){
            cnt[num]++;
        }

        vector<vector<int>> buckets(n+1);
        for(const auto& [num,freq] : cnt){
            buckets[freq].push_back(num);
        }

        vector<int> result;
        result.reserve(k);

        for(int i = n; i >= 1; i--){
            for(int num : buckets[i]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }
        
        return result;
    }
};
