class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(nums.size() == 0){
            return 0;
        }

        unordered_set<int> se; 
        for(int i = 0 ; i < n ; i++){
            se.insert(nums[i]);
        }

        int lcs_len = 1;

        for(const auto& num : nums){
            
            if(!se.contains(num-1)){
                int cur = num; 
                int cs_len = 1 ; 

                while(se.contains(cur+1)){
                    cur++;
                    cs_len++;
                }

                lcs_len = max(cs_len,lcs_len);
            }
        }

        return lcs_len;
    }
};
