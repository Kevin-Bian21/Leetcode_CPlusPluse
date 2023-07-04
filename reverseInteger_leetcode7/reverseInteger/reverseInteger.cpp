#include "reverseInteger.h"
#include <iostream>
using namespace std;

int reverseInteger::reverse(int x) {
	int sum = 0;
	while (x) {
		int num = x % 10;
		if (sum > 214748364 || (sum == 214748364 && num > 7)) {
			return 0;
		}
		else if (sum < -214748364 || (sum == 214748364 && num < -8)) {
			return 0;
		}
		sum = sum * 10 + num;
		x = x / 10;
	}
	return sum;
}

int main() {
	reverseInteger obj;
	cout << obj.reverse(0);
	return 0;
}