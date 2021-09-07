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
    ll tc;
    cin>> tc;
    while(tc--)
    {
        ll n,l,r;
        cin>> n >> l >> r;
        int left[n+1],right[n+1];
        mem(left,0);
        mem(right,0);
        for(ll i=1;i<=n;i++)
        {
            ll x;
            cin >> x;
            if(i<=l) left[x]++;
            else right[x]++;
        }

        

        for(ll i=0;i<=n;i++)
        {
            ll x=min(right[i],left[i]);
            right[i]-=x;
            left[i]-=x;
        }

        

        ll ans=0;
        ll lt=0,rt=0;
        ll a=0,b=0;
        for(ll i=0;i<=n;i++)
        {
            a+=left[i];
            b+=right[i];

            if(left[i]%2==0) lt+=left[i];
            else lt+=left[i]-1;
            if(right[i]%2==0) rt+=right[i];
            else rt+=right[i]-1;
        }
        if(a==b) ans=a;
        else if(a<b)
        {
            ans+=a;
            b-=a;
            ans+=(min(b,rt)/2);
            b-=min(b,rt);
            ans+=b;
        }
        else 
        {
            ans+=b;
            a-=b;
            ans+=(min(a,lt)/2);
            a-=min(a,lt);
            ans+=a;
        }

        cout<< ans << endl;
        
    }
    
    //---------------------------------
    
    return 0;
}