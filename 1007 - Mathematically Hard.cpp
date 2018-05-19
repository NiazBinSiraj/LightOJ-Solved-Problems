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
int phi[5000010];
unsigned LL res[5000010];


void phiSieve(int n)
{
    for(int i=1; i<=n; i++) phi[i]=i;
    phi[1] = 1;
    res[1] = 1;

    for(int i=2; i<=n ;i++)
    {
        if(!res[i])
        {
            for(int j=i; j<=n; j+=i)
            {
                res[j]=1;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
    return;
}

void score()
{
    res[1]=1;
    for(int i=2;i<=5000000;i++)
    {
        LL tmp = phi[i];
        res[i] = res[i-1]+(tmp*tmp);
    }
    return;
}

int main()
{
    phiSieve(5000000);
    score();
    int tc=100000, cn=0;
    int a,b;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&a,&b);
        printf("Case %d: %llu\n",++cn,res[b]-res[a-1]);
    }
    return 0;
}
