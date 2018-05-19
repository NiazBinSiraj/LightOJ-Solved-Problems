#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc,cn=0;
    double v1,v2,v3,a1,a2,d,t1,t2,s;

    cin >> tc;

    while(tc--)
    {
        cin >>v1>>v2>>v3>>a1>>a2;
        d = ((a1*v2*v2)+(a2*v1*v1))/(2.0*a1*a2);
        t1 = v1/(a1*1.0);
        t2 = v2/(a2*1.0);

        if(t1 > t2) s = t1*v3;
        else if(t2> t1) s = t2*v3;
        else s = t1*v3;

        printf("Case %d: %0.12lf %0.12lf\n",++cn,d,s);
    }
    return 0;
}
