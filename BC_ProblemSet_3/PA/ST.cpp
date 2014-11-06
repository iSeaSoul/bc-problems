#include <iostream>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = 447000 + 10;
const int MOD = 1000000007;

int n, a[MAXN];

int readint() {
	int ret = 0;
	char ch;
	for (ch = getchar(); !(ch >= '0' && ch <= '9'); ch = getchar());
	ret = ch - '0';
	for (ch = getchar(); (ch >= '0' && ch <= '9'); ch = getchar()) {
		ret = ret * 10 + ch - '0';
	}
	return ret;
}

void input() {
	scanf ("%d", &n);
	rep (i, n) {
		// scanf ("%d", &a[i]);
		a[i] = readint();
	}
}

void solve() {
	int ret = 0;
	rep (i, n) {
		long long sum = (long long)(i + 1) * (n - i) % MOD;
		sum = sum * a[i] % MOD;
		// ret = (ret + sum) % MOD;
		ret += sum;
		if (ret >= MOD) ret -= MOD;
	}
	printf ("%d\n", ret);
}

int main() {
	repcase {
		input();
		solve();
	}

	return 0;
}