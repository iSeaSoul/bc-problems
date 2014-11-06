#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int a[1005],dp[1005][2],i,j,T,n,ans,MAX;
int main()
{
    freopen ("LIS.in", "r", stdin);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (i=1; i<=n; i++) scanf("%d",&a[i]);
        dp[1][0]=1; dp[1][1]=0; MAX=1;
        for (i=2; i<=n; i++)
        {
            dp[i][0]=1; dp[i][1]=0;
            for (j=1; j<i; j++)
              if (a[j]<a[i])
              {
                  if (dp[j][0]+1>dp[i][0])
                  {
                      dp[i][1]=dp[i][0];
                      dp[i][0]=dp[j][0]+1;
                  } else
                    if (dp[j][0]+1>dp[i][1])
                        dp[i][1]=dp[j][0]+1;
                  if (dp[j][1]+1>dp[i][0])
                  {
                      dp[i][1]=dp[i][0];
                      dp[i][0]=dp[j][1]+1;
                  } else
                    if (dp[j][1]+1>dp[i][1])
                        dp[i][1]=dp[j][1]+1;
              }
            if (dp[i][0]==MAX) ans=max(ans,dp[i][0]); else
            {
                ans=max(ans,dp[i][1]);
                MAX=max(MAX,dp[i][0]);
            }
        }
        cout<<ans<<endl;
        ans=MAX=0;
    }
    return 0;
}