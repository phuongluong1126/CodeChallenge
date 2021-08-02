/*#include <iostream>
#include <vector>
using namespace std;*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int max = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        //find the same subArrays in 2 nums
        //result is the max
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (nums1[i] == nums2[j]) {
                    int k = 1;
                    while (i + k < size1 && j + k < size2 && nums1[i + k] == nums2[j + k]) k++;
                    if (max < k) {
                        max = k;
                    };
                }
            }
        }
        return max;
    }
};


/*int main() {
    Solution slt;
    vector<int> nums1 = { 0,1,3,4,5,3,9,0,0,0 };
    vector<int> nums2 = { 0,3,3,4,4,2,0,1,1 };
    cout << slt.findLength(nums1, nums2);
    return 0;
}*/