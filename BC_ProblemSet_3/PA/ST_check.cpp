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

#include "../../testlib.h"

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

void readEof() {
	if (inf.eof()) {
		inf.readEof();
	} else {
		inf.readEoln();
		inf.readEof();
	}
}

int main() {
	registerValidation();

	// case
	inf.readInt(1, 1);
	inf.readEoln();

	// one case
	int n = inf.readInt(1, 447000, "n");
	inf.readEoln();
	rep (i, n) {
		inf.readInt(0, 1000000000);
		if (i < n - 1) inf.readSpace();
		// end
		else readEof();
	}

	// puts ("AC");
	return 0;
}