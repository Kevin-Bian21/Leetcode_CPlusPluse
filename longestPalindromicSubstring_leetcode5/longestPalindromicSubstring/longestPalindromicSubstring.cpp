#include "longestPalindromicSubstring.h"
#include <iostream>

string longestPalindromicSubstring::longestPalindrome(string s) {
	if (s.length() <= 1) {
		return s;
	}
	string str = s.substr(0, 1);
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i + 1; j < s.length(); j++)
		{
			string subStr = s.substr(i, j-i + 1);
			if (isPlalindrome(subStr)) {
				if (str.length() < subStr.length()) {
					str = subStr;
				}
			}
		}
	}
	return str;
}

bool longestPalindromicSubstring::isPlalindrome(string s) {
	int i = 0; 
	int j = s.length() - 1;
	while (i <= j) {
		if (s[i] != s[j]) {
			return false;
		}
		else {
			i++;
			j--;
		}
	}
	return true;
}

int main() {
	longestPalindromicSubstring obj;
	string s = "ac";
	cout << obj.longestPalindrome("mwwfjysbkebpdjyabcfkgprtxpwvhglddhmvaprcvrnuxifcrjpdgnktvmggmguiiquibmtviwjsqwtchkqgxqwljouunurcdtoeygdqmijdympcamawnlzsxucbpqtuwkjfqnzvvvigifyvymfhtppqamlgjozvebygkxawcbwtouaankxsjrteeijpuzbsfsjwxejtfrancoekxgfyangvzjkdskhssdjvkvdskjtiybqgsmpxmghvvicmjxqtxdowkjhmlnfcpbtwvtmjhnzntxyfxyinmqzivxkwigkondghzmbioelmepgfttczskvqfejfiibxjcuyevvpawybcvvxtxycrfbcnpvkzryrqujqaqhoagdmofgdcbhvlwgwmsmhomknbanvntspvvhvccedzzngdywuccxrnzbtchisdwsrfdqpcwknwqvalczznilujdrlevncdsyuhnpmheukottewtkuzhookcsvctsqwwdvfjxifpfsqxpmpwospndozcdbfhselfdltmpujlnhfzjcgnbgprvopxklmlgrlbldzpnkhvhkybpgtzipzotrgzkdrqntnuaqyaplcybqyvidwcfcuxinchretgvfaepmgilbrtxgqoddzyjmmupkjqcypdpfhpkhitfegickfszermqhkwmffdizeoprmnlzbjcwfnqyvmhtdekmfhqwaftlyydirjnojbrieutjhymfpflsfemkqsoewbojwluqdckmzixwxufrdpqnwvwpbavosnvjqxqbosctttxvsbmqpnolfmapywtpfaotzmyjwnd") << endl;
}