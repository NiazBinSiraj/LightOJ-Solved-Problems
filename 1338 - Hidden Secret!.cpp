#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, cn=0,i;
    char s[110];
    vector <char> v1, v2;

    cin >> tc;
    getchar();
    while(tc--)
    {
        v1.clear();
        v2.clear();

        gets(s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i] >= 'A' && s[i]<= 'Z') v1.push_back(tolower(s[i]));
            else if(s[i] >= 'a' && s[i]<= 'z') v1.push_back(s[i]);
        }
        gets(s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i] >= 'A' && s[i]<= 'Z') v2.push_back(tolower(s[i]));
            else if(s[i] >= 'a' && s[i]<= 'z') v2.push_back(s[i]);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        if(v1 == v2) printf("Case %d: Yes\n",++cn);
        else printf("Case %d: No\n",++cn);
    }
    return 0;
}
