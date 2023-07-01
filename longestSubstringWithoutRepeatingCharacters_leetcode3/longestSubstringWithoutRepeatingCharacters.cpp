#include "longestSubstringWithoutRepeatingCharacters.h"

using namespace std;
#include <iostream>
/*
* 滑动窗口，j在i之前，j每移动一次，就更新maxLen
* 可以将滑动窗口想象成一个队列,队列的初始元素为i处的元素,判断j所处的元素在队列中有没有,没有则将j处的元素加入队列
* 软后更新maxLen的长度就为队列的最大长度.否则当j处的元素在队列中有相同的时,则将队列中与j相同的元素及其之前的元素全部出队.然后将j元素入队.直至j<s.length();
*/
//执行用时：4 ms, 在所有 C++ 提交中击败了97.19 %的用户
//内存消耗：6.7 MB, 在所有 C++ 提交中击败了93.64 %的用户
int longestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(string s) {
	if (s.size() <= 0) {
		return 0;
	}
	int i = 0; 
	int j = 1;
	int maxLen = 0;
	while (j < s.size()) {
		int temp = i;
		while (i < j) {
			if (s.at(i) == s.at(j)) {
				temp = i + 1;
				break;
			}
			i++;
		}
		maxLen = maxLen > (i - temp) ? maxLen : (i - temp);
		i = temp;
		j++;	
	}
	return maxLen +1;
}

int main() {
	longestSubstringWithoutRepeatingCharacters obj;
	string s = "pwwwwcc";
	int len = obj.lengthOfLongestSubstring(s);
	cout << len;
	return 0;
}

