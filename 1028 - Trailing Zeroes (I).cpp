#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define FOut freopen("output.txt","w",stdout)
#define FIn freopen("input.txt","r",stdin)
#define N 1000010
int mark[N+10];
vector <ll> prime;
ll nprime=0;

void siv()
{
    ll i,j,sq,p;
    sq=sqrt(N)+2;
    mark[0]=1;
    mark[1]=1;
    for(i=2;i<sq;i++){
        if(!mark[i]){
            for(j=i*i;j<N;j+=i)mark[j]=1;
        }
    }

    for(i=0;i<N;i++)
    {
        if(mark[i]==0) prime.push_back(i);
    }
    nprime = prime.size();
}

ll divisor_count(ll n)
{
    if(n<=1000000)
    {
        if(mark[n]==0) return 2;
    }
    ll nod = 1;
    for(ll i=0; i<nprime && i*i<=n; i++)
    {
        if(n<=1) return nod;
        if(n%prime[i]==0)
        {
            ll cnt=0;
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                cnt++;
            }
            nod=nod*(cnt+1);
        }
        if(n<=1000000 && n!=1)
        {
            if(mark[n]==0)
            {
                return nod*2;
            }
        }
    }
    if(n!=1) return nod*2;

    return nod;
}

int main()
{
    siv();
    ll tc,cn=0,n,d;
    scanf("%lld",&tc);

    while(tc--)
    {
        scanf("%lld",&n);
        d = divisor_count(n);
        printf("Case %lld: %lld\n",++cn,d-1);
    }

    return 0;
}

