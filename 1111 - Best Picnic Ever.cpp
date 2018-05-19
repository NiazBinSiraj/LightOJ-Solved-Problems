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
vector <int> edges[1010];
bool visited[1010];
bool cvis[1010];
int ans;
int tc, cn=0;


void bfs(int source)
{
    MS(visited,0);
    ans = 0;


    queue <int> Q;
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
                Q.push(edges[u][i]);
                visited[edges[u][i]] = 1;

            }
        }
    }

    for(int i=1; i<=node; i++)
    {
        if(cvis[i] == 0 && visited[i] == 1) ans++;
        else cvis[i] = 1;
    }
    return;
}

int main()
{
    //Fin;
    //Fout;
    int K, src[110];
    scanf("%d\n",&tc);

    while(tc--)
    {
        ans = 0;
        MS(cvis,0);
        MS(src,0);
        for(int i=0; i<1010; i++) edges[i].clear();

        scanf("%d%d%d",&K,&node, &edge);
        for(int i=0; i<K; i++) scanf("%d",&src[i]);
        for(int i=0; i<edge; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            edges[x].push_back(y);
        }

        for(int i=0; i<K; i++)
        {
            bfs(src[i]);
        }

        printf("Case %d: %d\n",++cn, ans);
    }
    return 0;
}
