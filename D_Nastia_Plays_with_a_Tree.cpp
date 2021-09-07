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
        ll n;
        cin >> n;
        vector<ll> adj[n+1];
        for(ll i=0;i<n-1;i++) 
        {
            ll u,v;
            cin >> u >> v;
            
            adj[u].pb(v);
            adj[v].pb(u);
        }

        for(int i=1;i<=n;i++) srt(adj[i]);
        
        ll vis[n+1];
        mem(vis,-1);
        
        vis[1]=0;
        queue<ll> q;
        q.push(1);
        ll d=0,node=1;
        ll parent[n+1];
        while(!q.empty())
        {
            ll cur=q.front();
            q.pop();
            if(d<vis[cur])
            {
                d=vis[cur];
                node=cur;
            }

            for(auto child: adj[cur])
            {
                if(vis[child]==-1)
                {
                    vis[child] =vis[cur]+1;
                    q.push(child);
                    parent[child]=cur;
                }
            }
        }

        vector<pair<ll,ll>> ans,ans1;

        for(ll i=1;i<=n;i++)
        {
            ll tm=adj[i].size()-2;
            for(ll j=0;j<tm;j++)
            {
                if(adj[i][j]!=parent[i]){
                ans.pb({i,adj[i][j]});
                ans1.pb({node,adj[i][j]});
                node=adj[i][j];
                }
                else tm++;
            }
        }

        cout << ans.size() << endl;
        for(ll i=0;i<(int)ans.size();i++)
        {
            cout << ans[i].first << " " << ans[i].second << " " << ans1[i].first << " " << ans1[i].second << endl;

        }
        
    }
    
    //---------------------------------
    
    return 0;
}