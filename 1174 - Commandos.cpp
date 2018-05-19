#include <bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define pii pair<int,int>
int node, edge;
vector <int> edges[110];
int level[110];
int dlevel[110];
bool visited[110];

void sbfs(int source)
{
    MS(visited,0);
    MS(level,0);

    queue <int> Q;
    level[source] = 0;
    Q.push(source);
    visited[source] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<edges[u].size(); i++)
        {
            if(visited[edges[u][i]]==0)
            {
                level[edges[u][i]] = level[u]+1;
                Q.push(edges[u][i]);
                visited[edges[u][i]] = 1;
            }
        }
    }

    return;
}

void dbfs(int source)
{
    MS(visited,0);
    MS(dlevel,0);

    queue <int> Q;
    dlevel[source] = 0;
    Q.push(source);
    visited[source] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<edges[u].size(); i++)
        {
            if(visited[edges[u][i]]==0)
            {
                dlevel[edges[u][i]] = dlevel[u]+1;
                Q.push(edges[u][i]);
                visited[edges[u][i]] = 1;
            }
        }
    }

    return;
}


int main()
{
    //Fin;
    //Fout;
    int tc, cn=0;
    int src, des;
    int x,y;
    int ans;
    scanf("%d",&tc);
    while(tc--)
    {
        ans = -1;

        for(int i=0; i<110; i++) edges[i].clear();

        scanf("%d",&node);
        scanf("%d",&edge);

        for(int i=0; i<edge; i++)
        {
            scanf("%d%d",&x,&y);
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        scanf("%d%d",&src, &des);

        sbfs(src);
        dbfs(des);

        for(int i=0; i<node; i++)
        {
            ans = max(ans,level[i]+dlevel[i]);
        }

        printf("Case %d: %d\n",++cn, ans);
    }
    return 0;
}
