#include <iostream>
#include <cstring>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = (1 << 18) + 10;

long long dp[2][MAXN], ans[20][20];

int count_bit(int x) {
	return x == 0? 0 : count_bit(x - (x & -x)) + 1;
}

void init() {
	dp[0][1] = ans[0][1] = 1;
	int flag = 1;
	repf (i, 1, 17) {
		memset (dp[flag], 0, sizeof(dp[flag]));
		int G = (1 << i);
		rep (st, G) {
			if (!dp[!flag][st]) continue ;
			int next_more = i;
			repd (pos, i, 0) {
				if ((st >> pos) & 1) {
					next_more = pos;
				}
				int newst = st & ((1 << pos) - 1);	// less than
				newst |= (1 << pos);	// current
				if (next_more != i) {	// replace next_more in min & shift bigger
					newst |= (((st ^ (1 << next_more)) >> pos) << (pos + 1));
				}
				// printf ("state %d %d -> newst %d\n", st, pos, newst);
				dp[flag][newst] += dp[!flag][st];
			}
		}
		rep (st, (G << 1)) {
			ans[i][count_bit(st)] += dp[flag][st];
		}
		flag = !flag;
	}
}

int main() {
	init();

	repcase {
		int n, k;
		scanf ("%d%d", &n, &k);
		printf ("%I64d\n", ans[n - 1][k]);
	}

	return 0;
}