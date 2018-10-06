class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        string thisStr;
        for(int i = 0;i < s.length();i++){
            int pos = thisStr.find_first_of(s[i]);
            if(pos != string::npos){
                thisStr = thisStr.substr(pos+1,string::npos);
            }
            thisStr += s[i];
            if(thisStr.length() > maxLen)
                maxLen = thisStr.length();
        }
        return maxLen;
    }
};
