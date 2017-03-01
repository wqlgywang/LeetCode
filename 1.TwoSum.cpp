/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> numscopy;
        vector<int> result;
        int length = nums.size();
        for (int i = 0;i < length; i++){
            numscopy.push_back(nums[i]);
        }
        sort(numscopy.begin(), numscopy.end());
        vector<int> copyres = compare(numscopy, target);
        
        /*pay attention to the two for loops' order,which is fist and which is second*/
        for(int i = 0;i < length;i++){
            for(int j = 0;j < copyres.size();j++){
                if(copyres[j] == nums[i]){
                    result.push_back(i);
                    break;
                }
            }
        }
        //if (result[0]>result[1]){
        //    result[0] = result[0]^result[1];
        //    result[1] = result[0]^result[1];
        //    result[0] = result[0]^result[1];
        //}
        /*the last 4 lines is equal to the sort()function*/
        sort(result.begin(),result.end());
        return result;
    }
     vector<int> compare(vector<int> &numscp, int target){
         vector<int> rescp;
         int i = 0;
         int len = numscp.size();
         int j = len - 1;
         while (i < j){
             int x = numscp[i] + numscp[j];
             if (x == target){
                 //rescp.push_back(i + 1);
                 //rescp.push_back(j + 1);
                 rescp.push_back(numscp[i]);
                 rescp.push_back(numscp[j]);
                 i++;j--;
             }
             else if(x > target){
                 j--;
             }
             else i++;
         }
         return rescp;
    }
};
