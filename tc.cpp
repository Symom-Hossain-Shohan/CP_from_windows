#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=20;
ll a[N];
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int main()
{
    ll n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
    	for(ll i=0;i<m;i++)
    		scanf("%lld",&a[i]);
    	ll end=(1<<m);
    	ll sum=0;
    	for(ll i=1;i<end;i++)
    	{
    		ll tmp=1,num=0;
    		for(ll j=0;j<m;j++)
    		{
    			if((1<<j)&i) tmp=lcm(tmp,a[j]),num++;
    			if(tmp>n) break;
    		}
    		if(num%2==1) sum+=n/tmp;
    		else sum-=n/tmp;
    	}
    	printf("%lld\n",n-sum);
    }
    return 0;
}