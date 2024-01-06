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
//#pragma GCC optimize("Ofast","inline","-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long LL;
const int N=6000005;
const int M=505;
// const int MOD=998244353;//1000000007;
const LL INF=2147483647;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int dp[N]{};
int n,m,p;
int tmp[N]{};
vector<pii> e[N];
set<int> st;
void sol(){
    cin >>n>>m>>p;
    for (int i=0,x,y;i<m;i++){
        cin >>x>>y;
        e[y-x].pb({x,y});
    }
    for (int i=1;i<=n;i++) dp[i]=1;

    int cnt=0;
    for (int j=1;j<=n;j++){
        for (int i=j;i<=n;i+=j) tmp[i]=0;
        st.clear();
        for (auto [x,y]:e[j]){
            tmp[x]=0;
            tmp[y]=0;
            st.ist(x); st.ist(y);
        }
        for (int i=j;i<=n;i+=j){
                tmp[i]=(tmp[i]+dp[i-j])%p;
                tmp[i]=(tmp[i]+dp[i+j])%p;
        }
        for (auto [x,y]:e[j]){
            tmp[x]=(tmp[x]+dp[y])%p;
            tmp[y]=(tmp[y]+dp[x])%p;
        }
    
        for (int i=j;i<=n;i+=j) (dp[i]+=tmp[i])%=p;
        
        for (int i:st){
            (dp[i]+=tmp[i])%=p;
        }
    }
    int ans=-n;
    //cout <<cnt<<' ';
    for (int i=1;i<=n;i++) (ans+=dp[i])%=p;//,  cout <<dp[i][n]<<' ';
    cout <<ans<<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    //srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}