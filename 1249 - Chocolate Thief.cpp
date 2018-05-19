#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int tc, cn=0, n, i, j, a,b,c;
    ll max,min;
    string s, thief, victim;
    vector <string> name;
    vector <ll> q;
    cin >> tc;
    while(tc--)
    {
        name.clear();
        q.clear();

        cin >> n;

        for(i=0;i<n;i++)
        {
            cin >> s >> a >> b >> c;
            name.push_back(s);
            q.push_back(a*b*c);
        }

        max = q[0];
        thief = name[0];
        min = q[0];
        victim = name[0];
        for(i=1;i<n;i++)
        {
            if(max < q[i])
                {
                    max = q[i];
                    thief = name[i];
                }
                if(min > q[i])
                {
                    min = q[i];
                    victim = name[i];
                }
        }

        if(max == min) printf("Case %d: no thief\n",++cn);
        else printf("Case %d: %s took chocolate from %s\n",++cn,thief.c_str(),victim.c_str());
    }
    return 0;
}
