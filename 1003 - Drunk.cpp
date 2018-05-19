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

vector <int> adj[10010];
char color[10010];
bool is_cyclic;
bool visited[10010];

void dfs(int source)
{
    color[source] = 'G';
    visited[source] = 1;

    for(int i=0; i<adj[source].size(); i++)
    {
        if(color[adj[source][i]] == 'G') is_cyclic = true;
        else if(color[adj[source][i]] == 'W')  dfs(adj[source][i]);
    }

    color[source] = 'B';
    return;
}

int main()
{
    //FAST;

    int tc, cn=0;
    int m;
    string from, to;

    cin >> tc;

    while(tc--)
    {
        is_cyclic = false;
        for(int i=0; i<10010; i++) {adj[i].clear(); color[i]='W';visited[i]=0;}

        map <string,int> stoi;
        int cnt=1;

        cin >> m;
        for(int i=1; i<=m; i++)
        {
            cin >> from >> to;


            if(stoi.find(from) == stoi.end()){
            stoi[from] = cnt;
            cnt++;
            }

            if(stoi.find(to) == stoi.end()){
            stoi[to] = cnt;
            cnt++;
            }

            adj[stoi[from]].push_back(stoi[to]);
        }

        for(int i=1; i<cnt; i++)
        {
            if(visited[i]==0) dfs(i);
            if(is_cyclic == true) break;
        }

        if(is_cyclic == true) printf("Case %d: No\n",++cn);
        else printf("Case %d: Yes\n", ++cn);
    }
    return 0;
}
