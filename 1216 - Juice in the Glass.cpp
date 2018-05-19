#include <bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)

int main()
{
    int tc, cn = 0;
    double r1,r2,h,p,r,v;

    cin >>tc;

    while(tc--)
    {
        cin >> r1 >> r2 >> h >> p;

        r = (r1*p + r2 * (h-p))/(1.0*h);
        v = (pi*p*(r2*r2 + r*r2 + r*r))/3.0;

        printf("Case %d: %.10lf\n",++cn,v);
    }
    return 0;
}
