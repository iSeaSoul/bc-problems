#include <iostream>
#include <cstring>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

namespace trinary {
	int base3[18] = {};
	void gen_base3() {
		base3[0] = 1;
		repf (i, 1, 16) {
			base3[i] = base3[i - 1] * 3;
		}
	}
	int get_bit(int mask, int bit) {
		return (mask % base3[bit + 1]) / base3[bit];
	}
	int change_bit(int mask, int bit, int num) {
		return mask + (num - get_bit(mask, bit)) * base3[bit];
	}
	bool test_bit(int mask, int bit, int num) {
		return get_bit(mask, bit) == num;
	}
};

const int MAXN = 16;

int n, k;
long long dp[2][14348907];
long long ans[MAXN][MAXN];
long long fac[MAXN];

void pre_calc(int x) {
	int flag = 0;
	int G = trinary::base3[x];
	rep (i, x) {
		memset (dp[flag], 0, sizeof(dp[flag]));
		if (i == 0) {
			rep (j, x) {
				dp[flag][trinary::change_bit(0, j, 2)] = 1;
			}
		} else {
			rep (mask, G) {
				if (!dp[!flag][mask]) continue;
				// printf ("go %d %d %I64d\n", i, mask, dp[!flag][mask]);
				rep (j, x) {
					if (!trinary::test_bit(mask, j, 0)) continue;
					int first_bigger = -1;
					repf (k, j + 1, x - 1) {
						if (trinary::test_bit(mask, k, 2)) {
							first_bigger = k;
							break;
						}
					}
					int new_mask = trinary::change_bit(mask, j, 2);
					if (first_bigger != -1) {
						// replace the first bigger number in sequence
						new_mask = trinary::change_bit(new_mask, first_bigger, 1);
					}
					dp[flag][new_mask] += dp[!flag][mask];
				}
			}
		}
		flag = !flag;
	}
	rep (mask, G) {
		int lis_len = 0;
		rep (i, x) {
			if (trinary::test_bit(mask, i, 2)) {
				lis_len += 1;
			}
		}
		// printf ("here %d %d %d %I64d\n", x, mask, lis_len, dp[!flag][mask]);
		ans[x][lis_len] += dp[!flag][mask];
	}
	long long tot = 0;
	printf ("{");
	bool first = true;
	repf (i, 1, x) {
		tot += ans[x][i];
		// printf ("ans[%d][%d] = %I64d\n", x, i, ans[x][i]);
		if (!first) printf (", ");
		first = false;
		printf ("%I64dLL", ans[x][i]);
	}
	puts ("},");
	// printf ("tot %I64d %I64d\n", tot, fac[x]);
}

void pre_calc() {
	fac[0] = 1;
	repf (i, 1, 15) {
		fac[i] = fac[i - 1] * i;
		pre_calc(i);
	}
}

int main() {
	trinary::gen_base3();
	pre_calc();

	return 0;
}