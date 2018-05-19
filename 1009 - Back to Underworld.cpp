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
vector <int> edge[100010];
int mark[20010];
int visited[20010];
int n;

int bfs(int source)
{
    int uu;
    int count1=0, count2=0;
    queue <int> Q;
    Q.push(source);
    visited[source] = 1;
    count1++;

    while(!Q.empty())
    {
        uu = Q.front();
        Q.pop();

        for(int i=0; i<edge[uu].size(); i++)
        {

            if(visited[edge[uu][i]]==0)
            {
                Q.push(edge[uu][i]);

                if(visited[uu] == 1)
                {
                    visited[edge[uu][i]] = 2;
                    count2++;
                }
                else if(visited[uu] == 2)
                {
                    visited[edge[uu][i]] = 1;
                    count1++;
                }

            }
        }
    }

    return max(count1,count2);
}

int main()
{
    int tc, cn=0;
    int x,y;
    scanf("%d",&tc);
    while(tc--)
    {
        //Reset
        for(int i=0; i<100010; i++) edge[i].clear();
        MS(mark,0);
        MS(visited,0);
        vector <int> node;


        scanf("%d",&n);
        for(int i=1 ; i<=n; i++)
        {
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
            if(mark[x]==0)
            {
                mark[x] = 1;
                node.push_back(x);
            }
            if(mark[y]==0)
            {
                mark[y] = 1;
                node.push_back(y);
            }
        }

        int ans = 0;
        for(int i=0; i< node.size(); i++)
        {
            if(visited[node[i]] == 0) ans = ans + bfs(node[i]);
        }
        printf("Case %d: %d\n",++cn,ans);
    }
    return 0;
}
