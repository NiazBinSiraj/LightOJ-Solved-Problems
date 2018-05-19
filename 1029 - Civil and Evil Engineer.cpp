#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define P_INF INT_MAX
#define N_INF INT_MIN
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
struct MinNode{
    int from;
    int to;
    int cost;
};
bool operator < (MinNode A, MinNode B) {return A.cost > B.cost;}

struct MaxNode{
    int from;
    int to;
    int cost;
};
bool operator < (MaxNode A, MaxNode B) {return A.cost < B.cost;}


int node;
int Min_sow, Max_sow;
bool taken[110];
int Max_hudai[110][110];
int Min_hudai[110][110];
vector <MinNode> Min_adj[110];
vector <MaxNode> Max_adj[110];


void PMinST(int source)
{
    Min_sow = 0;
    MS(taken,0);

    taken[source] = 1;
    priority_queue <MinNode> Q;

    MinNode temp;
    for(int i=0; i<Min_adj[source].size();i++)
    {
        temp.from = source;
        temp.to = Min_adj[source][i].to;
        temp.cost = Min_adj[source][i].cost;
        Q.push(temp);
    }

    while(!Q.empty())
    {
        MinNode u = Q.top();
        Q.pop();

        if(taken[u.to]) continue;

        temp.from = u.from;
        temp.to = u.to;
        temp.cost = u.cost;

        temp.from = u.to;
        temp.to = u.from;
        temp.cost = temp.cost;

        taken[u.to] = 1;
        Min_sow += u.cost;

        for(int i=0; i<Min_adj[u.to].size();i++)
        {
            if(taken[Min_adj[u.to][i].to]) continue;

            temp.from = Min_adj[u.to][i].from;
            temp.to = Min_adj[u.to][i].to;
            temp.cost = Min_adj[u.to][i].cost;
            Q.push(temp);
        }
    }
    return;
}


void PMaxST(int source)
{
    Max_sow = 0;
    MS(taken,0);

    taken[source] = 1;
    priority_queue <MaxNode> Q;

    MaxNode temp;
    for(int i=0; i<Max_adj[source].size();i++)
    {
        temp.from = source;
        temp.to = Max_adj[source][i].to;
        temp.cost = Max_adj[source][i].cost;
        Q.push(temp);
    }

    while(!Q.empty())
    {
        MaxNode u = Q.top();
        Q.pop();

        if(taken[u.to]) continue;

        temp.from = u.from;
        temp.to = u.to;
        temp.cost = u.cost;

        temp.from = u.to;
        temp.to = u.from;
        temp.cost = temp.cost;

        taken[u.to] = 1;
        Max_sow += u.cost;

        for(int i=0; i<Max_adj[u.to].size();i++)
        {
            if(taken[Max_adj[u.to][i].to]) continue;

            temp.from = Max_adj[u.to][i].from;
            temp.to = Max_adj[u.to][i].to;
            temp.cost = Max_adj[u.to][i].cost;
            Q.push(temp);
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
    scanf("%d",&tc);

    while(tc--)
    {
        for(int i=0; i<110; i++) {Min_adj[i].clear(); Max_adj[i].clear();}
        for(int i=0; i<110; i++)
        {
            for(int j=0; j<110; j++)
            {
                Max_hudai[i][j] = N_INF;
                Min_hudai[i][j] = P_INF;
            }
        }

        scanf("%d",&node);
        while(scanf("%d%d%d",&x,&y,&z)==3)
        {
            if(x==0 && y==0 && z==0) break;

            if(Min_hudai[x][y] > z)
            {
                MinNode temp;

                temp.from = x;
                temp.to = y;
                temp.cost = z;
                Min_adj[x].push_back(temp);

                temp.from = y;
                temp.to = x;
                temp.cost = z;
                Min_adj[y].push_back(temp);

                Min_hudai[x][y] = z;
                Min_hudai[y][x] = z;
            }

            if(Max_hudai[x][y] < z)
            {
                MaxNode temp;

                temp.from = x;
                temp.to = y;
                temp.cost = z;
                Max_adj[x].push_back(temp);

                temp.from = y;
                temp.to = x;
                temp.cost = z;
                Max_adj[y].push_back(temp);

                Max_hudai[x][y] = z;
                Max_hudai[y][x] = z;
            }
        }
        PMaxST(0);
        PMinST(0);
        int ans = Max_sow + Min_sow;
        if(ans%2 == 0) printf("Case %d: %d\n",++cn,ans/2);
        else printf("Case %d: %d/2\n",++cn,ans);
    }
    return 0;
}
