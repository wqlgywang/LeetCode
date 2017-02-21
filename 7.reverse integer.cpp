/*Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321 

Have you thought about this? 
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows. 
*/
/*runtime:19ms*/
class Solution {
public:
    int reverse(int x) {
        const int max = 0x7fffffff;
        const int min = 0x80000000;
   //can be set longlong,or unsigned,instead of int     
        long long sum = 0;      
        int temp =0;
        while(x != 0){
            temp = x % 10;
            sum = sum * 10 + temp;
            x = x / 10;
            if((sum > max) || (sum < min)){
                return 0;
            }
        }
        //if((sum > max) || (sum < min)){
        //    return 0;
        //}
        return sum;
        if(x =0) return 0;
    }
};

/*JAVA:some people's good idea1----15ms*/
public int reverse(int x)
{
    int result = 0;
    while (x != 0)
    {
        int tail = x % 10;
        int newResult = result * 10 + tail;
        if ((newResult - tail) / 10 != result)
        { return 0; }
        result = newResult;
        x = x / 10;
    }

    return result;
}
