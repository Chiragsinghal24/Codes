//leetcode 

class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int leftsum=0;
        int rightsum=0;
        int n=arr.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            rightsum+=arr[i];
        }

        for(int i=0;i<n;i++){
            if(i!=0) leftsum=arr[i-1]+leftsum;
            rightsum=rightsum-arr[i];

            if(leftsum==rightsum){
                return i;
            }
            }
        }
        return -1;
    }
};