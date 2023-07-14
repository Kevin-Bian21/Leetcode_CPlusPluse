#include "regular_expression_matching.h"
#include <iostream> 
#include <vector>

/*
��� p[j] == s[i] : dp[i][j] = dp[i-1][j-1]��
��� p[j] == '.' : dp[i][j] = dp[i-1][j-1]��
��� p[j] == '*'��  //����*�÷����
    ��� p[j-1] != s[i] : dp[i][j] = dp[i][j-2] //in this case, a* only counts as empty
    ��� p[i-1] == s[i] or p[i-1] == '.'��
        dp[i][j] = dp[i-1][j] //in this case, a* counts as multiple a
        or dp[i][j] = dp[i][j-1] // in this case, a* counts as single a
        or dp[i][j] = dp[i][j-2] // in this case, a* counts as empty
*/

bool CRegularExpressionMatching::isMatch(string s, string p) {
    s = " " + s;  //����ڱ�
    p = " " + p;
    int m = s.length();
    int n = p.length();
    vector <vector<bool>> dp(m+1, vector<bool>(n+1, false));  // m+1 * n+1 �Ķ�ά���飬��ʼ������Ԫ��Ϊfalse
    //memset(&dp, false, (m + 1) * (n + 1));
    dp[0][0] = true;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {  
                if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
                    dp[i][j] = dp[i][j - 2];
                else {
                    dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                }
            }
        }
    }
    return dp[m][n];
}
int main() {
    CRegularExpressionMatching regular;
    cout << regular.isMatch("aab", "a.*");
    return 0;
}
