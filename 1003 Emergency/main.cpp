//
//  main.cpp
//  1003 Emergency
//
//  Created by Zide Liu on 2019/8/4.
//  Copyright © 2019 Zide Liu. All rights reserved.
//
#include <iostream>
using namespace std;

const int inf = 65535;
const int N = 502;

int n;
bool mark[N];
int a[N][N];
int num[N];
int b[N];//b[i]表示在i处有多少人
int cost[N];
int way[N];

void dijkstra(int s) {
    for (int i = 0; i < n; ++i) {
        cost[i] = inf;
        mark[i] = false;
        num[i] = way[i] = 0;
    }
    num[s] = b[s];
    way[s] = 1;
    cost[s] =  0;
    for (int j = 0; j < n; ++j) {
        
        int k = -1;
        for (int i = 0; i < n; ++i) {
            if ((!mark[i]) && ((k < 0) || (cost[i] < cost[k]))) { //找出最短边
                k = i;
            }
        }
        mark[k] = true;//标记
        for (int i = 0; i < n; ++i) {
            if ((!mark[i]) && (a[k][i] < inf)) {
                int temp = cost[k] + a[k][i];
                if (temp < cost[i]) {
                    cost[i] = temp;
                    num[i] = num[k] + b[i];
                    way[i] = way[k];
                }
                else if (temp == cost[i]) {
                    num[i] = max(num[k] + b[i], num[i]);
                    way[i] += way[k];
                }
            }
        }
    }
}

int main() {
    int m,from,to;
    cin>>n>>m>>from>>to;
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
        for (int j = 0; j < n; ++j) {
            a[i][j] = inf;
        }
    }
    for (;m;--m) {
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y] = a[y][x] = min(a[x][y],z);
    }
    dijkstra(from);
    cout<<way[to]<<" "<<num[to]<<endl;
    return 0;
}
