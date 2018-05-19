#include <bits/stdc++.h>
//#include "custom.h"
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI acos(-1.0)
#define MOD 100000007LL
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define Set(XX,PS) XX|(1<<PS)
#define Reset(XX,PS) XX&(~(1<<PS))
#define Toggle(XX,PS) (XX^(1<<PS))
#define Check(XX,PS) (bool)(XX&(1<<PS))
#define SORT(v) sort(v.begin(),v.end())
#define REVERSE(V) reverse(v.begin(),v.end())
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define VALID(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define SIZE(ARRAY) sizeof(ARRAY)/sizeof(ARRAY[0])
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
string s;

int dp[110][110];

int pal(int i, int j)
{
    if(dp[i][j] != -1) return dp[i][j];
    if(i >= j) return 0;
    if(s[i] == s[j]) return dp[i][j] = pal(i+1,j-1);
    else return dp[i][j] = min(pal(i+1,j),pal(i,j-1))+1;
}

int main()
{
    FAST;
    int tc, cn=0;
    cin >>tc;
    while(tc--)
    {
        MS(dp,-1);
        cin >> s;

        int ans = pal(0,s.size()-1);

        printf("Case %d: %d\n", ++cn, ans);
    }


    return 0;
}
