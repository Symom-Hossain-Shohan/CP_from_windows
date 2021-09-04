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
int s,tt;

vector<int> primes;     
vector<int> adj[1001];
int lev[1001];

void bfs(int node)
{
    lev[node]=0;
    queue<int>q;
    q.push(node);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int i=0;i<(int)adj[cur].size();i++)
        {
            if(lev[adj[cur][i]]==0)
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
    bool pr[1003];
    mem(pr,true);

    pr[0]=false;
    pr[1]=false;
    for(int i=3;i*i<=1002;i+=2)
    {
        if(pr[i]==true){
        for(int j=i*i;j<=1002;j+=2*i)
        {
            pr[j]=false;
        }
        }
    }

    primes.pb(2);
    for(int j=3;j<1003;j+=2) if(pr[j]) primes.pb(j);

    
    
    ll tc;
    cin>> tc;
    for(int t=1;t<=tc;t++)
    {
        cin >> s>> tt;
        queue<int> Q;
        Q.push(s);
        for(int i=0;i<1001;i++) adj[i].clear();
        while(!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            if(x>tt) continue;
            else 
            {
                for(int i=0;primes[i]<=x;i++)
                {
                    if(x%primes[i]==0)
                    {
                        adj[x].pb(x+primes[i]);
                        Q.push(x+primes[i]);
                    }
                }
            }
        }

        bfs(s);
        c_test;
        if(lev[tt]==0) printf("-1\n");
        else printf("%d\n",lev[tt]);
        mem(lev,0);
    }
    
    
    //---------------------------------
    
    return 0;
}
