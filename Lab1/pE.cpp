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
//#pragma GCC optimize("O2")
int max(int x,int y){return x>=y?x:y;}
int min(int x,int y){return x>=y?y:x;}
using namespace std;
typedef long long ll;
const int N=1000005;
const int M=1000005;
const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int n;
pii a[N];
void sol(){
    cin >>n;
    a[0].fi=a[0].se=0;
    for (int i=1;i<=n;i++) cin >>a[i].fi,a[i].fi+=a[i-1].fi;
    for (int j=1;j<=n;j++) cin >>a[j].se;

    sort(a+1,a+n+1);
    int ans=INF,cur=0,sum=0;
    for (int i=1;i<=n;i++){
        cur+=(a[i].fi-a[1].fi)*a[i].se;
        sum+=a[i].se;
    }
    int m;
    sum/=2;
    for (m=1;m<=n;m++){
        if (a[m].se>sum) break;
        sum-=a[m].se;
    }
    for (int tt=max(1,m-10);tt<=min(n,m+10);tt++){
        cur=0;
        for (int i=1;i<=n;i++){
            cur+=abs(a[i].fi-a[tt].fi)*a[i].se;
        }
        ans=min(ans,cur);
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