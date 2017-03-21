/*
*Implement strStr(). 
*Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 
*/
//own solution:
class Solution {
public:
    int strStr(string haystack, string needle){
        string str1;
        int n = haystack.size();
        int m = needle.size();
        int a=0;
        if(m>n) return -1;
        if(m==0) return 0;
        for(int i=0;i<n;i++){
            if(needle[0]==haystack[i]){
                if(n-i < m) return -1;
                else{
                    str1.assign(haystack,i,m);
                    //int a = strmatch(str1,needle);
                    a = str1.compare(needle);
                }
                if(a==0) {
                    return i;
                    break; 
                }
            }
        }
        return -1;
    }
};

//solution2:java
//比自己的方法好
public String strStr(String haystack, String needle) {
    if(haystack==null || needle == null || needle.length()==0)
        return haystack;
    if(needle.length()>haystack.length())
        return null;
    for(int i=0;i<=haystack.length()-needle.length();i++)
    {
        boolean successFlag = true;
        for(int j=0;j<needle.length();j++)
        {
            if(haystack.charAt(i+j)!=needle.charAt(j))
            {
                successFlag = false;
                break;
            }
        }
        if(successFlag)
            return haystack.substring(i);
    }
    return null;
}
