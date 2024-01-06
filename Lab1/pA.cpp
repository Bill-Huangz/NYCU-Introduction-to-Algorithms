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
const int N=200005;
const int M=1000005;
const int MOD=998244353;//1000000007;
const ll INF=9223372036854775807;//2147483647;
const double PI=acos(-1);
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

struct I{
    int l,r,id;
    bool operator<(const I& rh){
        return l!=rh.l?l<rh.l:r>rh.r;
    }
};
int n;
I a[N];
set<int> st;
int ans1[N],ans2[N];
void sol(){
    cin >>n;
    for (int i=1;i<=n;i++){
        cin >>a[i].l>>a[i].r;
        a[i].id=i;
    }
    sort(a+1,a+n+1);
    for (int i=n;i>=1;i--){
        ans1[a[i].id]=(st.size()==0?0:*st.begin()<=a[i].r);
        st.ist(a[i].r);
    }
    st.clear();
    for (int i=1;i<=n;i++){
        ans2[a[i].id]=(st.size()==0?0:*st.rbegin()>=a[i].r);
        st.ist(a[i].r);
    }

    for (int i=2;i<=n;i++){
        if (a[i].l==a[i-1].l&&a[i].r==a[i-1].r){
            ans1[a[i].id]|=ans1[a[i-1].id];
        }
    }
    for (int i=n;i>=2;i--){
        if (a[i].l==a[i-1].l&&a[i].r==a[i-1].r){
            ans2[a[i-1].id]|=ans2[a[i].id];
        }
    }
    
    
    for (int i=1;i<=n;i++)
        cout <<ans1[i]<<' ';
    cout <<'\n';
    for (int i=1;i<=n;i++)
        cout <<ans2[i]<<' ';
    cout <<'\n';
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