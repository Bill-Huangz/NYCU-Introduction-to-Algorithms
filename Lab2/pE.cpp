#include <bits/stdc++.h>
#define int long long
#define double long double
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); // 好孩子不要查這行
#define pb push_back
#define ALL(i) i.begin(),i.end()
#define gcd(i,j) __gcd(i,j)
#define fi first
#define se second
//#define X first
//#define Y second
#define eps 0.00000001
#define ist insert
//#define mul(a,b,c) (a%c)*(b%c)%c
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O2")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=100005;
const int M=505;
// const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

pii mul(pii lh,pii rh,int k,int MOD){
    int x=lh.fi,y=rh.fi,a=lh.se,b=rh.se;
    return make_pair((k*x%MOD*y%MOD+a*y%MOD+b*x%MOD+a*b/k%MOD)%MOD,a*b%k);
}
pii qp(pii c,int b,int k,int MOD){
    if (b==0) return k==1?pii{1,0}:pii{0,1};
    if (b==1) return c;
    pii t=qp(c,b/2,k,MOD);
    t=mul(t,t,k,MOD);
    if (b%2==1) return mul(t,c,k,MOD);
    else return t;
}
void sol(){
    int x,y,k,p;
    cin >>x>>y>>k>>p;

    pii res=qp(pii{x/k,x%k},y,k,p);
    cout <<res.fi%p<<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    srand(time(NULL));
    int _=1;
    cin >>_;
    while (_--) sol();
    return 0;
}