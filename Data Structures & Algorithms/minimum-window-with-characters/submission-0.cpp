#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> targetMap;
        for (char c : t) {
            targetMap[c]++;
        }

        unordered_map<char, int> windowMap;

        int required = targetMap.size();
        int formed = 0;

        int minLen = INT_MAX;
        int startIdx = -1;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            windowMap[c]++;

            if (targetMap.count(c) && windowMap[c] == targetMap[c]) {
                formed++;
            }
            while (formed == required) {
                int currentLen = r - l + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    startIdx = l;
                }

                char charToRemove = s[l];
                if (targetMap.count(charToRemove) && windowMap[charToRemove] == targetMap[charToRemove]) {
                    formed--;
                }
                windowMap[charToRemove]--;
                l++;
            }
        }
 
        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
};