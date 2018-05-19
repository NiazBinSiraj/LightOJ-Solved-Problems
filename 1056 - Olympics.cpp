//1st Sollution (Using Bisection Search)

#include <bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)

int main()
{
    int tc,cn=0;
    double x,y,a,b,hi,lo,mid,d,cnt,c,theta,r,s;

    cin >> tc;

    while(tc--)
    {
        scanf("%lf : %lf",&x,&y);
        d=(x*1.0)/y;
        lo=0;
        hi=200;
        cnt=0;
        while(cnt<=50)
        {
            mid=(hi+lo)/2.0;
            b=mid;
            a=b*d;
            c=200-a-b;
            r=sqrt(a*a + b*b)/2.0;
            theta=acos((r*r + r*r - b*b)/(2.0*r*r));
            s=r*theta;
            if(a+b >= 200) hi=mid;
            else
            {
                if(c > s-b) lo=mid;
                else if (c < s-b) hi=mid;
            }
            cnt++;
        }
        printf("Case %d: %0.7lf %0.7lf\n",++cn,a,b);
    }
    return 0;
}

//2nd Sollution (Using Geometry)
#include <bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)

int main()
{
    int tc,cn=0;
    double a,b,theta,r,s,x;

    cin >> tc;

    while(tc--)
    {
        scanf("%lf : %lf",&a,&b);
            r=sqrt(a*a + b*b)/2.0;
            theta=acos((r*r + r*r - b*b)/(2.0*r*r));
            s=r*theta;
            x=400.0/(2.0*a + 2.0*s);
        printf("Case %d: %0.7lf %0.7lf\n",++cn,x*a,x*b);
    }
    return 0;
}
