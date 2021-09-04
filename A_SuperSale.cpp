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
ll n,g;
ll profit[1005];
ll weight[1005];

ll dp[1005][35];

ll DP(ll pos,ll wgt)
{
    if(pos>=n) return 0;
    if(dp[pos][wgt]!=-1) return dp[pos][wgt];
    ll val1=0,val2=0;
    if(weight[pos]<=wgt)
    {
        val1=profit[pos]+DP(pos+1,wgt-weight[pos]);
        val2=DP(pos+1,wgt);
        return dp[pos][wgt]=max(val2,val1);
    }
    else return dp[pos][wgt]=DP(pos+1,wgt);
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
        for(ll i=0;i<n;i++) cin >> profit[i] >> weight[i];
        
        cin >> g;
        ll w;
        ll ans=0;
        for(ll i=0;i<g;i++)
        {
            cin >> w;
            mem(dp,-1);
            ans+=DP(0,w);
        }

        cout << ans << endl;

    }
    
    //---------------------------------
    
    return 0;
}
