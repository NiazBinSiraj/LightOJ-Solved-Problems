#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define FOut freopen("output.txt","w",stdout)
#define FIn freopen("input.txt","r",stdin)

int point[100010],n;

int findmax(int value)
{
    int lo,hi,mid;
    lo=0;
    hi=n-1;

    while(1)
    {
        mid=(lo+hi)/2;
        if(point[mid] == value) return mid;
        else if(point[lo]==value) return lo;
        else if(point[hi]==value) return hi;
        else if(hi-lo == 1) return lo;
        else if(point[mid]<value) lo = mid;
        else hi = mid;
    }
    return mid;
}

int findmin(int value)
{
    int lo,hi,mid;
    lo=0;
    hi=n-1;

    while(1)
    {
        mid=(lo+hi)/2;
        if(point[mid] == value) return mid;
        else if(point[lo]==value) return lo;
        else if(point[hi]==value) return hi;
        else if(hi-lo == 1) return hi;
        else if(point[mid]<value) lo = mid;
        else hi = mid;
    }
    return mid;
}

int main()
{
    int tc,cn=0;
    int q,i,a,b;
    int max,min,noe;
    //FIn;
    //FOut;

    scanf("%d",&tc);

    while(tc--)
    {
        max=0;
        min=0;
        noe=0;
        printf("Case %d:\n",++cn);
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++) scanf("%d",&point[i]);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&a,&b);
            if(a>point[n-1] || b<point[0]) {printf("%d\n",0);continue;}
            else if(a==point[n-1] || b==point[0]) {printf("%d\n",1);continue;}

            if(a<=point[0]) min=0;
            else min = findmin(a);

            if(b>=point[n-1]) max=n-1;
            else max = findmax(b);

            noe = max-min;
            printf("%d\n",noe+1);
        }
    }
    return 0;
}

