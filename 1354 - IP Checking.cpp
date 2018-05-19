#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)

vector <char> s1,s2,s3,s4;

void rev()
{
    int i,j;
    char t;
    for(i=0,j=7;i<=3;i++,j--)
    {
        t = s1[i];
        s1[i] = s1[j];
        s1[j] = t;

        t = s2[i];
        s2[i] = s2[j];
        s2[j] = t;

        t = s3[i];
        s3[i] = s3[j];
        s3[j] = t;

        t = s4[i];
        s4[i] = s4[j];
        s4[j] = t;
    }
}

int deci(vector <char> s1)
{
    int i,m=1,d=0;
    for(i=0;i<=7;i++)
    {
        if(s1[i]=='1') d = d+m;
        m = m*2;
    }
    return d;
}

int main()
{
    int a,b,c,d;
    int tc,cn=0;
    char ch,hudai;

    scanf("%d",&tc);
    while(tc--)
    {
        s1.clear();
        s2.clear();
        s3.clear();
        s4.clear();

        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        scanf("%c",&hudai);
        for(int i=0;i<35;i++)
        {
            scanf("%c",&ch);
            if(i>=0 && i<=7) s1.push_back(ch);
            else if(i>=9 && i<=16) s2.push_back(ch);
            else if(i>=18 && i<=25) s3.push_back(ch);
            else if(i>=27 && i<=34) s4.push_back(ch);
        }

        rev();

        if(a == deci(s1) && b == deci(s2) && c == deci(s3) && d == deci(s4)) printf("Case %d: Yes\n",++cn);
        else printf("Case %d: No\n",++cn);
    }

    return 0;
}
