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

vector<LL>v;

int main()
{
    int tc,cn=0;
    cin >> tc;
    while(tc--)
    {
        int n,w;
        LL a,b;
        cin>>n>>w;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            v.push_back(b);
        }
        sort(v.begin(),v.end());
        int ans=1;
        a=v[0];
        for(int i=1; i<n; i++)
        {
            if(v[i]-a>w)
            {
                ans++;
                a=v[i];
            }
        }
        printf("Case %d: %d\n",++cn,ans);
        v.clear();
    }
    return 0;
}
