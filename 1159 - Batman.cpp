#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI acos(-1.0)
#define MOD 1000000007
#define PII pair<int,int>
#define PLL pair<LL,LL>
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

#define MX 60
string A,B,C;
bool visited[MX][MX][MX];
int dp[MX][MX][MX];

int LCS(int i, int j, int k)
{

    if(A[i]=='\0' || B[j]=='\0' || C[k]=='\0') return 0;
    if(visited[i][j][k]) return dp[i][j][k];

    int ans=0;
    if(A[i] == B[j] && B[j] == C[k]) ans = 1+LCS(i+1,j+1,k+1);
    else ans = max(LCS(i+1,j,k),max(LCS(i,j+1,k),LCS(i,j,k+1)));
    visited[i][j][k] = 1;
    dp[i][j][k] = ans;

    return dp[i][j][k];
}


int main()
{
    FAST;
    int tc, cn=0;
    cin >> tc;
    while(tc--)
    {
        MS(dp,0);
        MS(visited,0);

        cin >>A>>B>>C;
        int ans = LCS(0,0,0);
        printf("Case %d: %d\n",++cn,ans);
    }

    return 0;
}
