/*Write a function to find the longest common prefix string amongst an array of strings. */
/*explain:It seems that it is not to check between pair of strings but on all the strings in the array.
For example:
{"a","a","b"} should give "" as there is nothing common in all the 3 strings.
{"a", "a"} should give "a" as a is longest common prefix in all the strings.
{"abca", "abc"} as abc
{"ac", "ac", "a", "a"} as a.*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.size() == 0) return res;
        for (int j = 0;j< strs[0].size();j++){
            for (int i=0;i<strs.size();i++){
                if(strs[i][j]!=strs[0][j]) return res;
            }
            res.push_back(strs[0][j]);
        }
        return res;
    }
};
