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
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O2")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=200005;
const int M=1000005;
const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int n,Q;

int a[N];
int q[1005][4]; // ol or cr
int check(int x){
    for (int i=1;i<=Q;i++) q[i][2]=q[i][1];
    for (int i=n;i>=1;i--){
        int cur=a[i];
        for (int j=1;j<=x;j++){
            if (q[j][0]<=cur&&cur<=q[j][1]){
                cur=q[j][2]--;
            }
        }
        if (cur!=i) return 0;
    }
    return 1;
}
void sol(){
    cin >>n>>Q;
    for (int i=1;i<=n;i++) cin >>a[i];
    for (int i=1;i<=Q;i++) cin >>q[i][0]>>q[i][1],q[i][2]=q[i][1];
    
    int L=1,R=Q,ans=-1;
    while (R>=L){
        int m=(L+R)/2;
        if (check(m)){
            ans=m;
            R=m-1;
        }
        else L=m+1;
    }
    cout <<ans<<'\n';
}   

signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine
    //srand(time(NULL));
    int _=1;
    //cin >>_;
	while (_--) sol();
    //while (cin >>n&&n) sol();

    return 0;
}