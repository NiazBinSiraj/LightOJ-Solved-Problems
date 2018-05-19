#include <bits/stdc++.h>
//#include "custom.h"
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI acos(-1.0)
#define MOD 100000007LL
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define Set(XX,PS) XX|(1<<PS)
#define Reset(XX,PS) XX&(~(1<<PS))
#define Toggle(XX,PS) (XX^(1<<PS))
#define Check(XX,PS) (bool)(XX&(1<<PS))
#define SORT(v) sort(v.begin(),v.end())
#define REVERSE(V) reverse(v.begin(),v.end())
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define VALID(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define SIZE(ARRAY) sizeof(ARRAY)/sizeof(ARRAY[0])
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
struct topsort{
    int node;
    int ftime;

    topsort() {};
    topsort(int node_, int ftime_) {node = node_; ftime = ftime_;}
};
bool compare(topsort A, topsort B) {return A.ftime < B.ftime;}

int node, edge, from, to;
vector <int> adj[10010];
char color[10010];
int d[10010];
int f[10010];
int tme;

void dfs(int source)
{
    color[source] = 'G';
    tme++;
    d[source] = tme;

    for(int i=0; i<adj[source].size(); i++)
    {
        if(color[adj[source][i]] == 'W') dfs(adj[source][i]);
    }

    color[source] = 'B';
    tme++;
    f[source] = tme;
    return;
}


int main()
{
    FAST;
    int tc, cn=0;
    cin >> tc;

    while(tc--)
    {
        tme = 0;
        for(int i=0; i<10010; i++)
        {
            adj[i].clear();
            color[i] = 'W';
            d[i] = -1;
            f[i] = -1;
        }

        cin >> node >> edge;

        for(int i=0; i<edge; i++)
        {
            cin >> from >> to;
            adj[from].push_back(to);
        }

        for(int i=1; i<=node; i++)
        {
            if(color[i]=='W') dfs(i);
        }

        vector <topsort> nodes;
        for(int i=1; i<=node; i++)
        {
            nodes.push_back(topsort(i,f[i]));
        }
        sort(nodes.begin(), nodes.end(), compare);

        int tme=0;
        int ans = 0;
        for(int i=0; i<= node; i++)
        {
            color[i] = 'W';
            d[i] = -1;
            f[i] = -1;
        }

        for(int i=node-1; i>=0; i--)
        {
            if(color[nodes[i].node]=='W') {ans++; dfs(nodes[i].node);}
        }

        if(ans==0) ans++;
        printf("Case %d: %d\n", ++cn, ans);

    }
    return 0;
}
