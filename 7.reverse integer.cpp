class Solution {
public:
    int reverse(int x) {
        const int max = 0x7fffffff;
        const int min = 0x80000000;
   //must long long,instead of int     
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
