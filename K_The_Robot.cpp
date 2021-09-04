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
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        int X=0,Y=0;
        bool ok=false;
        for(int i=0;i<(ll)s.size();i++)
        {
            if(s[i]=='U') Y++;
            else if(s[i]=='D') Y--;
            else if(s[i]=='L') X--;
            else X++;

            int x=0,y=0;
            for(int j=0;j<(ll)s.size();j++)
            {
                if(s[j]=='U')
                {
                    if(Y==y+1 and X==x) continue;
                    else y++; 
                }
                else if(s[j]=='D')
                {
                    if(Y==y-1 and X==x) continue;
                    else y--;
                }
                else if(s[j]=='L')
                {
                    if(Y==y and X==x-1) continue;
                    else x--;
                }
                else 
                {
                    if(Y==y and X==x+1) continue;
                    else x++;
                }
            }

            if(x==0 and y==0)
            {
                ok=true;
                break;
            }
        }

        if(ok) cout << X << ' ' << Y << endl;
        else cout << "0 0\n";
    }
    
    //---------------------------------
    
    return 0;
}
