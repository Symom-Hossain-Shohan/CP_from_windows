 #include<bits/stdc++.h>
 #include<ext/pb_ds/assoc_container.hpp>
 #include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;







//defines...
#define ll long long
#define tata return;
#define pb push_back
#define mp make_pair
#define in insert
#define run ios_base::sync_with_stdio(false);cin.tie(NULL);
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define vec vector<ll>
#define setl set<ll>
#define mapl map<ll,ll>
#define shunno cout<<0<<endl;
#define ek cout<<1<<endl;
#define pi 2*acos(0.0)
#define hobena cout<<-1<<endl;
  ll mod =1e9+7;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p){ll r=1;while(p){if(p&1LL) r=modMul(r,b);b=modMul(b,b); p>>=1LL;}return r;}
inline ll modInverse(ll a){ return bigMod(a,mod-2);}
inline ll modDiv(ll a,ll b){ return modMul(a,modInverse(b));}

//typedefs...
typedef pair<ll,ll>pll;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

//const..
const ll fx[]={0,1,0,-1};
const ll fy[]={1,0,-1,0};


//...Custom_sort.......

bool cmp(pair<ll,ll>&x,pair<ll,ll>&y)
{

        return x.second < y.second;

}



ll ncr(ll n, ll k)
{
    ll res = 1;


    if (k > n - k)
        k = (n - k);

    for (ll i = 0; i < k; ++i) {
        res *= (n - i);

        res /= (i + 1);
    }

    return res;
}



ll po(ll n,ll k)
{
    ll i=1;
    ll ans=1;
    for(i=1;i<=k;i++)
    {
        ans*=n;
    }
    return ans;
}
ll cnt(ll n)
{
    ll i;
    i=0;
    while(n>0)
    {
        i++;
        n/=10;
    }
    return i;
}
/*
const ll mx=2e5+5;
ll dp[mx][3];
string s;
ll DP(ll i,ll f)
{
    if(i>=(ll)s.size())
        return 0;
    ll &ret=dp[i][f];
    if(ret!=-1)
        return ret;
    ret=0;
    if(f==2)
    {
        if(s[i]=='?')
        {
            ret=max(1+DP(i+1,1),1+(DP(i+1,0)));
        }
        else
            ret=1+DP(i+1,s[i]-'0');
    }
    else
    {
        if(s[i]=='?')
        {
            ret=1+DP(i+1,f^=1);
        }
        else if(s[i]-'0'!=f)
            ret=1+DP(i+1,s[i]-'0');
    }
    return ret;
}
*/
//...KMP....O(n+n)
/*
ll cn=0;
  vector<ll> create_array(string pattern)
  {
      vec  lps(pattern.size());
      ll i=0;
      ll j;
      for(j=1;j<pattern.size();)
      {
          if(pattern[j]==pattern[i])
            lps[j]=i+1,i++,j++;
          else
          {

              if(i!=0)
              {
                  i=lps[i-1];
              }
              else
              {
                  lps[j]=0;
                  j++;

              }
          }

      }
      return lps;

  }
void kmp(string text,string pattern)
{
    vec lps=create_array(pattern);
    ll i=0,j=0;
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
        if(j==pattern.size())
        {
            cn++;
            j=lps[j-1];
          //  break;
        }
    }
   // cout<<"NOT"<<endl;

}
*/
struct tup
{
    ll a,b,c;
};
//Prime Test
/*
ll a[10000];
void siv(ll n)
{
    ll i,j;
    memset(a,-1,sizeof a);
    a[0]=0;
    a[1]=0;
    for(i=2;i*i<=10000;i++)
    {
        if(a[i]==-1)
        {
            for(j=i*i;j<=n;j+=i)
            {
                a[j]=0;
            }
        }

    }
}
*/
void oka()
{

            setl s;
            ll n,m,y,l,r,j,i;
            ll ans[n+2];
            memset(ans,0,sizeof ans);
            cin>>n>>m;
            for(i=1;i<=n;i++)
            s.in(i);
            for(i=0;i<m;i++)
            {
                ll x;
                cin>>l>>r>>x;

                auto k=s.lower_bound(l);
                vec v;
                while(k!=s.end())
                {

                    if(*k>r)
                    break;
                    if(*k!=x)
                    {
                        v.pb(*k);
                        ans[*k]=x;

                    }
                    k++;

                }
                for(j=0;j<v.size();j++)
                    s.erase(v[j]);
                v.clear();
            }
            for(i=1;i<=n;i++)
            cout<<ans[i]<<' ';
            cout<<endl;

}

























































































































































































int main()
{
//#ifndef ONLINE_JUDGE
   // freopen("input.txt", "r", stdin);

   // freopen("output.txt", "w", stdout);
//#endif

    run

    ll t,i,j,n;
    t=1;
    ll cas=1;
   // memset(DP,-1,sizeof DP);
   // cout<<(2^3)<<endl;
    //cout<<(11^1)<<endl;
   // cout<<(int)'A'<<endl;






     //cin>>t;
           //getchar();
           //getchar();

 char c;
 //cin>>c;
   //getchar();
  // cout<<__gcd(0,2)<<endl;
  //getchar();


  while(t--){
   //
  // cout<<"Case "<<cas++<<": ";
  //  cout<<endl;

oka();
//cout<<t<<endl;

  }
}