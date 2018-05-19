#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, cn=0;
    double ab,bc,ca,r,ad;

    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%lf%lf%lf%lf",&ab,&bc,&ca,&r);

        ad = sqrt((ab*ab)/(1.0+(1.0/r)));

        printf("Case %d: %.12lf\n",++cn,ad);
    }
    return 0;
}
