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
        
        for(int i = 0;i < length;i++){
            for(int j = 0;j < copyres.size();j++){
                if(copyres[j] == nums[i]){
                    result.push_back(i);
                    break;
                }
            }
        }
        if (result[0]>result[1]){
            //reverse(result.begin(),result.end());
            result[0] = result[0]^result[1];
            result[1] = result[0]^result[1];
            result[0] = result[0]^result[1];
        }
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
