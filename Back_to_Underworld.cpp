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
vector <int > aj[20001];

int vis[20001];

ll m1,m2;

void dfs(ll node,ll col)
{
    vis[node]=1;
    if(col==1) m1++;
    else m2++;
    for(ll i=0;i<(ll)aj[node].size();i++)
    {
        if(vis[aj[node][i]]==0)
        {
            dfs(aj[node][i],!col);
        }
    }
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
    int t=1;
    while(tc--)
    {
        ll n;
        ll u,v;
        cin >> n;
        vector<ll> vv;
        for(int i=0;i<20001;i++) aj[i].clear();
        mem(vis,0);
        for(ll i=0;i<n;i++)
        {
            cin >> u >> v;
            aj[u].pb(v);
            aj[v].pb(u);
            vv.pb(u),vv.pb(v);
        }
        ll ans=0;
        for(ll i=0;i<(ll)vv.size();i++)
        {
            m1=0,m2=0;
            if(vis[vv[i]]==0)
            {
                dfs(vv[i],1);
                ans+=max(m1,m2);
            }
        }

        printf("Case %d: %lld\n",t,ans);
        t++;
        

    }
    
    //---------------------------------
    
    return 0;
}
