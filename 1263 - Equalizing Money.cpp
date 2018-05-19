#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF INT_MAX
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007
#define ck(XX) cout<<XX<<endl
#define set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int node, edge;
vector <int> adj[1010];
int money[1010];
bool visited[1010];
int tnode, tsum;


void bfs(int source)
{
    tnode = 0;
    tsum = 0;

    queue <int> Q;
    Q.push(source);
    visited[source] = 1;
    tnode++;
    tsum += money[source];

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            if(visited[adj[u][i]] == 1) continue;

            visited[adj[u][i]] = 1;
            tnode++;
            tsum += money[adj[u][i]];
            Q.push(adj[u][i]);
        }
    }
    return;
}


int main()
{
    //Fin;
    //Fout;

    int tc, cn=0;
    scanf("%d",&tc);

    while(tc--)
    {
        MS(money,0);
        MS(visited,0);
        for(int i=0; i<1010; i++) adj[i].clear();

        scanf("%d%d",&node,&edge);
        for(int i=1; i<=node; i++) scanf("%d",&money[i]);
        for(int i=0; i<edge; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int ans = 0;
        int trig = 0;
        for(int i=1; i<=node; i++)
        {
            if(visited[i]==1) continue;

            bfs(i);

            if(tsum%tnode != 0) {trig = 1; break;}
            if(tsum%tnode == 0)
            {
                if(i==1) ans = tsum/tnode;

                else if(ans != tsum/tnode) {trig = 1; break;}
            }
        }

        if(trig == 1) printf("Case %d: No\n",++cn);

        else printf("Case %d: Yes\n",++cn);
    }
    return 0;
}
