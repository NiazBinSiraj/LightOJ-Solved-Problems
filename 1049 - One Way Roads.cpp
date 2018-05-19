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
int edge[110];
int cost[110][110];
int seq[110][110];


int main()
{
    //Fin;
    //Fout;

    int tc, cn=0;
    int ans, tcost;
    int cst;
    scanf("%d",&tc);
    while(tc--)
    {
        ans = 0;
        tcost = 0;
        cst = 0;
        MS(cost,0);
        MS(edge,0);
        MS(seq,0);

        scanf("%d",&node);

        for(int i=0; i<node; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            tcost += z;
            seq[x][y]=z;
            if(edge[x]==0) {edge[x]=y; cost[x][y]=z;}
            else if(edge[y]==0) {edge[y]=x; cost[y][x]=0;}
            else
            {
                int t = edge[x];
                edge[x] = y;
                cost[x][y] = seq[x][y];

                x = x;
                y = t;
                while(1)
                {
                    if(edge[y]==0)
                    {
                        edge[y] = x;
                        cost[y][x] = seq[y][x];
                        break;
                    }
                    else
                    {
                        t = edge[y];
                        edge[y]=x;
                        cost[y][x]=seq[y][x];
                        x = y;
                        y = t;
                    }
                }
            }
        }

        for(int i=1; i<=node; i++)
        {
            cst = cst+cost[i][edge[i]];
            //cout<<i<<"->"<<edge[i]<<"->"<<cost[i][edge[i]]<<endl;
        }
        ans = min(cst,tcost-cst);

        printf("Case %d: %d\n",++cn, ans);
    }
    return 0;
}
