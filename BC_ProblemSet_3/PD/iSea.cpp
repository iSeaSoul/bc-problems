#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = 47 + 4;
const double eps = 1e-8;

int sgn(double x) { return (x > eps) - (x < -eps); }

int n, k;
double p[MAXN];

void input() {
	scanf ("%d%d", &n, &k);
	rep (i, n) {
		scanf ("%lf", &p[i]);
		p[i] /= 100;
	}
}

double calc_pro_first_k(int x) {
	vector<double> pro;
	rep (i, x) {
		pro.push_back(p[i]);
	}
	rep (i, k - x) {
		pro.push_back(p[n - 1 - i]);
	}
	double ret = 0.0;
	rep (i, k) {
		double cpro = 1.0;
		rep (j, k) {
			cpro *= (i == j? 1 - pro[j] : pro[j]);
		}
		ret += cpro;
	}
	return ret;
}

void solve() {
	int ans = k;
	double maxp = calc_pro_first_k(k);
	// fprintf (stderr, "%d : %.10lf\n", k, maxp);
	repd (i, k - 1, 0) {
		double cp = calc_pro_first_k(i);
		// fprintf (stderr, "%d : %.10lf\n", i, cp);
		if (sgn(cp - maxp) > 0) {
			ans = i;
			maxp = cp;
		}
	}

	vector<int> res;
	rep (i, ans) {
		res.push_back(i + 1);
	}
	int last_min = n - (k - ans - 1);
	int last_min_id = n - (k - ans - 1);
	// find the minimal index with same value
	while (last_min_id > ans + 1 && sgn(p[last_min_id - 1] - p[last_min_id - 2]) == 0) {
		last_min_id -= 1;
	}
	rep (j, k - ans) {
		int cid = n - (k - ans - 1 - j);
		if (sgn(p[cid - 1] - p[last_min - 1]) == 0) {
			res.push_back(last_min_id++);
		} else {
			res.push_back(cid);
		}
	}
	rep (i, k) {
		printf ("%d%c", res[i], i == k - 1? '\n' : ' ');
	}
}

int main() {
	repcase {
		input();
		solve();
	}

	return 0;
}