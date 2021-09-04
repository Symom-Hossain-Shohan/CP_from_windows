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
vector<int> adj[101];

int vis[101];

void dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++)
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
    int n,m;
    cin >> n >> m;
    vector<int >v[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        sum+=x;
        while(x--)
        {
            int y;
            cin >> y;
            v[i].pb(y);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=0;k<v[i].size();k++)
            {
                for(int l=0;l<v[j].size();l++)
                {
                    if(v[i][k]==v[j][l])
                    {
                        adj[i].pb(j);
                        adj[j].pb(i);
                        l=v[j].size();
                        k=v[i].size();
                        break;
                    }
                }
            }
        }
    }

    ll ans=-1;

    mem(vis,0);
    
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0) 
        {
            ans++;
            dfs(i);
        }
    }
    if(sum==0) cout << n << endl;
    else 
    cout << ans << endl;

    
    //---------------------------------
    
    return 0;
}
