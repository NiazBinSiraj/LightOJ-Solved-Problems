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
    //Fin;
    //Fout;

    int tc, cn=0;
    int n;
    int stone[110];
    int trig;
    int ans;
    scanf("%d",&tc);

    while(tc--)
    {
        MS(stone,0);
        trig = 0;
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&stone[i]);
            if(stone[i] != 1) trig = 1;
        }

        if(trig == 0)
        {
            if(n%2 == 0) printf("Case %d: Alice\n",++cn);
            else printf("Case %d: Bob\n",++cn);
        }

        else
        {
            ans = stone[0];
            for(int i=1; i<n; i++) ans = ans^stone[i];

            if(ans == 0) printf("Case %d: Bob\n",++cn);
            else printf("Case %d: Alice\n",++cn);
        }
    }
    return 0;
}
