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
int cnt[1000010];

int main()
{
    FAST;
    int tc, cn=0;
    int n;
    int pn;

    cin >> tc;

    while(tc--)
    {
        MS(cnt,0);

        cin >> n;
        vector<int>v;

        for(int i=0; i<n; i++)
        {
            cin >> pn;
            if(cnt[pn] == 0) v.push_back(pn);
            cnt[pn]++;
        }

        int letter = v.size();

        if(letter < n/2) printf("Case %d: no\n",++cn);

        else{
            int pos = 1;
            for(int i=0; i<letter; i++)
            {
                if(n%2 == 0){
                    if(cnt[v[i]]+cnt[n-1-v[i]] <=2 && v[i]<n) continue;
                    else pos = 0; break;
                }

                else{
                    if(cnt[v[i]]+cnt[n-1-v[i]] <=2 && cnt[n/2] == 1 && v[i]<n) continue;
                    else pos =0; break;
                }
            }
            if(pos == 0) printf("Case %d: no\n",++cn);
            else printf("Case %d: yes\n",++cn);
        }

    }
    return 0;
}
