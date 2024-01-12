//leetcode 34

class Solution {
public:

    //find leeft most and right most position
    int firstbinarySearch(int low, int high, int target,vector<int>&arr){
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if (arr[mid] == target) {
                ans=mid;
                high = mid - 1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }

    int lastbinarySearch(int low, int high, int target,vector<int>&arr){
        int i=0;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if (arr[mid] == target) {
                ans=mid;
                low = mid + 1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        vector<int>v(2,-1);
        v[0]=firstbinarySearch(low,high,target,nums);
        v[1]=lastbinarySearch(low,high,target,nums);
        return v;
    }
};