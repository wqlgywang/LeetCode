/*Given a digit string, return all possible letter combinations that the number could represent. 
*A mapping of digit to letters (just like on the telephone buttons) is given below.

*Input:Digit string "23"
*Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*Note:
*Although the above answer is in lexicographical order, your answer could be in any order you want. 
*/
//正确答案：
class Solution{ 
public: 
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string comb[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size()==0)return res;
        res.push_back("");//pay attention
       
        for(int i=0;i<digits.size();i++){
            vector<string> temp;
            string let = comb[digits[i] - '0'];
            for(int m=0;m<let.size();m++){
                for(int n=0;n<res.size();n++){
                    temp.push_back(res[n]+let[m]);
                }
            }
            res = temp;
        }
        return res;
    }
};

//针对vector<string>初始化问题：
//1:
vector<string> letterCombinations(string digits) {
        vector<string> res;
        //这边有问题：
        res.push_back("");
        string comb[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i=0;i<digits.size();i++){
            vector<string> temp;
            string let = comb[digits[i] - '0'];
            for(int m=0;m<let.size();m++){
                for(int n=0;n<res.size();n++){
                    temp.push_back(res[n]+let[m]);
                }
            }
            res = temp;
        }
        return res;
    }

//2:
class Solution{ 
public: 
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        string comb[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size()==0)return res;
        res.push_back("");
        //string let1 = comb[digits[0] - '0'];
        //for(int i=0;i<let1.size();i++){
         //这边是错误的，这相当于将char型赋值给string型。   
        //       res.push_back(let1[i]);
       // }
        
        for(int i=1;i<digits.size();i++){
            vector<string> temp;
            string let = comb[digits[i] - '0'];
            for(int m=0;m<let.size();m++){
                for(int n=0;n<res.size();n++){
                    temp.push_back(res[n]+let[m]);
                }
            }
            res = temp;
        }
        return res;
    }
};
