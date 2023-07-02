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


//中心扩散法
string longestPalindromicSubstring::longestPalindromeDiffuseCenter(string s) {
	if (s.length() <= 1) {
		return s;
	}
	int l = 0;
	int r = 0;
	int maxLen = 1;
	for (int i = 0; i < s.length(); i++)
	{
		//如果回文字串长度为奇数
		int left = i-1; 
		int right = i+1;
		while (left >= 0 && right <= s.length() && s[left] == s[right]) {
			int len = right - left + 1;
			if (maxLen < len) {
				maxLen = len;
				l = left;
				r = right;
			}
			left--;
			right++;
		}
		//如果回文字串长度为偶数
		left = i;
		right = i + 1;
		while (left >= 0 && right <= s.length() && s[left] == s[right]) {
			int len = right - left + 1;
			if (maxLen < len) {
				maxLen = len;
				l = left;
				r = right;
			}
			left--;
			right++;
		}
	}
	return s.substr(l, (r - l + 1));
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
	//cout << obj.longestPalindrome("mwwfjysbkebpdjyabcfkgprtxpwvhglddhmvaprcvrnuxifcrjpdgnktvmggmguiiquibmtviwjsqwtchkqgxqwljouunurcdtoeygdqmijdympcamawnlzsxucbpqtuwkjfqnzvvvigifyvymfhtppqamlgjozvebygkxawcbwtouaankxsjrteeijpuzbsfsjwxejtfrancoekxgfyangvzjkdskhssdjvkvdskjtiybqgsmpxmghvvicmjxqtxdowkjhmlnfcpbtwvtmjhnzntxyfxyinmqzivxkwigkondghzmbioelmepgfttczskvqfejfiibxjcuyevvpawybcvvxtxycrfbcnpvkzryrqujqaqhoagdmofgdcbhvlwgwmsmhomknbanvntspvvhvccedzzngdywuccxrnzbtchisdwsrfdqpcwknwqvalczznilujdrlevncdsyuhnpmheukottewtkuzhookcsvctsqwwdvfjxifpfsqxpmpwospndozcdbfhselfdltmpujlnhfzjcgnbgprvopxklmlgrlbldzpnkhvhkybpgtzipzotrgzkdrqntnuaqyaplcybqyvidwcfcuxinchretgvfaepmgilbrtxgqoddzyjmmupkjqcypdpfhpkhitfegickfszermqhkwmffdizeoprmnlzbjcwfnqyvmhtdekmfhqwaftlyydirjnojbrieutjhymfpflsfemkqsoewbojwluqdckmzixwxufrdpqnwvwpbavosnvjqxqbosctttxvsbmqpnolfmapywtpfaotzmyjwnd") << endl;
	cout << obj.longestPalindromeDiffuseCenter("bca");
}