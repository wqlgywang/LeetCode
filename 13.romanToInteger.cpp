/*Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
runtime:62ms*/
class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
/*pay attention to this: int res; it will make mistake,for MCMXCVI the output is 2616 while the expected is 1996*/
        int res = 0;
        for(int i=0;i<len-1;i++){
            if(chg(s[i])>=chg(s[i+1])){
                res = res + chg(s[i]);
            }
            else{
                res = res - chg(s[i]);
            }
        }
        res = res + chg(s[len-1]);
        return res;
    }
    int chg(char c){
        switch(c){
            case 'M':return 1000;
            case 'D':return 500;
            case 'C':return 100;
            case 'L':return 50;
            case 'X':return 10;
            case 'V':return 5;
            case 'I':return 1;
        }
    }
};
