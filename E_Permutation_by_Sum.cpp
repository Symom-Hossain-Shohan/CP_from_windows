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
    cin >> tc;

    while(tc--)
    {
        ll n,l,r,s;
        cin >> n >> l >> r >> s;
        ll low=r-l+1;
        low=low*(low+1)/2;
        ll high=0;
        for(ll i=n,j=0;j<r-l+1;j++,i--)high+=i;

        if(s>=low and s<=high) 
        {
            ll ar[n+1];
            mem(ar,0);

            vector<ll> ans;
            ll x=r-l+1;
            ll y=x;
            x--;
            while(x--)
            {
                y--;
                
                //cout << y << endl;
                //cout << s << endl;
                
                for(ll i=n;i>=1;i--)
                {
                    //cout << i << endl;
                    if(ar[i]==0 and y*(y+1)/2<=s-i)
                    {
                        ar[i]=1;
                        //cout << i << endl;
                        ans.pb(i);
                        s-=i;
                        break;
                    }
                }
            }
            ar[s]=1;
            ans.pb(s);

            for(ll i=0;i<l-1;i++)
            {
                for(ll j=1;j<=n;j++)
                {
                    if(ar[j]==0)
                    {
                        ar[j]=1;
                        cout<< j << ' ';
                        break;
                    }
                }
            }

            for(ll i=0;i<(int)ans.size();i++) cout<< ans[i] << ' ';
            for(ll i=r;i<n;i++)
            {
                for(ll j=1;j<=n;j++)
                {
                    if(ar[j]==0)
                    {
                        ar[j]=1;
                        cout << j << ' ';
                        break;
                    }
                }
            }

        }
        else cout << "-1";

        cout << endl;
    }
    
    //---------------------------------
    
    return 0;
}