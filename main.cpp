#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
ifstream in("bomboane1.in");
ofstream out("bomboane1.out");

int div(int n)
{int cnt=0,lim;
    lim=(int)sqrt(double(n));
    for(int i=1;i<=lim;i++)
    {
        if(n%i==0)
        {
            if(i%2==0)
                cnt++;
            if((n/i)%2 == 0)
                cnt++;
        }
    }
    cnt++;
    return cnt;
}

int main()
{int pos=0,cnt,x,y;int max=-1,pos_max,pos_min;int cutii[1000];
    cin>>x>>y;
    for(int i=x;i<=y;i++)
    {
        cutii[pos]=div(i);
        if(max<cutii[pos])
        {
            max=cutii[pos];
            cnt=0;
        }
        if(max==cutii[pos])
            cnt++;
        pos++;
    }
    for(int i=0;i<pos;i++)
    {
        if(cutii[i]==max)
            pos_max=i;
        if(cutii[pos-i-1]==max)
            pos_min=i;
    }
    cout<<y-pos_min<<" "<<pos_max+x<<" "<<cnt<<" "<<max;
    return 0;
}
