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
        int n = chgs.size();        int *a = new int[n];
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

/*the second solution:为每个元素都进行两次比较*/
class Solution {
public:
void getPalindrome(string& s, int left, int right, int &out1,int &out2)
{
	if (left < right && s[left] != s[right]) {
		out1 = out2 = left;
		return;
	}
	int size = s.size();
	while (left > 0 && (right + 1 < size) && s[left-1] == s[right+1]) {
		left--;
		right++;
	}
	out1 = left;
	out2 = right;
}
string longestPalindrome(string s) {
	int size = s.size();
	int left = 0;
	int len = 1;
	for (int i = 0; i < size; i++) {
		int l, r;
		getPalindrome(s, i, i, l, r);
		if (r - l+1 > len) {
			len = r - l + 1;
			left = l;
		}
		getPalindrome(s, i, i+1, l, r);
		if (r > l && r - l + 1 > len) {
			len = r - l + 1;
			left = l;
		}
	}
	return s.substr(left, len);
}
};
