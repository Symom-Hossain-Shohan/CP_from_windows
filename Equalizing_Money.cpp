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
vector<int > adj[1005];
int money[1005];
int vis[1005];

int ss,cc;

void dfs(int node)
{
    vis[node]=1;
    ss+=money[node];
    cc++;
    for(int i=0;i<(int)adj[node].size();i++)
    {
        if(vis[adj[node][i]]==0) dfs(adj[node][i]);
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
        int n,m;
        cin >> n >> m;
        int sum=0;
        for(int i=1;i<=n;i++) cin >> money[i],sum+=money[i];

        for(int i=0;i<=n;i++) adj[i].clear();

        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int avg=sum/n;
        bool ok=true;
        if(sum%n!=0) ok=false;
        else 
        {
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==0)
                {
                    ss=0,cc=0;
                    dfs(i);
                    if(ss%cc!=0 or ss/cc!=avg)
                    {
                        ok=false;break;
                    }
                }
            }

        }

        c_test;
        if(ok) printf("Yes\n");
        else printf("No\n");
        mem(vis,0);

    }
    
    //---------------------------------
    
    return 0;
}
