#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, cn=0;
    string s;
    stack <string> fd, bd;
    cin >> tc;
    while(tc--)
    {
        while(!fd.empty())
            fd.pop();
        while(!bd.empty())
            bd.pop();

        fd.push("http://www.lightoj.com/");
        printf("Case %d:\n",++cn);
        while(1)
        {
            cin >> s;

            if(s == "QUIT") break;

            else if(s == "VISIT")
            {
                cin >> s;
                fd.push(s);
                while(!bd.empty())
                    bd.pop();
                cout << fd.top() <<endl;
            }

            else if(s == "BACK")
            {
                if(fd.size()==1)
                {
                    cout <<"Ignored"<<endl;
                    continue;
                }

                bd.push(fd.top());
                fd.pop();
                cout << fd.top() <<endl;
            }

            else if(s == "FORWARD")
            {
                if(bd.size()==0)
                {
                    cout <<"Ignored"<<endl;
                    continue;
                }
                cout << bd.top() <<endl;
                fd.push(bd.top());
                bd.pop();
            }
        }
    }
    return 0;
}
