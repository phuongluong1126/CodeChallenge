/*#include <iostream>
#include <vector>
using namespace std;*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        //find any element bigger than left-neighbor and right-neighbor
        int i = 1;
        while (i <= (nums.size() - 2)) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
            else i = i + 1;
        }
        return i;
    }
};

/*int main() {
    solution slt;
    vector<int> nums = {0,1};
    cout << slt.findpeakelement(nums);
    return 0;
}*/