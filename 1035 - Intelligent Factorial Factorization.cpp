#include <bits/stdc++.h>
using namespace std;
int prime[30];
int mark[113];
int divs[110][110];
int nprime=0;

void siv()
{
    int i,j,sq=sqrt(110)+2;
    mark[1]=1;

    for(i=2;i<111;i++)
    {
        if(!mark[i])
        {
            nprime++;
            prime[nprime]=i;
            for(j=i*i;j<111;j+=i)
            {
                mark[j]=1;
            }
        }
    }
}

void create_divs()
{
    int k;
    for(int i=2;i<=105;i++)
    {
        int j=1;
        int z=i;
        while(prime[j]<=i && z!=1)
        {
            if(z%prime[j]==0)
            {
                divs[i][prime[j]]++;
                z=z/prime[j];
            }
            else
            {
                j++;
            }
        }
        if(i!=2)
        {
            k=1;
            while(prime[k]<=i)
            {
                divs[i][prime[k]]+=divs[i-1][prime[k]];
                k++;
            }
        }
    }
}

/*void print_divs()
{
    for(int i=2;i<101;i++)
    {
        printf("%d = ",i);
        for(int j=2;j<101;j++)
        {
            if(divs[i][j] != 0) printf("%d(%d)*",j,divs[i][j]);
        }
        cout << endl;
    }
}*/

int main()
{
    int tc, cn=0, n, i,j,z;
    //freopen("output.txt","w",stdout);
    siv();
    create_divs();
    scanf("%d",&tc);
    //tc=125;


    while(tc--)
    {
        scanf("%d",&n);
        //n=100;
        printf("Case %d: %d = 2 (%d)",++cn,n,divs[n][2]);
        for(int k=3;k<100;k++)
        {
            if(divs[n][k] != 0) printf(" * %d (%d)",k,divs[n][k]);
        }
        printf("\n");
    }
    return 0;
}
