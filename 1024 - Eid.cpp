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


string multiply( string a, int b ) {
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}

string rev(string s)
{
	int length;
	length = s.size();
	for(int i=0,j=length-1; i<length/2; i++,j--)
	{
		swap(s[i],s[j]);
	}
	return s;
}

int prime[10000];
bool mark[10110];
int nprime=0;

void sieve(int n)
{
    int i,j,limit = sqrt(n)+2;

    mark[1] = 1;

    for(i=4;i<=n;i+=2) mark[i]=1;
    prime[++nprime]=2;
    for(i=3;i<=n;i++)
    {
        if(!mark[i])
        {
            prime[++nprime]=i;

            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}

int pf[10010];
vector <int> factor;
void prime_factorization(int n)
{
    MS(pf,0);
    factor.clear();

    int s = sqrt(n)+1;
    int i = 1;
    while(prime[i]<=s && n != 1)
    {
        if(n%prime[i]==0)
        {
            if(pf[prime[i]] == 0) factor.push_back(prime[i]);
            n=n/prime[i];
            pf[prime[i]]++;
        }
        else {i++;}
    }
    if(n != 1) {
        if(pf[n] == 0) factor.push_back(n);
        pf[n]++;
    }

    return;
}

template <class X>  X ipow(X base, X exp)
{
    X result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}



int main()
{
	//Fin;
	//Fout;

	sieve(10100);

	int tc, cn=0, n;
	string ans;
	int input;
	int cnt[10010];


	scanf("%d",&tc);

	while(tc--)
	{
		scanf("%d",&n);
		ans = "1";
		MS(cnt,0);

		while(n--)
		{
			scanf("%d",&input);
			prime_factorization(input);

			int sz = factor.size();
			for(int i=0; i<sz; i++)
			{
				if(cnt[factor[i]] < pf[factor[i]]){
					ans = multiply(ans,ipow(factor[i],pf[factor[i]]-cnt[factor[i]]));
					cnt[factor[i]] = pf[factor[i]];
				}
			}
		}
		printf("Case %d: ", ++cn);
		cout<<rev(ans)<<"\n";
	}

	return 0;
}
