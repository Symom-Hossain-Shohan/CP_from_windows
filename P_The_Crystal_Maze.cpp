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
#define c_test       printf("Case %lld:\n",t)

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
int n,m,q;
char mtx[505][505];
int vis[505][505];
int cnt;

void dfs(int x,int y)
{
    vis[x][y]=1;
    if(mtx[x][y]=='C')cnt++;
    for(ll i=0;i<4;i++)
    {
        ll r=x+dRow[i];
        ll c=y+dCol[i];
        if(r>=1 and r<=n and c>=1 and c<=m and !vis[r][c] and mtx[r][c]!='#')
        {
            dfs(r,c);
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
    for(ll t=1;t<=tc;t++)
    {
        cin >> n >> m >> q;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cin >> mtx[i][j];
        }

        vector<pair<int,int>> query;
        for(int i=0;i<q;i++)
        {
            int x,y;
            cin >> x >> y;
            query.pb({x,y});
        }
        vector<int> ans(q,-1);
        for(int i=0;i<q;i++)
        {
            if(ans[i]==-1)
            {
                mem(vis,0);
                cnt=0;
                dfs(query[i].first,query[i].second);

                for(int j=0;j<q;j++)
                {
                    if(vis[query[j].first][query[j].second]==1) ans[j]=cnt;
                }
            }
        }

        c_test;
        for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    }
    
    //---------------------------------
    
    return 0;
}
