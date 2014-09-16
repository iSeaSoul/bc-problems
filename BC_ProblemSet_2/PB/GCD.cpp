#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

long long x, y, k;

void input() {
	scanf ("%I64d%I64d%I64d", &x, &y, &k);
}

long long get_kth_fac(long long X, long long k) {
	// find k-th factor of X
	vector<long long> facs;
	for (long long i = 1; i * i <= X; ++i) {
		if (X % i == 0) {
			facs.push_back(i);
			if (i * i != X) {
				facs.push_back(X / i);
			}
		}
	}
	sort (facs.begin(), facs.end());
	int facsz = (int)(facs.size());
	return k > facsz? -1LL : facs[facsz - k]; 
}

void solve() {
	printf ("%I64d\n", get_kth_fac(__gcd(x, y), k));
}

int main() {
	repcase {
		input();
		solve();
	}

	return 0;
}