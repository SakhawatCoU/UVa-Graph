#include<bits/stdc++.h>
#define int  long long
#define sci(n) scanf("%lld",&n)
#define pri(n) printf("%lld",n)
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fl2(i,a,b) for(int i=(a);i<(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define ff first
#define ss second
#define pb push_back
#define mkp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define nl printf("\n")
#define spc printf(" ")
#define pii pair<int,int>
#define piii pair<pii,int>
#define mii map<int,int>
#define msi map<string,int>
#define mci map<char,int>
#define mss map<string,string>
using namespace std;
int arr[1000009];

int func(int n)
{
    int s = n;
    while(n>0)
    {
        s+=(n%10);
        n/=10;
    }
    return s;
}
int32_t main()
{
//#ifdef ONPC
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//#endif
    f1(i,1000000)
    {
        if(arr[i]==0)
        {
            int n = i;
            while(n<=1000000)
            {
                n = func(n);
                if(arr[n]==1)
                    break;
                arr[n] = 1;
            }
        }
    }
    f1(i,1000000)
    {
        if(arr[i]==0)
            pri(i),nl;
    }

    return 0;
}


