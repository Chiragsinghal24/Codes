//leetcode 283

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //shifting all the zeros to the right side or shifting all the non zero to
        //the left side

        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[j],nums[i]);
                i++;
            }
        }
    }
};