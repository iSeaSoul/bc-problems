#include <iostream>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = 1000 + 10;

int n, a[MAXN];

void input() {
	scanf ("%d", &n);
	rep (i, n) {
		scanf ("%d", &a[i]);
	}
}

void solve() {
	bool can_win = false;
	rep (i, n) {
		can_win = !can_win;
		if (a[i] != 1) {
			break;
		}
	}
	puts (can_win? "Yes" : "No");
}

int main() {
	repcase {
		input();
		solve();
	}

	return 0;
}