// Rain Dreamer MODEL
// iSea @ 2014-08-25 14:01
// Comment - 

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

void readint(int &x, int lrange, int rrange = -1) {
	if (scanf ("%d", &x) == EOF) {
		throw 1;
	}
	if (rrange != -1) {
		if (!(x >= lrange && x <= rrange)) {
			throw 1;
		}
	}
}

void extra_input() {
	char buf[65536];
	if (scanf ("%s", buf) != EOF) {
		throw 1;
	}
}

#define HACK_STATUS false
#define MAXT 33

int main() {
	int T, N, X, Y;
	int maxt = MAXT;

	if (HACK_STATUS) {
		maxt = 1;
	}

	try {
		readint(T, 1, maxt);
		int bigcase = 0;
		rep (j, T) {
			readint(N, 3, 1000);
			if (N > 100) bigcase++;
			set<pair<int, int> > hash;
			rep (i, N) {
				readint(X, -1000000000, 1000000000);
				readint(Y, -1000000000, 1000000000);
				if (!hash.insert(pii(X, Y)).second) {
					throw 1;
				}
			}
		}
		// fprintf (stderr, "bigcase = %d\n", bigcase);
		if (T >= 4 && bigcase * 4 > T) {
			throw 1;
		}
		extra_input();
	} catch (...) {
		return 1;
	}

	puts ("AC");
	return 0;
}