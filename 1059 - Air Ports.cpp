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
int node, edge;
int sow;
int Acost;
bool taken[10010];
vector <Node> adj[10010];

void PMST(int source)
{
    sow = 0;

    taken[source] = 1;
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

        if(taken[u.to] || u.cost >= Acost) continue;

        taken[u.to] = 1;
        sow += u.cost;

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
    int tc, cn=0;
    int x,y,z;
    int Nairport;
    int ans;

    scanf("%d",&tc);
    while(tc--)
    {
        Nairport = 0;
        ans = 0;
        MS(taken,0);
        for(int i=0; i<10010; i++) {adj[i].clear();}

        scanf("%d%d%d",&node, &edge, &Acost);
        for(int i=0; i<edge; i++)
        {
            scanf("%d%d%d",&x,&y,&z);

            Node temp;

            temp.from = x;
            temp.to = y;
            temp.cost = z;
            adj[x].push_back(temp);
            temp.from = y;
            temp.to = x;
            temp.cost = z;
            adj[y].push_back(temp);
        }


        for(int i=1; i<=node; i++)
        {
            if(taken[i] == 0){
                PMST(i);
                Nairport++;
                ans += sow;
            }
        }
        ans = ans + (Nairport*Acost);
        printf("Case %d: %d %d\n",++cn,ans,Nairport);
    }
    return 0;
}
