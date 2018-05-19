#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define db(XX) cout<<XX<<endl;
#define Fin freopen("input.txt","r",stdin);
#define Fout freopen("output.txt","w",stdout);
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY));
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0));
int used[100];
char number[100];
int cnt;
int k;

void permutation(int p, int n)
{
    if(cnt==k) return;

    if(p == n+1)
    {
        cnt++;
        for(int i=1;i<=n;i++)
        {
            printf("%c",number[i]);
        }
        printf("\n");
        return;
    }

    for(int i=65;i<n+65;i++) if(!used[i])
    {
        used[i] = 1;
        number[p] = i;
        permutation(p+1,n);
        used[i] = 0;
    }
}





int main()
{
    int n,tc,cn=0;
    cin>>tc;
    while(tc--)
    {
        printf("Case %d:\n",++cn);
        cnt=0;
        MS(used,0);
        cin>>n>>k;
        permutation(1,n);
    }
    return 0;
}
