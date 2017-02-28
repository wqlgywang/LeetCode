/*Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int search[256]={0};
        //must Initialize the variable
        int i=0,j=0;
        int mlengh = 0;
        //max subscript of string s is n-1 
        int n = s.length();
        while(j<n){
            //search['a']==saerch[97];
            if(search[s[j]]){
                mlengh = max(mlengh,j-i);
                while(s[i]!=s[j]){
                    search[s[i]]=0;
                    i++;
                }
                i++;
                j++;
            }
            else{
                search[s[j]] = 1;
                j++;
            }
        }
        mlengh = max(mlengh,n-i);
        return mlengh;
    }
};
