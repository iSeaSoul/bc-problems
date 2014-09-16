#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = 1000 + 10;
const double eps = 1e-8;
const double pi = acos(-1.0);

int sgn(double x) { return (x > eps) - (x < -eps); }

struct point {
	int x, y;

	void input() {
		scanf ("%d%d", &x, &y);
	}
};

point p[MAXN];
int n;

void input() {
	scanf ("%d", &n);
	rep (i, n) {
		p[i].input();
	}
}

void solve() {
	vector<double> cp;
	long long ret = 0;
	rep (i, n) {
		cp.clear();
		rep (j, n) {
			if (i == j) continue;
			cp.push_back(atan2(p[j].y - p[i].y, p[j].x - p[i].x));
		}
		sort (cp.begin(), cp.end());
		// repeach (i, cp) {
		// 	printf ("%lf ", *i);
		// }
		// puts ("");
		int cnt = 0;
		rep (j, int(cp.size())) {
			if (sgn(cp[j] - pi / 2) > 0 || sgn(cp[j] + pi / 2) <= 0) {
				continue ;
			}
			if (j && sgn(cp[j] - cp[j - 1]) == 0) {
				cnt += 1;
			} else {
				ret += (cnt - 1) * cnt / 2;
				cnt = 1;
			}
		}

		ret += (cnt - 1) * cnt / 2;
	}
	printf ("%I64d\n", ret);
}

int main() {
	// freopen ("collinearity.in", "r", stdin);
	repcase {
		input();
		solve();
	}

	return 0;
}