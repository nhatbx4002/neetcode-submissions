class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> occurance;
        int left = 0;
        int maxOccurance = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            occurance[s[right]]++;
            maxOccurance = max(maxOccurance, occurance[s[right]]);

            while (right - left + 1 - maxOccurance > k) {
                occurance[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
