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
const int N=500005;
const int M=505;
// const int MOD=998244353;//1000000007;
const ll INF=2147483647;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

struct BIT{
    int n;
    vector<int> bit;
    void init(int _n){
        n=_n;
        bit.resize(n+5);
    }
    void modi(int i,int v){
        for (;i<=n;i+=(i&-i)){
            bit[i]=max(bit[i],v);
        }
    }
    int que(int i){
        int res=0;
        for (;i>0;i-=(i&-i))
            res=max(res,bit[i]);
        return res;
    }
};
int n;
struct I{
    int l,r,w;
    bool operator<(const I& rh){
        return r<rh.r;
    }
} a[N];
void sol(){
    cin >>n;
    vector<int> b;
    for (int i=0;i<n;i++) cin >>a[i].l>>a[i].r>>a[i].w,b.pb(a[i].l),b.pb(a[i].r);
    sort(ALL(b)); b.resize(unique(ALL(b))-b.begin());
    for (int i=0;i<n;i++){
        a[i].l=upper_bound(ALL(b),a[i].l)-b.begin();
        a[i].r=upper_bound(ALL(b),a[i].r)-b.begin();        
    }
    sort(a,a+n);
    BIT bit;bit.init(b.size()+1);
    for (int i=0;i<n;i++){
        bit.modi(a[i].r,bit.que(a[i].l-1)+a[i].w);
    }
    cout <<bit.que(b.size()+1)<<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}