/**
 * @author - liyan30 @ 2015-04-26 14:21
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

struct point {
    long long x, y;
    int t;

    void input() {
        int tx, ty;
        scanf("%d%d%d", &tx, &ty, &t);
        tx <<= 1; ty <<= 1; t <<= 1;
        x = (long long)tx + ty;
        y = (long long)tx - ty;
    }
    bool operator<(const point& rhs) const {
        return t < rhs.t;
    }
};

struct rectangle {
    long long lx, ly, rx, ry;

    void extend(const int& step) {
        lx -= step; ly -= step;
        rx += step; ry += step;
    }
    void intersect(const rectangle& rect) {
        lx = max(lx, rect.lx);
        ly = max(ly, rect.ly);
        rx = min(rx, rect.rx);
        ry = min(ry, rect.ry);
    }
    bool is_valid() const {
        return rx >= lx && ry >= ly;
    }
    void print() const {
        // cout << lx << ' ' << ly << " -> " << rx << ' ' << ry << endl;
    }
};

const int maxn = 50000 + 10;

point p[maxn];
int n;

bool can_visit_all(long long dis) {
    rectangle r{p[0].x - dis, p[0].y - dis, p[0].x + dis, p[0].y + dis};
    repf (i, 1, n - 1) {
        r.extend(p[i].t - p[i - 1].t);
        r.intersect(rectangle{p[i].x - dis, p[i].y - dis, p[i].x + dis, p[i].y + dis});
        if (!r.is_valid()) {
            return false;
        }
    }
    return true;
}

long long get_mind() {
    sort(p, p + n);
    long long l = 0, r = (long long)4e9;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can_visit_all(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;
}

int main() {
    freopen ("starchaser.out", "w", stdout);
    repcase {
        scanf("%d", &n);
        rep (i, n) {
            p[i].input();
        }
        long long ret = get_mind();
        printf("Case #%d:\n", Case++);
        if (ret & 1) {
            printf("%lld/2\n", ret);
        } else {
            printf("%lld/1\n", ret >> 1);
        }
    }
    if (scanf ("%*s") != EOF) while(1);
    return 0;
}