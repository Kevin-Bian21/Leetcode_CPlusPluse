#include "medianOfTwoSortedArrays.h"
#include <iostream>
using namespace std;

double medianOfTwoSortedArrays::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	vector<int> num;
	int i = 0;
	int j = 0;
	int mid = 0;
	while (i < nums1.size() && j < nums2.size()) {
		if (nums1[i] <= nums2[j]) {
			num.push_back(nums1[i++]);
		}
		else {
			num.push_back(nums2[j++]);
		}
	}
	while (i < nums1.size()) {
		num.push_back(nums1[i++]);
	}
	while (j < nums2.size()) {
		num.push_back(nums2[j++]);
	}
	if (num.size() == 0) {
		return 0;
	}
	mid = num.size() / 2;
	if (num.size() % 2 == 0) {	
		double sum = num[mid] + num[mid - 1];
		return sum / 2;
	}
	else {
		return (double)num[mid];
	}
}
int main() {
	medianOfTwoSortedArrays s;
	vector<int> v1 = {  };
	vector<int> v2 = {  };
	cout << s.findMedianSortedArrays(v1, v2) << endl;
}