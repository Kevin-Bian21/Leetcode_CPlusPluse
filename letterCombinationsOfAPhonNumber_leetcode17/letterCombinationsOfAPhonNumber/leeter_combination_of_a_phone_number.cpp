#include "leeter_combination_of_a_phone_number.h"
#include <iostream>


string phoneStr[] = { "", "", "abc", "def" ,"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
string s = "";  //存放单次结果
vector<string> res;  //存放所有结果
vector<string> CLeeterCombinationOfAPhoneNumber::letterCombinations(string digits) {
	
	if (digits.size() <= 0)
		return res;

	int index = 0;  //digits的下标

	backtracking(digits, 0);

	return res;
	
}

void CLeeterCombinationOfAPhoneNumber::backtracking(const string& digits, int index) {
	if (index == digits.size()) {
		res.push_back(s);
		return;
	}

	int digit = digits[index] - '0'; //获取digits在index位置处的数字
	string leeter = phoneStr[digit];
	for (int i = 0; i < leeter.size(); i++) {
		s.push_back(leeter[i]);
		backtracking(digits, index + 1);
		s.pop_back();
	}
}


int main() {
	CLeeterCombinationOfAPhoneNumber obj;
	obj.letterCombinations("2345");
	vector<string>::iterator itor = res.begin();
	for (; itor != res.end(); itor++) {
		cout << *itor << "       ";
	}
	return 0;
}
