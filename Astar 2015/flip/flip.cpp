/**
 * @author - liyan30 @ 2015-04-26 17:52
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

typedef bitset<256> equation;

const int maxn = 256;

equation eqpre[maxn], eqnow[maxn], eqtmp[maxn];
vector<equation> pro;
char s[maxn][maxn];
bool broken[maxn][maxn];
int n, m, k;

bool solve() {
    rep (i, m) {
        repf (j, i + 1, SZ(pro) - 1) {
            if (!pro[j].test(i)) {
                continue;
            }
            if (!pro[i].test(i)) {
                swap(pro[i], pro[j]);
            } else {
                pro[j] ^= pro[i];
            }
        }
    }
    rep (i, SZ(pro)) {
        bool allzero = true;
        rep (j, m) {
            if (pro[i].test(j)) {
                allzero = false;
            }
        }
        if (allzero && pro[i].test(m)) {
            return false;
        }
    }
    return true;
}

int main() {
    // freopen ("flip.out", "w", stdout);
    
    repcase {
        scanf("%d%d%d", &n, &m, &k);
        memset(broken, 0, sizeof(broken));
        rep (i, n) {
            scanf("%s", s[i]);
        }
        rep (i, k) {
            int a, b;
            scanf("%d%d", &a, &b);
            broken[--a][--b] = true;
        }
        rep (i, m) {
            eqnow[i].reset();
            eqnow[i].set(i);
        }
        pro.clear();
        rep (i, n) {
            rep (j, m) {
                eqtmp[j] = eqnow[j];
                if (i) eqtmp[j] ^= eqpre[j];
                if (j) eqtmp[j] ^= eqnow[j - 1];
                if (j < m - 1) eqtmp[j] ^= eqnow[j + 1];
                if (s[i][j] == 'B') {
                    eqtmp[j].flip(m);
                }
                if (broken[i][j]) {
                    pro.push_back(eqnow[j]);
                }
            }
            rep (j, m) {
                eqpre[j] = eqnow[j];
                eqnow[j] = eqtmp[j];
            }
        }
        rep (j, m) {
            pro.push_back(eqnow[j]);
        }
        puts(solve()? "YES" : "NO");
    }
    return 0;
}