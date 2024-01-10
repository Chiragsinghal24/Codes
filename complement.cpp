//leetcode 1009

//main function


class Solution {
public:
    int bitwiseComplement(int n) {
        int ans=0;
        int i=0;

        if(n==0){
            return 1;
        }
        while(n!=0){
            int bit=n&1;
            if(bit==1){
                ans=(bit-1)*pow(2,i)+ ans;
            }
            else{
                ans=(bit+1)*pow(2,i)+ ans;
            }
            n=n>>1;
            i++;
        }

        cout<<ans<<endl;
        return ans;
        
    }
};