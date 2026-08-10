class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(const auto& s : strs){
            res += to_string(s.length()) + "#" + s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0 ; 
        int n = s.length();

        while(i < n) {
            int j = i ; 

            while(j < n && s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i,j-i));

            res.push_back(s.substr(j+1,length));

            i = j + 1 + length;
        }

        return res;
    }
};
