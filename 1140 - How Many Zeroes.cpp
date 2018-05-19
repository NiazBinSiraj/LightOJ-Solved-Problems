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
LL ipow(LL base, LL exp)
{
    LL result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

LL nod(LL n)
{
    if(n==0) return 1;
    LL cnt=0;
    while(n != 0)
    {
        cnt++;
        n = n/10;
    }
    return cnt;
}

LL dp[10];

void initialize()
{
    dp[1] = 1;
    LL mul = 9;
    for(LL i=2; i<10; i++)
    {
        dp[i] = dp[i-1] + ((i-1)*mul);
        mul = mul*10;
    }
    return;
}


LL noz(LL n)
{
    LL digit = nod(n)-1;
    if(digit <= 0) return 1;
    LL temp = n-ipow(10LL,digit);

    return dp[digit] + noz(temp) + digit - nod(temp);
}

bool all9(LL n)
{
    while(n != 0)
    {
        if(n%10 != 9) return 0;
        n = n/10;
    }
    return 1;
}

int main()
{
    FAST
    LL tc, cn=0;
    LL m,n;
    initialize();

    cin >> n;
    if(all9(n) == 1) cout<<dp[nod(n)]<<endl;
    else cout<<noz(n)<<endl;



    /*cin >> tc;

    while(tc--)
    {
        cin >> m >> n;
        LL low, up;

        low = noz(m);
        up = noz(n);

        LL ans = up-low;
        printf("Case %lld: %lld\n", ++cn, ans);
    }*/

    return 0;
}
