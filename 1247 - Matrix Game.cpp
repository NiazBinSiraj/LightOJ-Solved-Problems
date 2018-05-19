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
    int r,c;
    int stone[60];
    int t;
    scanf("%d",&tc);

    while(tc--)
    {

        MS(stone,0);

        scanf("%d%d", &r, &c);
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                scanf("%d",&t);
                stone[i] += t;
            }
        }

        int ans = stone[0];
        for(int i=1; i<r; i++)
        {
            ans = ans^stone[i];
        }

        if(ans == 0) printf("Case %d: Bob\n", ++cn);
        else printf("Case %d: Alice\n", ++cn);
    }
    return 0;
}
