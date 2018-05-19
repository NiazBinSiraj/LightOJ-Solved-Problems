#include <bits/stdc++.h>
//#include "custom.h"
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI acos(-1.0)
#define MOD 100000007LL
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define ck2(XX,YY) cout<<XX<<"->"<<YY<<endl;
#define Set(XX,PS) XX|(1<<PS)
#define Reset(XX,PS) XX&(~(1<<PS))
#define Toggle(XX,PS) (XX^(1<<PS))
#define Check(XX,PS) (bool)(XX&(1<<PS))
#define SORT(v) sort(v.begin(),v.end())
#define REVERSE(V) reverse(v.begin(),v.end())
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define VALID(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define SIZE(ARRAY) sizeof(ARRAY)/sizeof(ARRAY[0])
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

class Euclid {
public:
    long long x, y, d;
    Euclid() {}
    Euclid(long long _x, long long _y, long long _d) : x(_x), y(_y), d(_d) {}
};

Euclid egcd(long long a, long long b) {
    if(!b) return Euclid(1, 0, a);
    Euclid r = egcd(b, a % b);
    return Euclid(r.y, r.x - a / b * r.y, r.d);
}

long long ModInverse(long long a, long long n) {
    Euclid t = egcd(a, n);
    if(t.d > 1) return 0;
    long long r = t.x % n;
    return (r < 0 ? r + n : r);
}

LL bigmod(LL a, LL b, LL M)
{
    if(b == 0) return 1 % M;
    LL x = bigmod(a, b/2, M);
    x = (x*x)%M;
    if(b%2 == 1) x = (x*a)%M;
    return x;
}


int main()
{
    FAST;
    //Fout;
    LL tc, cn=0LL;
    LL t = ceil(sqrt((double)(MOD)));

    LL k,result;
    LL n;

    cin >> tc;

    while(tc--)
    {
        vector <LL> baby;
        map <LL,LL> ai;

        cin>>k>>result;

        baby.push_back(1LL);
        ai[1LL] = 0LL;
        for(LL i=1LL; i<t; i++)
        {
            LL temp = ((k%MOD)*(baby[i-1LL]%MOD))%MOD;
            baby.push_back(temp);
            ai[temp] = i;
        }

        SORT(baby);

        LL kt = bigmod(ModInverse(k,MOD),t,MOD);


        for(LL j=0LL; j<t; j++)
        {
            if(binary_search(baby.begin(),baby.end(),result) == true)
            {
                n = ai[result]+j*t;
                break;
            }

            result = (result*kt)%MOD;
        }
        printf("Case %lld: %lld\n", ++cn, n%MOD);
    }
    return 0;
}
