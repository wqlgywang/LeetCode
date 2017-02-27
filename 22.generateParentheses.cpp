class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,n," ",res);
        return res;
    }
    vector<string> generate(int left,int right, string out,vector<string> &res){
        if(left ==0 && right == 0) res.push_back(out);
        else if(left > 0 && left <= right){
            generate(left-1,right,out+"(",res);
        }
        else if(right > 0 && left < right){
            generate(left,right-1,out+")",res);
        }
        return res;
    }
};
