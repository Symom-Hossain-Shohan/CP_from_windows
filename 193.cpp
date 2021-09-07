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

ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {x = 1;y = 0;return a;}
    ll x1, y1, d = ext_gcd(b, a % b, x1, y1);
    x = y1;y = x1 - y1 * (a / b);
    return d;
}

//code goes from here...
ll n,m;
map<pair<ll,ll>,ll> edges;
set<ll> max_set;

bool is_valid(ll node , set<ll> ind_set)
{
    for(auto i: ind_set)
    {
        if(edges[{i,node}]) return false;
    }
    return true;
}

void fun(ll node,set<ll> ind_set)
{
    for(ll i=node;i<=n;i++)
    {
        if(is_valid(i,ind_set))
        {
            ind_set.in(i);
            fun(i+1,ind_set);
            ind_set.erase(i);
        }
    }
    if(ind_set.size()>max_set.size()) max_set=ind_set;
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
        cin >> n >> m;
        edges.clear();
        max_set.clear();
        for(ll i=0;i<m;i++)
        {
            ll u,v;
            cin >> u >> v;
            edges[{u,v}]=1;
            edges[{v,u}]=1;
        }

        set<ll> ind_set;
        fun(1,ind_set);
        vector<ll> ans;
        for(auto i: max_set) ans.pb(i);

        cout << max_set.size() << endl;
        if (max_set.size()>0) printf("%d", ans[0]);
        for (int i=1, sizea=ans.size(); i<sizea; i++)
            printf(" %d", ans[i]);
        printf("\n");
        
    }
    
    //---------------------------------
    
    return 0;
}