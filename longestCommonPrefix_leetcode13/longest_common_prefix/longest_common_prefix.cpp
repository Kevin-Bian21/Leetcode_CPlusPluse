#include "longest_common_prefix.h"
#include <iostream>

//输入：strs = ["flower", "flow", "flight"]
//输出："fl"

//1.先找到最短的元素
//2.根据最短的元素去判断匹配与否
string CLongestCommonPrefix::longestCommonPrefix(vector<string>& strs) {
	int minLenElementIndex = 0;
	for (int i = 1; i < strs.size(); i++) {
		if (strs[i-1].length() < strs[i].length()) {
			minLenElementIndex = i-1;
		}
	}
	int index = 0;
	while (index < strs[minLenElementIndex].length()) {
		for (int i = 1; i < strs.size(); i++) {
			if (strs[i - 1][index] != strs[i][index]) {
				return strs[minLenElementIndex].substr(0, index);
			}
		}
		index++;
	}
	return strs[minLenElementIndex].substr(0, index);

}
int main() {
	vector<string> strs = { "c","c","c" };
	CLongestCommonPrefix obj;
	cout << obj.longestCommonPrefix(strs) << endl;
	return 0;
}
