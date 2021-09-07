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

map<string,vector<string>> adj;
map<string,ll> vis;


bool dfs(string s)
{
    vis[s]=1;
    for(auto child: adj[s])
    {
        if(vis[child]==0)
        {
            if(dfs(child)) return true;
        }
        else if(vis[child]==1) return true;
    }
    vis[s]=2;
    return false;
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
    for(ll t=1;t<=tc;t++)
    {
        ll m;
        cin >> m;
        adj.clear();
        vis.clear();

        vector<string> nodes;

        for(ll i=0;i<m;i++)
        {
            string u,v;
            cin >> u >> v;
            adj[u].pb(v);
            vis[u]=0;
            vis[v]=0;
            nodes.pb(u);
            nodes.pb(v);
        }

        bool ok=true;

        for(ll i=0;i<(int)nodes.size();i++)
        {
            if(vis[nodes[i]]==0)
            {
                if(dfs(nodes[i]))
                {
                    ok=false;
                    break;
                }
            }
        }

        c_test;
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    
    //---------------------------------
    
    return 0;
}