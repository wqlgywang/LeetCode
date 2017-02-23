/*Given an integer, convert it to a roman numeral. 
Input is guaranteed to be within the range from 1 to 3999.
runtime:56ms*/
class Solution {
public:
    string intToRoman(int num) {
        string str[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int number[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string res;
        int i=0;
        while(i < 13)
        {
            if(num >= number[i])
            {
                num = num - number[i];
                res = res + str[i];
            }
            else{
                i += 1;
            }
            if(num == 0)
            {
                break;
            }
        }
        return res;
    }
};

/*a little change makes the program different*/
class Solution {
public:
    string intToRoman(int num) {
        string str[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int number[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string res;
        /*pay attention to the terms in the for loop*/
        for(int i = 0;num != 0;i++)
        {
            while(num >= number[i])
            {
                num = num - number[i];
                res = res + str[i];
            }
        }
        return res;
    }
};

/*anther solution:maybe make the problem easy*/
class Solution {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];

    }
};
