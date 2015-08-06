/**
 * @author - liyan30 @ 2015-04-26 11:55
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

const int inf = 1000000000;
const int maxn = 100 + 10;

struct graph {
    int c[maxn][maxn], w[maxn][maxn];
    int flow[maxn][maxn], pre[maxn], dist[maxn], n;

    void clear() {
        memset (w, 0, sizeof(w));
        memset (c, 0, sizeof(c));
        memset (flow, 0, sizeof(flow));
        n = 0;
    }
    void insert(int u, int v, int fw, int ct) {
        c[u][v] = fw;
        w[u][v] = ct; w[v][u] = -ct;
        n = max(n, max(u, v) + 1);
    }
    int eliminate() {
        while (1) {
            memset(dist, 0, sizeof(dist[0]) * n);
            memset(pre, -1, sizeof(pre[0]) * n);
            bool found = false;
            for (int k = 0; k < n; ++k) {
                bool changed = false;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (c[i][j] - flow[i][j] && dist[i] + w[i][j] > dist[j]) {
                            dist[j] = dist[i] + w[i][j];
                            pre[j] = i;
                            changed = true;
                        }
                    }
                }
                if (changed == false) {
                    break;
                }
                for (int i = 0; i < n; ++i) {
                    int v = i;
                    for (int cnt = 0; cnt < n; ++cnt) {
                        if (pre[v] == -1) {
                            break;
                        }
                        v = pre[v];
                    }
                    if (pre[v] != -1) {
                        int nowv = v;
                        while (c[pre[v]][v] - flow[pre[v]][v]) {
                            ++flow[pre[v]][v];
                            --flow[v][pre[v]];
                            v = pre[v];
                            if (v == nowv) {
                                break;
                            }
                        }
                        found = true;
                        break;
                    }
                }
                if (found == true) {
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (w[i][j] && c[i][j] && flow[i][j]) {
                    ans += w[i][j] * flow[i][j];
                }
            }
        }
        return ans;
    }
};

graph g;
int n, m, k, in_degree[maxn], out_degree[maxn];

int get_maxd() {
    int maxd = 0;
    int magic_node = 2 * n;
    rep (i, n) {
        to_max(maxd, abs(in_degree[i] - out_degree[i]));
        g.insert(i + n, i, inf, 0);
        g.insert(i + n, magic_node, 0, 0); 
        g.insert(magic_node, i, 0, 0); 
    }
    rep (i, maxd) {
        if (g.eliminate() >= k) {
            return i;
        }
        rep (i, n) {
            ++g.c[i + n][magic_node];
            ++g.c[magic_node][i];
        }
    }
    return maxd;
}

int get_id(const string& name, map<string, int>& id_map) {
    if (id_map.find(name) == id_map.end()) {
        int ret = SZ(id_map);
        return id_map[name] = ret;
    }
    return id_map[name];
}

int main() {
    // freopen ("balance.out", "w", stdout);
    repcase {
        scanf("%d%d%d", &n, &m, &k);
        memset(in_degree, 0, sizeof(in_degree));
        memset(out_degree, 0, sizeof(out_degree));

        map<string, int> id_map;
        g.clear();
        set<pair<int, int> > s;
        rep (i, m) {
            char buf1[22], buf2[22];
            scanf("%s%s", buf1, buf2);
            int foo = get_id(string(buf1), id_map);
            int bar = get_id(string(buf2), id_map);
            if (foo == bar) while(1);
            if (!s.insert(pair<int, int>(foo, bar)).second) {
                printf("Case #%d: failed!\n", Case);
                exit(-1);
            }
            ++in_degree[bar]; ++out_degree[foo];
            g.insert(foo, bar + n, 1, 1);
        }
        printf ("%d\n", get_maxd());
    }
    if (scanf ("%*s") != EOF) while(1);
    return 0;
}
