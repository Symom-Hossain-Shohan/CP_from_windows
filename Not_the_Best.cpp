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
vector<ll> adj[5005];
vector<ll> cost[5005];
ll dis[5005];
ll parent[5005];

void bfs(ll s)
{
    dis[s]=0;
    priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>> q;
    q.push({0,s});
    while(!q.empty())
    {
        ll u=q.top().second;
        ll d=q.top().first;
        q.pop();
        for(int i=0;i<(int)adj[u].size();i++)
        {
            ll v=adj[u][i];
            if(dis[v]>d+cost[u][i])
            {
                dis[v]=d+cost[u][i];
                q.push({dis[v],v});
                parent[v]=u;
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
    int tc;
    cin >> tc;
    for(int t=1;t<=tc;t++)
    {
        ll n,r;
        cin >>n >> r;
        for(int i=0;i<=n;i++) adj[i].clear() ,cost[i].clear();

        for(int i=0;i<r;i++)
        {
            ll u,v,c;
            cin >> u >> v >> c;
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(c);
            cost[v].pb(c);
        }

        for(int i=0;i<=n;i++) dis[i]=1e18;

        bfs(1);

        ll ans1=dis[n];
        ll p=parent[n];
        ll x;
        for(int i=0;i<(int)adj[p].size();i++)
        {
            if(adj[p][i]==n)
            {
                x=cost[p][i];
                cost[p][i]=1e18;
                break;
                
            }
        }

        for(int i=0;i<(int) adj[n].size();i++)
        {
            if(adj[n][i]==p)
            {
                cost[n][i]=1e18;
                break;
            }
        }

        for(int i=0;i<=n;i++) dis[i]=1e18;

        bfs(1);
        ll ans2=dis[n];
        while(ans2==ans1)
        {
            for(int i=0;i<=n;i++) dis[i]=1e18;
            p=parent[n];
            for(int i=0;i<(int)adj[p].size();i++)
            {
                if(adj[p][i]==n)
                {
                    //x=cost[p][i];
                    cost[p][i]=1e18;
                    break;
                
                }
            }

            for(int i=0;i<(int) adj[n].size();i++)
            {
                if(adj[n][i]==p)
                {
                    cost[n][i]=1e18;
                    break;
                }
            }

            bfs(1);
            ans2=dis[2];


        }

        ans1+=2*x;
        c_test;
        printf("%lld\n",min(ans1,ans2)) ;


    }
    
    //---------------------------------
    
    return 0;
}
