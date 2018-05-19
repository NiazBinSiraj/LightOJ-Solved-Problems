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
    ll tc,cn=0,n;
    string s;

    cin >> tc;

    while(tc--)
    {
        cin>>n>>s;

        if(s=="Alice")
        {
            if((n+2)%3==0) printf("Case %d: Bob\n",++cn);
            else printf("Case %d: Alice\n",++cn);
        }

        else
        {
            if(n%3==0) printf("Case %d: Alice\n",++cn);
            else printf("Case %d: Bob\n",++cn);
        }
    }
    return 0;
}
