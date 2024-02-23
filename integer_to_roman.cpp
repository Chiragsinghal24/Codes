//leetcode 12

class Solution {
public:
    string intToRoman(int num) {

        vector<string>ones={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string>tens={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string>hundrends={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string>thousands={"","M","MM","MMM"};

        string ans="";
        ans+=thousands[num/1000];   //mmm
        num=num%1000;
        ans+=hundrends[num/100];    //mmmcm
        num=num%100;
        ans+=tens[num/10];        //xc
        num=num%10;
        ans+=ones[num];
        return ans;
    }
};