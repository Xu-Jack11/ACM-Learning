#include<bits/stdc++.h>
using namespace std;
bool isprime(int x)
{
    if(x==1)return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main(){
    int n,d;
    while(cin>>n)
    {
        if(n>0)
            cin>>d;
        else return 0;
        if(isprime(n))
        {
            int tmp=0;
            while(n>0)
                tmp=tmp*d+n%d,n/=d;
            if(isprime(tmp))
                {cout<<"Yes\n";
                continue;}
        }
        cout<<"No\n";
    }
}