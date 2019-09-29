#include<bits/stdc++.h>
#define int long long
#define scf(n) scanf("%lld",&n)
#define rep1(n) for(int i=1;i<=n;i++)
#define prf(n) printf("%lld",n)
#define sci(n) scanf("%lld",&n)
#define pri(n) printf("%lld",n)

#define nl printf("\n")
#define spc printf(" ")
#define file freopen("in.txt","rt",stdin)
#define pii pair<int,int>
#define piii pair<pii,int>
using namespace std;
int n;
int temp[109];
int max_sub()
{
    int mx = 0,now = 0;
    for(int i=1;i<=n;i++)
    {
        now+=temp[i];
        if(now>mx)
            mx = now;
        if(now<0)
            now = 0;
    }
    return mx;
}
int arr[109][109];

int32_t main()
{
#ifdef ONPC
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
     sci(n);
     int c = 0;
     int mxx = 0;
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=n;j++)
         {
             sci(arr[i][j]);
             if(arr[i][j]>=0)
                c = 1;
            mxx = max(mxx,arr[i][j]);
         }
     }
     if(c==0)
     {
         pri(mxx),nl;
     }
     else
     {
         mxx =  0;
         for(int L=1;L<=n;L++)
         {
             for(int k=1;k<=n;k++)
                temp[k] = arr[k][L];
              mxx = max(mxx,max_sub());
              for(int R = L+1;R<=n;R++)
              {
                  for(int j=1;j<=n;j++)
                  {
                  temp[j]+=arr[j][R];
                  }
                  mxx = max(mxx,max_sub());
              }
         }
     }
     pri(mxx),nl;

    return 0;
}

