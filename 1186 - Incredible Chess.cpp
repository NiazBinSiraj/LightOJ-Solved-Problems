#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF INT_MAX
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007
#define ck(XX) cout<<XX<<endl
#define set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

int main()
{
    int tc, cn=0;
    int n, w[110], b[110];

    cin >> tc;

    while(tc--)
    {
        MS(w,0);
        MS(b,0);
        int ans = 0;

        cin >> n;

        for(int i=0; i<n; i++) cin >> w[i];
        for(int i=0; i<n; i++) cin >> b[i];

        for(int i=0; i<n ;i++) ans = ans^(b[i]-w[i]-1);

        if(ans == 0) printf("Case %d: black wins\n", ++cn);
        else printf("Case %d: white wins\n", ++cn);

    }

    return 0;
}
