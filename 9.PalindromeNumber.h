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
