#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc,cn=0,n,balance, taka;
    string comand;

    scanf("%d",&tc);

    while(tc--)
    {
        balance = 0;
        scanf("%d",&n);
        printf("Case %d:\n",++cn);

        while(n--)
        {
            cin >> comand;
            if(comand == "donate"){
                scanf("%d",&taka);
                balance += taka;
            }
            else printf("%d\n",balance);
        }
    }
    return 0;
}
