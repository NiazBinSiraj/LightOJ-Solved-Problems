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
int r,c;
int ar,ac,br,bc,cr,cc,hr,hc;
char cell[22][22];
int fr[] = {1,-1,0,0};
int fc[] = {0,0,1,-1};
int level[22][22];
bool visited[22][22];

struct node{
    int row;
    int col;
};

int bfs(int sr, int sc, int dr, int dc)
{
    MS(level,0);
    MS(visited,0);

    node n;
    n.row = sr;
    n.col = sc;
    queue <node> Q;

    level[sr][sc] = 0;
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

            if(valid(nr,nc,r,c) && cell[nr][nc] != '#' && cell[nr][nc] != 'm' && visited[nr][nc] == 0)
            {
                node t;
                t.row = nr;
                t.col = nc;

                Q.push(t);
                level[nr][nc] = level[u.row][u.col]+1;
                visited[nr][nc] = 1;
            }
        }
    }
    return level[dr][dc];
}


int main()
{
    int tc, cn=0;
    int ans;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d%d",&r,&c);
        ans = 0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin >> cell[i][j];
                if(cell[i][j] == 'a') {ar=i;ac=j;}
                else if(cell[i][j] == 'b') {br=i;bc=j;}
                else if(cell[i][j] == 'c') {cr=i;cc=j;}
                else if(cell[i][j] == 'h') {hr=i;hc=j;}
            }
        }

        ans = max(max(bfs(ar,ac,hr,hc), bfs(br,bc,hr,hc)), bfs(cr,cc,hr,hc));
        printf("Case %d: %d\n", ++cn, ans);
    }

    return 0;
}
