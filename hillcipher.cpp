//hill cipher
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, char> mappedAlphabet() {
    unordered_map<int, char> mp;
    for(int i = 0; i < 26; i++) {
        mp['a' + i] = i;
    }
    return mp;
}

vector<int> findingletternumber(string value, unordered_map<int, char> mp) {
    vector<int> v;
    for(int i = 0; i < value.size(); i++) {
        v.push_back(mp[value[i]]);
    }
    return v;
}

vector<vector<int>> fillmatrix(vector<int> question, int order) {
    vector<vector<int>> ans;
    int val = 0;
    for (int i = 0; i < question.size(); i += order) {
        vector<int> newbie;
        for (int j = 0; j < order; j++) {
            if (val < question.size()) {
                newbie.push_back(question[val]);
                val++;
            }
        }
        ans.push_back(newbie); 
    }
    return ans;
}

void checkingpairs(string &message, int order) {
    int n = message.size();
    if(n % order != 0) {
        int rem = n % order;
        for(int i = 0; i < rem; i++) {
            message += 'a' + i;
        }
    }
}

vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

vector<vector<int>>  multiplymatrix(vector<vector<int>>v2, vector<vector<int>>v1){
    int n=v1.size();
    int m=v1[0].size();
    int p=v2[0].size();
    
    
    vector<vector<int>>result(n,vector<int>(p,0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] = (result[i][j] + v1[i][k] * v2[k][j]) % 26;
            }
        }
    }
    
    return result;
    
}

string convertingvalue(vector<vector<int>>result){
    int col=result[0].size();
    int row=result.size();
    string str="";
    
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            str+='a'+result[j][i];
        }
    }
    
    
    return str;
}

int main() {
    string message;
    int order;
    string key;

    cout << "Enter the text to be encrypted: ";
    cin >> message;

    for(int i = 0; i < message.size(); i++) {
        message[i] = tolower(message[i]); // making the message in the same case
    }

    cout << "Enter order of key matrix: ";
    cin >> order;

    cout << "Enter the key: ";
    cin >> key;

    for(int i = 0; i < key.size(); i++) {
        key[i] = tolower(key[i]); // making the key in the same case
    }

    unordered_map<int, char> mp = mappedAlphabet(); // mapping of the Alphabets
    vector<int> keyvector = findingletternumber(key, mp);

    vector<vector<int>> keymatrixpair = fillmatrix(keyvector, order); // making the matrix using the key matrix
    cout<<"Below is the keymatrix"<<endl;
    for(int i = 0; i < keymatrixpair.size(); i++) {
        for(int j = 0; j < keymatrixpair[0].size(); j++) {
            cout << keymatrixpair[i][j] << " ";
        }
        cout << endl;
    }
    checkingpairs(message, order);

    vector<int> messagevector = findingletternumber(message, mp);

    vector<vector<int>> messagevectorpair = fillmatrix(messagevector, order);
    
    //taking the transpose of the matrix means convert the row into coloun and column into row
    vector<vector<int>> transposedMessagepair = transposeMatrix(messagevectorpair);
    
    //doing the matrix multiplication
    vector<vector<int>>result = multiplymatrix(transposedMessagepair,keymatrixpair);
    
    string ans=convertingvalue(result);
    cout<<"encrypted message is: "<<ans<<endl;
    cout<<"decrypted message is: "<<message<<endl;
}
