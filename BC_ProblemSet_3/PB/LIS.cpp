#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = 1000 + 10;

int n, a[MAXN];
int lis[MAXN], lis_dirty[MAXN];

void input() {
	scanf ("%d", &n);
	rep (i, n) {
		scanf ("%d", &a[i]);
	}
}

void solve() {
	fill (lis_dirty, lis_dirty + n, -1);
	rep (i, n) {
		lis[i] = 1;
		int lislen_cnt[MAXN] = {0};
		rep (j, i) {
			if (a[i] > a[j]) {
				// update lis
				lis[i] = max(lis[i], lis[j] + 1);
				// update lis_dirty
				if (lis_dirty[j] != -1) {
					lis_dirty[i] = max(lis_dirty[i], lis_dirty[j] + 1);
				}
				lislen_cnt[lis[j]] += 1;
				// update lis_dirty by two lis
				if (lislen_cnt[lis[j]] > 1) {
					lis_dirty[i] = max(lis_dirty[i], lis[j] + 1);
				}
			}
		}
	}
	sort (lis, lis + n);
	printf ("%d\n", max(*max_element(lis_dirty, lis_dirty + n), lis[n - 2]));
}

int main() {
	repcase {
		input();
		solve();
	}

	return 0;
}