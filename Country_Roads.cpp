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



int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    int tc;
    cin>> tc;
    for(int t=1;t<=tc;t++)
    {
        ll n,r;
        cin >>n >> r;
        vector<int> adj[n];
        int cost[n][n];
        mem(cost,0);
        for(int i=0;i<r;i++)
        {
            int u,v,c;
            cin >> u >> v >> c;
            if(cost[u][v])
            {
                cost[u][v]=cost[v][u]=min(cost[u][v],c);
            }
            else 
            {
                adj[u].pb(v);
                adj[v].pb(u);
                cost[u][v]=cost[v][u]=c;
            }
        }

        int dis[n];
        for(int i=0;i<n;i++) dis[i]=INT_MAX;
        int town;
        cin >> town;
        
        dis[town]=0;
        queue<int> q;
        q.push(town);

        while(!q.empty())
        {
            ll u=q.front();
            q.pop();
            for(int i=0;i<(int)adj[u].size();i++)
            {
                ll v=adj[u][i];
                ll mx=max(dis[u],cost[u][v]);
                if(dis[v]>mx)
                {
                    dis[v]=mx;
                    q.push(v);
                }
            }
        }

        c_test;
        for(int i=0;i<n;i++)
        {
            if(dis[i]==INT_MAX) printf("Impossible\n");
            else printf("%d\n",dis[i]);
        }

    }
    
    //---------------------------------
    
    return 0;
}
