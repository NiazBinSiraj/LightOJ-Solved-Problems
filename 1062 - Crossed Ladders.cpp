#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc,cn=0,cnt;
    double x,y,c,h1,h2,z,cnew;
    double lo,mid,hi;

    cin>>tc;

    while(tc--)
    {
        cin>>x>>y>>c;
        cnt=0;
        lo=0;
        if(x<y) hi=x;
        else hi=y;
        while(cnt<=100)
        {
            mid=(lo+hi)/2.0;
            h1=sqrt(x*x-mid*mid);
            h2=sqrt(y*y-mid*mid);
            cnew=(h1*h2*1.0)/(h1+h2);
            if(cnew < c) hi=mid;
            else lo=mid;
            cnt++;
        }
        printf("Case %d: %0.10lf\n",++cn,mid);
    }
    return 0;
}
