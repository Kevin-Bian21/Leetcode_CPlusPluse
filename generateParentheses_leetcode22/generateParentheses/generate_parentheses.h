#pragma once
#include <vector>
#include <string>
using namespace std;

class CGenerateParentheses
{
public:
    vector<string> generateParenthesis(int n);
    /*
    * left : 表示左括号的剩余， right : 表示右括号的剩余 所以left<= right
    * left = 0 : 添加右括号； left == right : 添加左括号； left < right : 既可以添加左括号，又可以添加右括号
    */
    void backTracking(vector<string> &v, string s, int left, int right);
};

