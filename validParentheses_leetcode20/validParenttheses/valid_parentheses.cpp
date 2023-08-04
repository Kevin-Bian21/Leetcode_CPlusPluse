#include "valid_parentheses.h"
#include <iostream>
#include <stack>

bool CValidParentheses::isValid(string s) {
	int index = 0;
    stack<char> *st = new stack<char>;
    while (index < s.length()) {
        if (!st->empty()) {
            if (s[index] == ')') {
                if (st->top() == '(') {
                    st->pop();
                    index++;
                    continue;
                }		
            }
            if (s[index] == ']') {
                if (st->top() == '[') {
                    st->pop();
                    index++;
                    continue;
                }
            }
            if (s[index] == '}') {
                if (st->top() == '{') {
                    st->pop();
                    index++;
                    continue;
                }
            }
        }
        st->push(s[index++]);
    }
    return st->empty();
}

int main() {
	string s = "[]";
	CValidParentheses obj;
	bool res = obj.isValid(s);
	cout << res;
	return 0;
}
