#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

int jos(int n, int k)
{
    if(n==1) return 1;
    else return ((jos(n-1,k)+k-1)%n)+1;
}

int main()
{
    int tc,cn=0;
    int n,k;
    cin >> tc;
    while(tc--)
    {
        cin >>n>>k;
        printf("Case %d: %d\n",++cn, jos(n,k));
    }

    return 0;
}
