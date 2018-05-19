#include <bits/stdc++.h>
using namespace std;
#define pi 3.141592653589

int main()
{
    int tc, cn = 0;
    double r1,r2,r3,t1,t2,t3,a,b,c,A1,A2,A3,A,result;

    cin >> tc;
    while(tc--)
    {
        cin >>r1>>r2>>r3;
        a = r1+r2;
        b = r1+r3;
        c = r2+r3;

        t1 = acos((a*a + b*b - c*c)/(2.0*a*b));
        t2 = acos((c*c + a*a - b*b)/(2.0*a*c));
        t3 = acos((c*c + b*b - a*a)/(2.0*b*c));

        A1 = (r1*r1*t1)/2.0;
        A2 = (r2*r2*t2)/2.0;
        A3 = (r3*r3*t3)/2.0;

        A = a*b*sin(t1)/2.0;

        result = A - (A1 + A2 + A3);

        printf("Case %d: %0.11lf\n",++cn,result);
    }
    return 0;
}
