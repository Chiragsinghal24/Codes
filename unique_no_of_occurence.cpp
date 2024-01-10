//leetcode 1207

//finding the unique number of occurence


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        unordered_map<int,int>mp1;
        for(auto x:mp){
            if(mp1.find(x.second)!=mp1.end()){
                return false;
            }
            mp1[x.second]=0;
        }
        return true;
    }
};



