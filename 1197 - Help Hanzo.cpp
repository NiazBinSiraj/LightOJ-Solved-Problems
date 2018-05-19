#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int prime[6200];
bool mark[60040];
bool smark[300020];
vector <LL> sprime;
int nprime=0;
int nsprime=0;

void sieve(int n)
{
    int i,j,limit = sqrt(n)+2;

    mark[1] = 1;

    for(i=4;i<=n;i+=2) mark[i]=1;
    prime[++nprime]=2;
    for(i=3;i<=n;i++)
    {
        if(!mark[i])
        {
            prime[++nprime]=i;

            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}

void ssieve(LL a, LL b)
{
    int s = sqrt(b)+1;
    for(int i=1; prime[i] <= s; i++)
    {
        LL m = (((a-1)/prime[i])*prime[i])+prime[i];
        if(m == prime[i]) m*=2;
        for(LL j=m-a; j<=b-a; j+=prime[i])
        {
            smark[j]=1;
        }
    }

    for(int i=0; i<= b-a; i++)
    {
        if(a==1 && i==0) continue;
        else if(smark[i] != 1) {sprime.push_back(a+i);nsprime++;}
    }
}


int main()
{
    sieve(60020);
    //Fout;
    //Fin;
    int tc,cn=0,a,b;
    cin >> tc;
    while(tc--)
    {
        sprime.clear();
        MS(smark,0);
        nsprime=0;
        cin>>a>>b;
        ssieve(a,b);
        printf("Case %d: %d\n",++cn,nsprime);
    }
    //RT;
    return 0;
}
