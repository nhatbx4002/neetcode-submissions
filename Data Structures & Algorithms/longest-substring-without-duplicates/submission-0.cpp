class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();

        if(s.length() == 0){
            return 0;
        }

        int l = 0 , r = 0;
        int ans = 0 ;
        unordered_set<char> se;

        while(r < len){

            while(se.contains(s[r])){
                se.erase(s[l]);
                l++;
            }
            se.insert(s[r]);
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};
