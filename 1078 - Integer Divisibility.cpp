#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define runtime printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

int main()
{
    ll tc, cn=0;
    ll n,d,x,cnt,i;
    //Fin;
    //Fout;
    cin>>tc;

    while(tc--)
    {
        cnt=1;
        cin>>n>>d;
        i=d;
        while(d%n != 0)
        {
            d = (d%n)*10+i;
            cnt++;
        }
        printf("Case %lld: %lld\n",++cn,cnt);
    }
    //runtime;
    return 0;
}

