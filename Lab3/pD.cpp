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
const int N=3005;
const int M=505;
// const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;


int n,m;
struct I{
    int val,x,y;
    bool operator<(const I& rh){
        return val<rh.val;
    }
};
void sol(){
    cin >>n>>m;
    vector<int> house(n),poten(m),a;
    vector<vector<int>> res(n,vector<int>(m));
    for (int i=0;i<n;i++) cin >>house[i];
    for (int i=0;i<m;i++) cin >>poten[i];
    for (int i=0,x;i<n;i++)
        for (int j=0;j<m;j++)
            cin >>x, a.pb(x);
    vector<I> b;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            b.pb(I{house[i]*poten[j],i,j});
    sort(ALL(b));
    sort(ALL(a));

    int l=0,r=n*m-1,ans=0;
    while (l<n&&b[l].val*a[l]>=0){
        res[b[l].x][b[l].y]=a[l];
        ans+=b[l].val*a[l];
        l++;
    }
    while (r>=l&&b[r].val*a[r]>=0){
        res[b[r].x][b[r].y]=a[r];
        ans+=b[r].val*a[r];
        r--;
    }
    for (int i=l;i<=r;i++){
        res[b[i].x][b[i].y]=a[i];
        ans+=b[i].val*a[i];
    }
    cout <<ans<<'\n';
    for (int i=0;i<n;i++) cout <<house[i]<<' '; cout <<'\n';
    for (int i=0;i<m;i++) cout <<poten[i]<<' '; cout <<'\n';
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            cout <<res[i][j]<<' ';
        cout <<'\n';
    }
    
    

}   
signed main(){
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}