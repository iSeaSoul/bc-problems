#include <iostream>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = 1000 + 10;

int a, b, c;

void input() {
	scanf ("%d%d%d", &a, &b, &c);
}

void solve() {
	int ret = 0;
	repf (x, 1, c / a) {
		int py = c - x * a;
		if (py && py % b == 0) {
			ret += 1;
		}
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