#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


//defines...
#define ll           long long
#define boost        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb           push_back
#define mp           make_pair
#define in           insert
#define pi           2*acos(0.0)
#define srt(s)       sort(s.begin(),s.end())
#define rsrt(s)      sort(s.rbegin(),s.rend())
#define all(x)       x.begin(),x.end()
#define mem(a, b)    memset(a, b, sizeof(a))
#define c_test       printf("Case %lld: ",t)


const ll mod=1e9+7;
const ll MX=2e5+5;


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}


typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {x = 1;y = 0;return a;}
    ll x1, y1, d = ext_gcd(b, a % b, x1, y1);
    x = y1;y = x1 - y1 * (a / b);
    return d;
}

//code goes from here...


int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    vector<ll> v(5);
   
    while(cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4])
    {
        if(v[0]==0) break;
        srt(v);
        ll t=1;
        ll sum=0;
        bool ok=true;

        for(ll i=0;i<3 and ok;i++)
        {
            for(ll j=0;j<3 and ok;j++)
            {
                for(ll k=0;k<3 and ok;k++)
                {
                    for(ll l=0;l<3 and ok;l++)
                    {
                        
                        ll x;
                        if(i==0) x=v[0]+v[1];
                        else if(i==1) x=v[0]-v[1];
                        else if(i==2) x=v[0]*v[1];
                       
                       //again
                       if(j==0) x=x+v[2];
                       else if(j==1) x=x-v[2];
                       else if(j==2) x=x*v[2];

                       // again
                       if(k==0) x=x+v[3];
                       if(k==1) x=x-v[3];
                       else if(k==2) x=x*v[3];

                       //again
                       if(l==0) x=x+v[4];
                       else if(l==1) x=x-v[4];
                       else if(l==2) x=x*v[4];

                       if(x==23)
                       {
                           cout << "Possible\n";
                           ok=false;
                           break;
                       }
                    }
                }
            }
        }

        if(ok)
        {
            while(next_permutation(all(v)) and ok)
            {
                for(ll i=0;i<3 and ok;i++)
        {
            for(ll j=0;j<3 and ok;j++)
            {
                for(ll k=0;k<3 and ok;k++)
                {
                    for(ll l=0;l<3 and ok;l++)
                    {
                        
                        ll x;
                        if(i==0) x=v[0]+v[1];
                        else if(i==1) x=v[0]-v[1];
                        else if(i==2) x=v[0]*v[1];
                       
                       //again
                       if(j==0) x=x+v[2];
                       else if(j==1) x=x-v[2];
                       else if(j==2) x=x*v[2];

                       // again
                       if(k==0) x=x+v[3];
                       if(k==1) x=x-v[3];
                       else if(k==2) x=x*v[3];

                       //again
                       if(l==0) x=x+v[4];
                       else if(l==1) x=x-v[4];
                       else if(l==2) x=x*v[4];

                       if(x==23)
                       {
                           cout << "Possible\n";
                           ok=false;
                           break;
                       }
                    }
                }
            }
        }
            }
        }

        if(ok) cout << "Impossible\n";
    }
    
    //---------------------------------
    
    return 0;
}