//weekly contest 382

#include <iostream>
#include <cmath> // Include cmath for abs function

using namespace std;

int mainfunction(string s){
    int i = 0;
    int l = s.length();
    int count = 0;
    while(i < l - 1){
        if(abs(s[i+1] - s[i]) != 32 && s[i] != s[i+1]){
            count++;
        }
        i++;
    }
    return count;
}

int main()
{
    string s;
    cin >> s;
    cout << mainfunction(s) << endl;
    return 0;
}
