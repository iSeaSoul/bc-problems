/**
 * @author - liyan30 @ 2015-04-26 16:05
 * @brief - 
 **/

#include <bits/stdc++.h>

using namespace std;

// SELF TEMPLATE CODE BGEIN

#define LOG(level, fmt, arg...) \
    printf("[" #level "] [Line:%d] " fmt"\n", __LINE__, ##arg);

#define NOTICE(fmt, arg...) LOG(NOTICE, fmt, ##arg)
#define FATAL(fmt, arg...) LOG(FATAL, fmt, ##arg)

#define DEBUG(x) do { \
    stringstream ss; \
    ss << #x << ": " << x; \
    NOTICE("%s", ss.str().c_str()) \
} while(0)

#define SZ(x) ((int)((x).size()))
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repcase int t, Case = 1; for (scanf("%d", &t); t; --t)

template<class T> inline void to_min(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void to_max(T &a, const T b) { if (b > a) a = b; }

// SELF TEMPLATE CODE END

const int maxn = 100000 + 10;

int n, x, h[maxn], q[maxn];

void update_maxdis(long long& maxd, int& maxid, long long curd, int curid) {
    if (curd > maxd) {
        maxd = curd;
        maxid = curid;
    }
}

void update(long long& ans, int& id1, int& id2, long long cur, int cid1, int cid2) {
    if (cur > ans) {
        ans = cur;
        id1 = cid1, id2 = cid2;
    } else if (cur == ans) {
        if (cid1 < id1 || (cid1 == id1 && cid2 < id2)) {
            id1 = cid1, id2 = cid2;
        }
    }
}

int main() {
    // freopen ("tough.out", "w", stdout);

    repcase {
        scanf ("%d%d", &n, &x);
        rep (i, n) {
            scanf ("%d", &h[i]);
        }

        long long ans = 0;
        int p1, p2, half = n / 2;

        long long maxdis = 0;
        int maxid, right_half = half + 1;
        repf (i, right_half, n - 1) {
            update_maxdis(maxdis, maxid, h[i - right_half] + (long long)x * (i - right_half), i - right_half);
            update(ans, p1, p2, h[i] + (long long)x * (n - i) + maxdis, maxid, i);
        }

        int l = 0, r = -1;
        q[++r] = 0;
        repf (i, 1, n - 1) {
            while (l <= r && q[l] < i - half) ++l;
            update(ans, p1, p2, h[i] + h[q[l]] + (long long)x * (i - q[l]), q[l], i);
            while (l <= r && h[i] - (long long)x * i > h[q[r]] - (long long)x * q[r]) --r;
            q[++r] = i;
        }
        printf ("%d %d\n", p1 + 1, p2 + 1);
    }
    return 0;
}
