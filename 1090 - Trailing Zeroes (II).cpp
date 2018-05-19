#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007
#define pii pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define Set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int fact2[1000010];
int fact5[1000010];

int noz(int n, int p)
{
    int cnt=0;
    int temp;
    for(int i=p;;i*=p)
    {
        temp = (n/i);
        if(temp == 0) break;

        cnt+=temp;
    }
    return cnt;
}

int nop(int n, int p)
{
    int cnt=0;
    while(n%p == 0)
    {
        cnt++;
        n = n/p;
    }
    return cnt;
}

int main()
{
    FAST
    int tc, cn=0;
    int n,r,p,q;
    int ans;

    for(int i=0;i<=1000000;i++){
        fact2[i] = (noz(i,2));
        fact5[i] = (noz(i,5));
    }

    cin >> tc;

    while(tc--)
    {
        cin >>n>>r>>p>>q;

        int tw = fact2[n] - fact2[r] - fact2[n-r] + (q*nop(p,2));
        int fv = fact5[n] - fact5[r] - fact5[n-r] + (q*nop(p,5));

        ans = min(tw,fv);

        printf("Case %d: %d\n",++cn, ans);
    }

    return 0;
}
