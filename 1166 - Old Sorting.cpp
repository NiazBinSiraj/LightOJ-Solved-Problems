#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define runtime printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

int main()
{
    int tc, cn=0;
    int n,i,ara[110],cnt;

    cin >> tc;

    while(tc--)
    {
        cnt=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>ara[i];
        }

        for(i=1;i<=n;i++)
        {
            if(ara[i] != i)
            {
                swap(ara[i],ara[ara[i]]);
                cnt++;
                i--;
            }
        }
        printf("Case %d: %d\n",++cn,cnt);
    }
    return 0;
}

