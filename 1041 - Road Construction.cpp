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
struct Node{
    int from;
    int to;
    int cost;
};
bool operator < (Node A, Node B) {return A.cost > B.cost;}

int node;
int sow; //Sum Of Weight of MST
bool taken[110];
vector <Node> adj[110];
map <string,int> s;
int hudai[110][110];
int tnode;


void PMST(int source)
{
    tnode=0;
    sow = 0;
    MS(taken,0);

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
    //Fout;

    int tc, cn=0, m;
    string x,y;
    int z;
    scanf("%d",&tc);
    while(tc--)
    {
        s.clear();
        node = 0;
        for(int i=0; i<110; i++) {adj[i].clear();}
        for(int i=0; i<110; i++)
        {
            for(int j=0; j<110; j++)
            {
                hudai[i][j] = INF;
            }
        }


        scanf("%d",&m);
        while(m--)
        {
            cin >>x>>y>>z;
            if(s[x] == 0) s[x] = ++node;
            if(s[y] == 0) s[y] = ++node;

            if(hudai[s[x]][s[y]] < z) continue;

            Node temp;
            temp.from = s[x];
            temp.to = s[y];
            temp.cost = z;
            adj[s[x]].push_back(temp);
            temp.from = s[y];
            temp.to = s[x];
            temp.cost = z;
            adj[s[y]].push_back(temp);
        }
        PMST(1);
        if(tnode == node) printf("Case %d: %d\n", ++cn, sow);
        else printf("Case %d: Impossible\n", ++cn);
    }
    return 0;
}
