#include "generate_parentheses.h"
#include <iostream>


/*
1、一个「合法」括号组合的左括号数量一定等于右括号数量
2、对于一个「合法」的括号字符串组合 p，必然对于任何 0 <= i < len(p) 都有：子串 p[0..i] 中左括号的数量都大于或等于右括号的数量。
*/

vector<string> CGenerateParentheses::generateParenthesis(int n) {
	vector<string> res;
	string s = "";
	backTracking(res, s, n, n);
	return res;
}

void CGenerateParentheses::backTracking(vector<string> &v, string s, int left, int right) {
	//递归出口
	if (left == 0 && right == 0) {
		v.push_back(s);
		return;
	}
	if (left == 0) {
		backTracking(v, s + ")", left, right - 1);
	}
	else if (left == right) {
		backTracking(v, s + "(", left - 1, right);
	}
	else if (left < right) {
		backTracking(v, s + "(", left - 1, right);
		backTracking(v, s + ")", left, right - 1);
	}
}
int main() {
	CGenerateParentheses obj;
	vector<string> res = obj.generateParenthesis(2);
	int index = 0;
	while (index < res.size()) {
		cout << res[index++] << endl;
	}
	return 0;
}
