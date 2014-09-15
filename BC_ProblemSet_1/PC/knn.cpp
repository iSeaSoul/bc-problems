#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = 100000 + 10;
const int inf = (-1u) >> 1;

struct point {
	int x, id;
	double v;

	void input(int _id) {
		id = _id;
		scanf ("%d%lf", &x, &v);
	}
	bool operator<(const point& rhs) const {
		return x < rhs.x;
	}
};

point p[MAXN];
int n, m, k, rid[MAXN];

void input() {
	scanf ("%d%d%d", &n, &m, &k);
	rep (i, n) {
		p[i].input(i);
	}
}

double choose_nn(int& lx, int& rx, int basex) {
	int ldis = inf, rdis = inf;
	if (lx >= 0) {
		ldis = basex - p[lx].x;
	}
	if (rx < n) {
		rdis = p[rx].x - basex;
	}
	if (ldis > rdis) {
		return p[rx++].v;
	}
	if (ldis < rdis) {
		return p[lx--].v;
	}
	return p[lx].id < p[rx].id? p[lx--].v : p[rx++].v;
}

void solve() {
	sort (p, p + n);
	rep (i, n) {
		rid[p[i].id] = i;
	}
	long double ret = 0.0;
	rep (i, m) {
		int qid;
		scanf ("%d", &qid);
		qid = rid[qid - 1];

		int left_idx = qid - 1, right_idx = qid + 1;
		double sum = 0.0;
		rep (j, k) {
			sum += choose_nn(left_idx, right_idx, p[qid].x);
		}
		p[qid].v = sum / k;
		// printf ("%.3lf\n", sum / k);
		ret += sum / k;
	}
	printf ("%.8lf\n", (double)ret);
}

int main() {
	// freopen ("knn.out", "w", stdout);
	repcase {
		input();
		solve();
	}

	return 0;
}