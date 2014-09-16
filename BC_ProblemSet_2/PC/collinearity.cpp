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

int sgn(int x) { return (x > 0) - (x < 0); }

struct point {
	int x, y;

	point(int _x = 0, int _y = 0): x(_x), y(_y) {
	}
	void input() {
		scanf ("%d%d", &x, &y);
	}
	bool operator<(const point& rhs) const {
		// hand-writed atan2 - (-pi, pi]
		// be careful with the method of sorting
		if (x == 0 && rhs.x == 0) {
			return sgn(y) < sgn(rhs.y);
		}
		if (sgn(x) != sgn(rhs.x)) {
			return sgn(x) < sgn(rhs.x);
		}
		return (long long)x * rhs.y < (long long)y * rhs.x;
	}
	bool operator==(const point& rhs) const {
		return (long long)x * rhs.y == (long long)y * rhs.x && 
		(long long)x * rhs.x + (long long)y * rhs.y > 0;
	}
};

point p[MAXN], cp[MAXN];
int n;

void input() {
	scanf ("%d", &n);
	rep (i, n) {
		p[i].input();
	}
}

void solve() {
	int ret = 0;
	rep (i, n) {
		int ct = 0;
		rep (j, n) if (i != j) {
			cp[ct++] = point(p[j].x - p[i].x, p[j].y - p[i].y);
		}
		sort (cp, cp + ct);
		int cnt = 0;
		rep (j, ct) {
			if (cp[j].x < 0 || (cp[j].x == 0 && cp[j].y < 0)) {
				continue ;
			}
			if (j > 0 && cp[j] == cp[j - 1]) {
				cnt += 1;
			} else {
				ret += (cnt - 1) * cnt / 2;
				cnt = 1;
			}
		}
		ret += (cnt - 1) * cnt / 2;
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