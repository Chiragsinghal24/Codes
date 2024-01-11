//leetcode 349

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }

        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            int value=nums2[i];
            if(mp.find(value)!=mp.end() && mp[value]!=0){
                ans.push_back(value);
                mp[value]=0;
            }
        }
        return ans;
    }
};