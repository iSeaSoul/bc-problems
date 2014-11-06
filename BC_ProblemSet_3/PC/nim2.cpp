#include <iostream>
#include <cstring>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

const int MAXN = 1000 + 10;
const int MAXB = 40;

struct matSpace {
	long long data[MAXN];
	int rank, len;
 
	void input() {
		scanf ("%d", &len);
		for (int i = 0; i < len; ++i) {
			scanf ("%I64d", &data[i]);
		}
		gauss();
	}
 
	void gauss() {
		rank = 0;
 
		for (int b = MAXB; b >= 0; --b) {
			int mainRowID = -1;
			for (int i = rank; i < len; ++i) {
				if ((data[i] >> b) & 1) {
					mainRowID = i;
					break;
				}
			}
			if (mainRowID != -1) {
				if (mainRowID != rank) {
					swap (data[mainRowID], data[rank]);
				}
				for (int j = rank + 1; j < len; ++j) {
					if ((data[j] >> b) & 1) {
						data[j] ^= data[rank];
					}
				}
				rank += 1;
			}
		}
	}

	bool isFullRanked() {
		return rank == len;
	}
};

matSpace ms;

void input() {
	ms.input();
}

void solve() {
	puts (ms.isFullRanked()? "No" : "Yes");
}

int main() {
	repcase {
		input();
		solve();
	}

	return 0;
}