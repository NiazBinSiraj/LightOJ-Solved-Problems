#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, cn=0, n,m,ara[110],i,num1,num2,temp,j,k;
    char c;

    cin >> tc;

    while(tc--)
    {
        cin >>n>>m;

        for(i=0;i<n;i++)
        {
            cin >> ara[i];
        }
        for(j=1;j<=m;j++)
        {
            cin >> c;
            if(c=='S')
            {
                cin >> num1;
                for(i=0;i<n;i++)
                {
                    ara[i] = ara[i] + num1;
                }
            }
            else if(c=='M')
            {
                cin >> num1;
                for(i=0;i<n;i++)
                {
                    ara[i] = ara[i] * num1;
                }
            }
            else if(c=='D')
            {
                cin >> num1;
                for(i=0;i<n;i++)
                {
                    ara[i] = ara[i] / num1;
                }
            }
            else if(c=='R')
            {
                for(i=0,k=n-1;i<n/2;i++,k--)
                {
                    temp = ara[i];
                    ara[i] = ara[k];
                    ara[k] = temp;
                }
            }
            else if(c=='P')
            {
                cin >> num1 >> num2;
                temp = ara[num1];
                ara[num1] = ara[num2];
                ara[num2] = temp;
            }
        }
        printf("Case %d:\n",++cn);
        for(i=0;i<n;i++)
        {
            if(i==(n-1))
            {
                cout << ara[i] <<endl;
                break;
            }
            cout << ara[i] <<" ";
        }
    }
    return 0;
}
