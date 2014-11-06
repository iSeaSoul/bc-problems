#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int k[65];
long long num[1010];
int main()
{
  freopen ("nim2.in", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        memset(k,0,sizeof(k));
        int n,n1,n2,can=0;
        scanf("%d",&n);
        for(n1=1;n1<=n;n1++)
            scanf("%I64d",&num[n1]);
        for(n1=1;n1<=n;n1++)
        {
            for(n2=60;n2>=0;n2--)
                if(num[n1]&(1<<n2))
                    if(k[n2])
                        num[n1]^=k[n2];
                    else
                    {
                        k[n2]=num[n1];
                        break;
                    }
            if(num[n1]==0)
            {
                can=1;
                break;
            }
        }
        if(can)
            printf("Yes\n");
        else
            printf("No\n");
    }
}