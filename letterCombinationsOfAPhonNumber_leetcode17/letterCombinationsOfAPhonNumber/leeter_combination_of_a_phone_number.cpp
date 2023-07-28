#include "leeter_combination_of_a_phone_number.h"
#include <iostream>


string phoneStr[] = { "", "", "abc", "def" ,"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
string s = "";  //��ŵ��ν��
vector<string> res;  //������н��
vector<string> CLeeterCombinationOfAPhoneNumber::letterCombinations(string digits) {
	
	if (digits.size() <= 0)
		return res;

	int index = 0;  //digits���±�

	backtracking(digits, 0);

	return res;
	
}

void CLeeterCombinationOfAPhoneNumber::backtracking(const string& digits, int index) {
	if (index == digits.size()) {
		res.push_back(s);
		return;
	}

	int digit = digits[index] - '0'; //��ȡdigits��indexλ�ô�������
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
