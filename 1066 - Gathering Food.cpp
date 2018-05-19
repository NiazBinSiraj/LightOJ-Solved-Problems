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
struct node{
    int row;
    int col;
};

int fr[] = {1,-1,0,0};
int fc[] = {0,0,1,-1};
int rc;
char cell[12][12];
int food;
int ans;
int level[100][100];
bool visited[100][100];

int bfs(int sr, int sc, int dr, int dc)
{
    MS(visited,0);
    MS(level,0);

    cell[sr][sc] = '.';
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

            if(valid(nr,nc,rc,rc) && (cell[nr][nc] == '.' || cell[nr][nc] == cell[dr][dc]) && visited[nr][nc] == 0)
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
    if(visited[dr][dc] == 1) {cell[dr][dc] = '.'; return level[dr][dc];}
    else return -1;
}


int main()
{
    node src[100];
    int tc, cn=0;
    scanf("%d",&tc);
    while(tc--)
    {
        food = 0;
        ans = 0;

        scanf("%d",&rc);

        for(int i=0; i<rc;i++)
        {
            for(int j=0; j<rc; j++)
            {
                cin >> cell[i][j];
                if(cell[i][j] >= 'A' && cell[i][j] <= 'Z'){
                    food++;
                    src[cell[i][j]].row = i;
                    src[cell[i][j]].col = j;
                }
            }
        }

        for(int i='A'; i< 'A'+food-1; i++)
        {
            int temp = bfs(src[i].row, src[i].col, src[i+1].row, src[i+1].col);
            if(temp == -1){
                ans = -1;
                break;
            }
            else ans = ans + temp;
        }
        if(ans == -1) printf("Case %d: Impossible\n",++cn);
        else printf("Case %d: %d\n",++cn,ans);
    }
    return 0;
}
