#include "PalindromeNumber.h"
#include <iostream>
using std::cout;
bool CPalindromeNumber::isPalindrome(int x) {
	if (x < 0)
		return false;
	int sum = 0;
	int temp = 0;
	int p = x;
	while (x) {
		temp = x % 10;
		if (sum > 214748364 || sum == 214748364 && temp > 7)
			break;
		sum = sum * 10 + temp;
		x = x / 10;
	}
	return sum == p;
}

int main() {
	CPalindromeNumber palinedrome;
	cout << palinedrome.isPalindrome(INT_MAX);
	return 0;
}