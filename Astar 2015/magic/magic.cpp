/**
 * @author - liyan30 @ 2015-05-14 13:49
 * @brief - From sky to the sea.
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

const long long com = 1000000LL;

int main() {
    // freopen ("magic.out", "w", stdout);

    long long pow10[12] = {1};
    repf (len, 1, 9) {
        pow10[len] = pow10[len - 1] * 10;
    }

    repcase {
        double p;
        scanf("%lf", &p);
        long long int_p = (long long)(p * com + 1e-8);
        vector<long long> ret;

        if (int_p > com) {
            long long denominator = int_p - com;
            repf (len, 1, 9) rep (last, 10) rep (first, last) {
                if (first == 0) continue;
                long long numerator = (last - first) * (pow10[len] - 1);
                numerator *= com;
                if (numerator % denominator == 0) {
                    long long alter_res = numerator / denominator;
                    if (alter_res % 10 == last && alter_res / pow10[len] == first) {
                        ret.push_back(alter_res);
                    }
                }
            }
        } else if (int_p < com) {
            long long denominator = com - int_p;
            repf (len, 1, 9) rep (first, 10) rep (last, first) {
                if (first == 0) continue;
                long long numerator = (first - last) * (pow10[len] - 1);
                numerator *= com;
                if (numerator % denominator == 0) {
                    long long alter_res = numerator / denominator;
                    if (alter_res % 10 == last && alter_res / pow10[len] == first) {
                        ret.push_back(alter_res);
                    }
                }
            }
        } else {
            while(true);
        }

        sort(ret.begin(), ret.end());
        printf("Case #%d:\n%d\n", Case++, SZ(ret));
        rep (i, SZ(ret)) {
            printf("%lld%c", ret[i], " \n"[i == SZ(ret) - 1]);
        }
    }
    return 0;
}