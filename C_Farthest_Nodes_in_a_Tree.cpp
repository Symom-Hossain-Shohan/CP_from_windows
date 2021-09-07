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
vector<ll> adj[30005];
vector<ll> cost[30005];
ll max_dist,f_node;
ll vis[30005];
ll dis[30005];

void bfs(ll s)
{
    vis[s]=1;
    dis[s]=0;
    queue<ll> q;
    q.push(s);
    while(!q.empty())
    {
        ll cur=q.front();
        q.pop();
        if(dis[cur]>max_dist)
        {
            max_dist=dis[cur];
            f_node=cur;
        }

        for(ll i=0;i<(int)adj[cur].size();i++)
        {
            if(vis[adj[cur][i]]==0)
            {
                vis[adj[cur][i]]=1;
                q.push(adj[cur][i]);
                dis[adj[cur][i]]=dis[cur]+cost[cur][i];
            }
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
    for(ll t=1;t<=tc;t++)
    {
        ll n;
        cin >> n;

        for(int i=0;i<n;i++) adj[i].clear(),cost[i].clear();

        for(int i=0;i<n-1;i++)
        {
            ll u,v,c;
            cin >> u >> v >> c;
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(c);
            cost[v].pb(c);
        }

        max_dist=-1;
        mem(vis,0);
        mem(dis,0);
        bfs(0);
        max_dist=-1;
        mem(vis,0);
        mem(dis,0);
        //cout << f_node << endl;
        bfs(f_node);
        c_test;
        printf("%lld\n",max_dist);

    }
    
    //---------------------------------
    
    return 0;
}