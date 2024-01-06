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
const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int n;
int res[2005][2005];
int idx;
void DC(int ux,int uy,int dx,int dy){
    if (dx-ux==1){
        res[ux][uy]=++idx;
        return;
    }
    int mx=(ux+dx)/2;
    int my=(uy+dy)/2;
    DC(ux,uy,mx,my);
    DC(ux,my,mx,dy);
    DC(mx,uy,dx,my);
    DC(mx,my,dx,dy);
}
void sol(){
    cin >>n;
    if (n==0){
        cout <<"1\n";
        return;
    }
    idx=0;
    DC(0,0,(1<<n),(1<<n));
    for (int i=0;i<(1<<n);i++)
        for (int j=0;j<(1<<n);j++)
            cout <<res[i][j]<<" \n"[j==((1<<n)-1)];
    
}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    srand(time(NULL));
    int _=1;
    // /cin >>_;
    while (_--) sol();
    return 0;
}