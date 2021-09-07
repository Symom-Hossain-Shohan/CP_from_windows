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



int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    ll n;
    cin >> n;
    char mtx[n][n];

    pair<ll,ll> entry,ext;

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++) 
        {
            cin>> mtx[i][j];
            if(mtx[i][j]=='X')
            {
                ext={i,j};
            }
            else if(mtx[i][j]=='@') entry={i,j};
        }
    }

    ll vis[n][n];
    map<pair<ll,ll>,pair<ll,ll>> parent;
    mem(vis,0);

    vis[entry.first][entry.second]=1;
    queue<pair<ll,ll>> q;
    q.push(entry);
    while(!q.empty())
    {
        pair<ll,ll> cur=q.front();
        q.pop();
        for(ll i=0;i<4;i++)
        {
            ll r=cur.first+dRow[i];
            ll c=cur.second+dCol[i];

            if(!vis[r][c] and r>=0 and r<n and c>=0 and c<n and mtx[r][c]!='O')
            {
                vis[r][c]=1;
                q.push({r,c});
                parent[{r,c}]=cur;
            }
        }
    }

    if(vis[ext.first][ext.second])
    {
        cout << "Y\n";

        pair<ll,ll> ch=ext;
        pair<ll,ll> p=parent[ext];
        mtx[ch.first][ch.second]='+';
        while(p!=entry)
        {
            mtx[p.first][p.second]='+';
            ch=p;
            p=parent[ch];
        }
        //mtx[entry.first][entry.second]='+';

        for(int i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cout << mtx[i][j];
            }
            cout<< endl;
        }
        
    }
    else cout << "N\n";


    
    //---------------------------------
    
    return 0;
}