#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define FOut freopen("output.txt","w",stdout)
#define FIn freopen("input.txt","r",stdin)

ll countzero(ll n)
{
    ll cnt=0;

    for(ll i=5; i<=n; i=i*5)
    {
        cnt=cnt+(n/i);
    }
    return cnt;
}

int main()
{
    int tc, cn=0;
    ll q,lo,hi,mid,n,z;

    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%lld",&q);
        lo=1;
        hi=5000000000000000000;
        n=-1;

        while(lo<hi)
        {
            mid=(lo+hi)/2;
            z = countzero(mid);

            if(z==q) {n=mid;break;}
            else if(z>q) hi=mid;
            else lo=mid+1;
        }

        if(n==-1)
        {
            printf("Case %d: impossible\n",++cn);
            continue;
        }
        n=n-(n%5);
        printf("Case %d: %lld\n",++cn,n);
    }

    return 0;
}

