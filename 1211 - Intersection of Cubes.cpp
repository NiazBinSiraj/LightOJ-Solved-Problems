#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll maxf(ll ara[], ll length)
{
    ll mx=ara[0],i;
    for(i=1;i<length;i++)
    {
        if(ara[i]>mx) mx = ara[i];
    }
    return mx;
}

ll minf(ll ara[], ll length)
{
    ll mn=ara[0],i;
    for(i=1;i<length;i++)
    {
        if(ara[i]<mn) mn = ara[i];
    }
    return mn;
}

int main()
{
    ll tc, cn=0;
    ll n,i;
    ll x1[105],y1[105],z1[105],x2[105],y2[105],z2[105];
    ll c1x,c1y,c1z,c2x,c2y,c2z,ax,ay,az,bx,by,bz;
    ll ac1, ab, bc2, area;
    ll max_dis,lc;

    //freopen("out.txt","w",stdout);

    cin >> tc;

    while(tc--)
    {
        max_dis = 0;
        cin >> n;
        for(i=0;i<n;i++)
        {
            cin >>x1[i]>>y1[i]>>z1[i]>>x2[i]>>y2[i]>>z2[i];
            if(x1[i]<x2[i]) swap(x1[i],x2[i]);
            if(y1[i]<y2[i]) swap(y1[i],y2[i]);
            if(z1[i]<z2[i]) swap(z1[i],z2[i]);

            if((x1[i]-x2[i])>max_dis)
            {
                max_dis = x2[i]-x1[i];
                lc = i;
            }
        }

        c1x = minf(x1,n);
        c1y = minf(y1,n);
        c1z = minf(z1,n);

        c2x = maxf(x2,n);
        c2y = maxf(y2,n);
        c2z = maxf(z2,n);

        ax = c2x;
        ay = c1y;
        az = c1z;

        bx = c2x;
        by = c2y;
        bz = c1z;

        ac1 = abs(ax - c1x);
        ab = abs(ay - by);
        bc2 = abs(c2z - bz);

        area = ac1*ab*bc2;

        if(c1x < c2x || c1y < c2y || c1z < c2z) area = 0;

        printf("Case %lld: %lld\n",++cn,area);
    }
    return 0;
}

