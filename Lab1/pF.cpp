#include <bits/stdc++.h>
//#define int long long
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
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O2")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=100005;
const int M=505;
const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int n,K;
// int we[N],wd[N],wp[N];
int sd[M],se[M],sp[M];
int ggcd[1005][1005];
struct I{
    int wd,we,wp;
    bool operator<(const I& rh){
        return we==rh.we?wd<rh.wd:we<rh.we;
    }
} a[N];
inline ll lossHP(ll damage,ll shield,ll times){
    ll res=0;
    if (shield>=damage){
        times-=shield-damage+1;
        shield=damage-1;
    }
    if (times<=0) return res;

    if (shield>=times){
        int U=damage-shield;
        int D=U+times-1;
        res+=1LL*(U+D)*times/2;
        times-=shield;
    }   
    else {
        res+=1LL*damage*times-1LL*(shield+1)*shield/2;
    }
    return res;
}
inline bool check(int x,int i){
    //for (int i=1;i<=n;i++){
        int cur=x;
        ll ie=a[i].we,id=a[i].wd;
        for (int j=1,g;j<=K;j++){
            g=ggcd[a[i].wp][sp[j]];//g=gcd(a[i].wp,sp[j]);
            int je=se[j]+g,jd=sd[j]+g;
            
            int atktimes=(je+(id-1))/id;
            ie-=lossHP(jd,cur,atktimes-1);   
            cur=max(0,cur-atktimes+1);
            if (ie<=0) return 0;
        }
    //}
    return 1;

}

void sol(){
    cin >>n>>K;
    for (int i=1;i<=n;i++) cin >>a[i].wd;
    for (int i=1;i<=n;i++) cin >>a[i].we;
    for (int i=1;i<=n;i++) cin >>a[i].wp;
    sort(a+1,a+n+1);
    for (int i=1;i<=K;i++) cin >>sd[i];
    for (int i=1;i<=K;i++) cin >>se[i];
    for (int i=1;i<=K;i++) cin >>sp[i];
    for (int i=1;i<=1000;i++)
        for (int j=1;j<=1000;j++)
            ggcd[i][j]=gcd(i,j);
    vector<int> vc(n);
    for (int i=0;i<n;i++) vc[i]=i+1;
    int ans=0;
    while (vc.size()){
        int idx=vc[min(rand()%1,(int)vc.size()-1)];
        int L=0,R=1E9,res=-1;
        while (R>=L){
            int m=(L+R)/2;
            if (check(m,idx)){
                res=m;
                R=m-1;
            }
            else L=m+1;
        }
        ans=res;
        vector<int> tmp;
        for (auto i:vc)
            if (i!=idx&&!check(res,i))
                tmp.pb(i);
        vc=tmp;
    }    
    cout <<ans<<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    //while (cin >>n&&n) sol();
    return 0;
}