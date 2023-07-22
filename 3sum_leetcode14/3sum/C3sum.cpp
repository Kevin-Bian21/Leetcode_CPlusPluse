#include "C3sum.h"
#include <iostream>
vector<vector<int>> C3sum::threeSum(vector<int>& nums) {
	vector <vector<int>> vec;
	vector<int> nums_sorted = sortArray(nums);
	for (int i = 0; i < nums_sorted.size() - 2; i ++)
	{
		if (nums_sorted[i] > 0)
			return vec;
		if (i > 0 && nums_sorted[i] == nums_sorted[i - 1]) {
			continue;
		}
		int left = i + 1;
		int right = nums.size() - 1;
		while (left < right) {
			if (nums_sorted[i] + nums_sorted[left] + nums_sorted[right] < 0) {
				left++;
			}else if (nums_sorted[i] + nums_sorted[left] + nums_sorted[right] > 0) {
				right--;
			}else {
				vec.push_back({ nums_sorted[i] , nums_sorted[left], nums_sorted[right] });
				while (left < right && nums_sorted[left] == nums_sorted[left + 1])
					left++;
				while (left < right && nums_sorted[right] == nums_sorted[right - 1])
					right--;
				left++;
				right--;
			}
		}
	}
	return vec;
}

vector<int>& C3sum::sortArray(vector<int>& nums) {
	for (int i = 0; i < nums.size() ; i++)
	{
		for (int j = 1; j < nums.size() - i; j++) {
			if (nums[j - 1] > nums[j]) {
				int temp = nums[j];
				nums[j] = nums[j-1];
				nums[j-1] = temp;
			}
		}
	}
	return nums;
}
int main() {
	C3sum obj;
	vector <int> v = { 0,0,0 };
	vector<vector<int>> vec1 = obj.threeSum(v);
	vector<int> vec2;
	vector<vector<int>>::iterator iter = vec1.begin();
	vector<int>::iterator it;
	for (; iter != vec1.end(); iter++) {
		vec2 = *iter;
		for (it = vec2.begin(); it != vec2.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}
