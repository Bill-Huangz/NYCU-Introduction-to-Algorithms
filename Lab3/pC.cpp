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
const int N=1000005;
const int M=505;
// const int MOD=998244353;//1000000007;
const ll INF=2147483647;//9223372036854775807;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;


int n,K;
priority_queue<pii,vector<pii>,greater<pii>> pq;
pii a[N];
void sol(){
    cin >>n>>K;
    for (int i=1,x;i<=n;i++){
        cin >>a[i].fi;
        a[i].se=i;
        
    }
    if (n==1){
        cout <<"0\n0\n";
        return;
    }
    int ans=0,sum=0;
    vector<vector<int>> res;
    vector<int> tmp;
    sort(a+1,a+n+1,greater<pii>());
    int mx=1;
    while (mx<n) mx+=(K-1);
    mx-=(K-1);

    for (int i=mx;i<=n;i++){
        sum+=a[i].fi;
        tmp.pb(a[i].se);
    }
    if (tmp.size()>1){
        ans+=sum;
        res.pb(tmp);
        pq.push({sum,++n});
    }
    else {
        pq.push(a[mx]);
    }
    for (int i=1;i<mx;i++)
        pq.push(a[i]);
    // cout <<mx<<' '<<pq.size()<<'\n';
    while (pq.size()!=1){
        sum=0;
        tmp.clear();
        for (int i=0;i<K;i++){
            auto [x,y]=pq.top(); pq.pop();
            sum+=x;
            tmp.pb(y);
        } 
        ans+=sum;
        pq.push({sum,++n});
        res.pb(tmp);
    }
    
    cout <<ans<<'\n'<<res.size()<<'\n';
    for (auto i:res){
        cout <<i.size()<<' ';
        for (int j:i) cout <<j<<' ';
        cout <<'\n';
    }
}   
signed main(){
    // Nanase_Kurumi_aka_menhera_chan_is_mine 
    srand(time(NULL));
    int _=1;
    //cin >>_;
    while (_--) sol();
    return 0;
}