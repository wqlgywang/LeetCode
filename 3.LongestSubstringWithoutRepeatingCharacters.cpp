class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int search[256]={0};
        //must Initialize the variable
        int i=0,j=0;
        int mlengh = 0;
        int n = s.length();
        while(j<n){
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
