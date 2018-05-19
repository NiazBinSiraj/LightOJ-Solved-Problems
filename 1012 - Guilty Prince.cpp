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
int fr[] = {1,-1,0,0};
int fc[] = {0,0,1,-1};
int r,c;
char cell[22][22];
int visited[22][22];
int cnt;

struct node{
    int row;
    int col;
};

void bfs(int sr, int sc)
{
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

            if(valid(nr,nc,r,c) && cell[nr][nc] == '.' && visited[nr][nc] == 0)
            {
                node t;
                t.row = nr;
                t.col = nc;

                Q.push(t);
                visited[nr][nc] = 1;
                cnt++;
            }
        }
    }
    return;
}


int main()
{
    //Fin;
    int tc, cn=0;
    int sr,sc;
    cin >> tc;
    while(tc--)
    {
        cnt = 1;
        MS(visited,0);
        MS(cell,0);

        scanf("%d%d",&c,&r);

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin >> cell[i][j];
                if(cell[i][j] == '@') {sr=i;sc=j;}
            }
        }
        bfs(sr,sc);

        printf("Case %d: %d\n",++cn, cnt);
    }
    return 0;
}
