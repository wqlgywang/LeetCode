/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example: 
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.

Example: 
Input: "cbbd"

Output: "bb"*/

class Solution {
public:
    string changestring(string s){
        string change = "^";
        int n = s.size();
        for(int i=0;i<n;i++){
            change = change + "#" + s[i];
        }
        change = change + "#$";
        return change;
    }
    string longestPalindrome(string s) {
        string chgs = changestring(s);
        string res;
        int n = chgs.size();
        int *a = new int[n];
        a[0]=0;
        int mid = 1;int R = 1;
        for(int i= 1;i<n;i++){
            int j = 2*mid -i;
            a[i] = (R>i)?min(R-i,a[j]):0;
            //please pay attention to the diference between if and while
            while(chgs[i+1+a[i]]==chgs[i-1-a[i]]){
                a[i]++;
            }
            if (R<i+a[i]){
                mid = i;
                R = i + a[i];
            }
        }
        int maxlen = 0;
        int maxi = 0;
        for(int i = 0;i<n;i++){
            if(maxlen<a[i]){
                maxlen = a[i];
                maxi = i;
            }
        }
        res = s.substr((maxi - maxlen - 1)/2,maxlen);
        delete[] a;
        return res;
    }
};
