#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define ck(XX) cout<<XX<<endl
#define set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int T1[1010], T2[1010];
int LR[1010], RL[1010];
int n;


int main()
{
    int tc, cn=0,i;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for(i=0;i<n;i++) cin>>T1[i];
        for(i=0;i<n;i++) cin>>T2[i];
        for(i=0;i<n-1;i++) cin>>LR[i];
        for(i=0;i<n-1;i++) cin>>RL[i];

        l=min(min(T1[s]+T1[s-1],T1[s]+T2[s-1]+RL[s-1]),min(T2[s]+T2[s-1],T2[s]+T1[s-1]+LR[s-1]));


        printf("Case %d: %d\n", ++cn, dp(n-1));
    }
    return 0;
}

