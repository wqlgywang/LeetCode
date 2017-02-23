/*Determine whether an integer is a palindrome. Do this without extra space
Some hints: 
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.*/

class Solution {
public:
    bool isPalindrome(int x) {
/*negative integer is not palindrome*/
        if(x < 0){                  
            return false;
        }
/*find the highest position,which is the number of bits*/
        int rec = 1;
        while(x / rec >= 10){
           rec = rec * 10; 
        }
/*define two variable,one represents the beginning,the other is the end*/
        while(x != 0){
            int i = x / rec;
            int j = x % 10;
            if (i != j)
                return false;
            else{
                x = (x % rec)/10;
                rec = rec /100;
            }
        }
        return true;
    }
};

/*some people's good idea*/
/*only reversing till half and then compare*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
