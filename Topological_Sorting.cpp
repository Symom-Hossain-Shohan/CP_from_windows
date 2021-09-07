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

//code goes from here...
vector<ll> adj[10005];

ll vis[10005];
bool is_cyclic=false;

vector<ll> ans;

void dfs(ll node)
{
    vis[node]=1;

    for(auto child : adj[node])
    {
        if(vis[child]==0)
        {
            dfs(child);
        }
        if(vis[node]==1 and vis[child]==1)
        {
            is_cyclic=true;
        }
    }
    vis[node]=2;
    ans.pb(node);
}




int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    ll n,m;
    cin>> n >> m;

    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    for(ll i=1;i<=n;i++) rsrt(adj[i]);

    for(ll i=n;i>=1;i--)
    {
        if(vis[i]==0) dfs(i);
    }
    if(is_cyclic) cout << "Sandro fails.\n";
    else 
    {
        reverse(all(ans));
        for(auto i: ans) cout << i << ' ';
        cout << endl;
    }
    
    //---------------------------------
    
    return 0;
}