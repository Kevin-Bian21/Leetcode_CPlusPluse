#pragma once
#include <vector>
#include <string>
using namespace std;

class CGenerateParentheses
{
public:
    vector<string> generateParenthesis(int n);
    /*
    * left : ��ʾ�����ŵ�ʣ�࣬ right : ��ʾ�����ŵ�ʣ�� ����left<= right
    * left = 0 : ��������ţ� left == right : ��������ţ� left < right : �ȿ�����������ţ��ֿ������������
    */
    void backTracking(vector<string> &v, string s, int left, int right);
};

