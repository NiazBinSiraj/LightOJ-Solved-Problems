#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, cn=0, a1,b1,a2,b2,a3,b3,a4,b4;
    double a,b,d,s,area;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3);
        a4 = a1+a3-a2;
        b4 = b1+b3-b2;

        a = sqrt((a1-a2)*(a1-a2) + (b1-b2)*(b1-b2));
        b = sqrt((a1-a4)*(a1-a4) + (b1-b4)*(b1-b4));
        d = sqrt((a1-a3)*(a1-a3) + (b1-b3)*(b1-b3));
        s = (a+b+d)/2.0;

        area = 2*sqrt(s*(s-a)*(s-b)*(s-d));

        printf("Case %d: %d %d %0.0lf\n",++cn,a4,b4,area);
    }
    return 0;
}
