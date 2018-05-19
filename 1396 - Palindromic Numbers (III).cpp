#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define runtime printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
char s[100010];

bool is_pal()
{
    int length = strlen(s);
    int i,j;
    {
        for(i=0,j=length-1;i<=length/2;i++,j--)
        {
            if(s[i]!=s[j]) return 0;
        }
    }
    return 1;
}

bool all_nine()
{
    int length = strlen(s);
    int i,j;
    {
        for(i=0,j=length-1;i<=length/2;i++,j--)
        {
            if(s[i] != '9' || s[j] != '9') return 0;
        }
    }
    return 1;
}

void zero()
{
    for(int i=0;i<100010;i++)
    {
        s[i]=0;
    }
}


int main()
{
    int tc, cn=0,length,i,j,midc,l,r;
    //Fout;
    //Fin;
    scanf("%d",&tc);

    while(tc--)
    {
        midc = 0;
        zero();

        scanf("%s",s);
        length = strlen(s);

        if(length%2 == 1)
        {
            if(is_pal()==1)
            {
                if(all_nine()==1)
                {
                    s[0]='1';
                    s[length]='1';
                    for(i=1;i<length;i++)
                    {
                        s[i]='0';
                    }
                }

                else
                {
                    for(i=length/2,j=length/2;i>=0;i--,j++)
                    {
                        if(s[i]=='9') s[i]=s[j]='0';
                        else {s[i]++;s[j]=s[i];break;}
                    }
                }
            }

            else
            {
                for(i=0,j=length-1;i<=length/2;i++,j--)
                {
                    if(i==j && midc==1)
                    {
                        for(l=length/2,r=length/2;l>=0;l--,r++)
                        {
                            if(s[l]=='9') s[l]=s[r]='0';
                            else {s[l]++;s[r]=s[l];break;}
                        }
                    }
                    else if(s[i]>s[j]) {s[j]=s[i]; midc=0;}
                    else if(s[i]<s[j]) {s[j]=s[i]; midc=1;}
                }
            }
        }


        else
        {
            if(is_pal()==1)
            {
                if(all_nine()==1)
                {
                    s[0]='1';
                    s[length]='1';
                    for(i=1;i<length;i++)
                    {
                        s[i]='0';
                    }
                }

                else
                {
                    for(i=(length/2)-1,j=length/2;i>=0;i--,j++)
                    {
                        if(s[i]=='9') s[i]=s[j]='0';
                        else {s[i]++;s[j]=s[i];break;}
                    }
                }
            }

            else
            {
                for(i=0,j=length-1;i<=length/2;i++,j--)
                {
                    if(i+1==j && midc==1)
                    {
                        for(l=i,r=j;l>=0;l--,r++)
                        {
                            if(s[l]=='9' && s[r]=='9') s[l]=s[r]='0';
                            else if(s[l]>s[r]) {s[r]=s[l];break;}
                            else {s[l]++;s[r]=s[l];break;}
                        }
                    }
                    else if(i+1==j)
                    {
                        if(s[i]>s[j]) s[j]=s[i];
                        else if(s[i]<s[j]) {s[i]++; s[j]=s[i];}
                    }
                    else if(s[i]>s[j]) {s[j]=s[i];midc=0;}
                    else if(s[i]<s[j]) {s[j]=s[i]; midc=1;}
                }
            }
        }
        printf("Case %d: %s\n",++cn,s);
    }
    //runtime;
    return 0;
}

