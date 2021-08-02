/*#include <iostream>
#include <vector>
using namespace std;
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) return {0,1};
        vector<string> biArr = { "0", "1" };

        //From 2 bit
        //step 1: find (n-1)bit grayCode
        //step 2: make new arr1 by adding "0" to all element (n-1)bit grayCode
        //step 3: make new arr2 by adding "1" to all element (n-1)bit grayCode
        //step 4: (n)bit grayCode = join arr1 with reversion of arr2

        int count = 2;
        while (count <= n) {
            int len = biArr.size();
            vector<string> tempArr = {};
            for (int i = 0; i < len; i++) {
                string str = "0" + biArr[i];
                tempArr.push_back(str);
            }

            for (int i = len-1; i >= 0; i--) {
                string str = "1" + biArr[i];
                tempArr.push_back(str);
            }

            biArr = tempArr;
            count++;
        }

        vector<int> decArr = {};
        for (int i = 0; i < biArr.size(); i++) {
            int dec = binaryToDecimal(biArr[i]);
            decArr.push_back(dec);
        }

        return decArr;
    }

    int binaryToDecimal(string n)
    {
        int dec = 0;
        int len = n.length();
        for (int i = 0; i <= len - 1; i++) {
            if (n[i] != '0') {
                dec = dec + pow(2, i);
            }
        }

        return dec;
    }
};



/*int main() {
    Solution slt;
    vector<int> vec = slt.grayCode(2);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    return 0;
}*/