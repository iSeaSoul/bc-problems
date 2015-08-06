/**
 * @author - liyan30 @ 2015-04-20 11:59
 * @brief - Simple recursion
 **/

#include <cstdio>

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

const int mod = 1000000007;
const int maxn = 1000000 + 10;

int m_mul(int x, int y) {
    return (long long)x * y % mod;
}

int m_add(int x, int y) {
    return (x + y) % mod;
}

int ans[maxn], n;

int main() {
    // freopen ("remove.out", "w", stdout);
    ans[1] = 1;
    ans[2] = 2;
    repf (i, 3, maxn - 1) {
        ans[i] = m_add(ans[i - 1], m_mul(i - 1, ans[i - 2]));
    }
    repcase {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}
