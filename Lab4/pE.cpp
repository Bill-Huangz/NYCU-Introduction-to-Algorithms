#include <bits/stdc++.h>
#define int long long
#define double long double
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define ALL(i) i.begin(),i.end()
#define gcd(i,j) __gcd(i,j)
#define fi first
#define se second
#define bitCount(i) __builtin_popcount(i)
//#define X first
//#define Y second
#define eps 0.00000001
#define ist insert
//#define mul(a,b,c) (a%c)*(b%c)%c
// #pragma GCC optimize("Ofast","inline","-ffast-math")
// #pragma GCC optimize("O3")

// #pragma GCC target("avx,sse2,sse3,sse4,mmx")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=100005;
const int M=505;
const int MOD=1000000007;//998244353;
const ll INF=2147483647;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int n,m;
int a[N];
vector<pii> e[2*N];
int dp[2*N];
int deg[2*N];
void sol(){
    cin >>n>>m;
    for (int i=1;i<=n;i++) cin >>a[i];
    for (int i=0,x,y,w;i<m;i++){
        char c;
        cin >>x>>y>>c>>w;
        if (c=='B'){
            e[x+n].pb({y,w}); 
            deg[y]++;
        }
        else e[x].pb({y+n,w}), deg[y+n]++;
    }
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (deg[i]==0){
            q.push(i);
        }
        if (deg[i+n]==0){
            q.push(i+n);
        }
    }

    while (q.size()){
        int v=q.front(); q.pop();
        if (dp[v]<a[v>n?v-n:v]) {
            for (auto [x,y]:e[v]){
                deg[x]--;
                if (deg[x]==0)
                    q.push(x);
            }
        }
        else{
            for (auto [x,y]:e[v]){
                deg[x]--;
                dp[x]=max(dp[x],dp[v]+y);
                if (deg[x]==0)
                    q.push(x);
            }
        }
    }
    for (int i=1;i<=n;i++)
        cout <<max(dp[i],dp[i+n])<<' ';
    cout <<'\n';
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    //srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}