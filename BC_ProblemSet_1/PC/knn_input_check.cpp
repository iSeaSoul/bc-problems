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

int main() {
	int T, M, N, K;
	int maxt = 5;

	if (HACK_STATUS) {
		maxt = 1;
	}

	try {
		readint(T, 1, maxt);
		rep (j, T) {
			readint(N, 1, 100000);
			readint(M, 1, 100000);
			readint(K, 1, min(N - 1, 10));
			set<int> hash;
			rep (i, N) {
				int Xi, Vi;
				readint(Xi, 1, 1000000000);
				readint(Vi, 1, 1000);
				if (!hash.insert(Xi).second) {
					throw 1;
				}
			}
			rep (i, M) {
				int Qi;
				readint(Qi, 1, N);
			}
		}
		extra_input();
	} catch (...) {
		return 1;
	}

	puts ("AC");
	return 0;
}