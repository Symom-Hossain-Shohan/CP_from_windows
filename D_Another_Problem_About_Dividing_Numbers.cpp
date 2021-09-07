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
vector<ll> primes;
vector<bool> is_prime(500001,true);

void seive()
{
    for(ll i=3;i*i<500001;i+=2)
    {
        if(is_prime[i])
        {
            for(ll j=i*i;j<500001;j+=2*i)
            {
                is_prime[j]=false;
            }
        }
    }

    primes.pb(2);
    for(ll i=3;i<500001;i+=2) if(is_prime[i]) primes.pb(i);

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
   
    
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll a,b,k;
        cin >> a >> b >> k;
        map<ll,ll> ma,mb;
        ll t1=a,t2=b;
        set<ll> sa,sb;
        for(ll i=0;primes[i]<=sqrt(a)+1;i++)
        {
            while(a%primes[i]==0)
            {
                ma[primes[i]]++;
                sa.insert(primes[i]);
                a/=primes[i];
            }
        }
        if(a!=1) ma[a]++,sa.insert(a);

        for(ll i=0;primes[i]<=sqrt(b)+1;i++)
        {
            while(b%primes[i]==0)
            {
                mb[primes[i]]++;
                sb.insert(primes[i]);
                b/=primes[i];
            }
        }

        if(b!=1) mb[b]++,sb.insert(b);
        
        if(k==1)
        {
            if((t1%t2==0 or t2%t1==0) and t1!=t2) cout << "YES\n";
            else cout << "NO\n";
        }
        else 
        {
            ll sum=0;
            for(auto i: ma) sum+=i.second;
            for(auto i: mb) sum+=i.second;

            if(sum>=k) cout << "YES\n";
            else cout << "NO\n";
        }

        

    }
    
    //---------------------------------
    
    return 0;
}