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
char mtx[1005][1005];
ll dis[1005][1005];
ll n,m;

void bfs(ll x,ll y)
{
    dis[x][y]=0;
    deque<pair<ll,ll>> q;
    q.push_front({x,y});
    while(!q.empty())
    {
        pair<ll,ll> cur=q.front();
        q.pop_front();
        if(cur.first==n-1 and cur.second==m-1) return;
        for(int i=0;i<4;i++)
        {
            ll r=cur.first+dRow[i];
            ll c=cur.second+dCol[i];
            if(mtx[cur.first][cur.second]==mtx[r][c] and r>=0 and r<n and c>=0 and c<m and dis[r][c]>dis[cur.first][cur.second])
            {
                dis[r][c]=dis[cur.first][cur.second];
                q.push_front({r,c});
            }
            else if(r>=0 and r<n and c>=0 and c<m and dis[r][c]>dis[cur.first][cur.second]+1)
            {
                dis[r][c]=dis[cur.first][cur.second]+1;
                q.push_back({r,c});
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
    while(tc--)
    {
        cin>> n >> m;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cin>> mtx[i][j];
            }
        }

        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++) dis[i][j]=1e18;
        }

        bfs(0,0);

        cout << dis[n-1][m-1] << endl;
    }
    
    //---------------------------------
    
    return 0;
}