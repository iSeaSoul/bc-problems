#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#include <complex>
#define out(x) std::cout<<#x<<":"<<(x)<<std::endl
#define foreach(it,T) for(__typeof(T.begin()) it = T.begin(); it != T.end(); ++ it)
const double eps = 1e-8;
template<class T> int sgn (T x){ return (x > eps) - (x < -eps);}
int p[111];
bool ok (std::vector<int> &a, std::vector<int> &b){
    int n = a.size ();
    for (int i = 0; i < n; ++ i) 
        if (a[i] < b[i]) return 1;
        else if (a[i] > b[i]) return 0;
    return 0;
}
int main(){
    freopen ("iSea.in", "r", stdin);
    freopen ("iSea_test.out", "w", stdout);
    int T; scanf ("%d", &T);
    while (T--){
        int n, K;
        scanf ("%d%d", &n, &K);
        int r = -1;
        for (int i = 0; i < n; ++ i){
            scanf ("%d", &p[i]);
            if (p[i]) r = i;
        }
        if (r + 1 < K){
            for (int i = 1; i <= K; ++ i)
                printf ("%d%c", i, " \n"[i==K]);
            continue;
        }

        std::vector<int> v, tv;
        double pi = -1, s = 1;
        for (int i = 0; i <= r; ++ i){
            double tpi = p[i]/100.0, ts = (100.0 - p[i]) / p[i];
            tv.clear ();
            tv.push_back (p[i]);
            for (int num = 1, j = 0, k = r; num < K; ++ num){
                if (ts > 1){
                    if (j == i) ++ j;
                    tpi *= p[j] / 100.0; ts += (100.0 - p[j]) / p[j];
                    tv.push_back (p[j++]);
                } else{
                    if (k == i) -- k;
                    tpi *= p[k] / 100.0; ts += (100.0 - p[k]) / p[k];
                    tv.push_back (p[k--]);
                }
            }
            sort (tv.begin (), tv.end (), std::greater<int>());
            int tmp = sgn (tpi * ts - pi * s);
            if (tmp > 0) pi = tpi, s = ts, v = tv;
            else if (tmp == 0 && ok (v, tv)){
                pi = tpi; s = ts; v = tv;
            }
        }

        bool u = 0;
        if (r != n-1){
            double ans = 1;
            for (int i = 0; i < K-1; ++ i)
                ans *= p[i] / 100.0;
            if (sgn (ans - pi * s) >= 0){
                u = 1;
                printf ("%.10lf\n", ans);
                for (int i = 1; i <= K-1; ++ i)
                    printf ("%d ", i);
                printf ("%d\n", r+2);
            }
        }

        printf ("%.10lf\n", pi * s);

        if (!u){
            std::vector<int> ans;
            foreach (it, v){
                for (int i = 0; i < n; ++ i)
                    if (p[i] == (*it)){
                        ans.push_back (i+1), p[i] = -1; break;
                    }
            }
            bool tu = 0;
            std::sort (ans.begin (), ans.end ());
            foreach (it, ans){
                if (tu) printf (" "); tu = 1;
                printf ("%d", *it);
            }
            puts ("");
        }
    }
    return 0;
}