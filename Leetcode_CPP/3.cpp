class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0,headPos = -1;
        map<char,int> dict;
        for(int i = 0;i < s.length();i++){
            if(dict.find(s[i]) != dict.end() && dict[s[i]] > headPos){
                headPos = dict[s[i]];
            }
            dict[s[i]] = i;
            maxLen = max(maxLen,i - headPos);
        }
        return maxLen;
    }
};
