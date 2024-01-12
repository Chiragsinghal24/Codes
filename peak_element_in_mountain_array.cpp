//leetcode 852

//linear search

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        linear search
        int ans=arr[0];
        int value=0;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(ans!=max(ans,arr[i])){
                value=i;
                ans=max(ans,arr[i]);
            }
        }
        return value;
    }
};
//binary search

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(arr[mid]<arr[mid+1]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};