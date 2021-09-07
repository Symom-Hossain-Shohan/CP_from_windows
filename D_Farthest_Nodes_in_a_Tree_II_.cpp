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
#define c_test       printf("Case %lld:\n",t)

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

ll vis[30005];
ll dis[30005];
ll f_dis[30005];
int parent[30005];

ll maxD,fNode;

void farthest_node(ll node)
{
    vis[node]=1;
    dis[node]=0;
    queue<ll> q;
    q.push(node);
    while(!q.empty())
    {
        ll cur=q.front();
        q.pop();
        if(dis[cur]>maxD)
        {
            maxD=dis[cur];
            fNode=cur;
        }
        for(ll i=0;i<(int)adj[cur].size();i++)
        {
            if(!vis[adj[cur][i]])
            {
                vis[adj[cur][i]]=1;
                dis[adj[cur][i]]=dis[cur]+cost[cur][i];
                q.push(adj[cur][i]);
                parent[adj[cur][i]]=cur;
            }
        }
    }
}

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
        if(maxD<dis[cur])
        {
            maxD=dis[cur];
        }

        for(ll i=0;i<(int)adj[cur].size();i++)
        {
            if(!vis[adj[cur][i]])
            {
                vis[adj[cur][i]]=1;
                q.push(adj[cur][i]);
                dis[adj[cur][i]]=dis[cur]+cost[cur][i];
            }
        }
    }
}


void BFS(ll s)
{
    vis[s]=1;
    queue<ll> q;
    q.push(s);
    while(!q.empty())
    {
        ll cur=q.front();
        q.pop();
        for(ll i=0;i<(int)adj[cur].size();i++)
        {
            if(!vis[adj[cur][i]])
            {
                vis[adj[cur][i]]=1;
                q.push(adj[cur][i]);
                if(f_dis[adj[cur][i]]==-1) f_dis[adj[cur][i]]=f_dis[cur]+cost[cur][i];
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
        for(ll i=0;i<n;i++) adj[i].clear(),cost[i].clear();

        for(ll i=0;i<n-1;i++)
        {
            ll u,v,c;
            cin >> u >> v >> c;
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(c);
            cost[v].pb(c);
        }

        //findig the initital farthest node

        mem(vis,0);
        mem(dis,0);
        mem(f_dis,-1);

        maxD=-1;
        farthest_node(0);
        f_dis[0]=maxD;
        maxD=-1;

        mem(vis,0);
        mem(dis,0);
        bfs(fNode);
        f_dis[fNode]=maxD;

        ll ch=fNode;
        ll p=parent[ch];
        while(p!=0)
        {
            f_dis[p]=max(f_dis[ch]+(dis[ch]-dis[p]),(dis[p]-dis[fNode]));
            ch=p;
            p=parent[ch];
        }

        mem(vis,0);
        BFS(0);

        c_test;
        for(ll i=0;i<n;i++) printf("%lld\n",f_dis[i]);
    }
    
    //---------------------------------
    
    return 0;
}