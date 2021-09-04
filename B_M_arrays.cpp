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
        ll n,m;
        cin >> n >> m;
        vector<ll> v(n),rem(m);

        for(int i=0;i<n;i++)
        {
            cin >> v[i];
            rem[v[i]%m]++;
        }
        ll ans=0;
        if(rem[0]>0) ans++;

        //for(int i=0;i<m;i++) cout << rem[i] << endl;
        for(int i=1,j=m-1;i<=j;i++,j--)
        {
            if(rem[i]==rem[j] and rem[i]!=0)
            {
                rem[i]=0;
                rem[j]=0;
                ans++;
            }
            else if(rem[i]!=0 and rem[j]!=0 and rem[i]<rem[j])
            {
                rem[j]=rem[j]-rem[i]-1;
                rem[i]=0;
                ans++;
            }
            else if(rem[i]!=0 and rem[j]!=0 and rem[i]>rem[j])
            {
                rem[i]=rem[i]-rem[j]-1;
                rem[j]=0;
                ans++;
            }
        }
        //cout << endl;
        //for(int i=0;i<m;i++) cout << rem[i] << endl;

        for(int i=1;i<m;i++) ans+=rem[i];
        cout << ans << endl;
    }
    
    //---------------------------------
    
    return 0;
}
