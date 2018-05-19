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

int node;
vector <int> adj[50010];
int visited[50010];
int level[50010];
int parent[50010];


void bfs(int source, int des)
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
        if(u == des) return;
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            if(visited[adj[u][i]]==0)
            {
                level[adj[u][i]] = level[u]+1;
                Q.push(adj[u][i]);
                parent[adj[u][i]] = u;
                visited[adj[u][i]] = 1;
            }
        }
    }
    return;
}


void print(int node)
{
    if(parent[node] == node)
    {
        printf("%d",node);
        return;
    }
    print(parent[node]);
    printf(" %d",node);
}



int main()
{
    //Fin;
    //Fout;

    int tc, cn=0;
    int src,des;
    int city;
    int x,y;
    scanf("%d",&tc);

    while(tc--)
    {
        for(int i=0; i<50010; i++) adj[i].clear();

        scanf("%d", &node);
        for(int i=1; i<=node; i++)
        {
            scanf("%d",&city);

            if(i==1) {src = city; x = city;}
            else
            {
                des = city;
                y = city;
                adj[x].push_back(y);
                adj[y].push_back(x);
                x = y;
            }
        }

        for(int i=0; i<50010; i++)
        {
            sort(adj[i].begin(), adj[i].end());
            parent[i] = i;
        }

        bfs(src,des);
        printf("Case %d:\n",++cn);
        print(des);
        printf("\n");
    }
    return 0;
}
