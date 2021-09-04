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
    int tc;
    cin>> tc;
    for(int t=1;t<=tc;t++)
    {
        ll n , c;
        cin >> n >> c;
        vector<ll> v,v1;
        for(int i=1;i<=n;i++) v.pb(i);
        ll ans=-1;
        do
        {
            ll sum=0;
            v1=v;
            for(int i=0;i<n;i++)
            {
                int j=min_element(v1.begin()+i,v1.end())-v1.begin();
                sum+=(j-i+1);
                reverse(v1.begin()+i,v1.begin()+j+1);
            }

            if(sum-1==c)
            {
                ans=sum-1;
                break;
            }
        } while (next_permutation(all(v)));
        cout << "Case #" << t <<": " ;
        if(ans==-1) cout << "IMPOSSIBLE\n";
        else 
        {
            for(auto i: v) cout << i << ' ';
            cout << endl;
        }
    }
    
    //---------------------------------
    
    return 0;
}
