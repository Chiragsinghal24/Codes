//leetcode 13

class Solution {
public:
    //converting the roman number to the integer
    //approach moving from back1

    unordered_map<char, int> mapnumbers() {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        return mp;
    }

    int romanToInt(string s) {
        //map the numbers
        //traversing the string from the last
        unordered_map<char,int>mp=mapnumbers();  //mapping the numbers of the list
        int n=s.length()-1; //traversing the list from the end 2
        int ans=0;
        for(int i=n;i>=0;i--){
            if(i>0 && mp[s[i-1]]<mp[s[i]]){
                ans+=mp[s[i]];
                ans-=mp[s[i-1]];
                i--;
            }
            else{
                ans+=mp[s[i]];
            }
        }   
        return ans;     
    }
};