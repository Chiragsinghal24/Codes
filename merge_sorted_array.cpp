//leetcode 88

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n-1; //index of last zero
        int i=m-1;   //index of last nums1
        int j=n-1;  //index of last nums2

        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k]=nums2[j];
                k--;j--;
            }
        }
    }
};