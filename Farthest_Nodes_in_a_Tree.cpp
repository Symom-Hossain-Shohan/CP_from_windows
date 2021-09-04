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


vector<int> edge[30010] ;
vector<int> cost[30010] ;

int n,point1,point2,ans,v1;

bool visited[30010] ;
int d[30010] ;

void bfs(int src)
{
    visited[src]=1;
    d[src] =0;

    queue<int> Q;
    Q.push(src) ;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop() ;

        if(d[u]>v1)
        {
            v1=d[u] ;
            point1=u;
        }

        for(int i=0;i<(int)edge[u].size() ;i++)
        {
            int v=edge[u][i];

            if(d[v]<d[u]+cost[u][i] and !visited[v])
            {
                d[v]=d[u]+cost[u][i];
                Q.push(v);
                visited[v]=1;
            }
        }
    }
}

void allclear(int n)
{
    for(int i=0;i<n+5;i++)
    {
        edge[i].clear();
        cost[i].clear() ;
        d[i]=0;
        visited[i]=0;
    }
    v1=-1;
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

    for(int t=1;t<=tc;t++)
    {
        cin>> n;
        allclear(n);
        for(int i=0;i<n-1;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edge[u].pb(v);
        edge[v].pb(u) ;
        cost[u].pb(w);
        cost[v].pb(w) ;}

        bfs(0) ;

        for(int i=0;i<n+5;i++)
        {
            visited[i]=0;
            d[i]=0;
        }

        v1=-1;
        bfs(point1) ;

        c_test;
        printf("%d\n",v1) ;
    }

    
    //---------------------------------
    
    return 0;
}
