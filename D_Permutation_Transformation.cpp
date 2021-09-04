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
//code goes from here...
ll n,dp[105],ar[105];

void DP(ll l,ll r,ll ans)
{
   if (l < 0 || r >= n || r < 0 || l >= n || l > r) return;
		

    ll mx=0,ix=0;

    for(ll i=l;i<=r;i++)
    {
        if(mx<ar[i])
        {
            mx=ar[i];
            ix=i;
        }
    }

    dp[ix]=ans;
    DP(l,ix-1,ans+1);
    DP(ix+1,r,ans+1);
}


int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    ll tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        ll ix=0;
        for(ll i=0;i<n;i++)
        {
            dp[i]=0;
            cin >> ar[i];
            if(ar[i]==n) ix=i;
        }

        dp[ix]=0;
        dp[n]=0;

        DP(0,ix-1,1);
        DP(ix+1,n-1,1);

        for(ll i=0;i<n; i++) cout << dp[i] << ' ';
        cout << endl;
    }
    
    //---------------------------------
    
    return 0;
}
