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
    string x;
    ll t=1;
    while(cin >>x)
    {
        if(x.size()<=2) cout << t << ". " << x << endl;
        else if(x.size()==3) 
        {
            cout << t << ". " << x[0] << " shata " ;
            if(x[1]!='0') cout << x[1] ;
            if(x[2]!='0') cout << x[2] ;
            cout << endl;

        }
        else if(x.size()==4) 
        {
            cout << t << ". " << x[0] << " hajar " ;
            if(x[1]!='0') cout << x[1] << " shata ";
            if(x[2]!='0') cout << x[2] ;
            if(x[3]!='0') cout << x[3] ;
            cout << endl;

        }
        else if(x.size()==5) 
        {
            cout << t << ". " << x[0] << x[1] << " hajar ";
            if(x[2]!='0') cout << x[2] << " shata ";
            if(x[3]!='0') cout << x[3] ;
            if(x[4]!='0') cout << x[4] ;
            cout << endl;
        }
        else if(x.size()==6) 
        {
            cout << t<<  ". " << x[0] << " lakh "  ;
            if(x[1]!='0') cout << x[1] ;
            if(x[2]!='0') cout  << x[2] ;
            if(x[1]!='0' or x[2]!='0')cout << " hajar ";
            if(x[3]!='0') cout << x[3] << " shata ";
            if(x[4]!='0') cout << x[4];
            if(x[5]!='0')  cout << x[5] ;
            cout << endl;

        }
        else if(x.size()==7) 
        {
            cout << t << ". " << x[0] << x[1] <<  " lakh "  ;
            if(x[2]!='0') cout << x[2] ;
            if(x[3]!='0') cout << x[3] ;
            if(x[2]!='0' or x[3]!='0') cout << " hajar " ;
            if(x[4]!='0') cout << x[4] << " shata ";
            if(x[5]!='0') cout << x[5] ;
            if(x[6]!='0') cout << x[6];
            cout << endl;
        }
        else if(x.size()==8) 
        {
            cout << t << ". " << x[0] << " kuti " ;
            if(x[1]!='0') cout << x[1] ;
            if(x[2]!='0') cout << x[2] ;
            if(x[1]!='0' or x[2]!='0') cout << " lakh ";
            if(x[3]!='0') cout << x[3] ;
            if(x[4]!='0') cout << x[4] ;
            if(x[3]!='0' or x[4]!='0') cout << " hajar " ;
            if(x[5]!='0') cout << x[5] << " shata ";
            if(x[6]!='0') cout << x[6];
            if(x[7]!='0') cout << x[7];
            cout << endl;
        }

        else if(x.size()==9) 
        {
            cout << t << ". " << x[0] << x[1] << " kuti " ;
            if(x[2]!='0') cout << x[2] ;
            if(x[3]!='0') cout << x[3];
            if(x[2]!='0' or x[3]!='0 ') cout << " lakh ";
            if(x[4]!='0') cout << x[4] ;
            if(x[5]!='0') cout << x[5];
            if(x[4]!='0' or x[5]!='0') cout << " hajar " ;
            if(x[6]!='0') cout << x[6] << " shata ";
            if(x[7]!='0') cout << x[7];
            if(x[8]!='0') cout << x[8];
            cout << endl;
        }
        else if(x.size()==10) 
        {
            cout << t << ". " << x[0] << " shata " ;
            if(x[1]!='0') cout << x[1];
            if(x[2]!='0') cout << x[2] ;
            if(x[1]!='0' or x[2]!='0')  cout << " kuti ";
            else cout << "kuti ";
            if(x[3]!='0') cout << x[3];
            if(x[4]!='0') cout << x[4];
            if(x[3]!=0 or x[4]!='0') cout << " lakh ";
            if(x[5]!='0') cout << x[5];
            if(x[6]!='0') cout << x[6];
            if(x[5]!='0' or x[6]!='0') cout << " hajar ";
            if(x[7]!='0') cout << x[7] << " shata ";
            if(x[8]!='0') cout << x[8];
            if(x[9]!='0') cout << x[9];
            cout << endl;
        }
        else if(x.size()==11) 
        {
            cout << t << ". " << x[0] << " hajar " ;
            if(x[1]!='0') cout << x[1] << " shata ";
            if(x[2]!='0') cout << x[2];
            if(x[3]!='0') cout << x[3];
            if(x[2]!='0' or x[3]!='0')cout << " kuti ";
            else cout << "kuti ";
            if(x[4]!='0') cout << x[4];
            if(x[5]!='0') cout << x[5];
            if(x[4]!='0' or x[5]!='0' ) cout << " lakh ";
            if(x[6]!='0') cout << x[6];
            if(x[7]!='0') cout << x[7] ;
            if(x[6]!='0' or x[7]!='0') cout << " hajar ";
            if(x[8]!='0') cout << x[8] << " shata ";
            if(x[9]!='0') cout << x[9];
            if(x[10]!='0') cout << x[10];
            cout << endl;
        }
        else if(x.size()==12) 
        {
            cout << t << ". " << x[0] << x[1] << " hajar " ;
            if(x[2]!='0') cout << x[2] << " shata ";
            if(x[3]!='0') cout << x[3] ;
            if(x[4]!='0') cout << x[4];
            if(x[3]!='0' or x[4]!='0' ) cout << " kuti ";
            else cout << "kuti ";
            if(x[5]!='0') cout << x[5];
            if(x[6]!='0') cout << x[6];
            if(x[5]!='0' or x[6]!='0') cout << " lakh ";
            if(x[7]!='0') cout << x[7];
            if(x[8]!='0') cout << x[8];
            if(x[7]!='0' or x[8]!='0') cout << " hajar ";
            if(x[9]!='0') cout << x[9] << " shata ";
            if(x[10]!='0') cout << x[10];
            if(x[11]!='0') cout << x[11];
            cout << endl;
        }
        else if(x.size()==13) 
        {
            cout << t << ". " << x[0] << " lakh " << x[8] <<x[9] << " hajar " << x[10] << " shata " << x[11] << x[12] << endl;
            if(x[1]!='0') cout << x[1] ;
            if(x[2]!='0') cout << x[2] ;
            if(x[1]!='0' or x[2]!='0') cout << " hajar ";
            if(x[3]!='0') cout << x[3] << " shata ";
            if(x[4]!='0' ) cout << x[4];
            if(x[5]!='0') cout << x[5];
            if(x[1]!='0' or x[2]!='0' or x[3]!='0' or x[4]!='0' or x[5]!='0' ) cout << " kuti ";
            else cout << "kuti ";
            if(x[6]!='0') cout << x[6];
            if(x[7]!='0') cout << x[7];
            if(x[6]!='0' or x[7]!='0') cout << " lakh ";
        }
        else if(x.size()==14) cout << t << ". " << x[0] << x[1] <<  " lakh " << x[2] << x[3] << " hajar " << x[4] << " shata " << x[5] << x[6] << " kuti " << x[7] << x[8] << " lakh " <<  x[9] << x[10] << " hajar " << x[11] << " shata " << x[12] << x[13] << endl;
        else if(x.size()==15) cout << t << ". " << x[0] << " kuti " << x[1] << x[2] << " lakh " << x[3] << x[4] << " hajar " << x[5] << " shata " << x[6] << x[7]  << " kuti " << x[8] << x[9] << " lakh " << x[10] << x[11] << " hajar " << x[12] << " shata " << x[13] << x[14] << endl; 
        t++;
    }
    
    //---------------------------------
    
    return 0;
}
