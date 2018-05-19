#include <bits/stdc++.h>
using namespace std;
#define eps 0.00000001

int digit = 0, one = 0;
vector <int> b;

void dtob(int d)
{
    while(d)
    {
        b.push_back(d%2);
        if(d%2 == 1) one++;
        d = d/2;
        digit++;
    }
}


int main()
{
    int tc,cn=0,n,i,j,k, nextn,in;
    int segone,segzero;

    cin >> tc;
    while(tc--)
    {
        nextn = 0;
        segone = 0;
        segzero = 0;
        b.clear();
        digit = 0;
        one = 0;
        cin >> n;
        //n = ab;
        dtob(n);
        reverse(b.begin(),b.end());

        //Searching

        if(one == 1)
        {
            nextn = n*2;
            printf("Case %d: %d\n",++cn,nextn);
        }

        else {
        for(i=b.size()-1;i>=0;i--)
        {
            if(b[i] == 1)
            {
                for(j=i-1;j>=0;j--)
                {
                    if(b[j] == 0)
                    {
                        swap(b[j],b[j+1]);
                        if(b[j+2] == 1)
                        {
                            in = j+2;
                            //counting
                            for(int z = in; z<b.size();z++)
                            {
                                if(b[z] == 1) segone++;
                                else segzero++;
                            }

                            for(int z = in;z<in+segzero;z++)
                            {
                                b[z] = 0;
                            }
                            for(int z = in+segzero; z<b.size();z++)
                            {
                                b[z] = 1;
                            }

                        }
                        break;
                    }
                    else if(b[j] == 1 && j == 0)
                    {
                        b.clear();
                        b.push_back(1);
                        digit = digit+1;
                        for(k=1;k<=digit-one;k++)
                        {
                            b.push_back(0);
                        }
                        for(k=digit-one+1; k<digit;k++)
                        {
                            b.push_back(1);
                        }
                    }
                }
                break;
            }
        }

        //binary to decimal

        reverse(b.begin(),b.end());

        for(i=0;i<b.size();i++)
        {
            if(b[i] == 1) nextn = nextn + pow(2,i) + eps;
        }

        printf("Case %d: %d\n",++cn,nextn);
        }
    }
    return 0;
}
