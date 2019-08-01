//
//  main.cpp
//  1001 A+B Format
//
//  Created by Zide Liu on 2019/8/1.
//  Copyright © 2019 Zide Liu. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
int main() {
    int a, b, c;
    string s;
    cin>>a>>b;
    c = a + b;
    s = to_string(c);// to_string 将数值转化为字符串。返回对应的字符串。
    int n = s.size();
    int temp = 0;
    if (c < 0) temp = 1;
    for (int i = n - 3; i > temp; i -= 3) {
        s.insert(i, ",");// s.insert(pos, str)，pos是待插入的位置， str是待插入的字符串
    }
    cout << s << endl;
    return 0;
}
