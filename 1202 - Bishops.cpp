#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, cn=0, r1,c1,r2,c2;

    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);

        if((r1+c1)%2 == (r2+c2)%2)
        {
            if(abs(r1-r2) == abs(c1-c2)) printf("Case %d: 1\n",++cn);
            else printf("Case %d: 2\n",++cn);
        }
        else printf("Case %d: impossible\n",++cn);
    }
    return 0;
}
