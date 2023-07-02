#include "zigzagConversion.h"
#include <iostream>

//����Ϊ4�� s��ÿ��Ԫ�ص�λ��1234321234
string zigzagConversion::convert(string s, int numRows) {
    if (numRows <= 1)
        return s;
    int index = 1;
    string str = "";
    int num = 0;
    int k = 0;
    for (int i = 1; i <= numRows; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (index == 1) {
                num = 1;
            }
            if (index == numRows) {
                num = -1;
            }
            if (i == index) {
                str += s[j];
            }
            index += num;
        }
        index = 1;
    }
    return str;
}
int main() {
    zigzagConversion obj;
    cout << obj.convert("PAYPALISHIRING", 4);
 }