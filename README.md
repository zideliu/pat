# pat
pat甲级

#1001 A+B Format#

to_string()函数，将数值转化为字符串。返回对应的字符串。

字符串的插入：
s.insert(pos, str)，pos是待插入的位置， str是待插入的字符串
##

#1002 A+B for Polynomials#

首先选择一个存储结构。
方法一选取的是采用class结构，用来存储系数和指数。
方法二首先建立数组a[1001]（因为最大是1000）其中a[i]的值表示系数为i的指数。选取的是先输入完一组a[n]，接着第二次输入，在进行第二次输入时直接输入到a[n]中，类似于合并同类项，把相同的项合在一起。
##
#1003 Emergency#

dijkstra算法，在此算法中加入way[i]表示从起点到第i个地方的最短路径条数。num[i]表示经过第i个地方后遇到的救援队数量。b[i]表示在i处的救援队数量。

其中比较主要的是判断way[i]。在该最短路径算法中，判断最短路径的核心步骤：如果(s[i]>s[k]+w(k,i))则(s[i]=s[k]+w(k,i))，在进行计算最短路径的条数时可用到way[i]。

if(s[i]==s[k]+w(k,i))then(way[i]+=way[k])
else if(s[i]>s[k]+w(k,i))then(way[i]=way[k])这样便可以计算出way[i]的值，最后输出即可

在此基础上，再进行判断num[i]的值，如下：

if(s[i]==s[k]+w(k,i))then(way[i]+=way[k];num[i]+=num[k])

else if(s[i]>s[k]+w(k,i))then(way[i]=way[k];num[i]=num[k]+d[k])
这样就结束了。
##
