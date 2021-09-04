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
ll lm = 2750134;
ll pr[2750134];

void primee()
{
	ll i = 0, j, k;
	pr[2] = 0;
	for (i = 3; i * i <= lm; i += 2)
	{
		if (pr[i] != -1)
		{
			for (j = i * i; j <= lm; j += 2*i)
			{
				pr[j] = -1;
			}
		}
	}
	pr[2] = 1;
	k = 1;
	for (i = 3; i <= lm; i += 2)
	{
		if (pr[i] != -1)
		{
			k++;
			pr[i] = k;
		}
	}
	
}

ll f(ll p)
{
	ll x=0;
    for (ll i = 2; i * i <= p; i++)
	{
		if (p % i == 0)
		{
			x= max(i, p / i);
            break;
		}
	}
    return x;
}



int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    primee();
	ll n, i, j, k, l;
	vector<ll> v, ans;
	map<ll, ll> m;
	cin >> n;
	for (i = 0; i < 2 * n; i++)
	{
		cin >> j;
		v.push_back(j);
		m[j]++;
	}
	sort(v.begin(), v.end());
	for (i = v.size() - 1; i >= 0; i--)
	{
		
		
		if (m[v[i]])
		{
		
			if (pr[v[i]] > 0)
			{
				m[pr[v[i]]]--;
				m[v[i]]--;
				ans.push_back(pr[v[i]]);
			}
			else
			{
				m[f(v[i])]--;
				m[v[i]]--;

				ans.push_back(v[i]);
			}
		}
	}
	for (auto p : ans)
		cout << p << " ";
    
    //---------------------------------
    
    return 0;
}
