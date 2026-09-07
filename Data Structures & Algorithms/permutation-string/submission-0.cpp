class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        int n = s2.size();
        int m = s1.size();

        int s1_count[26] = {0};
        int s2_count[26] = {0};
        int matches = 0;

        for(int i = 0; i < m; i++){
            s1_count[s1[i]-'a']++;
            s2_count[s2[i]-'a']++;
        }

        for(int i = 0 ; i < 26; i++){
            if(s1_count[i] == s2_count[i]){
                matches++;
            }
        }

        if(matches == 26) return true;

        int l = 0;
        for (int r = m; r < n; r++) {
            int r_idx = s2[r] - 'a';
            s2_count[r_idx]++;
            if (s2_count[r_idx] == s1_count[r_idx]) {
                matches++;
            } else if (s2_count[r_idx] == s1_count[r_idx] + 1) {
                matches--; 
            }


            int l_idx = s2[l] - 'a';
            s2_count[l_idx]--;
            if (s2_count[l_idx] == s1_count[l_idx]) {
                matches++;
            } else if (s2_count[l_idx] == s1_count[l_idx] - 1) {
                matches--;
            }

            if (matches == 26) return true;

            l++;
        }
        return false;
    }
};
