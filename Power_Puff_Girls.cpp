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
int r,cc;
char mtx[22][22];
pair<int,int> a,b,c,h;
int level[22][22];



void bfs(int i,int j)
{
    level[i][j]=0;
    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty())
    {
        pair<int,int> cur=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int t=cur.first+dRow[i];
            int tt=cur.second+dCol[i];
            if(mtx[t][tt]!='#' and level[t][tt]==-1 and t<r and tt<cc and t>=0 and tt>=0 and mtx[t][tt]!='m' )
            {
                level[t][tt]=level[cur.first][cur.second]+1;
                q.push({t,tt});
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
    int tc;
    cin>> tc;
    for(int t=1;t<=tc;t++)
    {
        cin >> r >> cc;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<cc;j++)
            {
                cin >> mtx[i][j];
                if(mtx[i][j]=='a') a={i,j};
                else if(mtx[i][j]=='b') b={i,j};
                else if(mtx[i][j]=='c') c={i,j};
                else if(mtx[i][j]=='h') h={i,j};
            }
        }

        int ans=0;
        mem(level,-1);

        bfs(a.first,a.second);
        ans=max(ans,level[h.first][h.second]);

        mem(level,-1);
        bfs(b.first,b.second);
        ans=max(ans,level[h.first][h.second]);

        mem(level,-1);
        bfs(c.first,c.second);
        ans=max(ans,level[h.first][h.second]);

        c_test;
        printf("%d\n",ans);


    }
    
    //---------------------------------
    
    return 0;
}
