#include "integer_to_roman.h"

#include <iostream>

string CIntegerToRoman::intToRomanOne(int num) {
    string str = "";
    while (num / 1000) {
        str += "M";
        num -= 1000;
    }
    while (num / 500) {
        if (num >= 900) {
            str += "CM";
            num -= 900;
            continue;
        }
        str += "D";
        num -= 500;
    }
    while (num / 100) {
        if (num >= 400) {
            str += "CD";
            num -= 400;
            continue;
        }
        str += "C";
        num -= 100;
    }
    while (num / 50) {
        if (num >= 90) {
            str += "XC";
            num -= 90;
            continue;
        }
        str += "L";
        num -= 50;
    }
    while (num / 10) {
        if (num >= 40) {
            str += "XL";
            num -= 40;
            continue;
        }
        str += "X";
        num -= 10;
    }
    while (num / 5) {
        if (num >= 9) {
            str += "IX";
            num -= 9;
            continue;
        }
        str += "V";
        num -= 5;
    }
    while (num) {
        if (num >= 4) {
            str += "IV";
            num -= 4;
            continue;
        }
        str += "I";
        num -= 1;
    }
    return str;
}

string CIntegerToRoman::intToRomanTwo(int num) {
    //针对罗马数字和阿拉伯数字的规则做映射
    string rom[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int arr[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    int index = 0;
    string str = "";
    while (index < 13) {
        while (num >= arr[index]) {
            str += rom[index];
            num -= arr[index];
        }
        index++;
    }
    return str;
}

int main() {
    CIntegerToRoman obj;
    cout << obj.intToRomanOne(199) << endl;
    cout << obj.intToRomanTwo(199) << endl;
    return 0;
}
