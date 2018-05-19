#include <bits/stdc++.h>
using namespace std;
#define ll long long

int check(int n)
{
    int a,b;
    a = sqrt(n);
    b = a*a;
    if(n == b) return 1;
    else return 0;
}

int main()
{
    ll tc,cn=0,n,s,e,m,x,y;

    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld",&n);

        if(n==1)
        {
            printf("Case %lld: 1 1\n",++cn);
        }
        else
        {
            if(check(n)==1)
            {
                e = sqrt(n);
                e = e*e;

                s = sqrt(n)-1;
                s = s*s + 1;
            }

            else
            {
                e = sqrt(n);
                e = e+1;
                e = e*e;

                s = sqrt(n);
                s = s*s + 1;
            }

            m = (s+e)/2;
            if(e%2 == 1)
            {
                if(n>=m)
                {
                    x = e+1-n;
                    y = sqrt(e);
                }
                else
                {
                    x = sqrt(e);
                    y = n-(s-1);
                }
            }
            else
            {
                if(n>=m)
                {
                    x = sqrt(e);
                    y = e+1-n;
                }
                else
                {
                    x = n+1-s;
                    y = sqrt(e);
                }
            }
            printf("Case %lld: %lld %lld\n",++cn,x,y);
        }
    }
    return 0;
}
