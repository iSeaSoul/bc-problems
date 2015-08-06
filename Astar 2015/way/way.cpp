/**
 * @author - liyan30 @ 2015-06-03 12:15
 * @brief - 
 **/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>

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

const int maxn = 52;
const int maxl = 6;
const string fail_string = "Tough way!";

struct node {
    string s;
    int x;

    node(int _x, string _s): x(_x), s(_s) {
    }
    bool operator<(const node& e) const {
        return s > e.s;
    }
};

bool mat[maxn][maxn], vis[maxn];
vector<node> graph[maxn];
int n, a, s, g;

void dfs(int x) {
    if (vis[x]) {
        return ;
    }
    vis[x] = true;
    rep (i, n) {
        if (mat[x][i]) {
            dfs(i);
        }
    }
}

string solve() {
    dfs(g);
    if (!vis[s]) {
        return fail_string;
    }

    priority_queue<node> pq;
    set<string> hash[maxn];

    pq.push(node(s, ""));
    while (!pq.empty()) {
        node cur = pq.top(); 
        if (cur.x == g || SZ(cur.s) > maxl * n) {
            return cur.x == g && SZ(cur.s) <= maxl * n? cur.s : fail_string;
        }
        pq.pop();
        for (vector<node>::iterator it = graph[cur.x].begin(); it != graph[cur.x].end(); ++it) {
            if (vis[it->x]) {
                string news = cur.s + it->s;
                if (hash[it->x].insert(news).second) {
                    pq.push(node(it->x, news));
                }
            }
        }
    }
    return fail_string;
}

int main() {
    freopen ("input", "r", stdin);
    // freopen ("output", "w", stdout);
    repcase {
        scanf ("%d%d%d%d", &n, &a, &s, &g);
        memset(mat, 0, sizeof(mat));
        memset(vis, 0, sizeof(vis));
        rep (i, n) {
            graph[i].clear();
        }
        rep (i, a) {
            int u, v;
            char buf[8];
            scanf ("%d%d%s", &u, &v, buf);
            if (strlen(buf) > 6) {
                printf("Case #%d: failed\n", Case);
                exit(-1);
            }
            graph[u].push_back(node(v, string(buf)));
            mat[v][u] = true;
        }
        printf("Case #%d:\n", Case++);
        puts(solve().c_str());
    }
    if (scanf("%*s") != EOF) while(true);
    return 0;
}