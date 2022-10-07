class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int longest = 0;
        unordered_set<char> hashset;
        
        while (right < s.size()) {
            if (hashset.count(s[right]) == 0) {
                hashset.insert(s[right]);
                right++;
                longest = max(longest, int(hashset.size()));
            }
            else {
                hashset.erase(s[left]);
                left++;
            }
        }
        
        return longest;
    }
};
