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
        ll n,b;
        cin >> n >> b;
        map<string,vector<pair<ll,ll>>> m;
        string s1,s2;
        ll p,q;
        set<string> s;
        for(ll i=0;i<n;i++)
        {
            cin >> s1 >> s2 >> p >> q;
            m[s1].pb({p,q});
            s.in(s1);
            cout << s1 << ' ' << s2 << ' ' << q << ' ' << q << endl;
        }

        ll t=1;
        vector<pair<ll,pair<ll,ll>>> v;
        for(auto i: s)
        {
            for(auto j: m[i]) 
            {
                v.pb({t,{j.first,j.second}});
            }
            t++;
        }


        ll quality=0,price=0;
        srt(v);
        
        
        for(ll i=0;i<n;i++)
        {
            if(v[i].second.second>=quality)
            {
                price=v[i].second.first;
                ll tm=v[i].first;

                vector<ll> vist(t+1);
                vist[tm]=1;
                for(ll j=0;j<n;j++)
                {
                    if(vist[v[j].first]) continue;
                    else 
                    {
                        if(v[j].second.second>=quality)
                        {
                            price+=v[j].second.first;
                            vist[v[j].first]=1;
                        }
                    }
                }

                bool ok=true;

                for(ll j=1;j<=t;j++)
                {
                    if(!vist[j]) 
                    {
                        ok=false;
                        break;
                    }
                }

                if(ok and price<=b) quality=v[i].second.second;
                
            }
        }

        //cout << quality << endl;

        //for(auto i: v) cout << i.second.first << ' ' << i.second.second << endl;
        
    }
    
    //---------------------------------
    
    return 0;
}