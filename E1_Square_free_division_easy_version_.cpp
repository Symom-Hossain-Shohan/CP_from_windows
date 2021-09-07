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
int smallest_pf[10000009];

void sieve()
{
    for(ll i=2;i<=10000007;i++)
    {
        if(smallest_pf[i]==0)
        {
            for(ll j=i;j<=10000007;j+=i) smallest_pf[j]=i;
        }
    }
}

int fact(int x)
{
    int res=1;
    map<int,int> m;
    while(x>1)
    {
        m[smallest_pf[x]]++;
        x/=smallest_pf[x];
    }

    for(auto i: m)
    {
        if(i.second%2) res*=i.first;
    }
    return res;
}

int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    sieve();

    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll n,k;
        cin >> n >> k;
        vector<int> v;
        map<ll,ll> m;
        ll ans=1;

        for(ll i=0;i<n;i++) 
        {
            ll x;
            cin >> x;
            v.pb(fact(x));
        }

        for(ll i=0;i<n;i++)
        {
            if(m[v[i]]==0) m[v[i]]++;
            else 
            {
                m.clear();
                ans++;
                m[v[i]]++;
            }
        }

        cout << ans << endl;

    }
    
    //---------------------------------
    
    return 0;
}