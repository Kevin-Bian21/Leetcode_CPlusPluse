#include "_4sum.h"
#include <iostream>
#include <algorithm>

vector<vector<int>> C4Sum::fourSum(vector<int>& nums, int target) {
	std::sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	int lenght = nums.size();
	for (int i = 0; i < lenght - 3; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		for (int j = i + 1; j < lenght - 2; j++) {
			if (j > i+1 && nums[j] == nums[j - 1]) {  //j > i+1 ¹Ø¼üµã
				continue;
			}
			int left = j + 1;
			int right = nums.size() - 1;
			while (left < right) {
				long sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum < target) {
					left++;
				}
				else if (sum > target) {
					right--;
				}
				else {
					res.push_back({ nums[i], nums[j], nums[left], nums[right] });
					left++;
					right--;
					while (left < right && nums[left] == nums[left - 1]) {
						left++;
					}
					while (left < right && nums[right] == nums[right + 1]) {
						right--;
					}
				}
			}
		}
	}
	return res;
}
int main() {
	C4Sum obj;
	vector<int> vec = { 1000000000,1000000000,1000000000,1000000000 };
	vector<vector<int>> res;
	res = obj.fourSum(vec, 0);
	vector<vector<int>>::iterator iter = res.begin();
	for (; iter != res.end(); iter++) {
		vector<int> temp = *iter;
		for (int i = 0; i < temp.size(); i++) {
			cout << temp[i] << "\t";
		}
		cout << endl;
	}
	return 0;
}
