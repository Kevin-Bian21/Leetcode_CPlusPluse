#include "_3sum_closest.h"
#include <iostream>

int C3SumClosest::threeSumClosest(vector<int>& nums, int target) {
    vector<int> nums_sorted = sortArray(nums);
    int numClosest = INT_MAX;
    int res = 0;
    for (int i = 0; i < nums_sorted.size() - 2; i++)
    {
        if (i > 0 && nums_sorted[i] == nums_sorted[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums_sorted[i] + nums_sorted[left] + nums_sorted[right];
            if (abs(target - sum) < numClosest) {
                numClosest = abs(target - sum);
                res = sum;
            }
            if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
            else {
                while (left < right && nums_sorted[left] == nums_sorted[left + 1])
                    left++;
                while (left < right && nums_sorted[right] == nums_sorted[right - 1])
                    right--;
                left++;
                right--;
            }
        }
    }
    return res;
}
vector<int>& C3SumClosest::sortArray(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 1; j < nums.size() - i; j++) {
            if (nums[j - 1] > nums[j]) {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
    return nums;
}

int main() {
    vector<int> v = { 4,0,5,-5,3,3,0,-4,-5 };
    C3SumClosest obj;
    cout << obj.threeSumClosest(v, -2);
    return 0;
}
