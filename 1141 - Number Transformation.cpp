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
vector <int> edges[1010];
int level[1010];
bool visited[1010];

int prime[1000];
bool mark[1020];
int nprime=0;

void sieve(int n)
{
    int i,j,limit = sqrt(n)+2;

    mark[1] = 1;

    for(i=4;i<=n;i+=2) mark[i]=1;
    prime[++nprime]=2;
    for(i=3;i<=n;i++)
    {
        if(!mark[i])
        {
            prime[++nprime]=i;

            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}

void create_graph()
{
    for(int node=4; node<=1000; node++)
    {
        if(mark[node] == 0) continue;
        int t=0;
        int n = node;
        int s = sqrt(n)+1;
        int i = 1;
        while(prime[i]<=s && n != 1)
        {
            if(n%prime[i]==0)
            {
                if(t==0 && ((node+prime[i])<=1000))
                {
                    edges[node].push_back(node+prime[i]);
                    t = 1;
                }
                n=n/prime[i];
            }
            else {i++;t=0;}
        }
        if(n != 1 && ((node+n)<=1000)) edges[node].push_back(node+n);
    }
    return;
}


int bfs(int source, int des)
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
                if(edges[u][i] == des) return level[des];
                Q.push(edges[u][i]);
                visited[edges[u][i]] = 1;
            }
        }
    }
    return -1;
}

void show()
{
    for(int i=1; i<=1000; i++)
    {
        cout<<i<<"=";
        for(int j=0; j<edges[i].size();j++)
        {
            cout<<edges[i][j]<<",";
        }
        cout<<endl;
    }
    return;
}


int main()
{
    //Fin;
    //Fout;
    sieve(1010);
    create_graph();
    //show();
    //return 0;

    int tc, cn=0;
    int src,des;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&src,&des);
        if(src == des) {printf("Case %d: 0\n",++cn); continue;}
        if(mark[src]==0 || mark[des]==0 || src==1 || des<src) {printf("Case %d: -1\n",++cn); continue;}
        printf("Case %d: %d\n",++cn,bfs(src,des));
    }
    return 0;
}
