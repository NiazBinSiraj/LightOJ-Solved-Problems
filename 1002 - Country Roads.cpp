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
struct Node{
    int from;
    int to;
    int cost;
};
bool operator < (Node A, Node B) {return A.cost > B.cost;}

int node, m, t;
bool taken[510];
vector <Node> adj[510];
vector <Node> tree[510];
bool visited[510];
int cost[510];
int hudai[510][510];

void PMST(int source)
{
    //sow = 0;
    MS(taken,0);

    taken[source] = 1;
    priority_queue <Node> Q;

    Node temp;
    for(int i=0; i<adj[source].size();i++)
    {
        temp.from = source;
        temp.to = adj[source][i].to;
        temp.cost = adj[source][i].cost;
        Q.push(temp);
    }

    while(!Q.empty())
    {
        Node u = Q.top();
        Q.pop();
        if(taken[u.to]) continue;

        temp.from = u.from;
        temp.to = u.to;
        temp.cost = u.cost;
        tree[u.from].push_back(temp);
        temp.from = u.to;
        temp.to = u.from;
        temp.cost = temp.cost;
        tree[u.to].push_back(temp);
        taken[u.to] = 1;
        //sow += u.cost;

        for(int i=0; i<adj[u.to].size();i++)
        {
            if(taken[adj[u.to][i].to]) continue;

            temp.from = adj[u.to][i].from;
            temp.to = adj[u.to][i].to;
            temp.cost = adj[u.to][i].cost;
            Q.push(temp);
        }
    }
    return;
}


void bfs(int source)
{
    MS(visited,0);
    MS(cost,0);

    queue <int> Q;
    Q.push(source);
    visited[source] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<tree[u].size(); i++)
        {
            if(visited[tree[u][i].to]==0)
            {
                Q.push(tree[u][i].to);
                visited[tree[u][i].to] = 1;
                if(tree[u][i].cost > cost[u]) cost[tree[u][i].to] = tree[u][i].cost;
                else cost[tree[u][i].to] = cost[u];
            }
        }
    }
    return;
}


int main()
{
    Fin;
    Fout;
    int tc, cn=0;
    int x,y,z;
    scanf("%d", &tc);
    while(tc--)
    {
        for(int i=0; i<510; i++) {adj[i].clear(); tree[i].clear();}

        for(int i=0; i<510; i++)
        {
            for(int j=0; j<510; j++)
            {
                hudai[i][j] = INF;
            }
        }

        scanf("%d%d",&node, &m);
        for(int i=0; i<m ;i++)
        {
            Node temp;
            scanf("%d%d%d",&x,&y,&z);

            if(hudai[x][y] < z) continue;

            temp.from = x;
            temp.to = y;
            temp.cost = z;
            adj[x].push_back(temp);

            temp.from = y;
            temp.to = x;
            temp.cost = z;
            adj[y].push_back(temp);

            hudai[x][y] = z;
            hudai[y][x] = z;
        }
        scanf("%d", &t);
        PMST(t);
        bfs(t);

        printf("Case %d:\n",++cn);
        for(int i=0; i<node; i++)
        {
            if(visited[i] == 0) printf("Impossible\n");
            else printf("%d\n",cost[i]);
        }
    }
    return 0;
}
