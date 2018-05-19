#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, cn=0, n,p,q,i,a,cnt, weight;
    //freopen("output.txt","w",stdout);

    cin >> tc;

    while(tc--)
    {
        cnt = 0;
        weight = 0;
        cin >> n >> p >> q;

        for(i=1;i<=n;i++)
        {
            cin >> a;
            weight+=a;
            if(cnt < p && weight <=q) cnt++;
        }
        printf("Case %d: %d\n",++cn,cnt);
    }
    return 0;
}
