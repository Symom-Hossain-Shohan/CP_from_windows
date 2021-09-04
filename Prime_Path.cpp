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

vector<ll> adj[100001],primes;
int vis[100001],dist[100001];

bool isPrime(ll x)
{
    for(int i=2;i*i<=x;i++) if(x%i==0) return false;

    return true;
}

bool isValid(ll a, ll b)
{
    int cnt=0;
    while(a>0)
    {
        if(a%10!=b%10) cnt++;
        a/=10,b/=10;
    }
    if(cnt==1) return true;
    else return false;
}


void buildGraph()
{
    for(ll i=1000;i<=9999;i++)
    {
        if(isPrime(i)) primes.pb(i);
    }

    for(int i=0;i<primes.size();i++)
    {
        for(int j=0;j<primes.size();j++)
        {
            if(isValid(primes[i],primes[j]))
            {
                adj[primes[i]].pb(primes[j]);
                adj[primes[j]].pb(primes[i]);
            }
        }
    }
}

void bfs(ll node)
{
    queue <ll> q;
    q.push(node);

    vis[node]=1;
    dist[node]=0;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();

        for(int i=0;i<adj[curr].size();i++)
        {
            if(vis[adj[curr][i]]==0)
            {
                vis[adj[curr][i]]=1;
                dist[adj[curr][i]]=dist[curr]+1;
                q.push(adj[curr][i]);
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
    buildGraph();
    while(tc--)
    {
        ll a,b;
        cin >> a >> b;
        mem(dist,-1);
        mem(vis,0);
        bfs(a);

        if(dist[b]==-1) cout << "Impossible\n";
        else cout << dist[b] << endl;
    }
    
    //---------------------------------
    
    return 0;
}
