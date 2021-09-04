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
const ll fx[]={0,1,0,-1};
const ll fy[]={1,0,-1,0};


ll vis[25][25];
char s[25][25];

ll sum,n,m;
void dfs(ll x ,ll y)
{
    ll i;
    vis[x][y]=1;
    ll a,b;
    for(i=0;i<4;i++)
    {
        a=x+fx[i];
        b=y+fy[i];
        if(s[a][b]=='.'&&a>=0&&b>=0&&a<n&&b<m&&!vis[a][b])
        {
            sum++;
            vis[a][b]=1;
            dfs(a,b);
        }
    }

}

void oka()
{


    memset(vis,0,sizeof vis);
    cin>>m>>n;
    ll i,j,x,y;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++){
            cin>>s[i][j];
            if(s[i][j]=='@')
            {
                x=i;
                y=j;
            }
        }
    }
    dfs(x,y);
    cout<<sum<<endl;





}

int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    
    ll i,t;
    cin>>t;

    for(i=1;i<=t;i++)
    {
        sum=1;
        cout<<"Case "<<i<<":"<<" ";


    oka();
    }
    
    //---------------------------------
    
    return 0;
}
