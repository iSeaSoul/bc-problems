#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
#define eps 1e-8
#define maxn 1005
double num[maxn];
int k[maxn];
int main(){
    freopen ("iSea.in", "r", stdin);
    int  t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%lf",&num[i]),num[i]/=100;
        for(int i=0;i<m;i++)
            k[i]=i;
        k[m]=n;
        double a=1;
        double b=0;
        for(int i=0;i<m;i++){
            a*=num[k[i]];
            b+=1/num[k[i]];
            b-=m;
        }
        double p=a*b;
        for(int i=m-1;i>=0;i--){
            for(int j=k[i]+1;j<k[i+1];j++){
                double tema=a/num[k[i]]*num[j];
                double temb=b-1/num[k[i]]+1/num[j];
                double temp=tema*temb;
                if(temp>p+eps){
                    p=temp;
                    a=tema;
                    b=temb;
                    k[i]=j;
                }
                else break;
            }
        }
        
        for(int i=0;i<m;i++){
            if(i!=0) printf(" ");
            printf("%d",k[i]+1);
        }
        printf("\n");
    }
}