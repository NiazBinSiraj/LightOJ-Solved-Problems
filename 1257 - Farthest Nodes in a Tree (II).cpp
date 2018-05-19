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
int node;
vector <int> edges[30010];
vector <int> cost[30010];
int level[30010];
bool visited[30010];
int nlevel[30010];

void bfs(int source)
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
                level[edges[u][i]] = level[u]+cost[u][i];
                Q.push(edges[u][i]);
                visited[edges[u][i]] = 1;
            }
        }
    }
    return;
}


void nbfs(int source)
{
    MS(visited,0);
    MS(nlevel,0);

    queue <int> Q;
    nlevel[source] = 0;
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
                nlevel[edges[u][i]] = nlevel[u]+cost[u][i];
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
    int x,y,z;
    int ans;
    scanf("%d",&tc);

    while(tc--)
    {
        printf("Case %d:\n",++cn);

        for(int i=0; i<30010; i++)
        {
            edges[i].clear();
            cost[i].clear();
        }

        scanf("%d",&node);
        for(int i=0; i<node-1; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            edges[x].push_back(y);
            edges[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }

        bfs(0);
        int mx = level[0];
        int fnode1 = 0;
        for(int i=1; i<node; i++)
        {
            if(mx < level[i]) {mx = level[i]; fnode1 = i;}
        }
        bfs(fnode1);

        mx = level[0];
        int fnode2 = 0;
        for(int i=1; i<node; i++)
        {
            if(mx < level[i]) {mx = level[i]; fnode2 = i;}
        }
        nbfs(fnode2);


        for(int i=0; i<node; i++)
        {
            printf("%d\n",max(level[i],nlevel[i]));
        }
    }
    return 0;
}
