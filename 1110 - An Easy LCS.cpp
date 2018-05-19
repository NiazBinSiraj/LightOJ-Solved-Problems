//TLE
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

#define MX 110


int dp[MX][MX];

int LCS(string A, string B, int i, int j)
{

    if(A[i]=='\0' || B[j]=='\0') return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans=0;
    if(A[i] == B[j]) ans = 1+LCS(A,B,i+1,j+1);
    else ans = max(LCS(A,B,i+1,j),LCS(A,B,i,j+1));
    dp[i][j] = ans;

    return dp[i][j];
}


string ans,res;
void printAll(string A, string B, int i,int j)
{
	if(A[i]=='\0' or B[j]=='\0'){
		if(ans<res) res=ans;
		return;
	}
	if(A[i]==B[j]){
		ans+=A[i];
		printAll(A,B,i+1,j+1);
		ans.erase(ans.end()-1);
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) printAll(A,B,i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAll(A,B,i,j+1);
		else
		{
			printAll(A,B,i+1,j);
			printAll(A,B,i,j+1);
		}
	}
	return;
}

int main()
{
    //FAST;
    int tc,cn=0;
    scanf("%d",&tc);

    while(tc--){
    MS(dp,-1);
    res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\0";

    char ta[MX],tb[MX];
    scanf("%s%s",ta,tb);
    string A(ta), B(tb);

    int nos = LCS(A,B,0,0);

    if(nos == 0) printf("Case %d: :(\n",++cn);

    else{
    printAll(A,B,0,0);
    cn++;
    printf("Case %d: %s\n",++cn, res.c_str());
    }
    }
    return 0;
}
