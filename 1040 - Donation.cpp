#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PINF INT_MAX
#define NINF INT_MIN
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

int node;
int sow; //Sum Of Weight of MST
bool taken[55];
vector <Node> adj[55];
int hudai[55][55];
int tnode;


void PMST(int source)
{
    sow = 0;
    MS(taken,0);
    tnode = 0;

    taken[source] = 1;
    tnode++;
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

        temp.from = u.to;
        temp.to = u.from;
        temp.cost = temp.cost;

        taken[u.to] = 1;
        sow += u.cost;
        tnode++;

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

int main()
{
    //Fin;
    int tc, cn=0;
    int z;
    int sum;
    int sw;
    int src;
    scanf("%d",&tc);
    while(tc--)
    {
        sum = 0;
        src = 0;
        sw = 0;
        for(int i=0; i<55; i++) {adj[i].clear();}
        for(int i=0; i<55; i++)
        {
            for(int j=0; j<55; j++)
            {
                hudai[i][j] = PINF;
            }
        }

        scanf("%d",&node);
        for(int x=0; x<node; x++)
        {
            for(int y=0; y<node; y++)
            {
                scanf("%d",&z);
                sum += z;

                if(x==y) continue;
                if(z > hudai[x][y]) continue;
                if(z == 0) continue;


                Node temp;
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
                if(sw == 0) {src = x; sw = 1;}
            }
        }
        PMST(src);
        if(tnode == node) printf("Case %d: %d\n", ++cn, sum-sow);
        else printf("Case %d: -1\n", ++cn);
    }
    return 0;
}
