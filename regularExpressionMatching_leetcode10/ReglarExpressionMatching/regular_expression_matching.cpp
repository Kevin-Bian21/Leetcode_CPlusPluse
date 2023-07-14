#include "regular_expression_matching.h"
#include <iostream> 
#include <vector>

/*
如果 p[j] == s[i] : dp[i][j] = dp[i-1][j-1]；
如果 p[j] == '.' : dp[i][j] = dp[i-1][j-1]；
如果 p[j] == '*'：  //遇到*得分情况
    如果 p[j-1] != s[i] : dp[i][j] = dp[i][j-2] //in this case, a* only counts as empty
    如果 p[i-1] == s[i] or p[i-1] == '.'：
        dp[i][j] = dp[i-1][j] //in this case, a* counts as multiple a
        or dp[i][j] = dp[i][j-1] // in this case, a* counts as single a
        or dp[i][j] = dp[i][j-2] // in this case, a* counts as empty
*/

bool CRegularExpressionMatching::isMatch(string s, string p) {
    s = " " + s;  //添加哨兵
    p = " " + p;
    int m = s.length();
    int n = p.length();
    vector <vector<bool>> dp(m+1, vector<bool>(n+1, false));  // m+1 * n+1 的二维数组，初始化所有元素为false
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
