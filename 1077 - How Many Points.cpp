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
template <class X>  X gcd(X a, X b)
{
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main()
{
    FAST
    //Fin;
    //Fout;

    LL tc, cn=0;
    LL Ax,Ay,Bx,By;

    cin >> tc;

    while(tc--)
    {
        LL ans = 1;
        cin>>Ax>>Ay>>Bx>>By;

        LL x,y;
        x = abs(Bx-Ax);
        y = abs(By-Ay);

        LL Hx = x;
        LL Hy = y;

        if(x==y) {ans = x+1; printf("Case %lld: %lld\n",++cn,ans); continue;}
        else if(y==0) {ans = x+1; printf("Case %lld: %lld\n",++cn,ans); continue;}
        else if(x==0) {ans = y+1; printf("Case %lld: %lld\n",++cn,ans); continue;}

        x = x/gcd(Hx,Hy);
        y = y/gcd(Hx,Hy);

        LL Tx,Ty;
        Tx = (x*Hy)/y;

        if(Tx<Hx) Hx = Tx;

        ans = ans + (Hx/x);

        printf("Case %lld: %lld\n",++cn,ans);
    }

    return 0;
}
