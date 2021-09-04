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
        string s;
        cin >> s;

        ll n=s.size();
        if(s[0]=='A' && s[n-1]=='B')
        {
            bool ok=true ;
            ll t=0;

            for(ll i=0;i<n;i++)
            {
                if(s[i]=='A') t++;
                else t--;
                if(t<0) {ok=false; break ;}
            }

            if(ok==false)
            {
                ok=true;
                t=0;
                for(ll i=0;i<n;i++)
                {
                    if(s[i]=='A' or s[i]=='C') t++;
                    else t--;
                    if(t<0) {ok=false; break;}
                }
            }

            if(t!=0) ok=false;

            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
        else if(s[0]=='A' && s[n-1]=='C')
        {
            bool ok=true ;
            ll t=0;

            for(ll i=0;i< n;i++)
            {
                if(s[i]=='A') t++;
                else t--;
                if(t<0) {ok=false ; break ;}
            }

            if(ok==false)
            {
                ok=true ;
                t=0;
                for(ll i=0;i<n;i++)
                {
                    if(s[i]=='A' or s[i]=='B') t++;
                    else t--;
                    if(t<0) {ok=false ;break ;}
                }
            }
            if(t!=0) ok=false;
            if(ok ) cout << "YES\n";
            else cout << "NO\n";
        }
        else if(s[0]=='B' and s[n-1]=='A')
        {
            bool ok=true ;
            ll t=0;
            
            for( ll i=0;i< n;i++)
            {
                if(s[i]=='B') t++;
                else t--;
                if(t<0) {ok=false; break;}
            }

            if(ok==false)
            {
                ok=true;
                t=0;
                for(ll i=0;i< n;i++)
                {
                    if(s[i]=='B' or s[i]=='C') t++;
                    else t--;
                    if(t<0) {ok=false; break;}
                }
            }
            if(t!=0) ok=false;
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
        else if( s[0]=='B' and s[n-1]=='C')
        {
            bool ok=true;
            ll t=0;

            for(ll i=0;i< n;i++)
            {
                if(s[i]=='B') t++;
                else t--;
                if(t<0) {ok=false ;break; }
            }

            if(ok==false){
                ok=true;
                t=0;
                for(ll i=0;i< n;i++)
                {
                    if(s[i]=='A' or s[i]=='B') t++;
                    else t--;
                    if(t<0) {ok=false; break;}
                }
            }
            if(t!=0) ok=false;
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }

        else if(s[0]=='C' and s[n-1]=='A')
        {
            bool ok=true;
            ll t=0;
            
            for(ll i=0;i< n;i++)
            {
                if(s[i]=='C') t++;
                else t--;
                if(t<0) {ok=false; break;}
            }

            if(ok==false)
            {
                ok=true;
                t=0;
                for(ll i=0;i<n;i++)
                {
                    if(s[i]=='C' or s[i]=='B') t++;
                    else t--;
                    if(t<0) {ok=false; break;}
                }


            }
            if(t!=0) ok=false;
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
        else if(s[0]=='C' and s[n-1]=='B')
        {
            bool ok=true;
            ll t=0;
            for(ll i=0;i<n;i++)
            {
                if(s[i]=='C') t++;
                else t--;
                if(t<0) {ok=false; break;}
            }

            if(ok==false)
            {
                ok=true;
                t=0;
                for(ll i=0;i<n;i++)
                {
                    if(s[i]=='C' or s[i]=='A') t++;
                    else t--;
                    if(t<0) {ok=false ; break;}
                }
            }

            if(t!=0) ok=false;

            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";

        

    }
    
    //---------------------------------
    
    return 0;
}
