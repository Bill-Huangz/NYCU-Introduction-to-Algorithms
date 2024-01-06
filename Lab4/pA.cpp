#include <bits/stdc++.h>
//#define int long long
#define double long double
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb emplace_back
#define ALL(i) i.begin(),i.end()
#define gcd(i,j) __gcd(i,j)
#define fi first
#define se second
#define bitCount(i) __builtin_popcount(i)
//#define X first
//#define Y second
#define eps 0.00000001
#define ist insert
#define mul(a,b,c) (a%c)*(b%c)%c
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC optimize("O3")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")

int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long LL;
const int N=25;
const int M=505;
const int MOD=1000000007;//998244353;
const int INF=2100;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int32_t n;
int a[N][N];
int dp[(1<<21)];
int pre[(1<<21)];
vector<int> group[(1<<21)];
void sol(){
    cin >>n;
    int NN=(1<<n);
    for (int32_t i=0;i<NN;i++){
        pre[i]=-1, dp[i]=INF;
        // for (int j=0;j<n;j++)
        //     if (i&(1<<j))
        //         group[i].pb(j);
    }
    for (int i=0;i<n;i++)   
        for (int j=0;j<n;j++)   
            cin >>a[i][j];
    if (n==2){
        cout <<a[0][1]<<'\n'<<"1 1\n";
        return;
    }
    else if (n==3){
        cout <<a[0][1]+a[0][2]+a[1][2]<<'\n'<<"1 1 1\n";
        return;
    }
    pre[0]=dp[0]=0;
    

    
    for (int32_t bit=1;bit<NN;bit++){
        // auto vc=group[bit];
        // if (vc.size()<2) continue;
        pre[bit]=-1, dp[bit]=INF;
        vector<int> vc;
        
        for (int j=0;j<n;j++)
            if (bit&(1<<j))
                vc.pb(j);
        //for (int i:vc) cout <<i<<' '; cout<<'\n';
        if (vc.size()<2) continue;
        int nn=vc.size();
        //cout <<nn<<'\n';
        {
            int take_i=0,mn=INF;
            for (int ii=1;ii<nn;ii++){
                int i=vc[ii],j=vc[0];
                //cout <<ii<<' ';
                if (mn>dp[bit^(1<<i)^(1<<j)]+a[i][j]){ 
                    take_i=(1<<i)^(1<<j);
                    mn=dp[bit^take_i]+a[i][j];
                    
                }
            }
            dp[bit]=mn;
            pre[bit]=bit^take_i;   
        }
        {
            int take_i=0,mn=dp[bit];
            for (int ii=1;ii<nn;ii++)
                for (int jj=ii+1;jj<nn;jj++){
                    int i=vc[ii],j=vc[jj],k=vc[0];
                    if (mn>dp[bit^(1<<i)^(1<<j)^(1<<k)]+a[i][j]+a[j][k]+a[i][k]){
                        take_i=(1<<i)^(1<<j)^(1<<k);
                        mn=dp[bit^take_i]+a[i][j]+a[j][k]+a[i][k];
                    }
                }
            if (dp[bit]>mn)dp[bit]=mn, pre[bit]=bit^take_i;   
        }
        
        //cout <<'\n';
    }

    cout <<dp[NN-1]<<'\n';
    int vis[25];
    int cur=NN-1,t=1;
    while (cur){
        auto u=cur^pre[cur];
        for (int j=0;j<n;j++)
            if (u&(1<<j))
                vis[j]=t;
        t++;
        cur=pre[cur];
    }
    for (int i=0;i<n;i+=1) cout <<vis[i]<<' ';
    cout <<'\n';
}   
signed main(){
    //Nanase_Kurumi_aka_menhera_chan_is_mine 
    //srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}
/*
5
0 2 7 1 8
2 0 2 8 1 
7 2 0 8 2
1 8 8 0 8
8 1 2 8 0

3
0 1 2
1 0 3
2 3 0

9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/