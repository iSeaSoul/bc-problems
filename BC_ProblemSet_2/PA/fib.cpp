#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

// Self Template Code END

int a, b, c;

void input() {
	scanf ("%d%d%d", &a, &b, &c);
}

bool is_fib(int a, int b, int c) {
	if (a == c || b == c) {
		return true;
	}
	while (a + b <= c) {
		int next = a + b;
		if (next == c) {
			return true;
		}
		a = b;
		b = next;
	}
	return false;
}

void solve() {
	puts (is_fib(a, b, c)? "Yes" : "No");
}

int main() {
	repcase {
		input();
		solve();
	}

	return 0;
}