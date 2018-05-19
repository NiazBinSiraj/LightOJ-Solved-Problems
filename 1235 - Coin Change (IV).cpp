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
int A[20],B[20];
vector <int> SA,SB;
int n,k;
int l1,l2;

void subsetSumA(int pos, int sum)
{
    if(pos >= l1) {SA.push_back(sum); return;}
    subsetSumA(pos+1,sum+A[pos]);
    subsetSumA(pos+1,sum);
    subsetSumA(pos+1,sum+2*A[pos]);
    return;
}

void subsetSumB(int pos, int sum)
{
    if(pos >= l2) {SB.push_back(sum); return;}
    subsetSumB(pos+1,sum+B[pos]);
    subsetSumB(pos+1,sum);
    subsetSumB(pos+1,sum+2*B[pos]);
    return;
}

int main()
{
    FAST;
    int tc,cn=0;

    cin >> tc;
    while(tc--)
    {
        MS(A,0);
        MS(B,0);
        SA.clear();
        SB.clear();

        cin >>n>>k;

        if(n==1){
            int t;
            cin >> t;
            if(t==k || 2*t == k) printf("Case %d: Yes\n",++cn);
            else printf("Case %d: No\n",++cn);
            continue;
        }

        else if(n%2 == 0) {l1=l2=n/2;}
        else {l1=n/2; l2=(n+1)/2;}

        for(int i=0; i<l1; i++)
        {
            cin>>A[i];
        }
        for(int i=0; i<l2; i++)
        {
            cin>>B[i];
        }

        subsetSumA(0,0);
        subsetSumB(0,0);
        SORT(SB);

        int sz = SA.size();
        int found = 0;
        for(int i=0; i<sz; i++)
        {
            if(binary_search(SB.begin(),SB.end(),k-SA[i]) == 1) {found = 1; break;}
        }

        if(found == 1) printf("Case %d: Yes\n",++cn);
        else printf("Case %d: No\n",++cn);
    }
    return 0;
}
