#include "generate_parentheses.h"
#include <iostream>


/*
1��һ�����Ϸ���������ϵ�����������һ����������������
2������һ�����Ϸ����������ַ������ p����Ȼ�����κ� 0 <= i < len(p) ���У��Ӵ� p[0..i] �������ŵ����������ڻ���������ŵ�������
*/

vector<string> CGenerateParentheses::generateParenthesis(int n) {
	vector<string> res;
	string s = "";
	backTracking(res, s, n, n);
	return res;
}

void CGenerateParentheses::backTracking(vector<string> &v, string s, int left, int right) {
	//�ݹ����
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
