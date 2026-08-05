class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> se;

        se.reserve(nums.size());

        for(int num : nums){

            if(se.count(num)){
                return true;
            }

            se.insert(num);
        }

        return false;
    }
};