/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 
For example, given n = 3, a solution set is: 
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/
/*wrong answer*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,n," ",res);
        return res;
    }
    void generate(int left,int right, string out,vector<string> &res){
        if(left ==0 && right == 0) res.push_back(out);
        else if(left > 0 && left <= right){
            generate(left-1,right,out+"(",res);
        }
        else if(right > 0 && left < right){
            generate(left,right-1,out+")",res);
        }
    }
};
/*a little change makes the right answer,pay attention to the difference between if...if and if..else if */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,n,"",res);
        return res;
    }
    /*left and right are the remaining number of "(" and ")"*/
    void generate(int left,int right, string out,vector<string> &res){
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generate(left - 1, right, out + '(', res);
            if (right > 0) generate(left, right - 1, out + ')', res);
        }
    }
};
