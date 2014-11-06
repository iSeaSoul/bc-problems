#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
const int MAXB = 40;

struct matSpace {
	long long data[MAXN];
	int rank, len;
 
	bool input() {
		if (scanf ("%d", &len) == EOF) return false;
		printf ("%d\n", len);
		for (int i = 0; i < len; ++i) {
			scanf ("%I64d", &data[i]);
			printf ("%I64d%c", data[i], " \n"[i == len - 1]);
		}
		gauss();
		return true;
	}

	void printRanked() {
		printf ("%d\n", rank);
		for (int i = 0; i < rank; ++i) {
			printf ("%I64d%c", data[i], " \n"[i == rank - 1]);
		}
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
} ms;

int main() {
	ios::sync_with_stdio(false);

	freopen ("nim2_gen.in", "r", stdin);
	freopen ("nim2_gen_2.out", "w", stdout);

	while (ms.input()) {
		ms.printRanked();
	}

	// code...
	return 0;
}