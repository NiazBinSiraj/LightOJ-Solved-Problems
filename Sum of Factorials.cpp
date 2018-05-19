#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fact[25];
vector <int> sum;

void generate_fact()
{
    int i;
    for(i=0;i<=20;i++)
    {
        if(i==0) fact[i] = 1;
        else
        {
            fact[i] = i*fact[i-1];
        }
    }
}

int main()
{
    generate_fact();
    int tc, cn=0,i;
    ll n;
    freopen("out.txt","w",stdout);

    scanf("%d",&tc);

    while(tc--)
    {
        sum.clear();

        scanf("%lld",&n);

        for(i=20;i>=0;i--)
        {
            if(n>fact[i])
            {
                n = n - fact[i];
                sum.push_back(i);
                if(i==0 && n!= 0) sum.clear();
            }
            else if(n == fact[i])
            {
                sum.push_back(i);
                break;
            }
            else if(i==0)
            {
                sum.clear();
            }
        }

        if(sum.size()==0) printf("Case %d: impossible\n",++cn);
        else
        {
            sort(sum.begin(),sum.end());
            printf("Case %d: %d!",++cn,sum[0]);
            for(i=1;i<sum.size();i++)
            {
                printf("+%d!",sum[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
