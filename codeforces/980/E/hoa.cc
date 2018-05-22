#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
using namespace std;

#define prec setprecision

typedef long long ll;
typedef unsigned long long llu;
template<typename T> T gcd(T m, T n) {while(n) {T t=m%n; m=n;n=t;};return m;}
template<typename T> T exgcd(T a, T b, T& sa, T& ta) {T q, r, sb=0, tb=1, sc, tc; sa=1,ta=0; if(b) do q = a/b, r = a-q*b, a = b, b = r, sc = sa-q*sb, sa = sb, sb = sc, tc = ta-q*tb, ta = tb, tb = tc; while(b); return a; }
template<typename T> T mul_inv(T a, T b) { T t1 = a, t2 = b, t3; T v1 = 1, v2 = 0, v3; T x; while (t2 != 1) x = t1/t2, t3 = t1 - x*t2, v3 = v1 - x*v2, t1 = t2, t2 = t3, v1 = v2, v2 = v3; return (v2 + b) % b; }
template<typename T> T powmod(T a, T b, T MOD) {if (b < 0) return 0; T rv = 1; while (b) (b % 2) && (rv = (rv*a) % MOD), a = a*a%MOD, b /= 2; return rv;}

#ifndef ONLINE_JUDGE
#define DEBUG 0
#else
#define DEBUG 0
#endif

const int maxn = 1e6 + 7;

int n, k;

vector<int> adj[maxn];
int d[maxn];
bool removed[maxn];

int main(int argc, char *argv[]) {
    std::cin.sync_with_stdio(false);std::cin.tie(nullptr);
    #if DEBUG
    freopen("/tmp/in.txt", "r", stdin);
    while(cin >> n >> k)
    #else
    cin >> n >> k;
    #endif
    {
        #if DEBUG
        for(int i=1;i<=n;i++) adj[i].clear();
        memset(d, 0, sizeof(d));
        #endif
        for(int i=2;i<=n;i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            d[u] ++;
            d[v] ++;
        }
        
        set<int> Q;
        
        memset(removed, 0, sizeof(removed));
        for(int i=1;i<=n;i++) {
            if(d[i] == 1) Q.insert(i);
        }
        
        while(Q.size() > 0 && k-- > 0) {
            int to_remove = *Q.begin();
            removed[to_remove] = 1;
            Q.erase(to_remove);
            for(int v: adj[to_remove]) {
                d[v]--;
                if(d[v]==1) Q.insert(v);
            }
        }
        
        for(int i=1;i<=n;i++) if(removed[i]) cout << i << " "; cout << endl;
    }
    return 0;
}