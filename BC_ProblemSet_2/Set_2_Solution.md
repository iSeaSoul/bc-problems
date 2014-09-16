###A - Revenge of Fibonacci

重新定义fib的前两项为A和B，询问C是否fib数列中的一项。

由于C的范围有限，暴力计算出所有范围的fib数判断一下。

复杂度：$O(fib(C))$

难度：$0.5/5$

###B - Revenge of GCD

A与B的$k^{th} GCD$。

可以推出答案是$GCD(A, B)$的第K大因子。这个数的最大值是10^12，因此可以枚举所有因子求出第K大的。

复杂度：$O(sqrt(A))$

难度：$1.0/5$

###C - Revenge of Collinearity

枚举三点共线三元组中x最小的（即枚举每个点），极角排序，看极角在$(-pi/2, pi/2]$中的直线上点的个数，$sigma(C(num,2))$是当前点x值最小(x相等y值最小)的三元组个数。累加起来为答案。

这里坐标范围很大，所以不要使用$atan2$，$acos$这种函数，会有误差。

手写atan2极角排序的时候，注意区间是$(-pi, pi]$，而不是$(-pi/2, pi/2]$。如果没有想清楚，这里很容易出现错误的排序函数造成comp冲突，恰好生成了这样一组testcase。在HDOJ上测试会RE。一个typical的错误comp函数：

```cpp 
bool operator<(const point& rhs) const {
  long long dif = (long long)x * rhs.y - (long long)y * rhs.x;
  return dif == 0? (x == rhs.x? y < rhs.y : x < rhs.x) : dif < 0;
}
```

复杂度： $O(N^2logN)$

难度：$1.5/5$

###D - Revenge of LIS II

相对于kNN I，这里去掉了$k\le10$的限制，使得暴力扫描$O(MK)$复杂度过高。

考虑如何快速求出距离最近的k个点的权值之和，这里的距离具有明显的二分性。这样可以在$log(MAXX)$的时间内求出k个点的坐标范围。求出之后的问题是，区间求和，单点更新，树状数组足够解决这个问题了。

在二分的时候注意K和K+1可能都是符合条件的，如果算出K+1被舍弃的话，减小Distance可能得到的是K-1，并不连续，所以要判断一下这种情况。

第一场时候看了一下部分代码，没有人使用了这里最关键的二分处理，于是决定还是放这个题目了。有少部分上次用树状数组或线段树维护的，这道题算是小小补偿了一下。

复杂度：$O(NlogN + M*(log(MAXX) + log(N)))$

难度：$2.5/5$