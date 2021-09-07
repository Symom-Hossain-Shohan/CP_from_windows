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
vector<ll> adj[27];
ll cnt[28];
vector<char> ans;
ll vis[28];

void dfs(ll node)
{
    vis[node]=1;
    for(auto child: adj[node])
    {
        if(!vis[child]) dfs(child);
    }

    ans.pb('A'+node);
}

int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    string s;
    vector<string> node;
    while(cin>> s)
    {
        if(s=="#") break;
        node.pb(s);
    }

    for(ll i=1;i<(int)node.size();i++)
    {
        ll l1=node[i-1].size();
        ll l2=node[i].size();
        ll m=min(l1,l2);
        for(ll j=0;j<m;j++)
        {
            if(node[i-1][j]!=node[i][j])
            {
                adj[node[i-1][j]-'A'].pb(node[i][j]-'A');
                cnt[node[i-1][j]-'A']++;
                cnt[node[i][j]-'A']++;
                break;
            }
        }
    }

    for(char ch='A';ch<='Z';ch++)
    {
        if(!vis[ch-'A'] and cnt[ch-'A']) dfs(ch-'A');
    }
    reverse(all(ans));
    for(auto i: ans) cout << i;
    cout << endl;
    
    //---------------------------------
    
    return 0;
}