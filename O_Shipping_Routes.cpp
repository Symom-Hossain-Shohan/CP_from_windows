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

void bfs(string s)
{
    vis[s]=0;
    queue<string> q;
    q.push(s);
    while(!q.empty())
    {
        string cur=q.front();
        q.pop();
        for(auto child: adj[cur])
        {
            if(vis[child]==-1)
            {
                vis[child]=vis[cur]+1;
                q.push(child);
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
    cout << "SHIPPING ROUTES OUTPUT\n\n";
    for(ll t=1;t<=tc;t++)
    {
        ll n,m,p;
        cin >> n >> m >> p;
        adj.clear();
        vis.clear();
        for(ll i=0;i<n;i++)
        {
            vector<string> v;
            string s;
            cin >> s;
            adj[s]=v;
            vis[s]=-1;        }

        for(ll i=0;i<m;i++)
        {
            string u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cout <<"DATA SET  " << t << endl << endl;
        for(ll i=0;i<p;i++)
        {
            for(auto i: vis) i.second=-1;

            ll w;
            string entry ,ext;
            cin >> w >> entry >> ext;
            bfs(entry);

            
            if(vis[ext]==-1) cout << "NO SHIPMENT POSSIBLE\n";
            else 
            {
                if(vis[ext]==0) vis[ext]=1;
                cout <<"$" << w*vis[ext]*100 << endl;
            }

        }

        cout << endl;

    }

    cout <<"END OF OUTPUT\n";
    
    //---------------------------------
    
    return 0;
}