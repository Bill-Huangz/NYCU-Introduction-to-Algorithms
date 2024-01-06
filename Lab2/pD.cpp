#include <bits/stdc++.h>
#define int long long
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
const int N=2000005;
const int M=505;
// const int MOD=998244353;//1000000007;
const ll INF=2147483647;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int n;
int b[N],post[N],in[N],fa[N],repo[N],nleaf[N];
void DC(int f,int l_in,int r_in,int l_post,int r_post){
    if (r_in<l_in) return;
    int rt=post[r_post];
    //cerr <<rt<<' '<<l_in<<' '<<r_in<<' '<<l_post<<' '<<r_post<<'\n';
    fa[rt]=f;
    
    int m=repo[rt];
    DC(rt,l_in,m-1,l_post,l_post+m-(l_in)-1);
    DC(rt,m+1,r_in,l_post+m-l_in,r_post-1);
}
void sol(){
    cin >>n;
    for (int i=1;i<=n;i++) cin >>b[i];
    for (int i=1;i<=n;i++) cin >>in[i],repo[in[i]]=i;
    for (int i=1;i<=n;i++) cin >>post[i];
    DC(-1,1,n,1,n);
    // for (int i=1;i<=n;i++) cout <<fa[i]<<' ';
    // cout <<'\n';
    int rt,sum=0;
    for (int i=1;i<=n;i++){
        if (fa[i]==-1) rt=i;
        else nleaf[fa[i]]=1;
    }
    cout <<rt<<"\n";
    for (int i=1;i<=n;i++)
        sum+=(1-nleaf[i])*b[i];
    cout <<sum<<'\n';

}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}