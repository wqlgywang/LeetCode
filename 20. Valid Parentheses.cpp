/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
*determine if the input string is valid.
*The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*note:([{}])also is valid
*/
//第一种方法：用迭代
//虽然方法看起来比较简单，但是运行时间较长:50ms，复杂度较高
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len==0) return true;
        if(len%2 != 0) return false;
        
        
        for(int i=1;i<len;i++){
            if(s[i-1]=='(' && s[i]==')'){
                string ss = s.substr(0,i-1)+s.substr(i+1);
                return isValid(ss);
            }
            else if(s[i-1]=='[' && s[i]==']'){
                string ss = s.substr(0,i-1)+s.substr(i+1);
                return isValid(ss);
            }
            else if(s[i-1]=='{' && s[i]=='}'){
                string ss = s.substr(0,i-1)+s.substr(i+1);
                return isValid(ss);
            }
            
        }
        return false;
    }
};

//压栈的方法：运行时间较快：3ms
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len==0) return true;
        if(len%2 != 0) return false;
        vector<char> stack;
        
        for(int i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stack.push_back(s[i]);
            }
            else {
                if(stack.empty()) return false;
                if(s[i]=='}' && stack[stack.size()-1]!='{')
                    return false;
                if(s[i]==']' && stack[stack.size()-1]!='[')
                    return false;
                if(s[i]==')' && stack[stack.size()-1]!='(')
                    return false;
                stack.pop_back();
            }
        }
        if(stack.empty()) return true;
        else return false;
    }
};
