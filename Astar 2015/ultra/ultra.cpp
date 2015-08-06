/**
 * @author - liyan30 @ 2015-04-20 16:47
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

const int mod = 1000000007;
const int maxn = 100000 + 10;
const int maxc = 26 + 2;

int m_mul(int x, int y) {
    return (long long)x * y % mod;
}

int m_add(int x, int y) {
    return (x + y) % mod;
}

char s[maxn];
int minlen[maxn], num[2][maxn];
int minpos[maxc], pow_26[maxn];

void solve() {
    static auto ch_id = [](char ch) { return ch - 'a'; };
    int len = strlen(s);
    fill (minpos, minpos + 26, len + 1);
    minlen[len + 1] = 0;
    num[0][len + 1] = 1;
    num[1][len + 1] = 0;
    for (int idx = len; idx >= 0; --idx) {
        minlen[idx] = len + 1;
        rep (ch_idx, 26) {
            // to_min(minlen[idx], minlen[minpos[ch_idx]] + 1);
            if (minlen[idx] > minlen[minpos[ch_idx]] + 1) {
                minlen[idx] = minlen[minpos[ch_idx]] + 1;
                num[0][idx] = num[0][minpos[ch_idx]];
            } else if (minlen[idx] == minlen[minpos[ch_idx]] + 1 && minpos[ch_idx] != len + 1) {
                num[0][idx] = m_add(num[0][idx], num[0][minpos[ch_idx]]);
            }
        }
        num[1][idx] = 0;
        rep (ch_idx, 26) {
            if (minlen[idx] == minlen[minpos[ch_idx]] && minlen[idx] >= 2) {
                num[0][idx] = m_add(num[0][idx], pow_26[minlen[idx] - 2]);
            }
            if (minlen[idx] == minlen[minpos[ch_idx]]) {
                num[1][idx] = m_add(num[1][idx], num[0][minpos[ch_idx]]);
            } else if (minlen[idx] == minlen[minpos[ch_idx]] + 1) {
                num[1][idx] = m_add(num[1][idx], num[1][minpos[ch_idx]]);
            }
        }
        if (idx > 0) {
            to_min(minpos[ch_id(s[idx - 1])], idx);
        }
    }
    int cnt = 0;
    rep (ch_idx, 26) {
        if (minlen[0] == minlen[minpos[ch_idx]]) {
            cnt = m_add(cnt, num[0][minpos[ch_idx]]);
        } else if (minlen[0] == minlen[minpos[ch_idx]] + 1) {
            cnt = m_add(cnt, num[1][minpos[ch_idx]]);
        }
    }
    cnt = (pow_26[minlen[0]] + mod - cnt) % mod;
    printf("%d %d\n", minlen[0], cnt);
}

int main() {
    // freopen ("ultra.out", "w", stdout);
    pow_26[0] = 1;
    repf (i, 1, maxn - 1) {
        pow_26[i] = m_mul(pow_26[i - 1], 26);
    }

    repcase {
        scanf("%s", s);
        solve();
    }
    return 0;
}