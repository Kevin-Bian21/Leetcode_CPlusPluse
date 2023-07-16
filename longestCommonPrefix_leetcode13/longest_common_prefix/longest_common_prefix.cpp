#include "longest_common_prefix.h"
#include <iostream>

//���룺strs = ["flower", "flow", "flight"]
//�����"fl"

//1.���ҵ���̵�Ԫ��
//2.������̵�Ԫ��ȥ�ж�ƥ�����
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
