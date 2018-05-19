#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI acos(-1.0)
#define MOD 1000000007
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define Set(XX,PS) XX|(1<<PS)
#define reset(XX,PS) XX&(~(1<<PS))
#define toggle(XX,PS) (XX^(1<<PS))
#define check(XX,PS) (bool)(XX&(1<<PS))
#define SORT(v) sort(v.begin(),v.end())
#define REV(V) reverse(v.begin(),v.end())
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
vector <int,int> fg;

int main()
{
    FAST;
    //Fin;
    //Fout;

    int tc, cn=0;
    int n;
    cin >> tc;
    while(tc--)
    {
        cin >> n;

        vector <vector<int> > p;

        for(int i=0; i<n; i++)
        {
            int x,y;
            cin >> x >> y;
            vector <int> tmp;
            tmp.push_back(x);
            tmp.push_back(y);
            p.push_back(tmp);
        }
        sort(p.begin(),p.end());


        int cnt = 1;
        priority_queue<int, vector<int>, greater<int> > pqueue;
        pqueue.push(p[0][1]);

        for(int i=0; i<n-1; i++)
        {
            if(p[i+1][0] <= pqueue.top()){
                cnt++;
                pqueue.push(p[i+1][1]);
            }
            else{
                pqueue.pop();
                pqueue.push(p[i+1][1]);
            }
        }

        printf("Case %d: %d\n",++cn,cnt);
    }

    return 0;
}





//2nd Solution
/*
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI acos(-1.0)
#define MOD 1000000007
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define Set(XX,PS) XX|(1<<PS)
#define reset(XX,PS) XX&(~(1<<PS))
#define toggle(XX,PS) (XX^(1<<PS))
#define check(XX,PS) (bool)(XX&(1<<PS))
#define SORT(v) sort(v.begin(),v.end())
#define REV(V) reverse(v.begin(),v.end())
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
struct process{
    int start;
    int finish;
};

bool cmp(process a, process b) {return a.start < b.start;}

int main()
{
    FAST;
    //Fin;
    //Fout;

    process p[50010];
    int tc, cn=0;
    int n;
    cin >> tc;
    while(tc--)
    {
        cin >> n;

        for(int i=0; i<n; i++)
        {
            cin>>p[i].start>>p[i].finish;
        }

        sort(p,p+n,cmp);

        int cnt=1;
        priority_queue<int, vector<int>, greater<int> > pqueue;
        pqueue.push(p[0].finish);

        for(int i=0; i<n-1; i++)
        {
            if(p[i+1].start <= pqueue.top()){
                cnt++;
                pqueue.push(p[i+1].finish);
            }
            else{
                pqueue.pop();
                pqueue.push(p[i+1].finish);
            }
        }

        printf("Case %d: %d\n",++cn,cnt);
    }

    return 0;
}
*/
