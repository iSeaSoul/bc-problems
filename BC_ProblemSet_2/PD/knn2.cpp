#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = 100000 + 10;
const int inf = (-1u) >> 1;
const double eps = 1e-8;

int sgn(double x) { return (x > eps) - (x < -eps); }

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

struct binary_indexed_tree {
	#define lowbit(x) ((x) & (-(x)))
	double a[MAXN];

	void clear() {
		memset (a, 0, sizeof(a));
	}
	void update(int x, double y) {
		for (; x < MAXN; x += lowbit(x)) {
			a[x] += y;
		}
	}
	double getsum(int x) {
		double ret = 0.0;
		for (; x; x -= lowbit(x)) {
			ret += a[x];
		}
		return ret;
	}
	double getsum(int x, int y) {
		return getsum(y) - getsum(x - 1);
		// double ret = 0.0;
		// while (l <= r) {
		// 	if (r - lowbit(r) + 1 >= l) {
		// 		ret += a[r];
		// 		r -= lowbit(r);
		// 	} else {
		// 		ret += val[r--];
		// 	}
		// }
		// faster.. but need an extra val array
	}
};

point p[MAXN];
int n, m, rid[MAXN];
binary_indexed_tree bit;
int X[MAXN];

void input() {
	scanf ("%d%d", &n, &m);
	rep (i, n) {
		p[i].input(i);
	}
}

int get_inum(int R, int xid, int k) {
	int lidx = lower_bound(X, X + n, p[xid].x - R) - X;
	int ridx = upper_bound(X, X + n, p[xid].x + R) - X - 1;
	int inside_num = ridx - lidx;
	if (inside_num == k) {
		return 0;
	}
	if (inside_num - 1 == k) {
		int ldis = p[xid].x - p[lidx].x;
		int rdis = p[ridx].x - p[xid].x;
		if (ldis == rdis) {
			return 0;
		}
	}
	return inside_num > k? 1 : -1;
}

double get_isum(int R, int xid, int k) {
	int lidx = lower_bound(X, X + n, p[xid].x - R) - X;
	int ridx = upper_bound(X, X + n, p[xid].x + R) - X - 1;
	int inside_num = ridx - lidx;
	if (inside_num == k) {
		return bit.getsum(lidx + 1, ridx + 1) - p[xid].v;
	}
	int r_lidx = p[lidx].id;
	int r_ridx = p[ridx].id;
	if (r_lidx < r_ridx) {
		return bit.getsum(lidx + 1, ridx) - p[xid].v;
	} else {
		return bit.getsum(lidx + 2, ridx + 1) - p[xid].v;
	}
}

void solve() {
	sort (p, p + n);
	bit.clear();
	rep (i, n) {
		rid[p[i].id] = i;
		X[i] = p[i].x;
		bit.update(i + 1, p[i].v);
	}

	double ret = 0.0;
	rep (i, m) {
		int qid, qk;
		scanf ("%d%d", &qid, &qk);
		qid = rid[qid - 1];

		// binary search distance of k-NN
		int l = 0, r = max(p[n - 1].x - p[qid].x, p[qid].x - p[0].x);
		while (l <= r) {
			int mid = (l + r) / 2;
			int inum_ret = get_inum(mid, qid, qk);
			// printf ("here bs %d %d -> %d\n", mid, qid, inum_ret);
			if (inum_ret == 0) {
				break;
			} else if (inum_ret > 0) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		double sum = get_isum((l + r) / 2, qid, qk) / qk;
		double dif = sum - p[qid].v;
		p[qid].v = sum;
		// printf ("%lf\n", sum);
		ret += sum;
		bit.update (qid + 1, dif);
	}
	printf ("%.3lf\n", ret);
}

struct tm_node {
	clock_t begin;

	void init() {
		begin = clock();
	}
	void output() {
		fprintf (stderr, "Used Time = %lfs\n", 1.0 * (clock() - begin) / CLOCKS_PER_SEC);
	}
} TN;

int main() {
	TN.init();

	repcase {
		input();
		solve();
	}

	TN.output();

	return 0;
}