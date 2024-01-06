#include <bits/stdc++.h>
// #define int long long
#define double long double
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long LL;
const int N=500005;
const int M=505;
// const int MOD=998244353;//1000000007;
const LL INF=2147483647;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int ans;
int n,K;
vector<int> a;
int c[3*N];
LL DC(int L,int R){
    if (R-L==1){
        return (K==0);
    }
    //cerr <<l<<" "<<r<<": ";
    int m=(L+R)/2;
    int cur=m,cMax=0,cMin=n+1,ll,rr;
    LL cnt=0;
    unordered_map<int,int> mp;
    
    // 大R小R
    ll=rr=m;
    cur=m,cMax=0,cMin=n+1;

    for (int i=m;i<R;i++){
        cMax=max(cMax,a[i]);
        cMin=min(cMin,a[i]);
        
        while (ll-1>=L&&a[ll-1]<=cMax){
            ll--;
        }
        while (rr-1>=L&&a[rr-1]>=cMin){
            rr--;
        }
        cnt+=(max(ll,rr)<=K+i-cMax+cMin&&K+i-cMax+cMin<m);
    }


    // 大L小L



    ll=rr=m;
    cur=n+1,cMax=0,cMin=n+1;
    int ccur=n+1;
    for (int i=m;i<R;i++){
        cMax=max(cMax,a[i]);
        cMin=min(cMin,a[i]);
        while (ll-1>=L&&a[ll-1]<=cMax){
            ll--;
            cur=min(cur,a[ll]);
            c[ll-cur+N]++;
        }
        while (rr-1>=L&&a[rr-1]>=cMin){
            rr--;
            ccur=min(ccur,a[rr]);
            c[rr-ccur+N]--;
        }
        if (ll<rr){
            cnt+=c[K+i-cMax+N];
        }
    }
    // mp.clear();
    cur=n+1;
    for (int i=m-1;i>=L;i--){
        cur=min(cur,a[i]);
        c[i-cur+N]=0;
    }

    ll=rr=m;
    cur=0,cMax=0,cMin=n+1;
    ccur=0;
    for (int i=m;i<R;i++){
        cMax=max(cMax,a[i]);
        cMin=min(cMin,a[i]);
        while (ll-1>=L&&a[ll-1]>=cMin){
            ll--;
            cur=max(cur,a[ll]);
            c[ll+cur]++;
        }
        while (rr-1>=L&&a[rr-1]<=cMax){
            rr--;
            ccur=max(ccur,a[rr]);
            c[rr+ccur]--;
        }
        if (ll<rr){
            cnt+=c[K+i+cMin];
        }
    }
    // mp.clear();
    cur=0;
    for (int i=m-1;i>=L;i--){
        cur=max(cur,a[i]);
        c[i+cur]=0;
    }
    cur=0,cMax=0,cMin=n+1;
    ccur=0;
    for (int i=m-1;i>=L;i--){
        cMax=max(cMax,a[i]);
        cMin=min(cMin,a[i]);
        c[i+cMax-cMin]++;
    }
    cur=0,cMax=0,cMin=n+1;
    ccur=n+1;
    ll=m;
    for (int i=m;i<R;i++){
        cMax=max(cMax,a[i]);
        cMin=min(cMin,a[i]);
        while (ll-1>=L&&(cMax>=max(cur,a[ll-1])||cMin<=min(ccur,a[ll-1]))){
            ll--;
            cur=max(cur,a[ll]);
            ccur=min(ccur,a[ll]);
            c[ll+cur-ccur]--;
        }
        cnt+=c[K+i];
    }
    cur=0;
    ccur=n+1;
    for (int i=m-1;i>=L;i--){
        cur=max(cur,a[i]);
        ccur=min(ccur,a[i]);
        c[i+cur-ccur]=0;
    }
    return DC(L,m)+DC(m,R)+cnt;    
}
void sol(){
    cin >>n>>K;
    a.resize(n);
    for (int &i:a) cin >>i;
    cout <<DC(0,n)<<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}