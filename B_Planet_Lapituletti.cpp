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
        int ar[]={0,1,2,5,8,10,11,12,15,18,20,21,22,25,28,50,51,52,55,58,80,81,82,85,88};
        ll n=25;
        int h,m;
        int x,y;
        cin >> h >> m;
        string s;
        cin>>s ;
        x=(s[0]-'0')*10+(s[1]-'0');
        y=(s[3]-'0')*10+(s[4]-'0');
        
        bool ok=false;
        string ans1,ans2;
        ll t1,t2;
        ll dif=1e18;
        
        int tt1,tt2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ar[i]>=x && ar[i]<h && ar[j]>=y && ar[j]<m)
                {
                    if(ar[i]<=8)
                    {
                       tt1=ar[i]*10;
                    }
                    else tt1=(ar[i]%10)+ar[i]/10;

                    if(ar[j]<=8)
                    {
                        tt2=ar[j]*10;

                    }
                    else tt2=(ar[j]%10)+ar[j]/10;

                    if(tt1<m && tt2<h)
                    {
                        if(ar[i]<=8) cout << "0" << ar[i] << ':';
                        else cout << ar[i] << ':';

                        if(ar[j]<=8) cout << "0" << ar[j] << "\n";
                        else cout << ar[j] << endl;

                        ok=true;
                        break;
                    }
                }
            }
            if(ok) break;
        }

       if(ok==false)
       {
           for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ar[i]<=x && ar[i]<h && ar[j]<=y && ar[j]<m)
                {
                    if(ar[i]<=8)
                    {
                       tt1=ar[i]*10;
                    }
                    else tt1=(ar[i]%10)+ar[i]/10;

                    if(ar[j]<=8)
                    {
                        tt2=ar[j]*10;

                    }
                    else tt2=(ar[j]%10)+ar[j]/10;

                    if(tt1<m && tt2<h)
                    {
                        if(ar[i]<=8) cout << "0" << ar[i] << ':';
                        else cout << ar[i] << ':';

                        if(ar[j]<=8) cout << "0" << ar[j] << "\n";
                        else cout << ar[j] << endl;

                        ok=true;
                        break;
                    }
                }
            }
            if(ok) break;
        }
       }

    }
    
    //---------------------------------
    
    return 0;
}
