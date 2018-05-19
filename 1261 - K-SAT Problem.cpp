#include <bits/stdc++.h>
using namespace std;
int pw[50][50], sol[50],p,k;
int mark[50];

int check(int n)
{
    for(int z=1;z<=p;z++)
    {
        if(n == sol[z]) return 1;
    }
    return 0;
}

int check_mark(int ara[])
{
    for(int i=1;i<=k;i++)
    {
        if(mark[i]==1) return 1;
    }
    return 0;
}

void zero_marking()
{
    for(int i=1;i<50;i++)
    {
        mark[i]=0;
    }
}

int main()
{
    int tc,cn=0,n,m,i,j,t;
    int s;

    cin >> tc;

    while(tc--)
    {
        cin >>n>>m>>k;
        s = 1;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            {
                cin >> pw[i][j];
            }
        }

        cin >> p;

        for(i=1;i<=p;i++)
        {
            cin >> sol[i];
        }

        //Checking

        for(int i=1;i<=n;i++)
        {
            zero_marking();
            for(j=1;j<=k;j++)
            {
                if(pw[i][j] > 0)
                {
                    t = pw[i][j];
                    if(check(t)==1)
                    {
                        mark[j]=1;
                    }
                }
                else if(pw[i][j] < 0)
                {
                    t = abs(pw[i][j]);
                    if(check(t)==0)
                    {
                        mark[j]=1;
                    }
                }
            }
            if(check_mark(mark)==0)
            {
                s=0;
                break;
            }
        }
        if(s==0) printf("Case %d: No\n",++cn);
        else printf("Case %d: Yes\n",++cn);
    }
    return 0;
}
