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
int fr[] = {1,-1,0,0};
int fc[] = {0,0,1,-1};
int r,c;
char cell[510][510];
bool visited[510][510];
int ans[510][510];

struct node{
    int row;
    int col;
};

int bfs(int sr, int sc)
{
    MS(visited,0);
    int cnt = 0;
    node n;
    n.row = sr;
    n.col = sc;
    queue <node> Q;

    visited[sr][sc] = 1;
    Q.push(n);

    while(!Q.empty())
    {
        node u = Q.front();
        Q.pop();

        for(int i=0; i<4; i++)
        {
            int nr=u.row+fr[i];
            int nc=u.col+fc[i];

            if(valid(nr,nc,r,c) && cell[nr][nc] != '#' && visited[nr][nc] == 0)
            {
                if(cell[nr][nc] == 'C') cnt++;

                node t;
                t.row = nr;
                t.col = nc;

                Q.push(t);
                visited[nr][nc] = 1;
            }
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(visited[i][j] == 1) ans[i][j] = cnt;
        }
    }

    return cnt;
}



int main()
{
    //Fin;
    //Fout;

    int tc, cn=0;
    int q;
    scanf("%d",&tc);
    while(tc--)
    {
        MS(ans, -1);
        printf("Case %d:\n",++cn);
        scanf("%d%d%d",&r,&c,&q);
        for(int i=0; i<r; i++) scanf("%s",cell[i]);

        for(int i=1; i<=q; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(ans[x-1][y-1] != -1) printf("%d\n", ans[x-1][y-1]);
            else printf("%d\n",bfs(x-1,y-1));
        }
    }
    return 0;
}
