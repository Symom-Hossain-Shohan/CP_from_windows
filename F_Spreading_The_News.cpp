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
vector<ll> adj[2505];
ll vis[2505];
ll dis[2505];
ll lev[2505];

void bfs(ll s)
{
    vis[s]=1;
    dis[s]=0;
    //lev[0]++;
    queue<ll> q;
    q.push(s);
    while(!q.empty())
    {
        ll cur=q.front();
        q.pop();
        for(ll i=0;i<(int) adj[cur].size();i++)
        {
            if(!vis[adj[cur][i]])
            {
                vis[adj[cur][i]]=1;
                q.push(adj[cur][i]);
                dis[adj[cur][i]]=dis[cur]+1;
                lev[dis[cur]+1]++;
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
    ll e;
    cin >> e;
    for(int i=0;i<e;i++)
    {
        ll x;
        cin >> x;
        for(ll j=0;j<x;j++)
        {
            ll v;
            cin >> v;
            adj[i].pb(v);
        }
    }

    ll t;
    cin >> t;
    while(t--)
    {
        ll s;
        cin >> s;

        mem(vis,0);
        mem(dis,0);
        mem(lev,0);

        bfs(s);
        ll mx=-1,day;
        for(ll i=1;i<=e;i++)
        {
            if(lev[i]>mx)
            {
                mx=lev[i];
                day=i;
            }
        }
        if(mx==0) 
        {
            cout << 0 << endl;
            continue;
        }
        cout<< mx << ' ' << day << endl;
    }
    
    //---------------------------------
    
    return 0;
}