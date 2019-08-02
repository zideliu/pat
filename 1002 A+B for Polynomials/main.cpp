//
//  main.cpp
//  1002 A+B for Polynomials
//
//  Created by Zide Liu on 2019/8/2.
//  Copyright © 2019 Zide Liu. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
class s{
public:
    double x;
    double y;
};
int main(int argc, const char * argv[]) {
    int n,m,j=0,k=0;//数量
    cin>>n;
    s a[n];
    for(int i=0;i<n;i++)
        cin>>a[i].x>>a[i].y;
    cin>>m;
    s b[m];
    for(int i=0;i<m;i++)
        cin>>b[i].x>>b[i].y;
    s sum[n+m];
    int z=0;
    while(j<n||k<m)
        {
            if(j>=n){
                sum[z].x=b[k].x;
                sum[z].y=b[k].y;
                z++;
                k++;}
            else if(k>=m){
                sum[z].x=a[j].x;
                sum[z].y=a[j].y;
                z++;
                j++;
                
            }
            else if(a[j].x==b[k].x)
            {
                sum[z].x=a[j].x;
                sum[z].y=a[j].y+b[k].y;
                if(sum[z].y!=0)z++;
                k++;
                j++;
            }
            else if(a[j].x>b[k].x){
                sum[z].x=a[j].x;
                sum[z].y=a[j].y;
                z++;
                j++;
            }
            else if(a[j].x<b[k].x){
                sum[z].x=b[k].x;
                sum[z].y=b[k].y;
                z++;
                k++;
            }

        }
    cout<<z;
    for(int i=0;i<z;i++)
    {
            printf(" %d %0.1f",sum[i].x,sum[i].y);
    }
    
    return 0;
}
