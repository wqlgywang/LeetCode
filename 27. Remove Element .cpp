/*Given an array and a value, remove all instances of that value in place and return the new length. 
Do not allocate extra space for another array, you must do this in place with constant memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example:
Given input array nums = [3,2,2,3], val = 3 
Your function should return length = 2, with the first two elements of nums being 2.
Show Hint */
//solution1:
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int n = nums.size();
       if(n==0) return 0;
       
       sort(nums.begin(),nums.end());
       vector<int>::iterator it;
       vector<int>::iterator p;
       int i=0;
       for(it=nums.begin();it!=nums.end();it++){
           if(*it == val){
               p=it;
               i++;
           }
       }
       nums.erase(p-i+1,p+1);
       int m = nums.size();
       return m;
    }
};

//solution2:
