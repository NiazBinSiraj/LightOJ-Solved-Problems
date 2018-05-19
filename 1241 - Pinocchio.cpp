#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, cn=0,n,a,i,b,cnt;
    //freopen("output.txt","w",stdout);
    cin >> tc;

    while(tc--)
    {
        cin >> n;
        cnt = 0;
        for(i=0;i<n;i++)
        {
            cin >> a;

            if(i == 0 && a>2)
            {
                cnt=cnt+((a-2)/5);
                if((a-2)%5 !=0) cnt++;
            }
            else if(i != 0 && a != b)
            {
                cnt=cnt+((a-b)/5);
                if((a-b)%5 !=0) cnt++;
            }
            b = a;
        }
        printf("Case %d: %d\n",++cn,cnt);
    }
    return 0;

}
