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
vector<bool> is_prime(1005,true);
vector<ll> primes;

void seive()
{
    for(ll i=3;i*i<=1004;i+=2)
    {
        if(is_prime[i])
        {
            for(ll j=i*i;j<=1004;j+=2*i) is_prime[j]=false;
        }
    }

    primes.pb(2);
    for(ll i=3;i<=1004;i+=2) if(is_prime[i])primes.pb(i);

}

vector<ll> adj[1005];
ll vis[1005];

void bfs(ll node)
{
    vis[node]=0;
    queue<ll> q;
    q.push(node);

    while(!q.empty())
    {
        ll cur=q.front();
        q.pop();

        for(auto child: adj[cur])
        {
            if(cur+child<=1001)
            {
                if(vis[cur+child]==-1)
                {
                    vis[cur+child]=vis[cur]+1;
                    q.push(cur+child);
                }
                
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
    seive();
    //for(auto p: primes) cout << p <<' ';

    
    ll tc;
    cin >> tc;
    for(ll i=3;i<=1004;i++)
    {
        for(ll j=0;j<(int)primes.size() and primes[j]<i; j++) 
        {
            if(i%primes[j]==0) adj[i].pb(primes[j]);
        }
    }

    

    for(ll t=1;t<=tc;t++)
    {
        ll u,v;
        cin >> u >> v;
        mem(vis,-1);

        bfs(u);

        c_test;
        if(vis[v]==-1) printf("-1\n");
        else printf("%lld\n",vis[v]);
    }
    

    
   

    
    //---------------------------------
    
    return 0;
}