#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, cn=0;
    int p,l,i;
    vector <int> div;
    //freopen("output.txt","w",stdout);

    cin >> tc;

    while(tc--)
    {
        div.clear();

        cin >> p>>l;
        if(p-l <= l) printf("Case %d: impossible\n",++cn);
        else if(p==0 && l==0) printf("Case %d: 1\n",++cn);
        else
        {
            for(i=1;i<=sqrt(p-l);i++)
            {
                if((p-l)%i == 0)
                {
                    if(i > l) div.push_back(i);
                    if(i != (p-l)/i && (p-l)/i > l) div.push_back((p-l)/i);
                }
            }
            sort(div.begin(),div.end());
            printf("Case %d:",++cn);
            for(i=0;i<div.size();i++)
            {
                printf(" %d",div[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
