#include <bits/stdc++.h>
;
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



//code goes from here...
ll n;
ll memo[105][25011];
ll coin[105];

void dp(ll pos,ll val)
{
    for(ll i=pos;i<=n;i++)
    {
        for(ll j=1;j<=val;j++)
        {
            if(j<coin[i])
            {
                memo[i][j]=memo[i-1][j];
            }
            else 
            {
                memo[i][j]=(memo[i-1][j]||memo[i-1][j-coin[i]]);
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
        mem(memo,-1);
        cin >> n;
        for(ll i=1;i<=n;i++) cin >> coin[i];
        for(ll i=0;i<105;i++) memo[i][0]=1;
        
        ll sum=0;
        for(ll i=1;i<=sum;i++) memo[0][i]=0;
        for(ll i=1;i<=n;i++) sum+=coin[i];
        ll t=sum;
        sum/=2;
        
        dp(1,sum);
        for(ll i=sum;i>=1;i--)
        {
            if(memo[n][i]==1)
            {
                cout << t-2*i << endl;
                break;
            }
        }
    }
    
    //---------------------------------
    
    return 0;
}
