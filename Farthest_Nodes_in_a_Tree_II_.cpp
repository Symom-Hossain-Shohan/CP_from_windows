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
#define c_test       printf("Case %lld:",t)

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
vector<int> adj[30005];
vector<int> cost[30005];
int vis[30005];
int dis[30005];
int parent[30005];
int f_dis[30005];
int maxD,f_node;


void bfs(int s)
{
    vis[s]=1;
    dis[s]=0;
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(maxD<dis[cur])
        {
            maxD=dis[cur];
            f_node=cur;
        }

        for(int i=0;i<(int)adj[cur].size();i++)
        {
            int d=adj[cur][i];
            if(dis[d]<dis[cur]+cost[cur][i] and !vis[d])
            {
                vis[d]=1;
                dis[d]=dis[cur]+cost[cur][i];
                q.push(d);
                parent[d]=cur;
            }
        }
    }
}

void BFS(int s)
{
    vis[s]=1;
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        if(maxD<dis[cur]) maxD=dis[cur];

        for(int i=0;i<(int)adj[cur].size();i++)
        {
            int d=adj[cur][i];
            if(dis[d]<dis[cur]+cost[cur][i] and !vis[d])
            {
                vis[d]=1;
                dis[d]=dis[cur]+cost[cur][i];
                q.push(d);
            }
        }
    }
}

void bbfs(int s)
{
    vis[s]=1;
    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        for(int i=0;i<(int)adj[cur].size();i++)
        {
            int child=adj[cur][i];
            if(!vis[child])
            {
                vis[child]=1;
                q.push(child);
                if(f_dis[child]==-1) f_dis[child]=f_dis[cur]+cost[cur][i];
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
        int n;
        cin >> n;
        for(int i=0;i<n;i++) adj[i].clear(),cost[i].clear();

        for(int i=0;i<n-1;i++)
        {
            int u,v,c;
            cin >> u >> v >> c;
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(c);
            cost[v].pb(c);
        }

        //to find the first farthest node

        mem(vis,0);
        mem(dis,0);
        mem(f_dis,-1);

        maxD=-1;
        bfs(0);
        
        f_dis[0]=maxD;

        

        mem(vis,0);
        mem(dis,0);
        maxD=-1;

        BFS(f_node);
        f_dis[f_node]=maxD;
        //cout << f_node << ' ' << f_dis[f_node] << endl;

        

        int ch=f_node;
        int p=parent[ch];

        //cout << ch << endl;
        //cout << f_dis[ch] << endl;;
        while(p!=0)
        {
            
            //cout << p << endl;
            f_dis[p]=max(f_dis[ch]+(dis[ch]-dis[p]),(dis[p]-dis[f_node]));
            //cout << dis[p]-dis[ch] << endl;
            ch=p;
            p=parent[ch];
        }
        

        //cout << f_dis[3] << ' ' << f_dis[2] << ' ' << f_dis[1] << ' ' << f_dis[0] <<  endl;
        //works fine till here

        
        mem(vis,0);
        bbfs(0);

        c_test;
        printf("\n");
        for(int i=0;i<n;i++) printf("%d\n",f_dis[i]);


    }
    
    //---------------------------------
    
    return 0;
}
