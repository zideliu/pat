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
//第一种方法
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
//第二种方法
    int k[8],i=0,flag=0;//建立数组，两个七位数相加最多八位数，所以选择k[8]
    if(c<0){
        c=-c;
        flag=1;
    }
    if(c==0)cout<<"0";
    else{
        while(c)
        {
            k[7-i]=c%10;
            c=c/10;
            i++;
        }
        if(flag)cout<<"-";
        for(i=8-i;i<8;i++)//8-i为该数组的起始位置
        {
            cout<<k[i];
            if(i==1||i==4)
                cout<<",";
        }
    }
    return 0;
}
