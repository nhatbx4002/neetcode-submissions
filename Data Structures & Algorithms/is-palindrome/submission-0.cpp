class Solution {
public:

    vector<char> removeNonAlphanumerical(string s){
        int n = s.size();
        vector<char> res;
        for(int i = 0 ; i < n ; i++){
            s[i] = tolower(s[i]);
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'){
                res.push_back(s[i]);
            }
        }

        return res;
    }

    bool isPalindrome(string s) {
        vector<char> str = removeNonAlphanumerical(s);
        
        int i = 0 , j = str.size() - 1;

        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
