#include "longestSubstringWithoutRepeatingCharacters.h"

using namespace std;
#include <iostream>

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
				temp ++;
				j--;
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
	string s = "dvdf";
	int len = obj.lengthOfLongestSubstring(s);
	cout << len;
	return 0;
}

