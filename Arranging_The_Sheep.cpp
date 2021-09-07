///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           nd(a,b,c)                   mp(mp(a,b),c)
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=2e18;
const int mod=1e9+7;
const int M=1200005;
int cnt[M];
void solve()
{
   int n,x,ses=0;
   cin>>n;
   f(i,0,3*n)cnt[i]=0;
   f(i,1,n)
   {
       cin>>x;
       int z=i-x+n;
       ses+=cnt[z];
       cnt[z]++;
   }
   cout<<ses<<"\n";
}
 main()

{
    fast
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;

}



































