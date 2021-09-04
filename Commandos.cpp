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
//code goes from here...
vector<int> adj[105];
int lev[105];
int lev1[105];

int maxd;


void bfs(int node)
{
    lev[node]=0;
    maxd=max(maxd,lev[node]);

    queue<int> q;
    q.push(node);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        maxd=max(maxd,lev[cur]);
        for(int i=0;i<(int)adj[cur].size();i++)
        {
            if(lev[adj[cur][i]]==-1)
            {
                lev[adj[cur][i]]=lev[cur]+1;
                q.push(adj[cur][i]);
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
        int b,r;
        cin >> b >> r;
        for(int i=0;i<105;i++) adj[i].clear();

        for(int i=0;i<r;i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int entry,exit;
        cin >> entry >> exit;

        maxd=-1;
        mem(lev,-1);
        
        bfs(entry);
        for(int i=0;i<b;i++) lev1[i]=lev[i];
        mem(lev,-1);
        bfs(exit);

        int  ans=-1;
        for(int i=0;i<b;i++) ans=max(ans,lev[i]+lev1[i]);
        c_test ;
        printf("%d\n",ans);
        
    }
    return 0;
}
