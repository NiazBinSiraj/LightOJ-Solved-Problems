#include <bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)

int main()
{
    int tc, cn=0;
    double ox,oy,ax,ay,bx,by;
    double oa,ob,ab,aob,s;
    //freopen("out.txt","w",stdout);
    cin >> tc;

    while(tc--)
    {
        cin >>ox>>oy>>ax>>ay>>bx>>by;

        oa = sqrt((ox-ax)*(ox-ax) + (oy-ay)*(oy-ay));
        ob = sqrt((ox-bx)*(ox-bx) + (oy-by)*(oy-by));
        ab = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));

        aob = acos((oa*oa + ob*ob - ab*ab)/(2.0*oa*ob));

        s = oa*aob;

        //printf("Case %d: %.10lf  %.10lf\n",++cn,oa,ob);
        printf("Case %d: %.10lf\n",++cn,s);
    }
    return 0;
}
