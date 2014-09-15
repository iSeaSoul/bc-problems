/*
Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
const int N = 18;
LL dp[N + 1][1 << N], ans[N + 1][N + 1];
int p2[N + 1], nxt[N + 1];
void init()
{
	p2[0] = 1;
	for(int i = 1; i <= N; ++i)
	p2[i] = p2[i - 1] * 2;
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	for(int i = 1; i < N; ++i)
	for(int j = 0; j < p2[i]; ++j)
	if(dp[i][j] != 0)
	{
		nxt[i] = i;
		for(int k = i - 1; k >= 0; --k)
		if(j & p2[k]) nxt[k] = k;
		else nxt[k] = nxt[k + 1];
		int pos = 0, st;
		for(int k = 0; k <= i; ++k)
		{
			if(nxt[k] == i) st = j | p2[k];
			else st = (j % p2[k]) | ((j ^ p2[nxt[k]]) / p2[k] * p2[k + 1]) | p2[k];
			dp[i + 1][st] += dp[i][j];
		}
	}
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= N; ++i)
	for(int j = 0; j < p2[i]; ++j)
	{
		int lis = 0;
		for(int k = 0; k < i; ++k)
		if(j & p2[k]) lis++;
		ans[i][lis] += dp[i][j];
	}
}
int _, n, K;
int main()
{
	init();
	scanf("%d", &_);
	while(_--)
	{
		scanf("%d%d", &n, &K);
		cout << ans[n][K] << endl;
	}
	return 0;
}
