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

int main()
{
    FAST;
    int tc, cn=0;
    int n, l;

    cin >> tc;

    while(tc--)
    {
        vector <int> dl;
        int prev = 0;
        cin >> n;
        for(int i=0; i<n ;i++)
        {
            cin >> l;
            dl.push_back(l-prev);
            prev = l;
        }
        int ans = *max_element(dl.begin(),dl.end());
        int cnt = count(dl.begin(),dl.end(),ans);
        if(cnt > 1) ans++;
        printf("Case %d: %d\n", ++cn, ans);
    }
    return 0;
}
