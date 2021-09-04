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
    string a,b ;
    cin >> a >> b;
    ll mtx[27][27];
    for(int i=0;i<27;i++)
    {
        for(int j=0;j<27;j++)
        {
            if(i==j) mtx[i][j]=0;
            else mtx[i][j]=1e18;
        }
    }

    ll m;
    cin >> m ;
    for(int i=0;i<m;i++)
    {
        char u,v;
        ll c;
        cin >> u >> v >> c;
        mtx[u-'a'][v-'a']=min(c,mtx[u-'a'][v-'a']);
    }

    
    for(int k=0;k<26;k++)
    {
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(mtx[i][j]>mtx[i][k]+mtx[k][j]) mtx[i][j]=mtx[i][k]+mtx[k][j];
            }
        }
    }
    

    string ans="";
    if(a.size()!=b.size()) 
    {
        cout << -1 << endl;
        return 0;
    }

    ll cnt=0;

    for(int i=0;i<(int)a.size();i++)
    {
        ll val=1e18;
        char ch='A';
        for(char c='a';c<='z';c++)
        {
            if(mtx[a[i]-'a'][c-'a']!=1e18 and mtx[b[i]-'a'][c-'a']!=1e18)
            {
                if(mtx[a[i]-'a'][c-'a']+mtx[b[i]-'a'][c-'a']<val)
                {
                    val=mtx[a[i]-'a'][c-'a']+mtx[b[i]-'a'][c-'a'];
                    ch=c;
                }
            }
        }
        if(ch=='A')
        {
            cout << -1 << endl;
            return 0;
        }
        ans+=ch;
        cnt+=val;
    }

    cout << cnt << endl << ans << endl;
    
    //---------------------------------
    
    return 0;
}
