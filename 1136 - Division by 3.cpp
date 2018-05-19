#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)

int main()
{
    ll tc,cn=0,a,b,divided,number,result;

    scanf("%lld",&tc);

    while(tc--)
    {
        divided = 0;
        number = 0;
        result = 0;
        scanf("%lld%lld",&a,&b);

        number = (b-a)+1;
        divided = number / 3;
        result = divided*2;
        if(number%3 == 0)
        {
            printf("Case %lld: %lld\n",++cn,result);
            continue;
        }

        else if(b%3 == 0 && number%3 == 2) result = result+2;
        else if(number%3 == 2) result++;
        else if((b%3 == 0 || (b+1) % 3 == 0) && number%3 == 1) result++;

        printf("Case %lld: %lld\n",++cn,result);
    }
    return 0;
}

